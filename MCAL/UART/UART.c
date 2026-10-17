#include <avr/io.h>
#include <stdint.h>

#ifndef F_CPU
#define F_CPU 4000000UL
#endif

void UART_Init()
{
    //for hc-05 9600 baud rate, 8 data bits, 1 stop bit, no parity
	//enable receiver and transmitter
	UCSRB = (1 << RXEN) | (1 << TXEN);
    //UCSRC   8-bit , 1-stop bit, no parity 
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0)&~(1 << USBS&~(1 << UPM0&~(1 << UPM1)));
    //calculate and set baud rate for Asynchronous mode u2x =0 (default values)
	uint16_t ubrr =(F_CPU / (16UL * 9600UL)) - 1UL;
	UBRRH = (uint8_t)(ubrr >> 8);
	UBRRL = (uint8_t)ubrr;

}

void UART_TransmitByte(uint8_t data)
{
    int timeout = 10000; 
	while ((UCSRA & (1U << TXC)) == 0U&& timeout-->0) {
		/* Wait for the transmit buffer to become empty. */
	}
	UDR = data;
}

uint8_t UART_ReceiveByte(void)
{
    int timeout = 10000;
	while ((UCSRA & (1U << RXC)) == 0U && timeout-->0) {
		/* Wait until data is received. */
	}
	return UDR;
}

uint8_t UART_DataAvailable(void)
{
    
    if(UCSRA & (1U << RXC)) {
        return 1; // Data is available
    } else {
        return 0; // No data available
    }
}
