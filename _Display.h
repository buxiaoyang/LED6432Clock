#ifndef _DISPLAY_H_
#define _DISPLAY_H_

volatile uint8 display_cnt; /*用于定时显示数码管的位数*/
uint8 display_buffer[496]; 	/*显示缓冲区*/
uint8 display_buffer_temp[8];
uint16 	halfSecondCount; /*半秒定时计数器*/
uint8 	isSecondCountShow;
uint8 	currentMoveLeft;
uint16  moveSpeedTimerCount;

uint16 FreshDisplayBufferCount; /*刷新显示缓存时间计数器*/

void LED_SCREEN_INI()
{
	LS138_E_DDR |= 1<<LS138_E_BIT;
	//LS138_E_T_DDR |= 1<<LS138_E_T_BIT;
	LS138_A_DDR |= 1<<LS138_A_BIT;
	LS138_B_DDR |= 1<<LS138_B_BIT;
	LS138_C_DDR |= 1<<LS138_C_BIT;
	LS138_D_DDR |= 1<<LS138_D_BIT;
	HC595_D0_DDR |= 1<<HC595_D0_BIT;
	HC595_D1_DDR |= 1<<HC595_D1_BIT;
	HC595_LAT_DDR |= 1<<HC595_LAT_BIT;
	HC595_SCK_DDR |= 1<<HC595_SCK_BIT;
	//LS138_E_T_L;
	LS138_A_L;
	LS138_B_L;
	LS138_C_L;
	LS138_D_L;
	HC595_D0_L;
	HC595_D1_L;
	HC595_LAT_L;
	HC595_SCK_L;
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
	if(y) //左
	{
		for(i=0;i<21;i++)
		{
			temp = pgm_read_byte(&BIG_NUMBER_L[index][i*2]);
			display_buffer[i*8+x] = temp;
			temp = pgm_read_byte(&BIG_NUMBER_L[index][i*2+1]);
			display_buffer[i*8+x+1] = temp;
		}
	}
	else  //右
	{
		for(i=0;i<21;i++)
		{
			temp = pgm_read_byte(&BIG_NUMBER_L[index][i*2]);
			display_buffer[i*8+x] = temp >> 3;
			temp1 = pgm_read_byte(&BIG_NUMBER_L[index][i*2+1]);
			display_buffer[i*8+x+1] = (temp << 5)|(temp1>>3);
		}
	}
}

void FreshDisplayBufferAjustYear()
{
	writeOneChinese(0, 0, 10);
	writeOneChinese(2, 0, 11);
	writeOneChinese(4, 0, 12);
	writeOneChinese(6, 0, 13);
	writeOneChinese(0, 16, YearTen );
	writeOneChinese(2, 16, YearOne );
	writeOneChinese(4, 16, 16);
	writeOneChinese(6, 16, 31);
}

void FreshDisplayBufferAjustMonth()
{
	writeOneChinese(0, 0, 10);
	writeOneChinese(2, 0, 11);
	writeOneChinese(4, 0, 12);
	writeOneChinese(6, 0, 13);
	writeOneChinese(0, 16, MonthTen);
	writeOneChinese(2, 16, MonthOne);
	writeOneChinese(4, 16, 17);
	writeOneChinese(6, 16, 31);
}

void FreshDisplayBufferAjustDay()
{
	writeOneChinese(0, 0, 10);
	writeOneChinese(2, 0, 11);
	writeOneChinese(4, 0, 12);
	writeOneChinese(6, 0, 13);
	writeOneChinese(0, 16, DayTen);
	writeOneChinese(2, 16, DayOne);
	writeOneChinese(4, 16, 12);
	writeOneChinese(6, 16, 31);
}

void FreshDisplayBufferAjustHour()
{
	writeOneChinese(0, 0, 10);
	writeOneChinese(2, 0, 11);
	writeOneChinese(4, 0, 14);
	writeOneChinese(6, 0, 15);
	writeOneChinese(0, 16, HourTen);
	writeOneChinese(2, 16, HourOne);
	writeOneChinese(4, 16, 14);
	writeOneChinese(6, 16, 31);
}

void FreshDisplayBufferAjustMinute()
{
	writeOneChinese(0, 0, 10);
	writeOneChinese(2, 0, 11);
	writeOneChinese(4, 0, 14);
	writeOneChinese(6, 0, 15);
	writeOneChinese(0, 16, MinuteTen );
	writeOneChinese(2, 16, MinuteOne );
	writeOneChinese(4, 16, 19);
	writeOneChinese(6, 16, 31);
}

void FreshDisplayBufferAjustWeek()
{
	writeOneChinese(0, 0, 10);
	writeOneChinese(2, 0, 11);
	writeOneChinese(4, 0, 32);
	writeOneChinese(6, 0, 13);
	writeOneChinese(0, 16, 33);
	if(Week == 7)
	{
		writeOneChinese(2, 16, 12);
	}
	else
	{
		writeOneChinese(2, 16, Week + 33);
	}
	writeOneChinese(4, 16, 31);
	writeOneChinese(6, 16, 31);
}


void FreshDisplayBufferAjustLightMode() //亮度模式
{
	writeOneChinese(0, 0, 20);
	writeOneChinese(2, 0, 21);
	writeOneChinese(4, 0, 22);
	writeOneChinese(6, 0, 23);
	if(display_light_Mode)
	{
		writeOneChinese(0, 16, 26);
	}
	else
	{
		writeOneChinese(0, 16, 24);		
	}
	writeOneChinese(2, 16, 25);
	writeOneChinese(4, 16, 31);
	writeOneChinese(6, 16, 31);
}

void FreshDisplayBufferAjustProofTime() //校对时间模式
{
	writeOneChinese(0, 0, 27);
	writeOneChinese(2, 0, 17);
	writeOneChinese(4, 0, 28);
	writeOneChinese(6, 0, 14);
	if(AjustTimeMode)
	{
		writeOneChinese(0, 16, 29);		
	}
	else
	{
		writeOneChinese(0, 16, 30);		
	}
	writeOneChinese(2, 16, AjustTimeTen);
	writeOneChinese(4, 16, AjustTimeOne);
	writeOneChinese(6, 16, 19);
}

void FreshDisplayBufferNormal()
{
	///// 10年 11月 12周 13度 14一 15二 16三 17四 18五 19六 20日 21点 22空格
	wirteOneBigNumber(0,1,HourTen ); 	//8 时十位
	wirteOneBigNumber(2,1,HourOne );	//9 时个位
	wirteOneBigNumber(4,0,MinuteTen );	//10 分十位
	wirteOneBigNumber(6,0,MinuteOne );	//11 分个位
	
	writeOneSCROLL(0,22,22);
	writeOneSCROLL(1,22,22);
	writeOneSCROLL(2,22,22);
	writeOneSCROLL(3,22,22);
	writeOneSCROLL(4,22,22);
	writeOneSCROLL(5,22,22);
	writeOneSCROLL(6,22,22);
	writeOneSCROLL(7,22,22);

	writeOneSCROLL(0,23,YearThousand );		//0 年千位
	writeOneSCROLL(1,23,YearHundred );		//1 年百位
	writeOneSCROLL(2,23,YearTen );		//2 年十位
	writeOneSCROLL(3,23,YearOne );		//3 年个位
	writeOneSCROLL(4,23,10);
	writeOneSCROLL(5,23,MonthTen );		//4 月十位
	writeOneSCROLL(6,23,MonthOne );		//5 月个位
	writeOneSCROLL(7,23,11);	

	///// 10年 11月 12周 13度 14一 15二 16三 17四 18五 19六 20日 21点 22空格

	writeOneSCROLL(0,24,DayTen );		//6 日十位
	writeOneSCROLL(1,24,DayOne );		//7 日个位
	writeOneSCROLL(2,24,20);
	writeOneSCROLL(3,24,22);
	writeOneSCROLL(4,24,12);
	writeOneSCROLL(5,24,Week +13); 		//14 星期
	writeOneSCROLL(6,24,22); 
	writeOneSCROLL(7,24,TemperatureTen );		//15 温度十位

	writeOneSCROLL(0,25,TemperatureOne );		//16 温度个位
	writeOneSCROLL(1,25,21);	
	writeOneSCROLL(2,25,TemperatureDecimal );		//17 温度小数	
	writeOneSCROLL(3,25,13);	
	writeOneSCROLL(4,25,22);
	writeOneSCROLL(5,25,22);
	writeOneSCROLL(6,25,22);
	writeOneSCROLL(7,25,22); 
	
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
		if(halfSecondCount > 740) //到0.5s
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
		if(Mode == 0) //正常显示模式 日期温度滚动
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
		else //设置模式 不滚动
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
