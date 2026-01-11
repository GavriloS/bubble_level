/**********************************************************************************************************************
 * \file tc275_shared_IPC.h
 *********************************************************************************************************************/

#ifndef PERIPHERALWRAPPER_TC275_SHARED_IPC_H_
#define PERIPHERALWRAPPER_TC275_SHARED_IPC_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/

// 1. Define the actual data needed for a Bubble Level
typedef struct {
    float accel_x;  // Tilt on X-axis
    float accel_y;  // Tilt on Y-axis
} Bubble_Data_t;

// 2. Define the Shared Memory Container (Data + Protection)
typedef struct {
    volatile Bubble_Data_t  data;    // The sensor values
    volatile IfxCpu_mutexLock mutex; // The lock to protect this memory [cite: 19]
    volatile uint32 update_count;    // Optional: Increment this on write so reader knows data is new
} Shared_Memory_Block_t;

/*********************************************************************************************************************/
/*--------------------------------------------Global Variables (Extern)----------------------------------------------*/
/*********************************************************************************************************************/

// We need TWO shared memory areas as per the requirements [cite: 15]

// 1. Shared Memory between Core 1 (Producer) and Core 0 (Broker)
extern volatile Shared_Memory_Block_t g_SharedMem_C1_to_C0;

// 2. Shared Memory between Core 0 (Broker) and Core 2 (Consumer)
extern volatile Shared_Memory_Block_t g_SharedMem_C0_to_C2;

#endif /* PERIPHERALWRAPPER_TC275_SHARED_IPC_H_ */
