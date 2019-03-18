/***************************************************************************/
// 程序：LED3264电子日历
// 模块：点阵屏显示模块	
// 文件：_Display.h
// 作者：卜晓旸
// 版本：1.9.7
// 日期：2012年2月10日
/***************************************************************************/

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

volatile uint8 display_cnt; /*用于定时显示数码管的位数*/

uint8 display_buffer[496]; 	/*显示缓冲区*/
uint8 display_buffer_second[20]; //second buffer
uint8 display_buffer_temp[8];
uint8 	isSecondCountShow;
uint8 	currentMoveLeft;
uint16  moveSpeedTimerCount;

void LED_SCREEN_INI()
{
	LS138_E_DDR |= 1<<LS138_E_BIT;
	LS138_A_DDR |= 1<<LS138_A_BIT;
	LS138_B_DDR |= 1<<LS138_B_BIT;
	LS138_C_DDR |= 1<<LS138_C_BIT;
	LS138_D_DDR |= 1<<LS138_D_BIT;
	HC595_RED1_DDR |= 1<<HC595_RED1_BIT;
	HC595_RED2_DDR |= 1<<HC595_RED2_BIT;
	HC595_GREEN1_DDR |= 1<<HC595_GREEN1_BIT;
	HC595_GREEN2_DDR |= 1<<HC595_GREEN2_BIT;
	HC595_BLUE1_DDR |= 1<<HC595_BLUE1_BIT;
	HC595_BLUE2_DDR |= 1<<HC595_BLUE2_BIT;
	HC595_LAT_DDR |= 1<<HC595_LAT_BIT;
	HC595_SCK_DDR |= 1<<HC595_SCK_BIT;

	display_cnt = 0;
	isSecondCountShow = 0;
	currentMoveLeft = 0;
	moveSpeedTimerCount = 0;
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
	if(Display_BigNumber_Font == 0)
	{
		for(i=0;i<10;i++)
		{
			temp = pgm_read_byte(&SCROLL_STYLE1[index][i]);
			display_buffer[(y+(i*3))*8+x] = temp;
		}
	}	
	else if(Display_BigNumber_Font == 1)
	{
		for(i=0;i<10;i++)
		{
			temp = pgm_read_byte(&SCROLL_STYLE2[index][i]);
			display_buffer[(y+(i*3))*8+x] = temp;
		}	
	}
	else
	{
		for(i=0;i<10;i++)
		{
			temp = pgm_read_byte(&SCROLL_STYLE3[index][i]);
			display_buffer[(y+(i*3))*8+x] = temp;
		}	
	}	
}

void wirteOneBigNumber(uint8 x, uint8 y,uint8 index)
{
	uint8 temp,temp1;
	uint8 i;
	if(Display_BigNumber_Font == 0)
	{
		for(i=0;i<21;i++)
		{
			temp = pgm_read_byte(&BIG_NUMBER_STYLE1[index][i*2]);
			display_buffer[i*8+x] = temp >> y;
			temp1 = pgm_read_byte(&BIG_NUMBER_STYLE1[index][i*2+1]);
			display_buffer[i*8+x+1] = (temp << (8-y))|(temp1>>y);
		}
	}
	else if(Display_BigNumber_Font == 1)
	{
		for(i=0;i<21;i++)
		{
			temp = pgm_read_byte(&BIG_NUMBER_STYLE2[index][i*2]);
			display_buffer[i*8+x] = temp >> y;
			temp1 = pgm_read_byte(&BIG_NUMBER_STYLE2[index][i*2+1]);
			display_buffer[i*8+x+1] = (temp << (8-y))|(temp1>>y);
		}
	}
	else
	{
		for(i=0;i<21;i++)
		{
			temp = pgm_read_byte(&BIG_NUMBER_STYLE3[index][i*2]);
			display_buffer[i*8+x] = temp >> y;
			temp1 = pgm_read_byte(&BIG_NUMBER_STYLE3[index][i*2+1]);
			display_buffer[i*8+x+1] = (temp << (8-y))|(temp1>>y);
		}
	}
}

void FreshDisplayComment(uint8 *tenValue, uint8 *oneValue, uint8 matrixIndex)
{
	clearScreen();
	
	writeOneChinese(0, 0, 8);	
	writeOneChinese(0, 16, 9);
	wirteOneBigNumber(2,0,*tenValue); 
	wirteOneBigNumber(4,0,*oneValue);
	writeOneChinese(6, 16, matrixIndex);
}

void FreshDisplayBufferAjustYear()
{
	FreshDisplayComment(&YearTen, &YearOne, 15);
}

void FreshDisplayBufferAjustMonth()
{
	FreshDisplayComment(&MonthTen, &MonthOne, 16);
}

void FreshDisplayBufferAjustDay()
{
	FreshDisplayComment(&DayTen, &DayOne, 17);
}

void FreshDisplayBufferAjustHour()
{
	FreshDisplayComment(&HourTen, &HourOne, 13);
}

void FreshDisplayBufferAjustMinute()
{
	FreshDisplayComment(&MinuteTen, &MinuteOne, 18);
}

void FreshDisplayBufferAjustWeek()
{
	clearScreen();
	writeOneChinese(0, 0, 8);	
	writeOneChinese(2, 0, 9);
	writeOneChinese(0, 16, 21);
	writeOneChinese(2, 16, 22);
	writeOneUnSCROLL(4,22,30);
	wirteOneBigNumber(5,0,Week);
}

void FreshDisplayBufferAjustSpeed()
{
	clearScreen();
	writeOneChinese(0, 0, 8);	
	writeOneChinese(2, 0, 9);
	writeOneChinese(0, 16, 10);
	writeOneChinese(2, 16, 11);
	writeOneUnSCROLL(4,22,30);
	wirteOneBigNumber(5,0,moveSpeed);
}

void FreshDisplayBufferVoiceMode()
{
	clearScreen();
	writeOneChinese(0, 0,40);	
	writeOneChinese(2, 0, 41);
	writeOneChinese(0, 16, 42);
	writeOneChinese(2, 16, 13);
	writeOneUnSCROLL(4,22,30);
	if(Voice_Mode == 0)
	{
		writeOneChinese(6, 0, 43);
		writeOneChinese(6, 16, 44);
	}
	else if(Voice_Mode == 1)
	{
		writeOneChinese(6, 0, 45);
		writeOneChinese(6, 16, 46);
	}
	else
	{
		writeOneChinese(6, 0, 47);
		writeOneChinese(6, 16, 48);
	}
}

void FreshDisplayBufferAjustLightMode() //亮度模式
{
	clearScreen();
	writeOneChinese(0, 0, 8);	
	writeOneChinese(2, 0, 9);
	writeOneChinese(0, 16, 12);
	writeOneChinese(2, 16, 11);
	writeOneUnSCROLL(4,22,30);
	if(display_light_Mode) //手动
	{
		writeOneChinese(6, 0, 25);
	}
	else
	{
		writeOneChinese(6, 0, 24);
	}
	writeOneChinese(6, 16, 26);
}

void FreshDisplayBufferAjustLight()
{
	clearScreen();
	if(display_light_Mode)
	{
		writeOneChinese(0, 0, 8);	
		writeOneChinese(2, 0, 9);
		writeOneChinese(0, 16, 12);
		writeOneChinese(2, 16, 11);
		writeOneUnSCROLL(4,22,30);
		wirteOneBigNumber(5,0,display_light);
	}
	else
	{
		FreshDisplayBufferAjustLightMode();
	}
}

void FreshDisplayBufferChangeFont()
{
	clearScreen();
	writeOneChinese(0, 0, 8);	
	writeOneChinese(2, 0, 9);
	writeOneChinese(0, 16, 27);
	writeOneChinese(2, 16, 28);
	writeOneUnSCROLL(4,22,30);
	wirteOneBigNumber(5,0,3);
}

void FreshDisplayBufferAjustProofTime() //校对时间模式
{
	clearScreen();
	writeOneChinese(0, 0, 29);
	writeOneChinese(0, 16,13);	
	writeOneUnSCROLL(6,22,26); //每
	writeOneUnSCROLL(7,22,11);	//月
	if(AjustTimeMode) // 加
	{
		writeOneUnSCROLL(2,22,27);	 //加
	}
	else
	{
		writeOneUnSCROLL(2,22,33);	//减
	}
	wirteOneBigNumber(3,0,AjustTimeTen); 
	wirteOneBigNumber(5,0,AjustTimeOne);
	writeOneUnSCROLL(7,11,24); //分
}

void FreshDisplayBufferNormal()
{
	clearScreen();
	///// 10年 11月 12周 13度 14一 15二 16三 17四 18五 19六 20日 21点 22空格
	
	wirteOneBigNumber(0,0,HourTen ); 	//8 时十位
	wirteOneBigNumber(2,0,HourOne );	//9 时个位
	wirteOneBigNumber(4,3,MinuteTen );	//10 分十位
	wirteOneBigNumber(6,3,MinuteOne );	//11 分个位
	
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
	writeOneSCROLL(4,24,12);
	writeOneSCROLL(5,24,Week +13); 		//14 星期
	writeOneSCROLL(7,24,TemperatureTen );		//15 温度十位
	writeOneSCROLL(0,25,TemperatureOne );		//16 温度个位
	writeOneSCROLL(1,25,21);	
	writeOneSCROLL(2,25,TemperatureDecimal );		//17 温度小数	
	writeOneSCROLL(3,25,13);	
}

void FreshDisplayBufferSecond() //Second update
{	
	uint8 temp;
	uint8 i;
	if(Display_BigNumber_Font == 0)
	{
		for(i=0;i<10;i++)
		{
			temp = pgm_read_byte(&SCROLL_STYLE1[SecondTen][i]);
			display_buffer_second[i] = temp;
		}
		for(i=0;i<10;i++)
		{
			temp = pgm_read_byte(&SCROLL_STYLE1[SecondOne][i]);
			display_buffer_second[i+10] = temp;
		}
	}	
	else if(Display_BigNumber_Font == 1)
	{
		for(i=0;i<10;i++)
		{
			temp = pgm_read_byte(&SCROLL_STYLE2[SecondTen][i]);
			display_buffer_second[i] = temp;
		}
		for(i=0;i<10;i++)
		{
			temp = pgm_read_byte(&SCROLL_STYLE2[SecondOne][i]);
			display_buffer_second[i+10] = temp;
		}
	}
	else
	{
		for(i=0;i<10;i++)
		{
			temp = pgm_read_byte(&SCROLL_STYLE3[SecondTen][i]);
			display_buffer_second[i] = temp;
		}
		for(i=0;i<10;i++)
		{
			temp = pgm_read_byte(&SCROLL_STYLE3[SecondOne][i]);
			display_buffer_second[i+10] = temp;
		}
	}	
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
	HC595_LAT_L;
	/*
	if(Mode == 0)
	{
		halfSecondCount ++;
		if(halfSecondCount > 940) //到0.5s
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
	*/
	if(display_cnt > 5)
	{
		if(Mode == 0) //正常显示模式 日期温度滚动
		{
			uint8 temp1 = currentMoveLeft>>3;
			uint8 temp2 = currentMoveLeft<<5;
			temp2 = temp2>>5;
			uint16 temp3 = 176+(display_cnt-6)*24+temp1;
			ptr0 = &display_buffer[0+display_cnt*8];
			for(k=0; k<6; k++)
			{
				display_buffer_temp[k] = (display_buffer[temp3+k]<<temp2) | (display_buffer[temp3+k+1]>>(8-temp2));
			}
			display_buffer_temp[5] &= 0xFE;
			display_buffer_temp[6] = display_buffer_second[display_cnt-6];
			display_buffer_temp[7] = display_buffer_second[display_cnt+4];
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
	if(Display_color == 0)
	{
	/*  */
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_RED1_H;
				}
				if(*ptr1 & 1<<j)
				{
					HC595_RED2_H;
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 1)
	{
	/*	*/
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_GREEN1_H;
				}
				if(*ptr1 & 1<<j)
				{
					HC595_GREEN2_H;
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 2)
	{
	/*	*/
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_RED1_H;
					HC595_GREEN1_H;
				}
				if(*ptr1 & 1<<j)
				{
					HC595_RED2_H;
					HC595_GREEN2_H;
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 3)
	{
	/*	*/
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_BLUE1_H;
				}
				if(*ptr1 & 1<<j)
				{
					HC595_BLUE2_H;
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 4)
	{
	/*	*/
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_GREEN1_H;
					HC595_BLUE1_H;
				}
				if(*ptr1 & 1<<j)
				{
					HC595_GREEN2_H;
					HC595_BLUE2_H;
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 5)
	{
	/*	*/
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_RED1_H;
					HC595_BLUE1_H;
				}
				if(*ptr1 & 1<<j)
				{
					HC595_RED2_H;
					HC595_BLUE2_H;
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 6)
	{
	/*	*/
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_RED1_H;
					HC595_GREEN1_H;
					HC595_BLUE1_H;
				}
				if(*ptr1 & 1<<j)
				{
					HC595_RED2_H;
					HC595_GREEN2_H;
					HC595_BLUE2_H;
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 7)
	{
	/* 红，绿，黄 */
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_RED1_H;
				}
				if(display_cnt > 5 && i < 6)
				{

					if(*ptr1 & 1<<j)
					{
						HC595_GREEN2_H;
					}
				}
				else if(display_cnt > 5 && i >= 6)
				{
					if(*ptr1 & 1<<j)
					{
						HC595_RED2_H;
						HC595_GREEN2_H;
					}	
				}
				else
				{
					if(*ptr1 & 1<<j)
					{
						HC595_RED2_H;
					}	
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 8)
	{
	/*红，绿，蓝 */
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_RED1_H;
				}
				if(display_cnt > 5 && i < 6)
				{

					if(*ptr1 & 1<<j)
					{
						HC595_GREEN2_H;
					}
				}
				else if(display_cnt > 5 && i >= 6)
				{
					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
					}	
				}
				else
				{
					if(*ptr1 & 1<<j)
					{
						HC595_RED2_H;
					}	
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 9)
	{
	/* 绿，蓝，紫 */
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_GREEN1_H;
				}
				if(display_cnt > 5 && i < 6)
				{

					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
					}
				}
				else if(display_cnt > 5 && i >= 6)
				{
					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
						HC595_RED2_H;
					}	
				}
				else
				{
					if(*ptr1 & 1<<j)
					{
						HC595_GREEN2_H;
					}	
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 10)
	{
	/* 绿，蓝，黄 */
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_GREEN1_H;
				}
				if(display_cnt > 5 && i < 6)
				{

					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
					}
				}
				else if(display_cnt > 5 && i >= 6)
				{
					if(*ptr1 & 1<<j)
					{
						HC595_RED2_H;
						HC595_GREEN2_H;
					}	
				}
				else
				{
					if(*ptr1 & 1<<j)
					{
						HC595_GREEN2_H;
					}	
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 11)
	{
	/* 蓝，紫，黄 */
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_BLUE1_H;
				}
				if(display_cnt > 5 && i < 6)
				{

					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
						HC595_RED2_H;
					}
				}
				else if(display_cnt > 5 && i >= 6)
				{
					if(*ptr1 & 1<<j)
					{
						HC595_RED2_H;
						HC595_GREEN2_H;
					}	
				}
				else
				{
					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
					}	
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 12)
	{
	/* 蓝，紫，青 */
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_BLUE1_H;
				}
				if(display_cnt > 5 && i < 6)
				{

					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
						HC595_RED2_H;
					}
				}
				else if(display_cnt > 5 && i >= 6)
				{
					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
						HC595_GREEN2_H;
					}	
				}
				else
				{
					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
					}	
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 13)
	{
	/* 紫，黄，青 */
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_BLUE1_H;
					HC595_RED1_H;
				}
				if(display_cnt > 5 && i < 6)
				{

					if(*ptr1 & 1<<j)
					{
						HC595_RED2_H;
						HC595_GREEN2_H;
					}
				}
				else if(display_cnt > 5 && i >= 6)
				{
					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
						HC595_GREEN2_H;
					}	
				}
				else
				{
					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
						HC595_RED2_H;
					}	
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 14)
	{
	/* 紫，蓝，白 */
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_BLUE1_H;
					HC595_RED1_H;
				}
				if(display_cnt > 5 && i < 6)
				{

					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
					}
				}
				else if(display_cnt > 5 && i >= 6)
				{
					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
						HC595_RED2_H;
						HC595_GREEN2_H;
					}	
				}
				else
				{
					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
						HC595_RED2_H;
					}	
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 15)
	{
	/* 黄，青，白 */
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_RED1_H;
					HC595_GREEN1_H;
				}
				if(display_cnt > 5 && i < 6)
				{

					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
						HC595_GREEN2_H;
					}
				}
				else if(display_cnt > 5 && i >= 6)
				{
					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
						HC595_RED2_H;
						HC595_GREEN2_H;
					}	
				}
				else
				{
					if(*ptr1 & 1<<j)
					{
						HC595_RED2_H;
						HC595_GREEN2_H;
					}	
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 16)
	{
	/* 黄，红，绿 */
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_RED1_H;
					HC595_GREEN1_H;
				}
				if(display_cnt > 5 && i < 6)
				{

					if(*ptr1 & 1<<j)
					{
						HC595_RED2_H;
					}
				}
				else if(display_cnt > 5 && i >= 6)
				{
					if(*ptr1 & 1<<j)
					{
						HC595_GREEN2_H;
					}	
				}
				else
				{
					if(*ptr1 & 1<<j)
					{
						HC595_RED2_H;
						HC595_GREEN2_H;
					}	
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 17)
	{
	/* 青，白，紫 */
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_BLUE1_H;
					HC595_GREEN1_H;
				}
				if(display_cnt > 5 && i < 6)
				{

					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
						HC595_RED2_H;
						HC595_GREEN2_H;
					}
				}
				else if(display_cnt > 5 && i >= 6)
				{
					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
						HC595_RED2_H;
					}	
				}
				else
				{
					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
						HC595_GREEN2_H;
					}	
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	else if(Display_color == 18)
	{
	/* 青，蓝，绿 */
		for(i=0;i<8;i++)
		{
			for(j=7;j>=0;j--)
			{
				HC595_RED1_L;
				HC595_RED2_L;
				HC595_GREEN1_L;
				HC595_GREEN2_L;
				HC595_BLUE1_L;
				HC595_BLUE2_L;
				if(*ptr0 & 1<<j)
				{
					HC595_BLUE1_H;
					HC595_GREEN1_H;
				}
				if(display_cnt > 5 && i < 6)
				{

					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
					}
				}
				else if(display_cnt > 5 && i >= 6)
				{
					if(*ptr1 & 1<<j)
					{
						HC595_GREEN2_H;
					}	
				}
				else
				{
					if(*ptr1 & 1<<j)
					{
						HC595_BLUE2_H;
						HC595_GREEN2_H;
					}	
				}
				HC595_SCK_L;
				HC595_SCK_H;
			}
			ptr0++;
			ptr1++;
		}
		
	}
	//LS138_E_T_H;
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

void Show_welcome()
{
	uint16 timer_count;
	Mode = 28;
	writeOneChinese(0, 0, 0);	
	writeOneChinese(2, 0, 1);
	writeOneChinese(4, 0, 2);
	writeOneChinese(6, 0, 3);
	writeOneChinese(0, 16, 4);	
	writeOneChinese(2, 16, 5);
	writeOneChinese(4, 16, 6);
	writeOneChinese(6, 16, 7);
	for(timer_count=0; timer_count< 5000; timer_count++)
	{
		display();
		s_10us(10); //延迟10ms
	}
	clearScreen();
	Mode = 0;
}

#endif
