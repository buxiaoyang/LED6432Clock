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
	/*
	else if(Mode == 1) //调节年
	{
		if(KEY_UP_L) 
		{
			_delay_ms(10);
			if(KEY_UP_L)
			{
				uint8 value = YearTen*10 + YearOne;
				value ++;
				if(value > 99)
				{
					value = 0;
				}
				YearTen = value/10;
				YearOne = value%10;
				FreshDisplayBufferAjustYear();
			}
			while(KEY_UP_L);	
		}
		if(KEY_DOWN_L) 
		{
			_delay_ms(10);
			if(KEY_DOWN_L)
			{
				uint8 value = YearTen*10 + YearOne;
				value --;
				if(value > 99)
				{
					value = 99;
				}
				YearTen = value/10;
				YearOne = value%10;	
				FreshDisplayBufferAjustYear();			
			}
			while(KEY_DOWN_L);	
		}
	}
	else if(Mode == 2) //调节月
	{
		if(KEY_UP_L) 
		{
			_delay_ms(10);
			if(KEY_UP_L)
			{
				uint8 value = MonthTen*10 + MonthOne;
				value ++;
				if(value > 12)
				{
					value = 1;
				}
				MonthTen = value/10;
				MonthOne = value%10;
				FreshDisplayBufferAjustMonth();
			}
			while(KEY_UP_L);	
		}
		if(KEY_DOWN_L) 
		{
			_delay_ms(10);
			if(KEY_DOWN_L)
			{
				uint8 value = MonthTen*10 + MonthOne;
				value --;
				if(value > 12 || value < 1)
				{
					value = 12;
				}
				MonthTen = value/10;
				MonthOne = value%10;
				FreshDisplayBufferAjustMonth();		
			}
			while(KEY_DOWN_L);	
		}
	}
	else if(Mode == 3) //调节日
	{
		if(KEY_UP_L) 
		{
			_delay_ms(10);
			if(KEY_UP_L)
			{
				uint8 value = DayTen*10 + DayOne;
				value ++;
				if(value > 31)
				{
					value = 1;
				}
				DayTen = value/10;
				DayOne = value%10;
				FreshDisplayBufferAjustDay();
			}
			while(KEY_UP_L);	
		}
		if(KEY_DOWN_L) 
		{
			_delay_ms(10);
			if(KEY_DOWN_L)
			{
				uint8 value = DayTen*10 + DayOne;
				value --;
				if(value > 31 || value < 1)
				{
					value = 31;
				}
				DayTen = value/10;
				DayOne = value%10;
				FreshDisplayBufferAjustDay();
			}
			while(KEY_DOWN_L);	
		}
	}
	else if(Mode == 4) //调节时
	{
		if(KEY_UP_L) 
		{
			_delay_ms(10);
			if(KEY_UP_L)
			{
				uint8 value = HourTen*10 + HourOne;
				value ++;
				if(value > 23)
				{
					value = 0;
				}
				HourTen = value/10;
				HourOne = value%10;
				FreshDisplayBufferAjustHour();
			}
			while(KEY_UP_L);	
		}
		if(KEY_DOWN_L) 
		{
			_delay_ms(10);
			if(KEY_DOWN_L)
			{
				uint8 value = HourTen*10 + HourOne;
				value --;
				if(value > 23)
				{
					value = 23;
				}
				HourTen = value/10;
				HourOne = value%10;
				FreshDisplayBufferAjustHour();
			}
			while(KEY_DOWN_L);	
		}
	}
	else if(Mode == 5) //调节分
	{
		if(KEY_UP_L) 
		{
			_delay_ms(10);
			if(KEY_UP_L)
			{
				uint8 value = MinuteTen*10 + MinuteOne;
				value ++;
				if(value > 59)
				{
					value = 0;
				}
				MinuteTen = value/10;
				MinuteOne = value%10;
				FreshDisplayBufferAjustMinute();
			}
			while(KEY_UP_L);	
		}
		if(KEY_DOWN_L) 
		{
			_delay_ms(10);
			if(KEY_DOWN_L)
			{
				uint8 value = MinuteTen*10 + MinuteOne;
				value --;
				if(value > 59)
				{
					value = 59;
				}
				MinuteTen = value/10;
				MinuteOne = value%10;
				FreshDisplayBufferAjustMinute();
			}
			while(KEY_DOWN_L);	
		}
	}
	else if(Mode == 6) //调节星期
	{
		if(KEY_UP_L) 
		{
			_delay_ms(10);
			if(KEY_UP_L)
			{
				Week ++;
				if(Week > 7)
				{
					Week = 1;
				}
				FreshDisplayBufferAjustWeek();
			}
			while(KEY_UP_L);	
		}
		if(KEY_DOWN_L) 
		{
			_delay_ms(10);
			if(KEY_DOWN_L)
			{
				Week --;
				if(Week > 7 || Week < 1)
				{
					Week = 7;
				}
				FreshDisplayBufferAjustWeek();
			}
			while(KEY_DOWN_L);	
		}
	}
	else if(Mode == 7) //调节亮度模式
	{
		if(KEY_UP_L) 
		{
			_delay_ms(10);
			if(KEY_UP_L)
			{
				if(display_light_Mode)
				{
					display_light_Mode = 0;
				}
				else
				{
					display_light_Mode = 1;
				}
				FreshDisplayBufferAjustLightMode();
			}
			while(KEY_UP_L);	
		}
		if(KEY_DOWN_L) 
		{
			_delay_ms(10);
			if(KEY_DOWN_L)
			{
				if(display_light_Mode)
				{
					display_light_Mode = 0;
				}
				else
				{
					display_light_Mode = 1;
				}
				FreshDisplayBufferAjustLightMode();
			}
			while(KEY_DOWN_L);	
		}
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
	*/
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
