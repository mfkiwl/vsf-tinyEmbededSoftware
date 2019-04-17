/*****************************************************************************
 *   Copyright(C)2009-2019 by VSF Team                                       *
 *                                                                           *
 *  Licensed under the Apache License, Version 2.0 (the "License");          *
 *  you may not use this file except in compliance with the License.         *
 *  You may obtain a copy of the License at                                  *
 *                                                                           *
 *     http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                           *
 *  Unless required by applicable law or agreed to in writing, software      *
 *  distributed under the License is distributed on an "AS IS" BASIS,        *
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 *  See the License for the specific language governing permissions and      *
 *  limitations under the License.                                           *
 *                                                                           *
 ****************************************************************************/

#ifndef __HAL_DRIVER_NUVOTON_M484_USB_H__
#define __HAL_DRIVER_NUVOTON_M484_USB_H__

/*============================ INCLUDES ======================================*/
#include "hal/vsf_hal_cfg.h"
#include "../../device.h"
#include "./ohci/ohci.h"

/*============================ MACROS ========================================*/

#define __USB_HC_DEF(__N, __TYPE)                                               \
    extern const m480_##__TYPE##_t USB_HC##__N;
#define _USB_HC_DEF(__N, __TYPE)            __USB_HC_DEF(__N, __TYPE)
#define USB_HC_DEF(__N, __VALUE)            _USB_HC_DEF(__N, USB_HC##__N##_TYPE)

/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/

MREPEAT(USB_HC_COUNT, USB_HC_DEF, NULL)

/*============================ INCLUDES ======================================*/
/*============================ PROTOTYPES ====================================*/


#endif
/* EOF */