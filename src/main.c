#include <avr/io.h>
#define F_CPU 4000000UL
#include <util/delay.h>
#include "../MCAL/UART/UART.h"

int main()
{
    UART_Init();
    DDRD |= (1 << PD6);
    while (1)
    {
        // _delay_ms(500);

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
    }
    return 0;
}