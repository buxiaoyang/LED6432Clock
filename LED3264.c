/***************************************************************************/
// 程序：LED3264电子日历
// 模块：主函数	
// 文件：LED3264.c
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

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h> 
#include <avr/eeprom.h>
#include "_PinsValues.h"
#include "_Matrix.h"
//#include "_USART.h"
#include "_DS18B20.h"
#include "_EEPROM.h"
#include "_Display.h"
#include "_TWI.h"
#include "_PCF8563.h"
#include "_Key.h"
#include "_Dimming.h"
#include "_Timers.h"
#include "_Infrared.h"

void init_devices()
{
	cli(); //关闭所有中断
	MCUCR  = 0x00;
	//MCUCSR = 0x80;//禁止JTAG
	GICR   = 0x00;//关闭外部中断
	LED_SCREEN_INI(); //初始化LED点阵
	Key_Init();
	//USART_Init();
	timer0_init(); //初始化定时器
	timer2_init();
	PCF8563_init();
	ReadDS18B20Count = 0;
	AD_time_count = 0;
	KEY_Time_count = 0;
	ds1820_reset();  
	clearScreen();	
	sei(); //使能中断
}

int main()
{
	init_devices();
	ReadRunParameter();
	Show_welcome();
	ds1820_start();   
	_delay_100ms(6);   
	ReadTemputer(); 
	Updata_time();
	FreshDisplayBufferNormal();
	while(1)
	{
		//675 us 0.000675s
		if( Mode == 0)
		{
			Updata_time();
			FreshDisplayBufferCount ++;
			if(FreshDisplayBufferCount > 10000)
			{
				AjustTimerMonthly();
				FreshDisplayBufferNormal();
				FreshDisplayBufferCount = 0;
			}	
		}
		display();	
		Scan_Key();
	}
}

