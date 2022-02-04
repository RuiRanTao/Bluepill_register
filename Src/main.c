/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include"stm32f10x.h"
#include"stm32f10x_gpio.h"
#include "led.h"
#include "delay.h"
#include "usart.h"
#include "sys.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

u8 t;
u8 len;
u16 times=0;
u8 string[10]="received: ";

int main(void)
{
	Stm32_Clock_Init(9); //系统时钟设置
	delay_init(72);	     //延时初始化
	LED_init();
	USART1_Init(72,115200);	 //串口初始化为9600

    /* Loop forever */
	for(;;)
	{
//	 blink_0();
//	 blink_1();
//	 blink_2();
	   if (USART1_STA & 0x8000) {	//表示成功接收到数据
			USART1_SendData(string, 10);
			USART1_SendData(USART1_REC, USART_REC_LEN);
			USART1_STA &= ~0x8000;
		}
//	   delay_ms(1);
	}
}


void SystemInit(){}




