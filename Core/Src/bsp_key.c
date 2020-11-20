#include "bsp_key.h"
#include "main.h"

uint8_t exit_flag = 0;
uint8_t rising_falling_flag;

void key_light(){
    if(exit_flag == 1)
    {
        exit_flag = 2;
        if(rising_falling_flag == GPIO_PIN_RESET)
        {
            //debouce
            //消抖
            HAL_Delay(20);
            if(HAL_GPIO_ReadPin(KEY_GPIO_Port, KEY_Pin) == GPIO_PIN_RESET)
            {
                HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
                exit_flag = 0;
            }
            else
            {
                exit_flag = 0;
            }
        }
        else if(rising_falling_flag == GPIO_PIN_SET)
        {
            //debouce
            //消抖
            HAL_Delay(20);
            if(HAL_GPIO_ReadPin(KEY_GPIO_Port, KEY_Pin) == GPIO_PIN_SET)
            {
                HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
                exit_flag = 0;
            }
            else
            {
                exit_flag = 0;
            }
        }

    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == KEY_Pin)
    {
        if(exit_flag == 0)
        {
            exit_flag = 1;
            rising_falling_flag = HAL_GPIO_ReadPin(KEY_GPIO_Port, KEY_Pin);
        }
    }
}