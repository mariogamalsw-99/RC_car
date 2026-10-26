#include "../include/MotorDriver/motor.h"
#include "../include/MotorDriver/motor_private.h"
#include <avr/io.h>

#define TOP_PWM_10BIT    0x03ffUL
static void SetChannelA(uint16_t val);
static void SetChannelB(uint16_t val);
void motor_init()
{
    ///set val fo TCCR1A to set clear on compare match and fastpwm 10bit
    uint16_t reg_val=0;
    reg_val|=(CLEAR_OCM<<COM1A)|(CLEAR_OCM<<COM1B)|(FAST_PWM_10BIT_WGM10<<WGM10);
    TCCR1A|=reg_val;
    //set val for TCCR1B to complete fast pwm 10-bit mode config and set timer1 clk source
    reg_val=0;
    reg_val|=(FAST_PWM_10BIT_WGM12<<WGM12)|(TIMER1_NO_PRESCALER<<CS10);
    TCCR1B|=reg_val;
    //intit pwm 50%
    motor_setDutycycle(MOTOR_CHANNER_A,255);
    motor_setDutycycle(MOTOR_CHANNER_B,125);

}
void motor_setDutycycle(motor_eunumChannelSelcetor_t channel,uint8_t duty)
{
    // if(duty<100 && duty>0)
    // {
        uint16_t reg_val=TOP_PWM_10BIT*(duty/(float)255);
        switch (channel)
        {
        case MOTOR_CHANNER_A:
            SetChannelA(reg_val);
            break;
        case MOTOR_CHANNER_B:
            SetChannelB(reg_val);
            break;
        
        default:
            break;
        }
    // }
}

//private function
static void SetChannelA(uint16_t val)
{
    uint8_t H_val=(val>>8);
    uint8_t L_val=((val<<8)>>8);
    //write high then low
    OCR1AH=H_val;
    OCR1AL=L_val;
}
static void SetChannelB(uint16_t val)
{
    uint8_t H_val=(val>>8);
    uint8_t L_val=((val<<8)>>8);
    //write high then low
    OCR1BH=H_val;
    OCR1BL=L_val;
}