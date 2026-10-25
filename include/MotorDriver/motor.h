
#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
typedef enum
{
    MOTOR_CHANNER_A,
    MOTOR_CHANNER_B
}motor_eunumChannelSelcetor_t;

void motor_init();
void motor_setDutycycle(motor_eunumChannelSelcetor_t,uint8_t duty);


#endif /* MOTOR_H*/