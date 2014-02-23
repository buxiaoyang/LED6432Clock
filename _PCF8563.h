/***************************************************************************/
// ����LED3264��������
// ģ�飺PCF8563ʱ��оƬ����
// �ļ���_PCF8563.h
// ���ߣ������D
// �汾��1.9.7
// ���ڣ�2012��2��10��
// ���ܣ�ʱ�����־�̬��ʾ�����������¶ȹ�����ʾ����ѡ����ģʽ��ʱ�䲹����
// оƬ��Atmega16
// ��˿����λ0xA4 10100100 ��λ0xD1 11010001
// ���룺AVR GCC
// ���Ŷ��壺	PD0������MODE 
//				PD1: ������ʾģʽ
//				PD2����ʾ������LAT
//				PD3����ʾ������SCK
//				PD4����ʾ���ź�R1
//				PD5����ʾ���ź�R2
// 				PD7���¶ȴ�����DS18B20
//				PC6������UP
//				PC7������DOWN
//				PB0����ʾ������A
//				PB1����ʾ������B
//				PB2����ʾ������C
//				PB3����ʾ������EN
//				PB4����ʾ������D
//				PB6����ʾ������G1
//				PB7����ʾ������G2
//				PA0: ��������
/***************************************************************************/

#ifndef _PCF8563_H_
#define _PCF8563_H_

unsigned char syserr;

unsigned char write_buff[8],read_buff[8];
unsigned char time[7]={
		 	  		   0x40/*��*/,
					   0x59/*��*/,
					   0x23/*ʱ*/,
					   0x29/*��*/,
					   0x05/*����*/,
					   0x02/*��/����*/,
					   0x08/*��*/
};

uint16 freshTimeCount = 0;

//���ָ������ָ�����ȵ�����
void clear(unsigned char *p,unsigned char num)
{
 for(;num>0;num--)
 	{
	 *p=0;
	 p++;
	}
}

//��������: ��PCF8563ָ����ַд��һ������
void PCF8536_wt(unsigned int add,unsigned char data)
{
 unsigned char t;
 t=add>>8;
 t<<=1;
 i2cstart();
 if(i2cwt(W_ADD_COM+t)==SLAW)
 	{
	 i2cwt(add);
	 i2cwt(data);
	}
 else syserr=ERR_SLAW;
 i2cstop();
}

//��������: ��PCF8563��ַ�����ļĴ���д��ϵ������
void PCF8536_wt_p(unsigned int add,unsigned char *p,unsigned char num)
{
 unsigned char t;
 t=add>>8;
 t<<=1;
 i2cstart();
 if(i2cwt(W_ADD_COM+t)==SLAW)
 	{
	 i2cwt(add);
	 for(;num>0;num--)
	 	{
		 i2cwt(*p);
		 p++;
		 asm("nop");
		}
	}
 else syserr=ERR_SLAW;
 i2cstop();
}

//��PCF8563
void PCF8536_rd(unsigned int add,unsigned char *p,unsigned char num)
{
 unsigned char t;
 t=add>>8;
 t<<=1;
 i2cstart();
 if(i2cwt(W_ADD_COM+t)==SLAW)
 	{
	 i2cwt(add);
	}
 else syserr=ERR_SLAW;
 
 i2cstart();
 if(i2cwt(R_ADD_COM+t)==SLAW)
 	{
	 i2cwt(add);
	}
 else syserr=ERR_SLAW;
 
 for(;num>0;num--)
 	{
	 *p=i2crd();
	 p++;
	} 
}

//��������: PCF8563��ʼ��
void PCF8563_init(void)
{
 clear(write_buff,8);
 clear(read_buff,8);
 
 PCF8536_wt(0x00,0x20);//д�Ĵ���1��ֹͣ��ʱ
 //PCF8536_wt_p(0x02,time,7);//�趨ʱ��
 PCF8536_wt(0x00,0x00);//д�Ĵ���1����ʼ��ʱ
}

//ˢ��ʱ��Ĵ����������������
void Updata_time(void)
{
	PCF8536_rd(0x02,time,7);//��ȡʱ��

	time[0]=time[0]&0x7F;
	time[1]=time[1]&0x7F;
	time[2]=time[2]&0x3F;
	time[3]=time[3]&0x3F;
	time[4]=time[4]&0x07;
	time[5]=time[5]&0x1F;
	//time_tmp[]="00:00:00",data_tmp[]="2008.01.01",*week_tmp;
	//����ʱ��
	SecondOne = time[0]&0x0F;
	SecondTen = time[0]>>4;
	MinuteOne = time[1]&0x0F;
	MinuteTen = time[1]>>4;
	HourOne	= time[2]&0x0F;
	HourTen	= time[2]>>4;
	//��������
	DayOne = time[3]&0x0F;
	DayTen = time[3]>>4;
	MonthOne = time[5]&0x0F;
	MonthTen = time[5]>>4;
	YearOne = time[6]&0x0F;
	YearTen = time[6]>>4;
	//��������
	Week = (time[4]&0x0F)+1;
}

void Write_time(void)
{
	uint8 timeWriteBuffer[7] = {(SecondTen<<4)| SecondOne, 
								(MinuteTen<<4)| MinuteOne, 
								(HourTen<<4)| HourOne,
								(DayTen<<4)| DayOne,
								Week-1,
								(MonthTen <<4)| MonthOne,	
								(YearTen <<4)| YearOne,
	};
	PCF8536_wt_p(0x02, timeWriteBuffer, 7);
}

void AjustTimerMonthly()
{
	if(DayTen == 0 && DayOne == 1) // ÿ���µ�һ�� 
	{
		if(HourTen == 0 && HourOne == 3) //����
		{
			if(MinuteTen  == 3 && MinuteOne  == 0) //30��
			{
				if(AjustTimeMode && !AjustTimeIsAjusted) //��ʱ��
				{
					uint8 temp = MinuteTen*10 + MinuteOne;
					temp = temp + AjustTimeTen*10 + AjustTimeOne;
					MinuteTen = temp/10;
					MinuteOne = temp%10;
					Write_time();
					AjustTimeIsAjusted = 1;
				}
				else if(!AjustTimeMode && !AjustTimeIsAjusted) //��ʱ��
				{
					uint8 temp = MinuteTen*10 + MinuteOne;
					temp = temp - AjustTimeTen*10 - AjustTimeOne;
					MinuteTen = temp/10;
					MinuteOne = temp%10;
					Write_time();
					AjustTimeIsAjusted = 1;
				}
			}
			else if(MinuteTen  == 5)
			{
				AjustTimeIsAjusted = 0;
			}

		}
	}
}

#endif
