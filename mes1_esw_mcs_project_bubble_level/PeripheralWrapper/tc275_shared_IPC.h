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
#include "tc275_common_structs.h"

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/

/**
 * @struct Shared_Memory_Block_t
 * @brief Shared IMU data with mutex protection.
 *
 * Container for sensor data shared across execution contexts.
 *
 * @var Shared_Memory_Block_t::data
 * IMU sensor measurement values.
 *
 * @var Shared_Memory_Block_t::mutex
 * CPU mutex used to protect access to the shared data.
 *
 * @var Shared_Memory_Block_t::update_count
 * Counter incremented on each write to signal that new data is available.
 */
typedef struct {
    volatile c6dofimu14_axis_t  data;           /**< IMU sensor data */
    volatile IfxCpu_mutexLock   mutex;          /**< Access protection mutex */
    volatile uint32             update_count;   /**< Write/update counter */
} Shared_Memory_Block_t;

/*********************************************************************************************************************/
/*--------------------------------------------Global Variables (Extern)----------------------------------------------*/
/*********************************************************************************************************************/

// We need TWO shared memory areas as per the requirements

/**
 * @brief Shared memory from Core 1 to Core 0.
 *
 * Used by Core 1 as the producer and Core 0 as the broker.
 * Contains IMU data protected by a mutex for safe concurrent access.
 */
extern volatile Shared_Memory_Block_t g_SharedMem_C1_to_C0;

/**
 * @brief Shared memory from Core 0 to Core 2.
 *
 * Used by Core 0 as the broker and Core 2 as the consumer.
 * Contains IMU data protected by a mutex for safe concurrent access.
 */
extern volatile Shared_Memory_Block_t g_SharedMem_C0_to_C2;

#endif /* PERIPHERALWRAPPER_TC275_SHARED_IPC_H_ */
