/*
 * GINT.h
 *
 * Created: 11/5/2021 5:26:15 AM
 *  Author: mario
 */ 


#ifndef GINT_H_
#define GINT_H_

#define AVR_Status_reg    ( *(volatile uint8_t*) 0x5f )

#define Enable_Global_Interrupt			SET_BIT(AVR_Status_reg,7)
#define Disable_Global_Interrupt			CLEAR_BIT(AVR_Status_reg,7)




#endif /* GINT_H_ */