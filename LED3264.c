/***************************************************************************/
// 程序：LED3264电子挂历
// 模块：主函数
// 作者：卜晓旸
// 版本：1.0
// 日期：2012年1月13日
// 功能：时分数字静态显示，年月日周温度滚动显示
// 芯片：Atmega8
// 编译：AVR GCC
// 引脚定义：PD6-红外传感器，PC0-时钟芯片SCK，PC1-时钟芯片SDA，PC7-蜂鸣器，PD4-温度传感器，
// 
//	
//
//
/***************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h> 
#include "_PinsValues.h"
#include "_Matrix.h"
#include "_DS18B20.h"
#include "_Display.h"
#include "_TWI.h"
#include "_PCF8563.h"
#include "_Key.h"
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
	timer0_init(); //初始化定时器
	timer2_init();
	PCF8563_init();
	ReadDS18B20Count = 0;
	ds1820_reset();  
	clearScreen();	
	sei(); //使能中断
}

int main()
{
	init_devices();
	//Write_time();
	ds1820_start();    
	_delay_ms(1000);     
	ReadTemputer(); 
	Updata_time();
	FreshDisplayBufferNormal();
	while(1)
	{
		//675 us 0.000675s
		display();	
		Scan_Key();
	}
}

