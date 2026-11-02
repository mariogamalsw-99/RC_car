/*
 * MACROS.h
 *
 * Created: 7/15/2021 2:10:01 AM
 *  Author: mario
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,n)			reg|=(1<<n)
#define SET_2BITS(reg,n1,n2)	reg|= (1<<n1) | (1<<n2)
#define CLEAR_BIT(reg,n)		reg&=(~(1<<n))
#define TOOGLE_BIT(reg,n)		reg^=(1<<n)
#define GET_BIT(reg,n)			((reg>>n)&1)


#define SET_REG(REG)			(REG = 255)
#define CLEAR_REG(REG)			(REG = 0)
#define TOOGLE_REG(REG)			(REG ^= 255)


#define SET_DWORD(DWORD)		(DWORD = 0xffff)
#define CLEAR_DWORD(DWORD)		(DWORD = 0x0000)
#define	TOOGLE_DWORD(DWORD)		(DWORD ^= 0xffff)




#endif /*BIT_MATH_H_ */