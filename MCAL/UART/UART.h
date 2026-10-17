
#ifndef UART_H
#define UART_H

#include <stdint.h>

/* UART interface */
void UART_Init(void);
void UART_TransmitByte(uint8_t data);
uint8_t UART_ReceiveByte(void);
uint8_t UART_DataAvailable(void);

#endif /* UART_H */
