#ifndef __USART_H
#define __USART_H
//#include "sys.h"
#include "stdio.h"	 
#include"stm32f10x.h"

 
#define USART_REC_LEN  			200
#define EN_USART1_RX 			1
	  	
extern uint8_t  USART1_REC[USART_REC_LEN];
extern u16 USART1_STA;


extern void USART1_Init(uint32_t pclk2,uint32_t bound);
extern void USART1_SendData(u8 *data, u8 len);
#endif	   
















