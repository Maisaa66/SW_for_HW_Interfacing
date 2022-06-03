#include "GPIO.h"
#include "Interrupt.h"

unsigned int data = 0;

void EXTI0_IRQHandler(){
	data = ~data;  //toggle the data
	GPIO_WritePin(0, 1, data); //write the data to the led
	*EXTI_PR |= 0x01 << 0; //clear pending flag by software
}

int main(){

	GPIO_EnableClock(0);   //Enable Port A clock
	GPIO_Init(0, 0, INPUT, PULL_UP);   //configuration for pin 1(Push Button)
	GPIO_Init(0, 1, OUTPUT, PUSH_PULL);  //configuration for pin 1(Led)

	*RCC_APB2ENR |= 0x01 << 14;            //Enable clock for SYSCFG register
	*EXTI_IMR |= 0x01 << 0;               //un-masking for EXTI_IMR
	*EXTI_FTSR |= 0x01 << 0;             //Enable the external interrupt to failing edge
	*NVIC_ISER0 |= 0x01 << 6;           //Enable external interrupt 0
	*SYSCFG_EXTICR1 &= ~(0x0f << 0);   //External interrupt


	while(1){

	}
	return 0;


}
