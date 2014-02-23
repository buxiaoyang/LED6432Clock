#ifndef _TIMERS_H_
#define _TIMERS_H_



void timer0_init(void)
{
	TCCR0=0x00;//停止
	TCNT0=0x00;//清除定时器值
	TCCR0=0x79;//快速PWM模式,匹配时OC0清零,top时置数,系统时钟1024分频,输出比较匹配清除定时器值
	if(RunParameter[18] <= 8)
	{
		SET_DISPLAY_LIGHT;//OCR0置初值,占空比50%，调整OCR0的值用来调整占空比
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

/*定时器2的中断服务程序，用于显示处理*/
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
