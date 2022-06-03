/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f401xc.h"

//write result
#define OK ((unsigned char)0)
#define NOK ((unsigned char)1)

// Mode Types
#define INPUT ((unsigned char)0x00)
#define OUTPUT ((unsigned char)0x01)
#define ALTERNATE_FUN ((unsigned char)0x02)
#define ANALOG ((unsigned char)0x03)

// Output modes
#define PUSH_PULL ((unsigned char)0x00)
#define OPEN_DRAIN ((unsigned char)0x01)

// Resistor modes
#define NO_PULL_UP_DOWN ((unsigned char)0x00)
#define PULL_UP ((unsigned char)0x02)
#define PULL_DOWN ((unsigned char)0x04)



void GPIO_EnableClock(unsigned char PortID);
void GPIO_Init(unsigned char PortID, unsigned char PIN_NO , unsigned char PinMode, unsigned char DefaultState);
unsigned char GPIO_WritePin(unsigned char PortID, unsigned char PIN_NO, unsigned char Data);
unsigned char GPIO_ReadPin(unsigned char PortID, unsigned char PIN_NO);




#endif /* GPIO_H */
