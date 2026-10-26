#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../MCAL/UART/UART.h"
#include "../include/MotorDriver/motor.h"
int main()
{
    //UART_Init();
    motor_init();
    uint8_t a=0,b=0;
    //DDRD |= (1 << PD6);
    DDRD |= (1 << PD4);
    DDRD |= (1 << PD5);
    while (1)
    {
        _delay_ms(500);
        motor_setDutycycle(MOTOR_CHANNER_A,a);
        motor_setDutycycle(MOTOR_CHANNER_B,b);
        a+=5;
        b-=5;
 
        _delay_ms(1);
        /***
         * 
         if (UART_DataAvailable())
         {
             uint8_t receivedData = UART_ReceiveByte();
             if (receivedData == 'o')
             {
                 PORTD &= ~(1 << PD6);
             }
             else if (receivedData == 'f')
             {
                 PORTD |= (1 << PD6);
             }
             else if (receivedData == 't')
             {
                 PORTD ^= (1 << PD6);
             }
             UART_TransmitByte(receivedData); // Echo the received data back
         }
         */
    }
    return 0;
}