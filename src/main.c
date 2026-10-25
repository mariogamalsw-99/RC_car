#include <avr/io.h>
#define F_CPU 4000000UL
#include <util/delay.h>
#include "../MCAL/UART/UART.h"
#include "../include/MotorDriver/motor.h"
int main()
{
    //UART_Init();
    motor_init();
    uint8_t a=50,b=50;
    //DDRD |= (1 << PD6);
    DDRD |= (1 << PD4);
    DDRD |= (1 << PD5);
    while (1)
    {
        // _delay_ms(500);
        motor_setDutycycle(MOTOR_CHANNER_A,a);
        motor_setDutycycle(MOTOR_CHANNER_B,b);
        a+=5;
        b-=5;
        a%=100;
        b%=100;
        _delay_ms(500);
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