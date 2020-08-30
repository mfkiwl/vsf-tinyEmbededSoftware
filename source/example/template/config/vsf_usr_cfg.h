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


//! \note User Level Application Configuration

#ifndef __VSF_USR_CFG_H__
#define __VSF_USR_CFG_H__

/*============================ INCLUDES ======================================*/
/*============================ MACROS ========================================*/

#if     defined(__M484__)
#   include "./vsf_usr_cfg/vsf_usr_cfg_m484.h"
#elif   defined(__F1C100S__)
#   include "./vsf_usr_cfg/vsf_usr_cfg_f1c100s.h"
#elif   defined(__WIN__)
#   include "./vsf_usr_cfg/vsf_usr_cfg_win.h"
#elif   defined(__LINUX__)
#   include "./vsf_usr_cfg/vsf_usr_cfg_linux.h"
#elif   defined(__GD32E103__)
#   include "./vsf_usr_cfg/vsf_usr_cfg_gd32e103.h"
#elif   defined(__MT071__)
#   include "./vsf_usr_cfg/vsf_usr_cfg_mt071.h"
#elif   defined(__MPS2__)
#   include "./vsf_usr_cfg/vsf_usr_cfg_mps2.h"
#endif

#if APP_CFG_USE_USBH_DEMO == ENABLED
#   define VSF_USE_USB_HOST                             ENABLED
#       define VSF_USBH_CFG_ISO_EN                      ENABLED
#       define VSF_USE_USB_HOST_LIBUSB                  ENABLED
#       define VSF_USE_USB_HOST_HID                     ENABLED
#       define VSF_USE_USB_HOST_DS4                     ENABLED
#       define VSF_USE_USB_HOST_NSPRO                   ENABLED
#       define VSF_USE_USB_HOST_XB360                   ENABLED
#       define VSF_USE_USB_HOST_XB1                     ENABLED
#   if APP_CFG_USE_SCSI_DEMO == ENABLED
#       define VSF_USE_USB_HOST_MSC                     ENABLED
#   endif
#       define VSF_USE_USB_HOST_UAC                     ENABLED
#   if APP_CFG_USE_VSFIP_DEMO == ENABLED || APP_CFG_USE_LWIP_DEMO == ENABLED
#       define VSF_USE_USB_HOST_ECM                     ENABLED
#   endif
#   if APP_CFG_USE_DFU_HOST_DEMO == ENABLED
#       define VSF_USE_USB_HOST_DFU                     ENABLED
#   endif
#endif

#if APP_CFG_USE_BTSTACK_DEMO == ENABLED
#   if APP_CFG_USE_USBH_DEMO == ENABLED
#      define VSF_USE_USB_HOST_BTHCI                    ENABLED
#   endif
#   define VSF_USE_BTSTACK                              ENABLED
#endif

#if APP_CFG_USE_SDL2_DEMO == ENABLED
#   define VSF_USE_SDL2                                 ENABLED
#endif

#if APP_CFG_USE_AWTK_DEMO == ENABLED || APP_CFG_USE_LVGL_DEMO == ENABLED || APP_CFG_USE_XBOOT_XUI_DEMO == ENABLED || APP_CFG_USE_TGUI_DEMO == ENABLED
#   define VSF_USE_UI                                   ENABLED
#endif
#if APP_CFG_USE_AWTK_DEMO == ENABLED
#   define VSF_USE_UI_AWTK                              ENABLED
#endif
#if APP_CFG_USE_LVGL_DEMO == ENABLED
#   define VSF_USE_UI_LVGL                              ENABLED
#endif
#if APP_CFG_USE_XBOOT_XUI_DEMO == ENABLED
#   define VSF_USE_XBOOT                                ENABLED
#endif
#if APP_CFG_USE_VSFVM_DEMO == ENABLED
#   define VSFVM_LEXER_DEBUG_EN                         DISABLED
#   define VSFVM_PARSER_DEBUG_EN                        DISABLED
#   define VSFVM_COMPILER_DEBUG_EN                      DISABLED
#endif

// UI runs in vsf_prio_0, other modules runs above vsf_prio_0
#if VSF_USE_UI == ENABLED
#   ifndef VSF_USBH_CFG_EDA_PRIORITY
#       define VSF_USBH_CFG_EDA_PRIORITY                vsf_prio_1
#   endif
#   ifndef APP_CFG_USBH_HW_PRIO
#       define APP_CFG_USBH_HW_PRIO                     vsf_arch_prio_1
#   endif
#endif

#if APP_CFG_USE_VSFIP_DEMO == ENABLED || APP_CFG_USE_LWIP_DEMO == ENABLED
#   define VSF_USE_TCPIP                                ENABLED
#endif
#if APP_CFG_USE_VSFIP_DEMO == ENABLED
#   define VSF_USE_VSFIP                                ENABLED
#   define VSF_USE_LWIP                                 DISABLED
#elif APP_CFG_USE_LWIP_DEMO == ENABLED
#   define VSF_USE_VSFIP                                DISABLED
#   define VSF_USE_LWIP                                 ENABLED
#endif

#if VSF_USE_LINUX == ENABLED
#   define VSF_USE_POSIX                                ENABLED
#endif

/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/
/*============================ INCLUDES ======================================*/

#if APP_CFG_USE_TGUI_DEMO == ENABLED
#   include "vsf_tgui_cfg.h"
#endif

#endif
/* EOF */
