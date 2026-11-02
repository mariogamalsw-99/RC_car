/*
 * TIMER_interface.h
 *
 * Created: 11/16/2021 8:48:20 PM
 *  Author: mario
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_
#include <stdint.h>

typedef enum timer_n{timer_0,timer_2} timer_n;
typedef enum timer_mode{timer_NormalMode,timer_PWMphaseCorrectMode,timer_CTCmode,timer_FastPWMmode}timer_mode;
typedef enum timer_nonPWM_COmode{timer_OCdisconnected,timer_OCtoggle,timer_OCclear,timer_OCset}timer_nonPWM_COmode;
typedef enum timer_PWM_COmode{timer_OCdisconnect,timer_OCnon_invert=2,timer_OCinvert}timer_PWM_COmode;
typedef enum timer0_ClockSource{timer0_NoClock,
								timer0_NoPrescale,
								timer0_8Prescale,
								timer0_64Prescale,
								timer0_256Prescale,
								timer0_1024Prescale,
								timer0_ExFallingEdge,
								timer0_ExRisingEdge}timer0_ClockSource;

typedef enum timer2_ClockSource{timer2_NoClock,
								timer2_NoPrescale,
								timer2_8Prescale,
								timer2_32Prescale,
								timer2_64Prescale,
								timer2_128Prescale,
								timer2_256Prescale,
								timer2_1024Prescale}timer2_ClockSource;



typedef enum {timer_InterruptOVF,timer_InterrupCOMP}timer_INT_type;

typedef enum{timer_noInterrupt,timer_OverflowOnly,timer_CompareMatchOnly,timer_OverflowAndCompareMatch}timer_TINT;
typedef struct Timer_t 
	{
		timer_n n;
		timer_mode mode;
		timer_nonPWM_COmode nonPWM_COmode;
		timer_PWM_COmode PWM_COmode;
		union{
					timer0_ClockSource ClockSource_t0;
					timer2_ClockSource ClockSource_t2;
						
			};
		
		timer_TINT interrptEnable;
	
	}Timer_t;
	
void MTimer_voidTimerInit(Timer_t* T);
uint8_t MTimer_u8GetCounter(Timer_t* T);
void MTimer_voidSetCounter(Timer_t* T ,uint8_t Counter_value);
void MTimer_voidSetOutputCompare(Timer_t* T ,uint8_t Compare_value);

void MTimer_voidSetInterrupt(Timer_t* T);
void MTimer_voidSetCallback(Timer_t* T,void (*callback)(void),timer_INT_type INT_type);

void MTimer_voidSetDutyCycle(Timer_t* T ,uint8_t duty_cycle);






#endif /* TIMER_INTERFACE_H_ */