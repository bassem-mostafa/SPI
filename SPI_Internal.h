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

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef SPI_INTERNAL_H_
    #define SPI_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "SPI.h"
    #include "driver/STM32L496VGT6P/SPI_STM32L496VGT6P.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef SPI_TIM
        #define SPI_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef SPI_LOG
        #define SPI_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define SPI_NAME       "SPI"
    #define SPI_LOG_PREFIX UTIL_StringConcatenateConstant( SPI_NAME, "> " )

    #ifdef DEBUG
        #define SPI_Raw( Level, Format, ... ) LOG_Raw( SPI_LOG, Level, Format, ##__VA_ARGS__ )
        #define SPI_Trace( Format, ... )      LOG_Trace( SPI_LOG, UTIL_StringConcatenateConstant( SPI_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define SPI_Debug( Format, ... )      LOG_Debug( SPI_LOG, UTIL_StringConcatenateConstant( SPI_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define SPI_Info( Format, ... )       LOG_Info( SPI_LOG, UTIL_StringConcatenateConstant( SPI_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define SPI_Warning( Format, ... )    LOG_Warning( SPI_LOG, UTIL_StringConcatenateConstant( SPI_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define SPI_Error( Format, ... )      LOG_Error( SPI_LOG, UTIL_StringConcatenateConstant( SPI_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define SPI_Fatal( Format, ... )      LOG_Fatal( SPI_LOG, UTIL_StringConcatenateConstant( SPI_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define SPI_Raw( Level, Format, ... )
        #define SPI_Trace( Format, ... )
        #define SPI_Debug( Format, ... )
        #define SPI_Info( Format, ... )
        #define SPI_Warning( Format, ... )
        #define SPI_Error( Format, ... )
        #define SPI_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef enum SPI_Type
    {
        SPI_Type_Unknown = 0,
        SPI_Type_Null,
        SPI_Type_STM32L496VGT6P,
    } SPI_Type_t;

    typedef struct SPI_Instance
    {
        SPI_Type_t Type;

        union
        {
            SPI_STM32L496VGT6P_t STM32L496VGT6Px;
        };

        GPIO_t ChipSelect;

        SPI_OnComplete_t OnComplete;
    } SPI_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    SPI_Status_t SPI_Port_Initialize( SPI_t SPIx );
    SPI_Status_t SPI_Port_Cycle( SPI_t SPIx );
    SPI_Status_t SPI_Port_DeInitialize( SPI_t SPIx );

    SPI_Status_t SPI_Port_SetOnComplete( SPI_t SPIx, SPI_OnComplete_t * OnComplete );

    SPI_Status_t SPI_Port_Write( SPI_t SPIx, SPI_Data_t * Data, SPI_DataLength_t DataLength );
    SPI_Status_t SPI_Port_Read( SPI_t SPIx, SPI_Data_t * Data, SPI_DataLength_t DataLength );
    SPI_Status_t SPI_Port_Transaction( SPI_t SPIx, SPI_Data_t * DataTx, SPI_DataLength_t DataTxLength, SPI_Data_t * DataRx, SPI_DataLength_t DataRxLength );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* SPI_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
