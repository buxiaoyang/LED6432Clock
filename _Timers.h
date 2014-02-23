/***************************************************************************/
// ����LED3264��������
// ģ�飺��ʱ��
// �ļ���_Timers.h
// ���ߣ������D
// �汾��1.9.7
// ���ڣ�2012��2��10��
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
	KEY_Time_count_speed_color ++;
	TCNT2=0x00;	
}

#endif
