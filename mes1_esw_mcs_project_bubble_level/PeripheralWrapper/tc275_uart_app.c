/*
 * UART.c
 *
 *  Created on: 2 Nov 2022
 *  Author: Technikum Wien
 *
 *  A working UART implementation with custom wrapper functions of the Asclin UART functions
 *  If more functionality is needed, make wrapper functions of the original UART functions.
 *  The original functions can be found in Asclin/Asc/IfxAsclin_Asc.h
 *
 */

#include <Asclin/Asc/IfxAsclin_Asc.h>
#include "IfxCpu_Irq.h"
#include "Bsp.h"
#include "tc275_uart_app.h"

/*************************************************************************************************************/
/*------------------------------------------------------Macros-----------------------------------------------*/
/*************************************************************************************************************/
#define SERIAL_BAUDRATE         115200                              //Baud rate in bit/s

#define SERIAL_PIN_RX_CON_1     IfxAsclin3_RXD_P32_2_IN             // RX pin of the board
#define SERIAL_PIN_TX_CON_1     IfxAsclin3_TX_P15_7_OUT             // TX pin of the board

#define ASC_TX_BUFFER_SIZE      64                                  // Definition of the buffer size
#define ASC_RX_BUFFER_SIZE      64                                  // Definition of the buffer size

#define INTPRIO_ASCLIN3_TX 1                                        // Interrupt priority for UART transfer
#define INTPRIO_ASCLIN3_RX 2                                        // Interrupt priority for UART receive
#define INTPRIO_ASCLIN3_ER 3                                        // Interrupt priority for UART Error

/*************************************************************************************************************/
/*-------------------------------------------------Global variables------------------------------------------*/
/*************************************************************************************************************/
IfxAsclin_Asc asc;                                                  // Declaration of the ASC handle
uint8 ascTxBuffer[ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];       // Declaration of the FIFOs parameters
uint8 ascRxBuffer[ASC_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];       // Declaration of the FIFOs parameters

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
IFX_INTERRUPT(asclin3_Tx_ISR, 0, INTPRIO_ASCLIN3_TX);               // Adding the Interrupt Service Routine
IFX_INTERRUPT(asclin3_Rx_ISR, 0, INTPRIO_ASCLIN3_RX);               // Adding the Interrupt Service Routine
IFX_INTERRUPT(asclin3_Er_ISR, 0, INTPRIO_ASCLIN3_ER);               // Adding the Interrupt Service Routine


/**
 * @brief ASCLIN3 transmit interrupt service routine.
 *
 * Delegates the interrupt handling to the iLLD ASC transmit handler for the
 * configured UART instance.
 */
void asclin3_Tx_ISR(void) {
    IfxAsclin_Asc_isrTransmit(&asc);
}

/**
 * @brief ASCLIN3 receive interrupt service routine.
 *
 * Delegates the interrupt handling to the iLLD ASC receive handler for the
 * configured UART instance.
 */
void asclin3_Rx_ISR(void) {
    IfxAsclin_Asc_isrReceive(&asc);
}

/**
 * @brief ASCLIN3 error interrupt service routine.
 *
 * Delegates the interrupt handling to the iLLD ASC error handler for the
 * configured UART instance.
 */
void asclin3_Er_ISR(void) {
    IfxAsclin_Asc_isrError(&asc);
}

/**
 * @brief Initialize the UART (ASCLIN) module
 *
 * Configures the ASCLIN3 module for UART communication with the following settings:
 * - Baudrate: 115200 bps
 * - Pins: TX on P15.7, RX on P32.2
 * - Buffers: Configures Tx and Rx software FIFOs
 * - Interrupts: Enables Tx, Rx, and Error interrupts with defined priorities.
 *
 * This function must be called before any UART transmission occurs.
 */
void initUART() {

    /* Initialize an instance of IfxAsclin_Asc_Config with default values */
        IfxAsclin_Asc_Config ascConfig;
        IfxAsclin_Asc_initModuleConfig(&ascConfig, SERIAL_PIN_TX_CON_1.module);

        /* Set the desired baud rate */
        ascConfig.baudrate.prescaler = 1;
        ascConfig.baudrate.baudrate = SERIAL_BAUDRATE;
        ascConfig.baudrate.oversampling = IfxAsclin_OversamplingFactor_16;

        /* ISR priorities and interrupt target */
        ascConfig.interrupt.txPriority = INTPRIO_ASCLIN3_TX;
        ascConfig.interrupt.rxPriority = INTPRIO_ASCLIN3_RX;
        ascConfig.interrupt.erPriority = INTPRIO_ASCLIN3_ER;
        ascConfig.interrupt.typeOfService = IfxCpu_Irq_getTos(IfxCpu_getCoreIndex());

        /* FIFO configuration */
        ascConfig.txBuffer = &ascTxBuffer;
        ascConfig.txBufferSize = ASC_TX_BUFFER_SIZE;
        ascConfig.rxBuffer = &ascRxBuffer;
        ascConfig.rxBufferSize = ASC_RX_BUFFER_SIZE;

        /* Port pins configuration */
        const IfxAsclin_Asc_Pins pins = {
            NULL_PTR,         IfxPort_InputMode_pullUp,             // CTS pin not used
            &SERIAL_PIN_RX_CON_1,   IfxPort_InputMode_pullUp,       // RX pin not used
            NULL_PTR,         IfxPort_OutputMode_pushPull,          // RTS pin not used
            &SERIAL_PIN_TX_CON_1,   IfxPort_OutputMode_pushPull,    // TX pin
            IfxPort_PadDriver_cmosAutomotiveSpeed1
        };
        ascConfig.pins = &pins;

        IfxAsclin_Asc_initModule(&asc, &ascConfig);

}

/**
 * @brief: a wrapper function of the IfxAsclin_Asc_blockingWrite function
 * it sends one byte via UART to the receiver
 * @params: uint8, the byte to be transfered
 * @return: void
 */
void uart_blockingWrite(uint8 byte) {
    IfxAsclin_Asc_blockingWrite(&asc, byte);
}

/**
 * @brief: a wrapper function of the IfxAsclin_Asc_write function
 * it sends a char array to the receiver
 * @params: uint8 pointer: the char array to be transfered
 * @params: Ifx_SizeT: the size of the char array
 * @return: void
 */
void uart_sendMessage(uint8 *data, Ifx_SizeT size) {
    IfxAsclin_Asc_write(&asc, data, &size, TIME_INFINITE);
}

