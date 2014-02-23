/***************************************************************************/
// 程序：LED3264电子日历
// 模块：变量，引脚，宏定义
// 文件：_PinsValues.h
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

#ifndef _PINSVALUES_H_
#define _PINSVALUES_H_
/*数据类型定义*/
#define uint8	 unsigned char
#define uint16	 unsigned short 
#define uint32	 unsigned long 

#define LS138_E_DDR		DDRB
#define LS138_E_PORT	PORTB
#define LS138_E_BIT		PB3

#define LS138_A_DDR		DDRB
#define LS138_A_PORT	PORTB
#define LS138_A_BIT		PB0
#define LS138_A_H		LS138_A_PORT |= (1<<LS138_A_BIT)
#define LS138_A_L		LS138_A_PORT &= ~(1<<LS138_A_BIT)

#define LS138_B_DDR		DDRB
#define LS138_B_PORT	PORTB
#define LS138_B_BIT		PB1
#define LS138_B_H		LS138_B_PORT |= (1<<LS138_B_BIT)
#define LS138_B_L		LS138_B_PORT &= ~(1<<LS138_B_BIT)

#define LS138_C_DDR		DDRB
#define LS138_C_PORT	PORTB
#define LS138_C_BIT		PB2
#define LS138_C_H		LS138_C_PORT |= (1<<LS138_C_BIT)
#define LS138_C_L		LS138_C_PORT &= ~(1<<LS138_C_BIT)

#define LS138_D_DDR		DDRB
#define LS138_D_PORT	PORTB
#define LS138_D_BIT		PB4
#define LS138_D_H		LS138_D_PORT |= (1<<LS138_D_BIT)
#define LS138_D_L		LS138_D_PORT &= ~(1<<LS138_D_BIT)

#define HC595_D0_DDR		DDRD
#define HC595_D0_PORT		PORTD
#define HC595_D0_BIT		PD4
#define HC595_D0_H		HC595_D0_PORT |= (1<<HC595_D0_BIT)
#define HC595_D0_L		HC595_D0_PORT &= ~(1<<HC595_D0_BIT)

#define HC595_D1_DDR		DDRD
#define HC595_D1_PORT		PORTD
#define HC595_D1_BIT		PD5
#define HC595_D1_H		HC595_D1_PORT |= (1<<HC595_D1_BIT)
#define HC595_D1_L		HC595_D1_PORT &= ~(1<<HC595_D1_BIT)

#define HC595_D2_DDR		DDRB
#define HC595_D2_PORT		PORTB
#define HC595_D2_BIT		PB6
#define HC595_D2_H		HC595_D2_PORT |= (1<<HC595_D2_BIT)
#define HC595_D2_L		HC595_D2_PORT &= ~(1<<HC595_D2_BIT)

#define HC595_D3_DDR		DDRB
#define HC595_D3_PORT		PORTB
#define HC595_D3_BIT		PB7
#define HC595_D3_H		HC595_D3_PORT |= (1<<HC595_D3_BIT)
#define HC595_D3_L		HC595_D3_PORT &= ~(1<<HC595_D3_BIT)

#define HC595_LAT_DDR		DDRD
#define HC595_LAT_PORT		PORTD
#define HC595_LAT_BIT		PD2
#define HC595_LAT_H		HC595_LAT_PORT |= (1<<HC595_LAT_BIT)
#define HC595_LAT_L		HC595_LAT_PORT &= ~(1<<HC595_LAT_BIT)

#define HC595_SCK_DDR		DDRD
#define HC595_SCK_PORT	PORTD
#define HC595_SCK_BIT		PD3
#define HC595_SCK_H		HC595_SCK_PORT |= (1<<HC595_SCK_BIT)
#define HC595_SCK_L		HC595_SCK_PORT &= ~(1<<HC595_SCK_BIT)

#define KEY_UP_DDR		DDRC
#define KEY_UP_PORT		PORTC
#define KEY_UP_PIN		PINC
#define KEY_UP_BIT		PC6
#define KEY_UP_H		KEY_UP_PIN & (1<<KEY_UP_BIT)
#define KEY_UP_L		!(KEY_UP_PIN & (1<<KEY_UP_BIT))

#define KEY_DOWN_DDR		DDRC
#define KEY_DOWN_PORT		PORTC
#define KEY_DOWN_PIN		PINC
#define KEY_DOWN_BIT		PC7
#define KEY_DOWN_H			KEY_DOWN_PIN & (1<<KEY_DOWN_BIT)
#define KEY_DOWN_L			!(KEY_DOWN_PIN & (1<<KEY_DOWN_BIT))

#define KEY_MODE_DDR		DDRD
#define KEY_MODE_PORT		PORTD
#define KEY_MODE_PIN		PIND
#define KEY_MODE_BIT		PD0
#define KEY_MODE_H			KEY_MODE_PIN & (1<<KEY_MODE_BIT)
#define KEY_MODE_L			!(KEY_MODE_PIN & (1<<KEY_MODE_BIT))

#define KEY_DISPLAY_COLOR_DDR		DDRD
#define KEY_DISPLAY_COLOR_PORT		PORTD
#define KEY_DISPLAY_COLOR_PIN		PIND
#define KEY_DISPLAY_COLOR_BIT		PD1
#define KEY_DISPLAY_COLOR_H			KEY_DISPLAY_COLOR_PIN & (1<<KEY_DISPLAY_COLOR_BIT)
#define KEY_DISPLAY_COLOR_L			!(KEY_DISPLAY_COLOR_PIN & (1<<KEY_DISPLAY_COLOR_BIT))

#define DQ_DDR		DDRD
#define DQ_PORT		PORTD
#define DQ_PIN		PIND
#define DQ_BIT		PD7
#define DQ_INPUT 	DQ_DDR &= ~(1 << DQ_BIT)    
#define DQ_OUT 		DQ_DDR |= (1 << DQ_BIT)    
#define DQ_LO 		DQ_PORT &= ~(1 << DQ_BIT)  
#define DQ_HI 		DQ_PORT |= (1 << DQ_BIT)   
#define DQ_R 		DQ_PIN & (1 << DQ_BIT)     


#define YearThousand RunParameter[0]
#define YearHundred RunParameter[1]
#define YearTen RunParameter[2]
#define YearOne RunParameter[3]
#define MonthTen RunParameter[4]
#define MonthOne RunParameter[5]
#define DayTen RunParameter[6]
#define DayOne RunParameter[7]
#define HourTen RunParameter[8]
#define HourOne RunParameter[9]
#define MinuteTen RunParameter[10]
#define MinuteOne RunParameter[11]
#define SecondTen RunParameter[12]
#define SecondOne RunParameter[13]
#define Week RunParameter[14]
#define TemperatureTen RunParameter[15]
#define TemperatureOne RunParameter[16]
#define TemperatureDecimal RunParameter[17]
#define display_light_Mode RunParameter[18]
#define display_light RunParameter[19]
#define moveSpeed RunParameter[20]
#define Mode RunParameter[21]
#define AjustTimeMode RunParameter[22]
#define AjustTimeTen RunParameter[23]
#define AjustTimeOne RunParameter[24]
#define AjustTimeIsAjusted  RunParameter[25]
#define Display_color  RunParameter[26]

#define SET_DISPLAY_LIGHT OCR0= (display_light-1)*25+1

#define W_ADD_COM 0xa2
#define R_ADD_COM 0xa3
#define SLAW 0x18
#define ERR_SLAW 1

#define DS18B20_Delay 5

//uint8 display_light; /* 屏幕亮度 1 到 8 */
//uint8 moveSpeed; /* 日期左移速度 1 到 8 */
//uint8 Mode; /* 运行模式 0：正常运行 1：调节年 2：调节月 3：调节日 4：调节时 5：调节分 6：调节星期 7：调节亮度模式 8：调节校队时间 28：显示欢迎界面*/

uint8 RunParameter[27] = {	2,	//0 年千位
							0, 	//1 年百位
							1, 	//2 年十位
							2, 	//3 年个位
							0,	//4 月十位
							1,	//5 月个位
							1,	//6 日十位
							7,	//7 日个位
							2,	//8 时十位
							2,	//9 时个位
							1, 	//10 分十位
							9,	//11 分个位
							0,	//12 秒十位
							0,	//13 秒个位
							2,	//14 星期
							2,	//15 温度十位
							3,	//16 温度个位
							4,	//17 温度小数
							0, 	//18 亮度模式 0：自动 1：手动
							7,	//19 亮度
							1,	//20 速度
							0,	//21 运行模式 
							0,	//22 校对时间 0：减 1：加
							0,	//23 校对时间 十位
							0,	//24 校队时间 个位
							0,	//25 是否已经校时状态位 0：未校时 1：已校时
							0	//26 显示模式 0：单红 1：单绿 2：单黄 3：红底黄字 4：绿底黄字
						};

#endif
