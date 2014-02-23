/***************************************************************************/
// 程序：LED3264电子日历
// 模块：串口
// 文件：_USART.h
// 作者：卜晓旸
// 版本：1.9.7
// 日期：2012年2月10日
// 功能：时分数字静态显示，年月日周温度滚动显示。可选亮度模式，时间补偿。
// 芯片：Atmega8
// 容丝：低位0x24 高位0xD1
// 编译：AVR GCC
// 引脚定义：	PD0：按键MODE 
//				PD1: 按键显示模式
//				PD2：显示屏控制LAT
//				PD3：显示屏控制SCK
//				PD4：显示屏信号R1
//				PD5：显示屏信号R2
// 				PD7：温度传感器DS18B20
//				PC6：按键UP
//				PC7：按键DOWN
//				PB0：显示屏控制A
//				PB1：显示屏控制B
//				PB2：显示屏控制C
//				PB3：显示屏控制EN
//				PB4：显示屏控制D
//				PB6：显示屏数据G1
//				PB7：显示屏数据G2
//				PA0: 光敏电阻
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
