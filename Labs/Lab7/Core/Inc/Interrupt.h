/*
 * Interrupt.h
 *
 *  Created on: Dec 25, 2021
 *      Author: lenovo
 */


#ifndef INC_INTERRUPT_H_
#define INC_INTERRUPT_H_

#include "stm32f401cc_interface.h"


#define INTERRUPT_REG(PORT_ID, REG_ID) ((unsigned int *)(PORT_ID + REG_ID))

// Interrupts
#define RCC_APB2ENR            INTERRUPT_REG(0x40023800, 0x44)
#define SYSCFG_EXTICR1         INTERRUPT_REG(0x40013800, 0x08)
#define EXTI_IMR               INTERRUPT_REG(0x40013C00, 0x00)
#define EXTI_RTSR              INTERRUPT_REG(0x40013C00, 0x08)
#define EXTI_FTSR              INTERRUPT_REG(0x40013C00, 0x0C)
#define EXTI_PR                INTERRUPT_REG(0x40013C00, 0x14)
#define NVIC_ISER0             INTERRUPT_REG(0xE000E100, 0x00)


#endif /* INC_INTERRUPT_H_ */
