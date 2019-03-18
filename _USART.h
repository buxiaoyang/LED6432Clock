/***************************************************************************/
// 程序：LED3264电子日历
// 模块：串口
// 文件：_USART.h
// 作者：卜晓旸
// 版本：1.9.7
// 日期：2012年2月10日
/***************************************************************************/

#ifndef _USART_H_
#define _USART_H_

void USART_Init()
{
	// 通信参数: 8 Data, 1 Stop, No Parity  
	// 波特率: 
	//晶振8M时波特率设置  UBRRL=0x33; 
	UCSRB=0x00;  
	UCSRA=0x00; 	     //控制寄存器清零 
	UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);  //允许发送和接收 
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0); //8位数据位+1位停止位 
	UCSRA=0x01; 
	UBRRH=0x00;  
	UBRRL=0x33;//波特率设置为9600 
}

void uart_send_char( unsigned char data )
{
    UDR = data;   
    while(!(UCSRA&(1<<UDRE)));    
}

#endif
