#ifndef C_BOARD_STUDY_BSP_LED_H
#define C_BOARD_STUDY_BSP_LED_H

#include "main.h"
#include "tim.h"
#include "struct_typedef.h"

extern void aRGB_led_show(uint_t aRGB);
extern void RGB_led_flow(void);
extern void LED_Init(void);

#endif //C_BOARD_STUDY_BSP_LED_H
