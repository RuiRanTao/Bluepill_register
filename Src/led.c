#include "led.h"
#include"stm32f10x.h"
#include"stm32f10x_gpio.h"
#include "delay.h"

void LED_init()
{
	RCC->APB2ENR |=(1<<2);				//使能PORTA时钟
	GPIOA->CRL &= ~(0x0F<<(4*1));
	GPIOA->CRL |= (3<<(4*1));
	GPIOA->BSRR |= (1<<1);				//将第1位(bit)设置为1，设置为高电平，GPIO_SetBits
	GPIOA->BRR |= (1<<1);				//将第1位(bit)设置为0，设置为低电平，GPIO_ResetBits
}

void blink_0()
{
	GPIOA->ODR &= 0xffffffff-(1<<1);  	//将第1位(bit)清空
	GPIOA->ODR &= ~(1<<1);         		//将第1位(bit)设置为0，设置为低电平
	delay_ms(1000);
	GPIOA->ODR &= 0xffffffff-(1<<1);	//将第1位(bit)清空
	GPIOA->ODR |= (1<<1);				//将第1位(bit)设置为1，设置为高电平
	delay_ms(1000);	
}

void blink_1()
{
	GPIOA->ODR &= 0xffffffff-(1<<1); 		//将第1位(bit)清空
	GPIOA->BRR &= (1<<1);					//将第1位(bit)设置为0，设置为低电平
	GPIOA->BSRR |= (1<<(1+16));				//将第1位(bit)设置为0，设置为低电平
	delay_ms(1000);
	GPIOA->ODR &= 0xffffffff-(1<<1);		//将第1位(bit)清空
	GPIOA->BSRR |= (1<<1);					//将第1位(bit)设置为1，设置为高电平
	delay_ms(1000);
}

void blink_2()
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);		//GPIOA1置低电平
	delay_ms(1000);
	GPIO_SetBits(GPIOA,GPIO_Pin_1);			//GPIOA1置高电平
	delay_ms(1000);
}

