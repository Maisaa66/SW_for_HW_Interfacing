/*
 * GPIO.c
 *
 *  Created on: Dec 25, 2021
 *      Author: lenovo
 */


#include <GPIO.h>

#define GPIO_REG(PORT_ID, REG_ID) ((unsigned int *)(PORT_ID +REG_ID))

#define GPIOA_MODER     GPIO_REG(0x40020000, 0x00) //0x40020000
#define GPIOA_OTYPER    GPIO_REG(0x40020000, 0x04) //0x40020004
#define GPIOA_PUPDR     GPIO_REG(0x40020000, 0x0c)
#define GPIOA_IDR       GPIO_REG(0x40020000, 0x10)
#define GPIOA_ODR       GPIO_REG(0x40020000, 0x14)
#define GPIOA_OSPEEDR    GPIO_REG(0x40020000, 0x08)
#define GPIOA_BSRR       GPIO_REG(0x40020000, 0x18)
#define GPIOA_LCKR       GPIO_REG(0x40020000, 0x1c)
#define GPIOA_AFRL       GPIO_REG(0x40020000, 0x20)
#define GPIOA_AFRH       GPIO_REG(0x40020000, 0x24)

#define RCC_AHB1ENR	    GPIO_REG(0x40023800,0x30)

#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

unsigned int* look_up[2][10] = {{ GPIO_REG(0x40020000, 0x00), GPIO_REG(0x40020000, 0x04),GPIO_REG(0x40020000, 0x0c),GPIO_REG(0x40020000, 0x10),GPIO_REG(0x40020000, 0x14)
		,GPIO_REG(0x40020000, 0x08),GPIO_REG(0x40020000, 0x18),GPIO_REG(0x40020000, 0x1c),GPIO_REG(0x40020000, 0x20),GPIO_REG(0x40020000, 0x24)},

		{GPIO_REG(0x40020400, 0x00),GPIO_REG(0x40020400, 0x04),GPIO_REG(0x40020400, 0x0c),GPIO_REG(0x40020400, 0x10),GPIO_REG(0x40020400, 0x14)
		,GPIO_REG(0x40020400, 0x08),GPIO_REG(0x40020400, 0x18),GPIO_REG(0x40020400, 0x1c),GPIO_REG(0x40020400, 0x20),GPIO_REG(0x40020400, 0x24)}};



void GPIO_EnableClock(unsigned char PortID) {

      *RCC_AHB1ENR |= (0x01 << PortID);
};


void GPIO_Init(unsigned char PortID, unsigned char PIN_NO , unsigned char PinMode, unsigned char DefaultState){

	*look_up[PortID][0] &= ~(0x03 << 2*PIN_NO);
	*look_up[PortID][0] |= PinMode << 2 * PIN_NO;

	*look_up[PortID][1] &= ~(1 << PIN_NO);
	*look_up[PortID][1] |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PIN_NO;

	*look_up[PortID][2] &= ~(0x03 << 2 * PIN_NO);
	*look_up[PortID][2] |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PIN_NO);

};


unsigned char GPIO_WritePin(unsigned char PortID, unsigned char PIN_NO, unsigned char Data){
	  unsigned char result;

	if(((*look_up[PortID][0] >> (2*PIN_NO))&3) == 1)
				{
				     if(Data)
				     {
				    	 *look_up[PortID][4] |= (1<<PIN_NO);
				     }
				     else
				     {
				    	 *look_up[PortID][4] &= ~(1<<PIN_NO);
				     }
					result = OK;
				}
				else
				{
					result = NOK;
				}
	return result;
};

unsigned char GPIO_ReadPin(unsigned char PortID, unsigned char PIN_NO){

	unsigned char result;
 result = (*look_up[PortID][3]>>PIN_NO)&1;
	return result;

};
