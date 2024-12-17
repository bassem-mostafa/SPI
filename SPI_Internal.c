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

#include <stddef.h>
#include <stdio.h>

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

LOG_Status_t SPI_LOG_Raw( LOG_Level_t LOG_Level, LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_RawWithArgs( SPI_LOG, LOG_Level, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t SPI_LOG_Trace( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_TraceWithArgs( SPI_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t SPI_LOG_Debug( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_DebugWithArgs( SPI_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t SPI_LOG_Info( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_InfoWithArgs( SPI_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t SPI_LOG_Warning( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_WarningWithArgs( SPI_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t SPI_LOG_Error( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_ErrorWithArgs( SPI_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t SPI_LOG_Fatal( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_FatalWithArgs( SPI_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
