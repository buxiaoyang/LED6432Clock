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
		FreshDisplayBufferCount ++;
		if(FreshDisplayBufferCount > 21000)
		{
			FreshDisplayBufferNormal();
			FreshDisplayBufferCount = 0;
			freshTimeCount = 0;
		}
	
		freshTimeCount ++;
		if(freshTimeCount > 16000)
		{
			Updata_time();
			freshTimeCount = 0;
		}	
		ReadDS18B20Count ++;
		if(ReadDS18B20Count == 60000)
		{
			ds1820_start();    
		}
		
		if(ReadDS18B20Count > 61250)
		{
			ReadTemputer(); 
			ReadDS18B20Count = 0;
		}	
	}	
	TCNT2=0x00;	
}

#endif
