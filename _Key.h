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
	if(Mode == 0) //��������ģʽ
	{
		if(KEY_UP_L) //���ȵ���
		{
			_delay_ms(10);
			if(KEY_UP_L)
			{
				display_light ++;
				if(display_light > 8)
				{
					display_light = 1;
				}
				SET_DISPLAY_LIGHT;//OCR0�ó�ֵ,ռ�ձ�50%������OCR0��ֵ��������ռ�ձ�
			}
			while(KEY_UP_L);	
		}
		if(KEY_DOWN_L) //�ٶȵ���
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
	else if(Mode == 1) //������
	{
		Key_Operation(99, 0, &YearTen, &YearOne, &FreshDisplayBufferAjustYear);
	}
	else if(Mode == 2) //������
	{
		Key_Operation(12, 1, &MonthTen, &MonthOne, &FreshDisplayBufferAjustMonth);
	}
	else if(Mode == 3) //������
	{
		Key_Operation(31, 1, &DayTen, &DayOne, &FreshDisplayBufferAjustDay);
	}
	else if(Mode == 4) //����ʱ
	{
		Key_Operation(23, 0, &HourTen, &HourOne, &FreshDisplayBufferAjustHour);
	}
	else if(Mode == 5) //���ڷ�
	{
		Key_Operation(59, 0, &MinuteTen, &MinuteOne, &FreshDisplayBufferAjustMinute);
	}
	else if(Mode == 6) //��������
	{
		uint8 temp = 0;
		Key_Operation(7, 1, &temp, &Week, &FreshDisplayBufferAjustWeek);
	}
	else if(Mode == 7) //��������ģʽ
	{
		uint8 temp = 0;
		Key_Operation(1, 0, &temp, &display_light_Mode, &FreshDisplayBufferAjustLightMode);
	}

	else if(Mode == 8) //����У��ʱ��
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
	if(KEY_MODE_L) //ģʽ����
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
				case 0:	//��������
					//����ʱ�䵽ʱ��оƬ
					Write_time();
					//�������в�����eepROM

					clearScreen(); //����
					FreshDisplayBufferNormal(); //����������ʱģʽ
					break; 
				case 1:	//������
					FreshDisplayBufferAjustYear();
					break; 
				case 2:	//������
					FreshDisplayBufferAjustMonth();
					break; 
				case 3:	//������
					FreshDisplayBufferAjustDay();
					break; 
				case 4:	//����ʱ
					FreshDisplayBufferAjustHour();
					break; 
				case 5:	//���ڷ�
					FreshDisplayBufferAjustMinute();
					break;
				case 6:	//��������
					FreshDisplayBufferAjustWeek();
					break;  
				case 7:	//��������ģʽ
					FreshDisplayBufferAjustLightMode();
					break;
				case 8:	//����У��ʱ��
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
