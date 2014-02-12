/***************************************************************************/
// 程序：LED3264电子日历
// 模块：语音
// 文件：_Voice.h
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
//				PB6：显示屏数据G1
//				PB7：显示屏数据G2
//				PA0: 光敏电阻
/***************************************************************************/

#ifndef _VOICE_H_
#define _VOICE_H_

#define VOICE_BUSY_DDR		DDRC
#define VOICE_BUSY_PORT		PORTC
#define VOICE_BUSY_PIN		PINC
#define VOICE_BUSY_BIT		PC2
#define VOICE_BUSY_H		VOICE_BUSY_PIN & (1<<VOICE_BUSY_BIT)
#define VOICE_BUSY_L		!(VOICE_BUSY_PIN & (1<<VOICE_BUSY_BIT))

#define VOICE_REST_DDR		DDRC
#define VOICE_REST_PORT		PORTC
#define VOICE_REST_BIT		PC3
#define VOICE_REST_H		VOICE_REST_PORT |= (1<<VOICE_REST_BIT)
#define VOICE_REST_L		VOICE_REST_PORT &= ~(1<<VOICE_REST_BIT)

#define VOICE_DATA_DDR		DDRC
#define VOICE_DATA_PORT		PORTC
#define VOICE_DATA_BIT		PC4
#define VOICE_DATA_H		VOICE_DATA_PORT |= (1<<VOICE_DATA_BIT)
#define VOICE_DATA_L		VOICE_DATA_PORT &= ~(1<<VOICE_DATA_BIT)

#define uint8 unsigned char
#define uint16 unsigned int

uint8 PLUSE_Number;
uint8 PLUSE_Delay;
uint8 PLUSE_Status;

uint16 SPEEK_TIME_Delay;
uint8 SPEEK_TIME_Status;

uint8 inVoice;

void Voice_Init()
{
	VOICE_BUSY_PORT |= 1<<VOICE_BUSY_BIT;
	VOICE_BUSY_DDR  &= ~(1<<VOICE_BUSY_BIT);
	VOICE_REST_DDR |= 1<<VOICE_REST_BIT;
	VOICE_DATA_DDR |= 1<<VOICE_DATA_BIT;
}

void SPEEK_Time()
{
	uint8 nowHours;
	switch(SPEEK_TIME_Status)
	{
		case 0:
			inVoice = 0;
		break;
		case 1: //火车站播音声叮叮叮
			/*
			初始化测试代码
			HourTen = 			0;
			HourOne = 			8;
			MinuteTen = 		3;
			MinuteOne = 		0;
			TemperatureTen = 	2;
			TemperatureOne = 	0;
			TemperatureDecimal = 0;
			初始化测试代码
			*/
			PLUSE_Number=25;
			PLUSE_Status=1;
			SPEEK_TIME_Status = 2;
		break;
		case 2: //现在时刻北京时间
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				PLUSE_Number=22;
				PLUSE_Status=1;
				SPEEK_TIME_Status = 3;		
			}
		break;
		case 3: //上午	
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				nowHours = HourTen*10 + HourOne;
				if(nowHours >= 0 && nowHours < 7)
				{
					SPEEK_TIME_Status = 4;	
				}
				else if(nowHours >= 7 && nowHours < 13)
				{
					PLUSE_Number= 28;
					PLUSE_Status=1;
					SPEEK_TIME_Status = 4;	
				}
				else if(nowHours >= 13 && nowHours < 19)
				{
					PLUSE_Number= 29;
					PLUSE_Status=1;
					SPEEK_TIME_Status = 4;	
				}
				else if(nowHours >= 19 && nowHours < 24)
				{
					PLUSE_Number= 30;
					PLUSE_Status=1;
					SPEEK_TIME_Status = 4;	
				}		
				else
				{
					SPEEK_TIME_Status = 4;
				}
			}	
		break;
		case 4: //二	
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				if(HourTen > 1)
				{
					PLUSE_Number= HourTen+1;
					PLUSE_Status=1;
					SPEEK_TIME_Status = 5;	
				}	
				else
				{
					SPEEK_TIME_Status = 5;
				}
			}	
		break;
		case 5: //十
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				if(HourTen != 0)
				{

					PLUSE_Number=11;
					PLUSE_Status=1;
					SPEEK_TIME_Status = 6;	
				}
				else
				{
					SPEEK_TIME_Status = 6;
				}
			}
		break;
		case 6: //一
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				if(HourOne == 0 && HourTen != 0)
				{
					SPEEK_TIME_Status = 7;
							
				}
				else
				{
					PLUSE_Number=HourOne+1;
					PLUSE_Status=1;
					SPEEK_TIME_Status = 7;
				}
			}
		break;
		case 7: //点
			 if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				PLUSE_Number=13;
				PLUSE_Status=1;
				SPEEK_TIME_Status =8;		
			}
		break;
		case 8: //五
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				if(MinuteTen == 0 && MinuteOne == 0)
				{
					PLUSE_Number= 26;
					PLUSE_Status=1;
					SPEEK_TIME_Status =9;
				}
				else if(MinuteTen > 1)
				{
					PLUSE_Number=MinuteTen+1;
					PLUSE_Status=1;
					SPEEK_TIME_Status =9;	
				}
				else
				{
					SPEEK_TIME_Status =9;
				}
			}
		break;
		case 9: //十
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				if(MinuteTen == 0 && MinuteOne == 0)
				{
					SPEEK_TIME_Status =10;
				}
				else if(MinuteTen != 0)
				{
					PLUSE_Number=11;
					PLUSE_Status=1;
					SPEEK_TIME_Status =10;
				}
				else
				{
					PLUSE_Number=1;
					PLUSE_Status=1;
					SPEEK_TIME_Status =10;
				}		
			}
		break;
		case 10: //三
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				if(MinuteOne == 0 && MinuteTen == 0)
				{
					SPEEK_TIME_Status =11;
				}
				else if(MinuteOne == 0 && MinuteTen != 0)
				{
					SPEEK_TIME_Status =11;	
				}
				else
				{
					PLUSE_Number=MinuteOne+1;
					PLUSE_Status=1;
					SPEEK_TIME_Status =11;	
				}
			}
		break;
		case 11: //分
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				if(MinuteTen == 0 && MinuteOne == 0)
				{
					SPEEK_TIME_Status =12;
				}
				else
				{
					PLUSE_Number=14;
					PLUSE_Status=1;
					SPEEK_TIME_Status = 12;	
				}	
			}
		break;
		case 12: //等待
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				SPEEK_TIME_Delay = 1000;
				SPEEK_TIME_Status = 13;		
			}
		break;
		case 13: //现在温度是
			SPEEK_TIME_Delay --;
			if(SPEEK_TIME_Delay == 0)
			{
				PLUSE_Number=23;
				PLUSE_Status=1;
				SPEEK_TIME_Status = 14;		
			}
		break;
		case 14: //二
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				if(TemperatureTen > 1 && TemperatureTen < 10)
				{
					PLUSE_Number=TemperatureTen+1;
					PLUSE_Status=1;
					SPEEK_TIME_Status = 15;	
				}
				else if(TemperatureTen > 10)
				{
					PLUSE_Number=31;
					PLUSE_Status=1;
					SPEEK_TIME_Status = 15;
				}
				else
				{
					SPEEK_TIME_Status = 15;
				}
			}
		break;
		case 15: //十
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				if(TemperatureTen != 0 && TemperatureTen != 14)
				{
					PLUSE_Number=11;
					PLUSE_Status=1;
					SPEEK_TIME_Status = 16;
				}
				else
				{
					SPEEK_TIME_Status = 16;
				}
			}
		break;
		case 16: //一
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				if(TemperatureOne != 0)
				{
					PLUSE_Number=TemperatureOne+1;
					PLUSE_Status=1;
					SPEEK_TIME_Status = 17;	
				}
				else if(TemperatureOne ==0 && (TemperatureTen == 0 || TemperatureTen == 14))
				{
					PLUSE_Number=TemperatureOne+1;
					PLUSE_Status=1;
					SPEEK_TIME_Status = 17;
				}
				else
				{
					SPEEK_TIME_Status = 17;	
				}
			}
		break;
		case 17: //点
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				PLUSE_Number=13;
				PLUSE_Status=1;
				SPEEK_TIME_Status = 18;		
			}
		break;
		case 18: //五
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				PLUSE_Number=TemperatureDecimal+1;
				PLUSE_Status=1;
				SPEEK_TIME_Status =19;		
			}
		break;
		case 19: //度
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				PLUSE_Number=20;
				PLUSE_Status=1;
				SPEEK_TIME_Status = 20;		
			}
		break;
		case 20:
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				SPEEK_TIME_Status = 0;		
			}		
		break;	
		case 100: //按键音
			SPEEK_TIME_Status = 0;
			/*
			PLUSE_Number = 32;
			PLUSE_Status = 1;
			SPEEK_TIME_Status = 101;
			*/
		break;
		case 101:
			if(PLUSE_Status == 0 && VOICE_BUSY_H)
			{
				SPEEK_TIME_Status = 0;		
			}		
		break;	
	}
}

void PLUSE_Out()
{
	switch(PLUSE_Status)
	{
		case 0:
			PLUSE_Delay = 2;
			VOICE_DATA_L;
			VOICE_REST_L;	
		break;
		case 1:
			VOICE_DATA_L;
			VOICE_REST_H;
			PLUSE_Delay--;
			if(PLUSE_Delay==0)
			{
				VOICE_REST_L;
				PLUSE_Status=2;
			}
		break;
		case 2:
			if(PLUSE_Number>0)
			{
			  	PLUSE_Delay = 1;
				PLUSE_Status = 3;
			}
			else
			{
				PLUSE_Status = 0;
			}	
		break;
		case 3:
			VOICE_DATA_L;
			PLUSE_Delay--;
			if(PLUSE_Delay==0)
			{
				PLUSE_Delay = 1;
				PLUSE_Status=4;
			}
		break;
		case 4:
			VOICE_DATA_H;
			PLUSE_Delay--;
			if(PLUSE_Delay==0)
			{
				PLUSE_Status=5;
			}
		break;
		case 5:
			VOICE_DATA_L;
			PLUSE_Number--;
			PLUSE_Status = 2;
		break;
	}	
}

#endif
