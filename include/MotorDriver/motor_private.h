
#ifndef MOTOR_PRIVATE_H
#define MOTOR_PRIVATE_H
//TCCR1A
//bits shift 
#define COM1A 6
#define COM1B 4
#define WGM10 0
//val for MOde
#define CLEAR_OCM 0b10
#define FAST_PWM_10BIT_WGM10 0b11
//TCCR1B
//bits shift
#define  CS10 0
#define  WGM12 3
#define  ICES 6
//val
typedef enum
{
    TIMER1_NO_CLK_SRC=0,
    TIMER1_NO_PRESCALER,
    TIMER1_PRESCALER_8,
    TIMER1_PRESCALER_64,
    TIMER1_PRESCALER_256,
    TIMER1_PRESCALER_1024,
    TIMER1_EXTERNAKClk_FALLING_EDGE,
    TIMER1_EXTERNAKClk_RISING_EDGE,
}timer1_enumPrescaler_t;
#define FAST_PWM_10BIT_WGM12 0b10




#endif /* MOTOR_PRIVATE_H*/