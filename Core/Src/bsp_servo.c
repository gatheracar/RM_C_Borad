#include "main.h"
#include "bsp_servo.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;

void servo_sweep(){
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 500);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, 500);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3, 500);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, 500);
    __HAL_TIM_SetCompare(&htim8, TIM_CHANNEL_1, 500);
    __HAL_TIM_SetCompare(&htim8, TIM_CHANNEL_2, 500);
    __HAL_TIM_SetCompare(&htim8, TIM_CHANNEL_3, 500);
    HAL_Delay(1000);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 2000);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, 2000);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3, 2000);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, 2000);
    __HAL_TIM_SetCompare(&htim8, TIM_CHANNEL_1, 2000);
    __HAL_TIM_SetCompare(&htim8, TIM_CHANNEL_2, 2000);
    __HAL_TIM_SetCompare(&htim8, TIM_CHANNEL_3, 2000);
    HAL_Delay(1000);
}
