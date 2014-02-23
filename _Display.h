#ifndef _DISPLAY_H_
#define _DISPLAY_H_

volatile uint8 display_cnt; /*���ڶ�ʱ��ʾ����ܵ�λ��*/
uint8 display_buffer[496]; 	/*��ʾ������*/
uint8 display_buffer_temp[8];
uint16 	halfSecondCount; /*���붨ʱ������*/
uint8 	isSecondCountShow;
uint8 	currentMoveLeft;
uint16  moveSpeedTimerCount;

uint16 FreshDisplayBufferCount; /*ˢ����ʾ����ʱ�������*/

void LED_SCREEN_INI()
{
	LS138_E_DDR |= 1<<LS138_E_BIT;
	LS138_A_DDR |= 1<<LS138_A_BIT;
	LS138_B_DDR |= 1<<LS138_B_BIT;
	LS138_C_DDR |= 1<<LS138_C_BIT;
	LS138_D_DDR |= 1<<LS138_D_BIT;
	HC595_D0_DDR |= 1<<HC595_D0_BIT;
	HC595_D1_DDR |= 1<<HC595_D1_BIT;
	HC595_LAT_DDR |= 1<<HC595_LAT_BIT;
	HC595_SCK_DDR |= 1<<HC595_SCK_BIT;

	display_cnt = 0;
	halfSecondCount = 0;
	isSecondCountShow = 0;
	currentMoveLeft = 0;
	moveSpeedTimerCount = 0;
	FreshDisplayBufferCount = 0;
}

void clearScreen()
{
	memset(display_buffer,0x00,256);
}

void fullScreen()
{
	memset(display_buffer,0xFF,256);
}


void writeCloclColon(uint8 isSecondCountShow)
{
	if(isSecondCountShow)
	{
		display_buffer[36] |= 0xC0;
		display_buffer[44] |= 0xC0;
		display_buffer[52] |= 0xC0;
		display_buffer[35] |= 0x01;
		display_buffer[43] |= 0x01;
		display_buffer[51] |= 0x01;
	
		display_buffer[108] |= 0xC0;
		display_buffer[116] |= 0xC0;
		display_buffer[124] |= 0xC0;
		display_buffer[107] |= 0x01;
		display_buffer[115] |= 0x01;
		display_buffer[123] |= 0x01;
	}
	else
	{
		display_buffer[36] &= 0x3F;
		display_buffer[44] &= 0x3F;
		display_buffer[52] &= 0x3F;
		display_buffer[35] &= 0xFE;
		display_buffer[43] &= 0xFE;
		display_buffer[51] &= 0xFE;
	
		display_buffer[108] &= 0x3F;
		display_buffer[116] &= 0x3F;
		display_buffer[124] &= 0x3F;
		display_buffer[107] &= 0xFE;
		display_buffer[115] &= 0xFE;
		display_buffer[123] &= 0xFE;
	}
}
/*
void writeOneChinese(uint8 x, uint8 y,uint8 index)
{
	uint8 temp;
	uint8 i;
	for(i=0;i<16;i++)
	{
		temp = pgm_read_byte(&CHINESE[index][i*2]);
		display_buffer[(y+i)*8+x] = temp;
		temp = pgm_read_byte(&CHINESE[index][i*2+1]);
		display_buffer[(y+i)*8+x+1] = temp;
	}
	
}
*/
void writeOneUnSCROLL(uint8 x, uint8 y,uint8 index)
{
	uint8 temp;
	uint8 i;
	for(i=0;i<10;i++)
	{
		temp = pgm_read_byte(&SCROLL[index][i]);
		display_buffer[(y+i)*8+x] = temp;
	}	
}

void writeOneSCROLL(uint8 x, uint8 y,uint8 index)
{
	uint8 temp;
	uint8 i;
	for(i=0;i<10;i++)
	{
		temp = pgm_read_byte(&SCROLL[index][i]);
		display_buffer[(y+(i*3))*8+x] = temp;
	}	
}


void wirteOneBigNumber(uint8 x, uint8 y,uint8 index)
{
	uint8 temp,temp1;
	uint8 i;
	for(i=0;i<21;i++)
	{
		temp = pgm_read_byte(&BIG_NUMBER_L[index][i*2]);
		display_buffer[i*8+x] = temp >> y;
		temp1 = pgm_read_byte(&BIG_NUMBER_L[index][i*2+1]);
		display_buffer[i*8+x+1] = (temp << (8-y))|(temp1>>y);
	}
}

void FreshDisplayComment(uint8 *tenValue, uint8 *oneValue, uint8 matrixIndex)
{
	clearScreen();
	writeOneUnSCROLL(0,0,28);
	writeOneUnSCROLL(1,0,29);
	writeOneUnSCROLL(2,0,30);
	wirteOneBigNumber(3,0,*tenValue); 
	wirteOneBigNumber(5,0,*oneValue);
	writeOneUnSCROLL(7,11,matrixIndex);
}

void FreshDisplayBufferAjustYear()
{
	FreshDisplayComment(&YearTen, &YearOne, 10);
	/*
	clearScreen();
	writeOneUnSCROLL(0,0,28);
	writeOneUnSCROLL(1,0,29);
	writeOneUnSCROLL(2,0,30);
	wirteOneBigNumber(3,0,YearTen ); 
	wirteOneBigNumber(5,0,YearOne );
	writeOneUnSCROLL(7,11,10);
	*/
}

void FreshDisplayBufferAjustMonth()
{
	FreshDisplayComment(&MonthTen, &MonthOne, 11);
	/*
	clearScreen();
	writeOneUnSCROLL(0,0,28);
	writeOneUnSCROLL(1,0,29);
	writeOneUnSCROLL(2,0,30);
	wirteOneBigNumber(3,0,MonthTen ); 
	wirteOneBigNumber(5,0,MonthOne );
	writeOneUnSCROLL(7,11,11);
	*/
}

void FreshDisplayBufferAjustDay()
{
	FreshDisplayComment(&DayTen, &DayOne, 20);
	/*
	clearScreen();
	writeOneUnSCROLL(0,0,28);
	writeOneUnSCROLL(1,0,29);
	writeOneUnSCROLL(2,0,30);
	wirteOneBigNumber(3,0,DayTen ); 
	wirteOneBigNumber(5,0,DayOne );
	writeOneUnSCROLL(7,11,20);
	*/
}

void FreshDisplayBufferAjustHour()
{
	FreshDisplayComment(&HourTen, &HourOne, 23);
	/*
	clearScreen();
	writeOneUnSCROLL(0,0,28);
	writeOneUnSCROLL(1,0,29);
	writeOneUnSCROLL(2,0,30);
	wirteOneBigNumber(3,0,HourTen ); 
	wirteOneBigNumber(5,0,HourOne );
	writeOneUnSCROLL(7,11,23);
	*/
}

void FreshDisplayBufferAjustMinute()
{
	FreshDisplayComment(&MinuteTen, &MinuteOne, 24);
	/*
	clearScreen();
	writeOneUnSCROLL(0,0,28);
	writeOneUnSCROLL(1,0,29);
	writeOneUnSCROLL(2,0,30);
	wirteOneBigNumber(3,0,MinuteTen ); 
	wirteOneBigNumber(5,0,MinuteOne );
	writeOneUnSCROLL(7,11,24);
	*/
}

void FreshDisplayBufferAjustWeek()
{
	clearScreen();
	writeOneUnSCROLL(0,0,28);
	writeOneUnSCROLL(1,0,29);
	writeOneUnSCROLL(2,0,30);
	writeOneUnSCROLL(3,11,12); 
	wirteOneBigNumber(5,0,Week );
}


void FreshDisplayBufferAjustLightMode() //����ģʽ
{
	clearScreen();
	writeOneUnSCROLL(0,0,28);
	writeOneUnSCROLL(1,0,29);
	writeOneUnSCROLL(2,0,30);
	if(display_light_Mode) //�ֶ�
	{
		wirteOneBigNumber(3,0,display_light_Mode); 
		writeOneUnSCROLL(5,0,32);
	}
	else
	{
		wirteOneBigNumber(3,0,display_light_Mode); 
		writeOneUnSCROLL(5,0,31);	
	}
	writeOneUnSCROLL(7,0,33);	
	writeOneUnSCROLL(5,13,25);	
	writeOneUnSCROLL(7,13,13);	
}

void FreshDisplayBufferAjustProofTime() //У��ʱ��ģʽ
{
	clearScreen();
	writeOneUnSCROLL(0,0,28);
	writeOneUnSCROLL(1,0,29);
	writeOneUnSCROLL(2,0,30);
	writeOneUnSCROLL(0,11,26);
	writeOneUnSCROLL(1,11,11);
	if(AjustTimeMode) // ��
	{
		writeOneUnSCROLL(2,11,27);	
	}
	else
	{
		writeOneUnSCROLL(2,11,14);	
	}
	wirteOneBigNumber(3,0,AjustTimeTen); 
	wirteOneBigNumber(5,0,AjustTimeOne);
	writeOneUnSCROLL(7,11,24);
}

void FreshDisplayBufferNormal()
{
	clearScreen();
	///// 10�� 11�� 12�� 13�� 14һ 15�� 16�� 17�� 18�� 19�� 20�� 21�� 22�ո�
	wirteOneBigNumber(0,0,HourTen ); 	//8 ʱʮλ
	wirteOneBigNumber(2,0,HourOne );	//9 ʱ��λ
	wirteOneBigNumber(4,3,MinuteTen );	//10 ��ʮλ
	wirteOneBigNumber(6,3,MinuteOne );	//11 �ָ�λ
	writeOneSCROLL(0,23,YearThousand );		//0 ��ǧλ
	writeOneSCROLL(1,23,YearHundred );		//1 ���λ
	writeOneSCROLL(2,23,YearTen );		//2 ��ʮλ
	writeOneSCROLL(3,23,YearOne );		//3 ���λ
	writeOneSCROLL(4,23,10);
	writeOneSCROLL(5,23,MonthTen );		//4 ��ʮλ
	writeOneSCROLL(6,23,MonthOne );		//5 �¸�λ
	writeOneSCROLL(7,23,11);	
	///// 10�� 11�� 12�� 13�� 14һ 15�� 16�� 17�� 18�� 19�� 20�� 21�� 22�ո�
	writeOneSCROLL(0,24,DayTen );		//6 ��ʮλ
	writeOneSCROLL(1,24,DayOne );		//7 �ո�λ
	writeOneSCROLL(2,24,20);
	writeOneSCROLL(4,24,12);
	writeOneSCROLL(5,24,Week +13); 		//14 ����
	writeOneSCROLL(7,24,TemperatureTen );		//15 �¶�ʮλ
	writeOneSCROLL(0,25,TemperatureOne );		//16 �¶ȸ�λ
	writeOneSCROLL(1,25,21);	
	writeOneSCROLL(2,25,TemperatureDecimal );		//17 �¶�С��	
	writeOneSCROLL(3,25,13);	
}


void display()
{
	uint8 i;
	signed char j;
	uint8 k;
	uint8 *ptr0,*ptr1;

	moveSpeedTimerCount++;
	if(moveSpeedTimerCount > (9-moveSpeed)*10) 
	{
		moveSpeedTimerCount = 0;
		currentMoveLeft ++;
		if(currentMoveLeft > 192)
		{
			currentMoveLeft = 0;
		}
	}
	if(Mode == 0)
	{
		halfSecondCount ++;
		if(halfSecondCount > 740) //��0.5s
		{
			halfSecondCount = 0;
			if(isSecondCountShow)
			{
				isSecondCountShow = 0;
				writeCloclColon(0);
			}
			else 
			{
				isSecondCountShow = 1;
				writeCloclColon(1);
			}
		}
	}
	if(display_cnt > 5)
	{
		if(Mode == 0) //������ʾģʽ �����¶ȹ���
		{
		uint8 temp1 = currentMoveLeft>>3;
		uint8 temp2 = currentMoveLeft<<5;
		temp2 = temp2>>5;
		uint16 temp3 = 176+(display_cnt-6)*24+temp1;
		ptr0 = &display_buffer[0+display_cnt*8];
		for(k=0; k<8; k++)
		{
			display_buffer_temp[k] = (display_buffer[temp3+k]<<temp2) | (display_buffer[temp3+k+1]>>(8-temp2));
		}
		ptr1 = display_buffer_temp;
		}
		else //����ģʽ ������
		{
			ptr0 = &display_buffer[0+display_cnt*8];
			ptr1 = &display_buffer[128+display_cnt*8];
		}
	}
	else
	{
		ptr0 = &display_buffer[0+display_cnt*8];
		ptr1 = &display_buffer[128+display_cnt*8];	
	}

	for(i=0;i<8;i++)
	{
		for(j=7;j>=0;j--)
		{
			HC595_D0_H;
			HC595_D1_H;

			if(*ptr0 & 1<<j)
				HC595_D0_L;
			if(*ptr1 & 1<<j)
				HC595_D1_L;
	
			HC595_SCK_L;
			//_delay_us(1);
			HC595_SCK_H;
		}
		ptr0++;
		ptr1++;
	}
	//LS138_E_T_H;
	HC595_LAT_L;
	HC595_LAT_H;
	switch(display_cnt)
	{
		case 0: 
			LS138_D_L;LS138_C_L;LS138_B_L;LS138_A_L;
			break;	
		case 1: 
			LS138_D_L;LS138_C_L;LS138_B_L;LS138_A_H;
			break;
		case 2: 
			LS138_D_L;LS138_C_L;LS138_B_H;LS138_A_L;
			break;	
		case 3: 
			LS138_D_L;LS138_C_L;LS138_B_H;LS138_A_H;
			break;		
		case 4: 
			LS138_D_L;LS138_C_H;LS138_B_L;LS138_A_L;
			break;	
		case 5: 
			LS138_D_L;LS138_C_H;LS138_B_L;LS138_A_H;
			break;
		case 6: 
			LS138_D_L;LS138_C_H;LS138_B_H;LS138_A_L;
			break;
		case 7: 
			LS138_D_L;LS138_C_H;LS138_B_H;LS138_A_H;
			break;	

		case 8: 
			LS138_D_H;LS138_C_L;LS138_B_L;LS138_A_L;
			break;	
		case 9: 
			LS138_D_H;LS138_C_L;LS138_B_L;LS138_A_H;
			break;	
		case 10: 
			LS138_D_H;LS138_C_L;LS138_B_H;LS138_A_L;
			break;	
		case 11: 
			LS138_D_H;LS138_C_L;LS138_B_H;LS138_A_H;
			break;	
		case 12: 
			LS138_D_H;LS138_C_H;LS138_B_L;LS138_A_L;
			break;	
		case 13: 
			LS138_D_H;LS138_C_H;LS138_B_L;LS138_A_H;
			break;	
		case 14: 
			LS138_D_H;LS138_C_H;LS138_B_H;LS138_A_L;
			break;	
		case 15: 
			LS138_D_H;LS138_C_H;LS138_B_H;LS138_A_H;
			break;	

		default: display_cnt=0;break;
	}
	//LS138_E_T_L;
	display_cnt++;
	if(display_cnt==16)display_cnt=0;
}

#endif
