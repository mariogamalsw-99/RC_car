
#include <avr/io.h>
#include <util/delay.h>
#include "../MCAL/UART/UART.h"
#include "../include/OS/SCH.h"
#include "../include/MotorDriver/motor.h"
void toggleD1()
{
    PORTD ^= 1;
}

int main()
{
    SCH_intit();
    SCH_Add_Task(toggleD1, 1, 100);
    // UART_Init();
     motor_init();
     uint8_t a=0,b=0;
    // DDRD |= (1 << PD6);
    DDRD |= (1 << PD4);
    DDRD |= (1 << PD5);
    DDRD |= (1 << PD1);
    while (1)
    {
        SCH_Dispatch_Tasks();
        // _delay_ms(500);
        motor_setDutycycle(MOTOR_CHANNER_A,a);
        motor_setDutycycle(MOTOR_CHANNER_B,b);
        a+=5;
        b-=5;

        // _delay_ms(1);
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