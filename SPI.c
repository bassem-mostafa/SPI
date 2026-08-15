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

typedef struct SPI_Context
{
    SPI_Instance_t Instance[ SPI_Count ];
} SPI_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static SPI_Status_t SPI_Context_Initialize( void );
static SPI_Status_t SPI_Context_Cycle( void );
static SPI_Status_t SPI_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static SPI_Context_t SPI_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static SPI_Status_t SPI_Context_Initialize( void )
{
    SPI_Status_t Status = SPI_Status_Success;

    do
    {
        SPI_Trace( "%s( void )", __FUNCTION__ );

        for ( SPI_t SPI_x = SPI_Null; SPI_x < SPI_Count; ++SPI_x )
        {
            SPI_Context.Instance[ SPI_x ].SPIx = SPI_x;
        }
    }
    while ( 0 );

    return Status;
}

static SPI_Status_t SPI_Context_Cycle( void )
{
    SPI_Status_t Status = SPI_Status_Success;

    do
    {
        SPI_Trace( "%s( void )", __FUNCTION__ );
    }
    while ( 0 );

    return Status;
}

static SPI_Status_t SPI_Context_DeInitialize( void )
{
    SPI_Status_t Status = SPI_Status_Success;

    do
    {
        SPI_Trace( "%s( void )", __FUNCTION__ );
    }
    while ( 0 );

    return Status;
}

SPI_Status_t SPI_GetInstance( SPI_t SPIx, SPI_Instance_t ** Instance )
{
    SPI_Status_t Status = SPI_Status_Success;

    do
    {
        SPI_Trace( "%s( SPIx=%d, Instance=%p )", __FUNCTION__, SPIx, Instance );

        if ( Instance == NULL )
        {
            Status = SPI_Status_ArgumentInvalid;
            break;
        }

        *Instance = &SPI_Context.Instance[ SPIx ];
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

SPI_Status_t SPI_Initialize( SPI_t SPIx )
{
    SPI_Status_t Status = SPI_Status_Success;

    do
    {
        SPI_Trace( "%s( SPIx=%d )", __FUNCTION__, SPIx );

        if ( ( Status = SPI_IsValid( SPIx ) ) != SPI_Status_Success )
        {
            break;
        }

        if ( ( Status = SPI_Context_Initialize( ) ) != SPI_Status_Success )
        {
            break;
        }

        for ( SPI_t SPI_x = SPI_Null; SPI_x < SPI_Count; ++SPI_x )
        {
            if ( SPIx != SPI_All && SPIx != SPI_x )
            {
                continue;
            }

            SPI_Status_t SPI_Status = SPI_Status_Success;
            if ( ( SPI_Status = SPI_Instance_Initialize( &SPI_Context.Instance[ SPI_x ] ) ) != SPI_Status_Success )
            {
                Status = SPI_Status;
            }
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

        if ( ( Status = SPI_IsValid( SPIx ) ) != SPI_Status_Success )
        {
            break;
        }

        if ( ( Status = SPI_Context_Cycle( ) ) != SPI_Status_Success )
        {
            break;
        }

        for ( SPI_t SPI_x = SPI_Null; SPI_x < SPI_Count; ++SPI_x )
        {
            if ( SPIx != SPI_All && SPIx != SPI_x )
            {
                continue;
            }

            SPI_Status_t SPI_Status = SPI_Status_Success;
            if ( ( SPI_Status = SPI_Instance_Cycle( &SPI_Context.Instance[ SPI_x ] ) ) != SPI_Status_Success )
            {
                Status = SPI_Status;
            }
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

        if ( ( Status = SPI_IsValid( SPIx ) ) != SPI_Status_Success )
        {
            break;
        }

        for ( SPI_t SPI_x = SPI_Null; SPI_x < SPI_Count; ++SPI_x )
        {
            if ( SPIx != SPI_All && SPIx != SPI_x )
            {
                continue;
            }

            SPI_Status_t SPI_Status = SPI_Status_Success;
            if ( ( SPI_Status = SPI_Instance_DeInitialize( &SPI_Context.Instance[ SPI_x ] ) ) != SPI_Status_Success )
            {
                Status = SPI_Status;
            }
        }

        Status = SPI_Context_DeInitialize( );
    }
    while ( 0 );

    return Status;
}

SPI_Status_t SPI_SetCallbackOnComplete( SPI_t SPIx, SPI_CallbackOnComplete_t Callback )
{
    SPI_Status_t Status = SPI_Status_Success;

    do
    {
        SPI_Trace( "%s( SPIx=%d, Callback=%p )", __FUNCTION__, SPIx, Callback );

        if ( ( Status = SPI_IsValid( SPIx ) ) != SPI_Status_Success )
        {
            break;
        }

        for ( SPI_t SPI_x = SPI_Null; SPI_x < SPI_Count; ++SPI_x )
        {
            if ( SPIx != SPI_All && SPIx != SPI_x )
            {
                continue;
            }

            SPI_Status_t SPI_Status = SPI_Status_Success;
            if ( ( SPI_Status = SPI_Instance_SetCallbackOnComplete( &SPI_Context.Instance[ SPIx ], Callback ) ) != SPI_Status_Success )
            {
                Status = SPI_Status;
            }
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

        if ( ( Status = SPI_IsValid( SPIx ) ) != SPI_Status_Success )
        {
            break;
        }

        SPI_Instance_t * SPI_Instance = &SPI_Context.Instance[ SPIx ];

        Status = SPI_Instance_Write( SPI_Instance, Data, DataLength );
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

        if ( ( Status = SPI_IsValid( SPIx ) ) != SPI_Status_Success )
        {
            break;
        }

        SPI_Instance_t * SPI_Instance = &SPI_Context.Instance[ SPIx ];

        Status = SPI_Instance_Read( SPI_Instance, Data, DataLength );
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

        if ( ( Status = SPI_IsValid( SPIx ) ) != SPI_Status_Success )
        {
            break;
        }

        SPI_Instance_t * SPI_Instance = &SPI_Context.Instance[ SPIx ];

        Status = SPI_Instance_Transaction( SPI_Instance, DataTx, DataTxLength, DataRx, DataRxLength );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char SPI_VERSION[] = "0.0.0.v20260815-2008";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
