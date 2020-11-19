#include "bsp_buzzer.h"
#include "main.h"

#define MAX_PSC                 1000

#define MAX_BUZZER_PWM      20000
#define MIN_BUZZER_PWM      10000

extern TIM_HandleTypeDef htim4;
void buzzer_on(uint16_t psc, uint16_t pwm)
{
    __HAL_TIM_PRESCALER(&htim4, psc);
    __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_3, pwm);

}
void buzzer_off(void)
{
    __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_3, 0);
}

void buzzer_kc(void){
    uint16_t psc = 0;
    uint16_t pwm = MIN_BUZZER_PWM;

    pwm++;
    psc++;

    if(pwm > MAX_BUZZER_PWM)
    {
        pwm = MIN_BUZZER_PWM;
    }
    if(psc > MAX_PSC)
    {
        psc = 0;
    }
    buzzer_on(psc, pwm);
    HAL_Delay(1);
}