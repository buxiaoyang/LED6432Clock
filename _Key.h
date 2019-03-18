/***************************************************************************/
// 程序：LED3264电子日历
// 模块：按键扫描
// 文件：_Key.h
// 作者：卜晓旸
// 版本：1.9.7
// 日期：2012年2月10日
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
			SPEEK_TIME_Status = 100; //按键音
			KEY_Time_count = 0;
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
			SPEEK_TIME_Status = 100; //按键音
			KEY_Time_count = 0;
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
			SPEEK_TIME_Status = 1;
			Display_color ++;
			if(Display_color > 18)
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
				SPEEK_TIME_Status = 100; //按键音
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
				SPEEK_TIME_Status = 100; //按键音
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
				KEY_Time_count = 0;
				SPEEK_TIME_Status = 100; //按键音
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
				KEY_Time_count = 0;
				SPEEK_TIME_Status = 100; //按键音
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
	else if(Mode == 10) //报时
	{
		uint8 temp = 0;
		Key_Operation(2, 0, &temp, &Voice_Mode, &FreshDisplayBufferVoiceMode);
	}
	//////////////////////////////////////////////////////////
	if(KEY_MODE_L) //模式调节
	{
		_delay_ms(10);
		if(KEY_MODE_L)
		{
			SPEEK_TIME_Status = 100; //按键音
			KEY_Time_count = 0;
			Mode ++;
			if(Mode > 10)
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
				case 10://调节语音报时
					FreshDisplayBufferVoiceMode();
					break;
				default:
					break; 
			} 
		}
		while(KEY_MODE_L);	
	}
}


#endif
