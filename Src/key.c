/*
 * key.c
 *
 *  Created on: Apr 27, 2022
 *      Author: uv
 */
#include"stm32f10x.h"
#include"stm32f10x_gpio.h"
#include"key.h"
#include "delay.h"

//按键初始化函数
//PA0.15和PC5 设置成输入
void KEY_Init(void)
{
	RCC->APB2ENR|=1<<2;     //使能PORTA时钟
	GPIOA->CRH&=0XFFFFFFF0;	//PA8设置成输入
	GPIOA->CRH|=0X00000008;
	GPIOA->ODR|=1<<8;	   	//PA8上拉,
}
//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//返回值：
//0，没有任何按键按下
//KEY0_PRES，KEY0按下
//KEY1_PRES，KEY1按下
//WKUP_PRES，WK_UP按下
//注意此函数有响应优先级,KEY0>KEY1>WK_UP!!
u8 KEY_Scan(u8 mode)
{
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按
	if(key_up&&(KEY1==0))
	{
		delay_ms(10);//去抖动
		key_up=0;
		if(KEY1==0)return KEY1_PRES;
	}else if(KEY1==1)key_up=1;
	return 0;// 无按键按下
}
