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

#ifndef __VSF_GPIO_74HC165_H__
#define __VSF_GPIO_74HC165_H__

/*============================ INCLUDES ======================================*/

#include "hal/vsf_hal_cfg.h"

#if VSF_HAL_GPIO_USE_74HC165 == ENABLED

#if defined(__VSF_HAL_GPIO_74HC164_CLASS_IMPLEMENT)
#   define __PLOOC_CLASS_IMPLEMENT__
#endif

#include "utilities/ooc_class.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================ MACROS ========================================*/
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/

typedef struct vsf_gpio_74hc165_op_t {
    void (*ce_control)(void *param, uint_fast8_t bit);
    void (*pl_control)(void *param, uint_fast8_t bit);
    void (*cp_control)(void *param, uint_fast8_t bit);
    uint_fast8_t (*data_input)(void *param);
} vsf_gpio_74hc165_op_t;

vsf_class(vsf_gpio_74hc165_t) {
    public_member(
        vsf_gpio_74hc165_op_t *op;
        void *param;
        uint8_t cascade_num;
    )

    private_member(
        uint32_t data;
    )
};

/*============================ GLOBAL VARIABLES ==============================*/
/*============================ INCLUDES ======================================*/
/*============================ PROTOTYPES ====================================*/

extern void vsf_gpio_74hc165_config_pin(vsf_gpio_74hc165_t *gpio_ptr, uint32_t pin_mask, uint_fast32_t feature);
extern void vsf_gpio_74hc165_set_direction(vsf_gpio_74hc165_t *gpio_ptr, uint32_t direction_mask, uint32_t pin_mask);
extern uint32_t vsf_gpio_74hc165_get_direction(vsf_gpio_74hc165_t *gpio_ptr, uint32_t pin_mask);
extern void vsf_gpio_74hc165_set_input(vsf_gpio_74hc165_t *gpio_ptr, uint32_t pin_mask);
extern void vsf_gpio_74hc165_set_output(vsf_gpio_74hc165_t *gpio_ptr, uint32_t pin_mask);
extern void vsf_gpio_74hc165_switch_direction(vsf_gpio_74hc165_t *gpio_ptr, uint32_t pin_mask);
extern uint32_t vsf_gpio_74hc165_read(vsf_gpio_74hc165_t *gpio_ptr);
extern void vsf_gpio_74hc165_write(vsf_gpio_74hc165_t *gpio_ptr, uint32_t value, uint32_t pin_mask);
extern void vsf_gpio_74hc165_set(vsf_gpio_74hc165_t *gpio_ptr, uint32_t pin_mask);
extern void vsf_gpio_74hc165_clear(vsf_gpio_74hc165_t *gpio_ptr, uint32_t pin_mask);
extern void vsf_gpio_74hc165_toggle(vsf_gpio_74hc165_t *gpio_ptr, uint32_t pin_mask);

#ifdef __cplusplus
}
#endif

#endif
#endif
