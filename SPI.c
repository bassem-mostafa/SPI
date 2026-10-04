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

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "SPI.h"
#include "SPI_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

SPI_Status_t SPI_Initialize( SPI_t SPIx )
{
    SPI_Status_t Status = SPI_Status_Success;

    do
    {
        SPI_Trace( "%s( SPIx=%d )", __FUNCTION__, SPIx );

        if ( ( Status = SPI_Port_Initialize( SPIx ) ) != SPI_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

SPI_Status_t SPI_Cycle( SPI_t SPIx )
{
    SPI_Status_t Status = SPI_Status_Success;

    do
    {
        SPI_Trace( "%s( SPIx=%d )", __FUNCTION__, SPIx );

        if ( ( Status = SPI_Port_Cycle( SPIx ) ) != SPI_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

SPI_Status_t SPI_DeInitialize( SPI_t SPIx )
{
    SPI_Status_t Status = SPI_Status_Success;

    do
    {
        SPI_Trace( "%s( SPIx=%d )", __FUNCTION__, SPIx );

        if ( ( Status = SPI_Port_DeInitialize( SPIx ) ) != SPI_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

SPI_Status_t SPI_SetOnComplete( SPI_t SPIx, SPI_OnComplete_t OnComplete )
{
    SPI_Status_t Status = SPI_Status_Success;

    do
    {
        SPI_Trace( "%s( SPIx=%d, OnComplete={Callback=%p, Context=%p} )", __FUNCTION__, SPIx, OnComplete.Callback, OnComplete.Context );

        if ( ( Status = SPI_Port_SetOnComplete( SPIx, &OnComplete ) ) != SPI_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

SPI_Status_t SPI_Write( SPI_t SPIx, SPI_Data_t * Data, SPI_DataLength_t DataLength )
{
    SPI_Status_t Status = SPI_Status_Success;

    do
    {
        SPI_Trace( "%s( SPI=%d, Data=%p, Length=%d )", __FUNCTION__, SPIx, Data, DataLength );

        if ( ( Status = SPI_Port_Write( SPIx, Data, DataLength ) ) != SPI_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

SPI_Status_t SPI_Read( SPI_t SPIx, SPI_Data_t * Data, SPI_DataLength_t DataLength )
{
    SPI_Status_t Status = SPI_Status_Success;

    do
    {
        SPI_Trace( "%s( SPI=%d, Data=%p, Length=%d )", __FUNCTION__, SPIx, Data, DataLength );

        if ( ( Status = SPI_Port_Read( SPIx, Data, DataLength ) ) != SPI_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

SPI_Status_t SPI_Transaction( SPI_t SPIx, SPI_Data_t * DataTx, SPI_DataLength_t DataTxLength, SPI_Data_t * DataRx, SPI_DataLength_t DataRxLength )
{
    SPI_Status_t Status = SPI_Status_Success;

    do
    {
        SPI_Trace( "%s( SPI=%d, TX={Data=%p, Length=%d} RX={Data=%p, Length=%d} )", __FUNCTION__, SPIx, DataTx, DataTxLength, DataRx, DataRxLength );

        if ( ( Status = SPI_Port_Transaction( SPIx, DataTx, DataTxLength, DataRx, DataRxLength ) ) != SPI_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char SPI_VERSION[] = "0.0.0.v20261004-1542";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
