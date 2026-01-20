// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

/**
 *  @file
 *
 *  @brief Platform SPI Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_SPI SPI
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_SPI_Driver Driver
 *
 *  @{
 *  @}
 */

#ifndef SPI_H_
    #define SPI_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include <stdint.h>

    #include "SPI_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief SPI Operation Status
     *
     *  @enum SPI_Status_t
     */
    typedef enum SPI_Status
    {
        SPI_Status_Success = 0,     ///< Success
        SPI_Status_ArgumentInvalid, ///< Argument Invalid
        SPI_Status_NotSupported,    ///< Not Supported
        SPI_Status_Error,           ///< General Error
        SPI_Status_Busy,            ///< Busy
        SPI_Status_Timeout,         ///< Timeout
    } SPI_Status_t;

    /**
     *  @brief SPI Data Type
     */
    typedef uint8_t SPI_Data_t;

    /**
     *  @brief SPI Data Length Type
     */
    typedef uint32_t SPI_DataLength_t;

    /**
     *  @brief SPI On-Complete Callback
     *
     *  @param[in] SPIx   Instance
     *  @param[in] Status Execution status
     *
     *  @return SPI_Status_t
     */
    typedef SPI_Status_t ( *SPI_CallbackOnComplete_t )( SPI_t SPIx, SPI_Status_t Status );

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize SPI peripheral
     *
     *  @note MUST BE called before using any SPI API
     *
     *  @param[in] SPIx Peripheral
     *
     *  @return SPI_Status_t
     */
    SPI_Status_t SPI_Initialize( SPI_t SPIx );

    /**
     *  @brief Cycle SPI peripheral
     *
     *  @param[in] SPIx Peripheral
     *
     *  @return SPI_Status_t
     */
    SPI_Status_t SPI_Cycle( SPI_t SPIx );

    /**
     *  @brief DeInitialize SPI peripheral
     *
     *  @param[in] SPIx Peripheral
     *
     *  @return SPI_Status_t
     */
    SPI_Status_t SPI_DeInitialize( SPI_t SPIx );

    /**
     *  @brief Set callback for on-complete of SPI instance
     *
     *  @param[in] SPIx     Instance
     *  @param[in] Callback On-complete callback
     *
     *  @return SPI_Status_t
     */
    SPI_Status_t SPI_SetCallbackOnComplete( SPI_t SPIx, SPI_CallbackOnComplete_t Callback );

    /**
     *  @brief Write data to SPI peripheral
     *
     *  @param[in] SPIx       Peripheral
     *  @param[in] Data       Data buffer
     *  @param[in] DataLength Length of data buffer
     *
     *  @return SPI_Status_t
     */
    SPI_Status_t SPI_Write( SPI_t SPIx, SPI_Data_t * Data, SPI_DataLength_t DataLength );

    /**
     *  @brief Read data from SPI peripheral
     *
     *  @param[in] SPIx       Peripheral
     *  @param[in] Data       Data buffer
     *  @param[in] DataLength Length of data buffer
     *
     *  @return SPI_Status_t
     */
    SPI_Status_t SPI_Read( SPI_t SPIx, SPI_Data_t * Data, SPI_DataLength_t DataLength );

    /**
     *  @brief Write and Read simultaneously to/from SPI peripheral
     *
     *  @param[in] SPIx         Peripheral
     *  @param[in] DataTx       Transmit data buffer
     *  @param[in] DataTxLength Transmit length of data buffer
     *  @param[in] DataRx       Receive data buffer
     *  @param[in] DataRxLength Receive length of data buffer
     *
     *  @return SPI_Status_t
     */
    SPI_Status_t SPI_Transaction( SPI_t SPIx, SPI_Data_t * DataTx, SPI_DataLength_t DataTxLength, SPI_Data_t * DataRx, SPI_DataLength_t DataRxLength );

    // TODO More APIs

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char SPI_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* SPI_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
