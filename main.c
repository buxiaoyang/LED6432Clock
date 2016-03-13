/***************************************************************************/
// 程序：LED3264电子日历
// 模块：主函数	
// 文件：LED3264.c
// 作者：卜晓旸
// 版本：1.9.7
// 日期：2012年2月10日
// 功能：时分数字静态显示，年月日周温度滚动显示。可选亮度模式，时间补偿。
// 芯片：Atmega16
// 容丝：低位0xA4 10100100 高位0xD1 11010001
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
//				PA1：显示屏数据G1
//				PA2：显示屏数据G2
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
#include "_Voice.h"
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
	Voice_Init();
	//USART_Init();
	timer0_init(); //初始化定时器
	timer2_init();
	PCF8563_init();
	INFRARED_INI();
	ReadDS18B20Count = 0;
	AD_time_count = 0;
	KEY_Time_count = 0;
	ds1820_reset();  
	clearScreen();	
	sei(); //使能中断
}

int main()
{
	uint8 currentlyHourVoice;//当前小时数，用于语音报时
	uint8 needFreshDisplayBuffer = 1; //used in fresh disply buffer
	uint8 secondPointFreshFlag = 0; //used for check whether to fresh the second dot
	
	unsigned char out_put = 0;  //Used for test output
	init_devices();
	ds1820_start();   
	_delay_100ms(6);   
	ReadTemputer();
	if(KEY_MODE_L) //判断是否加载初始化参数
	{
		_delay_ms(10);
		if(KEY_MODE_L)
		{
			display_light_Mode = 	1;
			display_light = 		1;
			moveSpeed = 			1;
			Mode = 					0;
			AjustTimeMode = 		0;
			AjustTimeTen = 			0;
			AjustTimeOne = 			0;	
			Display_color = 		0;
			Display_BigNumber_Font = 0;
			SET_DISPLAY_LIGHT;
			SaveRunParameter();
		}
	}
	ReadRunParameter();
	Show_welcome();
	Updata_time();
	FreshDisplayBufferNormal();
	SPEEK_TIME_Status = 1;
	while(1)
	{
		//675 us 0.000675s
		if( Mode == 0)
		{
			//test code begin
			if(out_put)
			{
				INFR_H;
				out_put = 0;
			}
			else
			{
				INFR_L;
				out_put = 1;
			}
			//test code end
			Updata_time();
			FreshDisplayBufferSecond(); //update second
			if(SecondTen == 0 && SecondOne == 0 && needFreshDisplayBuffer)
			{
				AjustTimerMonthly();
				FreshDisplayBufferNormal();
				needFreshDisplayBuffer = 0;
			}
			if(SecondTen == 5 && SecondOne == 9)
			{
				needFreshDisplayBuffer = 1;
			}
			if(secondPointFreshFlag != SecondOne)
			{
				writeCloclColon(SecondOne % 2);
				secondPointFreshFlag = SecondOne;
			}
			//语音报时开始
			if(Voice_Mode == 0)//正常模式
			{
				if(MinuteTen == 0 && MinuteOne == 0 && SecondTen == 0 && SecondOne < 10 && inVoice == 0)
				{
					inVoice = 1;
					SPEEK_TIME_Status = 1;
				}
			}
			else if(Voice_Mode == 1) //勿扰模式
			{
				currentlyHourVoice = HourTen*10 + HourOne;
				if(currentlyHourVoice > 6 && currentlyHourVoice <= 23)
				{
					if(MinuteTen == 0 && MinuteOne == 0 && SecondTen == 0 && SecondOne < 10 && inVoice == 0)
					{
						inVoice = 1;
						SPEEK_TIME_Status = 1;
					}
				}
			}
			else //关闭模式
			{
			
			}
			//语音报时结束

		}
		display();	
		Scan_Key();
	}
}