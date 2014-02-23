/***************************************************************************/
// 程序：LED3264电子日历
// 模块：按键扫描
// 文件：_Key.h
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

#ifndef _KEY_H_
#define _KEY_H_

uint16 KEY_Time_count;
uint16 KEY_Time_count_speed_color;

void Key_Init()
{
	KEY_UP_PORT |= 1<<KEY_UP_BIT;
	KEY_UP_DDR  &= ~(1<<KEY_UP_BIT);
	KEY_DOWN_PORT |= 1<<KEY_DOWN_BIT;
	KEY_DOWN_DDR  &= ~(1<<KEY_DOWN_BIT);
	KEY_MODE_PORT |= 1<<KEY_MODE_BIT;
	KEY_MODE_DDR  &= ~(1<<KEY_MODE_BIT);
	KEY_DISPLAY_COLOR_PORT |= 1<<KEY_DISPLAY_COLOR_BIT;
	KEY_DISPLAY_COLOR_DDR  &= ~(1<<KEY_DISPLAY_COLOR_BIT);
}

void Key_Operation(uint8 maxNum, uint8 minNum, uint8 *tenValue, uint8 *oneValue, void (*FunP)())
{
	if(KEY_UP_L) 
	{
		_delay_ms(10);
		if(KEY_UP_L)
		{
			uint8 value = *tenValue*10 + *oneValue;
			value ++;
			if(value > maxNum)
			{
				value = minNum;
			}
			*tenValue = value/10;
			*oneValue = value%10;
			(*FunP)();
		}
		while(KEY_UP_L);	
	}
	if(KEY_DOWN_L) 
	{
		_delay_ms(10);
		if(KEY_DOWN_L)
		{
			uint8 value = *tenValue*10 + *oneValue;
			value --;
			if((value > maxNum) | (value < minNum))
			{
				value = maxNum;
			}
			*tenValue = value/10;
			*oneValue = value%10;
			(*FunP)();			
		}
		while(KEY_DOWN_L);	
	}
}

void Scan_Key()
{
	if(Mode != 0 && Mode != 27 && Mode != 26 && KEY_Time_count > 21000)
	{
		Mode = 0;
		//保存时间到时钟芯片
		Write_time();
		//保存运行参数到eepROM
		SaveRunParameter();
		clearScreen(); //清屏
		FreshDisplayBufferNormal(); //加载正常走时模式
	}
	
	if(Mode == 27 || Mode == 26)
	{
		if(KEY_Time_count_speed_color > 500)
		{
			Mode = 0;
			SaveRunParameter();
			FreshDisplayBufferNormal(); //加载正常走时模式
		}
	}

	if(KEY_DISPLAY_COLOR_L) //显示颜色调节
	{
		_delay_ms(10);
		if(KEY_DISPLAY_COLOR_L)
		{
			Display_color ++;
			if(Display_color > 4)
			{
				Display_color = 0;
			}
			SaveRunParameter();
		}
		while(KEY_DISPLAY_COLOR_L);	
	}

	if(Mode == 0 || Mode== 27 || Mode == 26) //正常运行模式 调节速度和亮度模式
	{

		if(KEY_UP_L) //亮度调节
		{
			_delay_ms(10);
			if(KEY_UP_L)
			{
				if(display_light_Mode) //手动调节亮度模式
				{
					display_light ++;
					if(display_light > 8)
					{
						display_light = 1;
					}
					SET_DISPLAY_LIGHT;//OCR0置初值,占空比50%，调整OCR0的值用来调整占空比
				}
				else //自动调节亮度模式
				{
				
				}
				Mode = 27;
				KEY_Time_count_speed_color = 0;
				FreshDisplayBufferAjustLight();
			}
			while(KEY_UP_L);	
		}
	
		if(KEY_DOWN_L) //速度调节
		{
			_delay_ms(10);
			if(KEY_DOWN_L)
			{
				moveSpeed ++;
				if(moveSpeed > 8)
				{
					moveSpeed = 1;
				}
				Mode = 26;
				KEY_Time_count_speed_color = 0;
				FreshDisplayBufferAjustSpeed();
			}
			while(KEY_DOWN_L);	
		}
	}
	else if(Mode == 1) //调节年
	{
		Key_Operation(99, 0, &YearTen, &YearOne, &FreshDisplayBufferAjustYear);
	}
	else if(Mode == 2) //调节月
	{
		Key_Operation(12, 1, &MonthTen, &MonthOne, &FreshDisplayBufferAjustMonth);
	}
	else if(Mode == 3) //调节日
	{
		Key_Operation(31, 1, &DayTen, &DayOne, &FreshDisplayBufferAjustDay);
	}
	else if(Mode == 4) //调节时
	{
		Key_Operation(23, 0, &HourTen, &HourOne, &FreshDisplayBufferAjustHour);
	}
	else if(Mode == 5) //调节分
	{
		Key_Operation(59, 0, &MinuteTen, &MinuteOne, &FreshDisplayBufferAjustMinute);
	}
	else if(Mode == 6) //调节星期
	{
		uint8 temp = 0;
		Key_Operation(7, 1, &temp, &Week, &FreshDisplayBufferAjustWeek);
	}
	else if(Mode == 7) //调节亮度模式
	{
		uint8 temp = 0;
		Key_Operation(1, 0, &temp, &display_light_Mode, &FreshDisplayBufferAjustLightMode);
	}
	else if(Mode == 8) //设置字体
	{
		uint8 temp = 0;
		Key_Operation(2, 0, &temp, &Display_BigNumber_Font, &FreshDisplayBufferChangeFont);
	}
	else if(Mode == 9) //调节校对时间
	{
		if(KEY_UP_L) 
		{
			_delay_ms(10);
			if(KEY_UP_L)
			{
				uint8 value = AjustTimeTen*10 + AjustTimeOne;
				value ++;
				if(value > 20)
				{
					value = 0;
				}
				AjustTimeTen = value/10;
				AjustTimeOne = value%10;
				FreshDisplayBufferAjustProofTime();
			}
			while(KEY_UP_L);	
		}
		if(KEY_DOWN_L) 
		{
			_delay_ms(10);
			if(KEY_DOWN_L)
			{
				if(AjustTimeMode)
				{
					AjustTimeMode = 0;
				}
				else
				{
					AjustTimeMode = 1;
				}
				FreshDisplayBufferAjustProofTime();
			}
			while(KEY_DOWN_L);	
		}
	}
	//////////////////////////////////////////////////////////
	if(KEY_MODE_L) //模式调节
	{
		_delay_ms(10);
		if(KEY_MODE_L)
		{
			KEY_Time_count = 0;
			Mode ++;
			if(Mode > 9)
			{
				Mode = 0;
			}
			switch(Mode){
				case 0:	//正常运行
					//保存时间到时钟芯片
					Write_time();
					//保存运行参数到eepROM
					SaveRunParameter();
					clearScreen(); //清屏
					FreshDisplayBufferNormal(); //加载正常走时模式
					break; 
				case 1:	//调节年
					FreshDisplayBufferAjustYear();
					break; 
				case 2:	//调节月
					FreshDisplayBufferAjustMonth();
					break; 
				case 3:	//调节日
					FreshDisplayBufferAjustDay();
					break; 
				case 4:	//调节时
					FreshDisplayBufferAjustHour();
					break; 
				case 5:	//调节分
					FreshDisplayBufferAjustMinute();
					break;
				case 6:	//调节星期
					FreshDisplayBufferAjustWeek();
					break;  
				case 7:	//调节亮度模式
					FreshDisplayBufferAjustLightMode();
					break;
				case 8:	//设置字体
					FreshDisplayBufferChangeFont();
					break;
				case 9:	//调节校队时间
					FreshDisplayBufferAjustProofTime();
					break;  
				default:
					break; 
			} 
		}
		while(KEY_MODE_L);	
	}
}


#endif
