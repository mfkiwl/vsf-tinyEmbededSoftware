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

#ifndef __USRAPP_USBH_COMMON_H__
#define __USRAPP_USBH_COMMON_H__

/*============================ INCLUDES ======================================*/

#include "vsf.h"

#if VSF_USE_USB_HOST == ENABLED

#if VSF_USE_USB_HOST_HCD_LIBUSB == ENABLED
#   include "component/usb/driver/hcd/libusb_hcd/vsf_libusb_hcd.h"
#elif VSF_USE_USB_HOST_HCD_WINUSB == ENABLED
#   include "component/usb/driver/hcd/winusb_hcd/vsf_winusb_hcd.h"
#endif

/*============================ MACROS ========================================*/

#ifndef APP_CFG_USBH_HW_PRIO
#   define APP_CFG_USBH_HW_PRIO                 vsf_arch_prio_0
#endif

/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/

struct usrapp_usbh_common_const_t {
#if VSF_USE_USB_HOST_HCD_OHCI == ENABLED
    vk_ohci_param_t ohci_param;
#elif VSF_USE_USB_HOST_HCD_LIBUSB == ENABLED
    vk_libusb_hcd_param_t libusb_hcd_param;
#elif VSF_USE_USB_HOST_HCD_WINUSB == ENABLED
    vk_winusb_hcd_param_t winusb_hcd_param;
#else
    // on chip non-ip hcd driver
    vsf_usb_hcd_param_t hcd_param;
#endif
};
typedef struct usrapp_usbh_common_const_t usrapp_usbh_common_const_t;

struct usrapp_usbh_common_t {
    vk_usbh_t host;
#if VSF_USE_USB_HOST_HUB == ENABLED
    vk_usbh_class_t hub;
#endif
#if VSF_USE_USB_HOST_LIBUSB == ENABLED
    vk_usbh_class_t libusb;
#endif
#if VSF_USE_TCPIP == ENABLED && VSF_USE_USB_HOST_ECM == ENABLED
    vk_usbh_class_t ecm;
#endif
#if VSF_USE_USB_HOST_MSC == ENABLED
    vk_usbh_class_t msc;
#endif
#if VSF_USE_USB_HOST_BTHCI == ENABLED
    vk_usbh_class_t bthci;
#endif
#if VSF_USE_USB_HOST_HID == ENABLED
    vk_usbh_class_t hid;
#endif
#if VSF_USE_USB_HOST_DS4 == ENABLED
    vk_usbh_class_t ds4;
#endif
#if VSF_USE_USB_HOST_NSPRO == ENABLED
    vk_usbh_class_t nspro;
#endif
#if VSF_USE_USB_HOST_XB360 == ENABLED
    vk_usbh_class_t xb360;
#endif
#if VSF_USE_USB_HOST_XB1 == ENABLED
    vk_usbh_class_t xb1;
#endif
#if VSF_USE_USB_HOST_UAC == ENABLED
    vk_usbh_class_t uac;
#endif
};
typedef struct usrapp_usbh_common_t usrapp_usbh_common_t;

/*============================ GLOBAL VARIABLES ==============================*/

#if     VSF_USE_USB_HOST_HCD_OHCI == ENABLED                                    \
    ||  VSF_USE_USB_HOST_HCD_LIBUSB == ENABLED                                  \
    ||  VSF_USE_USB_HOST_HCD_WINUSB == ENABLED
extern const usrapp_usbh_common_const_t usrapp_usbh_common_const;
#endif
extern usrapp_usbh_common_t usrapp_usbh_common;

/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/

extern vsf_err_t usrapp_usbh_common_init(void);

#endif      // VSF_USE_USB_HOST
#endif      // __USRAPP_USBH_COMMON_H__
/* EOF */