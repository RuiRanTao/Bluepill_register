#include "usart.h"	  
#include"stm32f10x.h"
#include "sys.h" 
#include "string.h"


#if EN_USART1_RX
u8 USART1_REC[USART_REC_LEN];
//USART1_STA[15] 标识是否接收完成状态位，1：标识接收完成；0：未接收完成；
//USART1_STA[14] 标识是否为第一个数据，1：非第一个数据；0：表示第一个数据；
//USART1_STA[13:0] 标识有效的数据接收长度
u16 USART1_STA = 0;

#ifdef __GNUC__

#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)

PUTCHAR_PROTOTYPE
{
    //注意下面第一个参数是&husart1，因为cubemx配置了串�???1自动生成�???
	USART1_SendData((uint8_t*)&ch, 1);
    return ch;
}
#endif

void USART1_IRQHandler(void) {
	u8 buf = 0;
	if (USART1->SR & 0x20) {	//当接收中断产生

		if (!(USART1_STA & 0x4000)) {	//第一个数据
			USART1_STA = 0x4000;	//表示下次接收，就不再是第一个数据，清除掉了数据接收长度
			memset(USART1_REC, 0, USART_REC_LEN);
		}

		buf = USART1->DR;
		USART1_REC[USART1_STA & 0x3FFF] = buf;
		USART1_STA++;

		if ((USART1_STA & 0x3FFF) >= USART_REC_LEN) {	//达到将要满载状态
			USART1_STA = 0;	//覆盖原本数据
		}
	}

	if (USART1->SR & 0x10) {	//总线空闲
		USART1_STA |= 0x8000;	//标识接收成功
		USART1_STA &= ~0x4000;	//清除14位
		USART1_REC[USART1_STA & 0x3FFF] = '\0';	//保证有效字符串
		buf = USART1->DR;	//清空状态
	}

}
#endif										 

void USART1_SendData(u8 *data, u8 len) {
	u8 i = 0;

	for (i = 0; i < len; i++) {
		if (*(data + i) == '\0')	//空白符号无需发送
			return;
		//判断是否允许发送数据
		while ((USART1->SR & 0x40) == 0);
		USART1->DR = *(data + i);	//等效于下面的函数
//		USART_SendData(USART1, *(data + i));
	}
}


//void uart_init(uint32_t pclk2,uint32_t bound)
//{
//	float temp;
//	u16 mantissa;
//	u16 fraction;
//	temp=(float)(pclk2*1000000)/(bound*16);
//	mantissa=temp;
//	fraction=(temp-mantissa)*16;
//    mantissa<<=4;
//	mantissa+=fraction;
//	RCC->APB2ENR|=1<<2;
//	RCC->APB2ENR|=1<<14;
//	GPIOA->CRH&=0XFFFFF00F;
//	GPIOA->CRH|=0X000008B0;
//	RCC->APB2RSTR|=1<<14;
//	RCC->APB2RSTR&=~(1<<14);
// 	USART1->BRR=mantissa;
//	USART1->CR1|=0X200C;
//#if EN_USART1_RX
//	USART1->CR1|=1<<5;
//	MY_NVIC_Init(3,3,USART1_IRQn,2);
//#endif
//}


void USART1_Init (uint32_t pclk2,uint32_t bound)
{
	float temp;
	u16 mantissa;
	u16 fraction;
	temp=(float)(pclk2*1000000)/(bound*16);
	mantissa=temp;
	fraction=(temp-mantissa)*16;
	mantissa<<=4;
	mantissa+=fraction;
    //1.使能时钟
	RCC->APB2ENR |= 1 << 2;	//GPIOA 时钟使能
	RCC->APB2ENR |= 1 << 14;	//USART1 时钟使能

	//2.初始化GPIO
	GPIOA->CRH &= ~(0x0F << 4);
	GPIOA->CRH |= 0x0B << 4;	//设置GPIOA.9 -> 50MHz，复用推挽

	GPIOA->CRH &= ~(0x0F << 8);
	GPIOA->CRH |= 0x04 << 8;	//设置GPIOA.10 -> 浮空输入模式

	//3.初始化USART1
	//3.1 设置波特率
	USART1->BRR = mantissa ;//0x1D4 << 4 | 0x4B;//设置波特率9600
	//3.2 设置校验位
	USART1->CR1 &= ~(1 << 10);			//不使用校验位
	//3.3 数据位
	USART1->CR1 &= ~(1 << 12);			//8位长度
	//3.4 停止位
	USART1->CR2 &= ~(0x02 << 12);			//1个停止位
	//4.使能
	USART1->CR1 |= 1 << 3;			//使能TX
	USART1->CR1 |= 1 << 2;			//使能RX
	USART1->CR1 |= 1 << 13;			//使能USART1

	//配置数据接收时候，需要用到中断
	//5.配置NVIC
	//5.1 先分组
	MY_NVIC_Init(3,3,USART1_IRQn,2);

	//6 使能接受数据中断寄存器
	USART1->CR1 |= 1 << 5;
	USART1->CR1 |= 1 << 4;			//开启IDLE中断
}

