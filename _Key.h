/***************************************************************************/
// ����LED3264��������
// ģ�飺����ɨ��
// �ļ���_Key.h
// ���ߣ������D
// �汾��1.9.7
// ���ڣ�2012��2��10��
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
			SPEEK_TIME_Status = 100; //������
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
			SPEEK_TIME_Status = 100; //������
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
		//����ʱ�䵽ʱ��оƬ
		Write_time();
		//�������в�����eepROM
		SaveRunParameter();
		clearScreen(); //����
		FreshDisplayBufferNormal(); //����������ʱģʽ
	}
	
	if(Mode == 27 || Mode == 26)
	{
		if(KEY_Time_count_speed_color > 500)
		{
			Mode = 0;
			SaveRunParameter();
			FreshDisplayBufferNormal(); //����������ʱģʽ
		}
	}

	if(KEY_DISPLAY_COLOR_L) //��ʾ��ɫ����
	{
		_delay_ms(10);
		if(KEY_DISPLAY_COLOR_L)
		{
			SPEEK_TIME_Status = 1;
			Display_color ++;
			if(Display_color > 4)
			{
				Display_color = 0;
			}
			SaveRunParameter();
		}
		while(KEY_DISPLAY_COLOR_L);	
	}

	if(Mode == 0 || Mode== 27 || Mode == 26) //��������ģʽ �����ٶȺ�����ģʽ
	{

		if(KEY_UP_L) //���ȵ���
		{
			_delay_ms(10);
			if(KEY_UP_L)
			{
				SPEEK_TIME_Status = 100; //������
				if(display_light_Mode) //�ֶ���������ģʽ
				{
					display_light ++;
					if(display_light > 8)
					{
						display_light = 1;
					}
					SET_DISPLAY_LIGHT;//OCR0�ó�ֵ,ռ�ձ�50%������OCR0��ֵ��������ռ�ձ�
				}
				else //�Զ���������ģʽ
				{
				
				}
				Mode = 27;
				KEY_Time_count_speed_color = 0;
				FreshDisplayBufferAjustLight();
			}
			while(KEY_UP_L);	
		}
	
		if(KEY_DOWN_L) //�ٶȵ���
		{
			_delay_ms(10);
			if(KEY_DOWN_L)
			{
				SPEEK_TIME_Status = 100; //������
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
	else if(Mode == 8) //��������
	{
		uint8 temp = 0;
		Key_Operation(2, 0, &temp, &Display_BigNumber_Font, &FreshDisplayBufferChangeFont);
	}
	else if(Mode == 9) //����У��ʱ��
	{
		if(KEY_UP_L) 
		{
			_delay_ms(10);
			if(KEY_UP_L)
			{
				KEY_Time_count = 0;
				SPEEK_TIME_Status = 100; //������
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
				SPEEK_TIME_Status = 100; //������
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
	else if(Mode == 10) //��ʱ
	{
		uint8 temp = 0;
		Key_Operation(2, 0, &temp, &Voice_Mode, &FreshDisplayBufferVoiceMode);
	}
	//////////////////////////////////////////////////////////
	if(KEY_MODE_L) //ģʽ����
	{
		_delay_ms(10);
		if(KEY_MODE_L)
		{
			SPEEK_TIME_Status = 100; //������
			KEY_Time_count = 0;
			Mode ++;
			if(Mode > 10)
			{
				Mode = 0;
			}
			switch(Mode){
				case 0:	//��������
					//����ʱ�䵽ʱ��оƬ
					Write_time();
					//�������в�����eepROM
					SaveRunParameter();
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
				case 8:	//��������
					FreshDisplayBufferChangeFont();
					break;
				case 9:	//����У��ʱ��
					FreshDisplayBufferAjustProofTime();
					break; 
				case 10://����������ʱ
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
