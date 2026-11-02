/*
 * TIMER_private.h
 *
 * Created: 11/16/2021 8:48:41 PM
 *  Author: Mario
 */ 


#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_
//timer0 registers
#define TCCR0_reg						( *(volatile uint8_t*) 0x53 )
#define TimerCounter0					( *(volatile uint8_t*) 0x52 )
#define Timer0_OutputCompare			( *(volatile uint8_t*) 0x5c )
//timer2 registers
#define TCCR2_reg						( *(volatile uint8_t*) 0x45 )
#define TimerCounter2					( *(volatile uint8_t*) 0x44 )
#define Timer2_OutputCompare			( *(volatile uint8_t*) 0x43 )




#define TIMSK_reg						( *(volatile uint8_t*) 0x59 )
#define TIFR_reg						( *(volatile uint8_t*) 0x58 )


//interrupt vectors
#define TINT0_OVF0_ISR		__vector_11
#define TINT0_COMP0_ISR		__vector_10

#define TINT2_OVF2_ISR		__vector_5
#define TINT2_COMP2_ISR		__vector_4

//interrupt functions
void (*Timer_overflow_Callback[2]) (void)={0,0};
void (*Timer_CompareMatch_Callback[2]) (void)={0,0};



//interrupt declaration
void TINT0_OVF0_ISR()	__attribute__((signal,used));
void TINT0_COMP0_ISR()	__attribute__((signal,used));

void TINT2_OVF2_ISR	()	__attribute__((signal,used));
void TINT2_COMP2_ISR()	__attribute__((signal,used));



#endif /* TIMER_PRIVATE_H_ */