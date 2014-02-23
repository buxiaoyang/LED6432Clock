#ifndef _KEY_H_
#define _KEY_H_


void Key_Init()
{
	KEY_UP_PORT |= 1<<KEY_UP_BIT;
	KEY_UP_DDR  &= ~(1<<KEY_UP_BIT);
	KEY_DOWN_PORT |= 1<<KEY_DOWN_BIT;
	KEY_DOWN_DDR  &= ~(1<<KEY_DOWN_BIT);
	KEY_MODE_PORT |= 1<<KEY_MODE_BIT;
	KEY_MODE_DDR  &= ~(1<<KEY_MODE_BIT);
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
	if(Mode == 0) //正常运行模式
	{
		if(KEY_UP_L) //亮度调节
		{
			_delay_ms(10);
			if(KEY_UP_L)
			{
				display_light ++;
				if(display_light > 8)
				{
					display_light = 1;
				}
				SET_DISPLAY_LIGHT;//OCR0置初值,占空比50%，调整OCR0的值用来调整占空比
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

	else if(Mode == 8) //调节校对时间
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
			Mode ++;
			if(Mode > 8)
			{
				Mode = 0;
			}
			switch(Mode){
				case 0:	//正常运行
					//保存时间到时钟芯片
					Write_time();
					//保存运行参数到eepROM

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
				case 8:	//调节校队时间
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
