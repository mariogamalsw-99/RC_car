/*
 * TIMER_program.c
 *
 * Created: 11/16/2021 8:48:59 PM
 *  Author: mario
 */ 


#include "../LIB/BIT_MATH.h"

#include "../lib/GINT.h"

#include "../MCAL/Timer/TIMER_interface.h"
#include "../MCAL/Timer/TIMER_private.h"
#include <stdint.h>

void MTimer_voidSetOutputCompare(Timer_t* T ,uint8_t Compare_value)
{
	switch (T->n)
	{
		case timer_0:
			Timer0_OutputCompare = Compare_value;
			break;
		case timer_2:
			Timer2_OutputCompare = Compare_value;
	
		
	}
};

uint8_t MTimer_u8GetCounter(Timer_t* T)
{
	switch (T->n)
	{
		case timer_0:
			return TimerCounter0;
			break;
		case timer_2:
			return TimerCounter2;
			break;
		default:
			return 0;
	}	
}

void MTimer_voidSetCounter(Timer_t* T ,uint8_t Counter_value)
{
	switch (T->n)
	{
		case timer_0:
			TimerCounter0=Counter_value;
			break;
		case timer_2:
			TimerCounter2=Counter_value;
	}
	
}

void MTimer_voidTimerInit(Timer_t* T)
{
	uint8_t moode=T->mode;
	switch(T->n)
	{
		case timer_0:
				//nonPWM
				if (moode==timer_NormalMode || moode==timer_CTCmode)
				{
					TCCR0_reg|= ( (T->nonPWM_COmode)<<4 );
					CLEAR_BIT(TCCR0_reg,6);
					if (moode == timer_NormalMode)
					CLEAR_BIT(TCCR0_reg,3);
					else
					SET_BIT(TCCR0_reg,3);
				}
				else//PWM
				{
					TCCR0_reg|= ( (T->PWM_COmode )<<4 );
					SET_BIT(TCCR0_reg,6);
					if(moode== timer_PWMphaseCorrectMode)
					CLEAR_BIT(TCCR0_reg,3);
					else
					SET_BIT(TCCR0_reg,3);
				}
				TCCR0_reg|= (T->ClockSource_t0);
				///////////////////
				//enable interrupt
				MTimer_voidSetInterrupt(T);
				break;
		case timer_2:
				//nonPWM
				if (moode==timer_NormalMode || moode==timer_CTCmode)
				{
					TCCR2_reg|= ( (T->nonPWM_COmode)<<4 );
					CLEAR_BIT(TCCR2_reg,6);
					if (moode == timer_NormalMode)
					CLEAR_BIT(TCCR2_reg,3);
					else
					SET_BIT(TCCR2_reg,3);
				}
				else//PWM
				{
					TCCR2_reg|= ( (T->PWM_COmode )<<4 );
					SET_BIT(TCCR2_reg,6);
					if(moode== timer_PWMphaseCorrectMode)
					CLEAR_BIT(TCCR2_reg,3);
					else
					SET_BIT(TCCR2_reg,3);
				}
				TCCR2_reg|= (T->ClockSource_t2);
				///////////////////
				//enable interrupt
				MTimer_voidSetInterrupt(T);
				break;
				
	}
}



void MTimer_voidSetInterrupt(Timer_t* T)
{
	switch(T->n)
	{
		case timer_0:
			TIMSK_reg|=(T->interrptEnable);
			break;
		case timer_2:
			TIMSK_reg|=( (T->interrptEnable)<<6 ) ;
			break;
	}
	if( (T->interrptEnable) )
		Enable_Global_Interrupt;
}


void MTimer_voidSetCallback(Timer_t* T,void (*callback)(void),timer_INT_type INT_type)
{

		if(INT_type == timer_InterruptOVF)
			Timer_overflow_Callback[T->n]=callback;
		if(INT_type== timer_InterrupCOMP)
			Timer_CompareMatch_Callback[T->n]=callback;
}

void MTimer_voidSetDutyCycle(Timer_t* T ,uint8_t duty_cycle)
{
	int x = (duty_cycle*255)/100;
	if(T->PWM_COmode == timer_OCnon_invert)
		MTimer_voidSetOutputCompare(T,x);
	else
	{
		x=255-x;
		MTimer_voidSetOutputCompare(T,x);
	}
}




/*
void MTimer_voidStop(Timer_t* T);
void MTimer_voidStart(Timer_t* T);
void MTimer_voidSetDutyCycle(Timer_t* T,uint8_t duty);
void MTimer_voidEnabelInterrupt(Timer_t* T);
void MTimer_voidDisableInterrupt(Timer_t* T);
void MTimer_voidSetCallBack(Timer_t* T, void(*CallBack)(void) );
*/


void TINT0_OVF0_ISR()
{
	if(Timer_overflow_Callback[0] != 0 )
		Timer_overflow_Callback[0]();
}

void TINT0_COMP0_ISR()
{
	if(Timer_CompareMatch_Callback[0] !=0)
		Timer_CompareMatch_Callback[0]();
}

void TINT2_OVF2_ISR()
{
	if(Timer_overflow_Callback[1] != 0 )
	Timer_overflow_Callback[1]();
}

void TINT2_COMP2_ISR()
{
	if(Timer_CompareMatch_Callback[1] !=0)
	Timer_CompareMatch_Callback[1]();
}
