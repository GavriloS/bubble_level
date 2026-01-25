/*
 * UART.h
 *
 *  Created on: 2 Nov 2022
 *      Author: Technikum Wien
 */

#ifndef TC275_UART_APP_H_
#define TC275_UART_APP_H_

/**
 * @brief ASCLIN3 transmit interrupt service routine.
 *
 * Delegates the interrupt handling to the iLLD ASC transmit handler for the
 * configured UART instance.
 */
void asclin3_Tx_ISR(void);

/**
 * @brief ASCLIN3 receive interrupt service routine.
 *
 * Delegates the interrupt handling to the iLLD ASC receive handler for the
 * configured UART instance.
 */
void asclin3_Rx_ISR(void);

/**
 * @brief ASCLIN3 error interrupt service routine.
 *
 * Delegates the interrupt handling to the iLLD ASC error handler for the
 * configured UART instance.
 */
void asclin3_Er_ISR(void);

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
void initUART(void);

/**
 * @brief: a wrapper function of the IfxAsclin_Asc_blockingWrite function
 * it sends one byte via UART to the receiver
 * @params: uint8, the byte to be transfered
 * @return: void
 */
void uart_blockingWrite(uint8 byte);

/**
 * @brief: a wrapper function of the IfxAsclin_Asc_write function
 * it sends a char array to the receiver
 * @params: uint8 pointer: the char array to be transfered
 * @params: Ifx_SizeT: the size of the char array
 * @return: void
 */
void uart_sendMessage(uint8 *data, Ifx_SizeT size);
#endif /* TC275_UART_APP_H_ */
