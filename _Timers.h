/***************************************************************************/
// ����LED3264��������
// ģ�飺��ʱ��
// �ļ���_Timers.h
// ���ߣ������D
// �汾��1.9.7
// ���ڣ�2012��2��10��
// ���ܣ�ʱ�����־�̬��ʾ�����������¶ȹ�����ʾ����ѡ����ģʽ��ʱ�䲹����
// оƬ��Atmega8
// ��˿����λ0x24 ��λ0xD1
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

#ifndef _TIMERS_H_
#define _TIMERS_H_



void timer0_init(void)
{
	TCCR0=0x00;//ֹͣ
	TCNT0=0x00;//�����ʱ��ֵ
	TCCR0=0x79;//����PWMģʽ,ƥ��ʱOC0����,topʱ����,ϵͳʱ��1024��Ƶ,����Ƚ�ƥ�������ʱ��ֵ
	if(RunParameter[18] <= 8)
	{
		SET_DISPLAY_LIGHT;//OCR0�ó�ֵ,ռ�ձ�50%������OCR0��ֵ��������ռ�ձ�
	}
	else
	{
		OCR0 = 0x64;
	}
}

void timer2_init(void)
{

	//TCNT2=0xE6;
	TCCR2 = 0x05;
	TIMSK |= 1<<TOIE2;

}

/*��ʱ��2���жϷ������������ʾ����*/
SIGNAL(SIG_OVERFLOW2)
{
	//2730.58 us 0.002730s
	if( Mode == 0)
	{
		/*
		FreshDisplayBufferCount ++;
		if(FreshDisplayBufferCount > 5000)
		{
			FreshDisplayBufferNormal();
			FreshDisplayBufferCount = 0;
			freshTimeCount = 0;
		}
	
		freshTimeCount ++;
		if(freshTimeCount > 4000)
		{
			Updata_time();
			AjustTimerMonthly();
			freshTimeCount = 0;
		}	
		*/
		ReadDS18B20Count ++;
		if(ReadDS18B20Count == 51250)
		{
			ds1820_start();    
		}
		
		if(ReadDS18B20Count > 60000)
		{
			ReadTemputer(); 
			ReadDS18B20Count = 0;
		}	
		if(!display_light_Mode)
		{
			AD_time_count ++;
			if(AD_time_count == 100)
			{
				StartAD();    
			}
		
			if(AD_time_count > 200)
			{
				GetDispalyLight(); 
				AD_time_count = 0;
			}	
		}
	}
	KEY_Time_count ++;	
	TCNT2=0x00;	
}

#endif
