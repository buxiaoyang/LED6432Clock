/***************************************************************************/
// 程序：LED3264电子日历
// 模块：DS18B20温度传感器驱动模块
// 文件：_DS18B20.h
// 作者：卜晓旸
// 版本：1.9.7
// 日期：2012年2月10日
/***************************************************************************/

#ifndef	_DS18B20_H_
#define	_DS18B20_H_

uint16 ReadDS18B20Count;
//中断标志
unsigned char init_f; 

unsigned char out_put = 0;    

//延时函数
void s_10us(unsigned int _10us)
{
	unsigned char aa;
	for(;_10us>=1;_10us--)
	{
		for(aa = 0;aa< 9; aa ++)
		{
			asm("nop");
		}
	}

	//test code
	/*
	if(out_put)
	{
		INFR_H;
		out_put = 0;
	}
	else
	{
		INFR_L;
		out_put = 1;
	}
	*/
	//test code
}	

void _delay_100ms(unsigned int _100ms)
{
	for(;_100ms>=1;_100ms--)
	{
		s_10us(10000);
	}
}

//DS18B20复位
void ds1820_reset(void) 
{
	unsigned char i;
	//中断保护
	init_f = SREG;    
	//关中断
	cli();      
	DQ_OUT;
	DQ_LO;
	s_10us(60);    //延时600us
	DQ_HI;
	DQ_INPUT;
	s_10us(5);     //延时50us
	i = DQ_R;
	s_10us(50);    //延时500us
	if (init_f & 0x80)  //恢复中断状态
	{   
		sei();        
	}
}

//DS18B20字节读取
unsigned char ds1820_read_byte(void) 
{
	unsigned char i;
	unsigned char value = 0;
	//中断保护
	init_f = SREG;
	//关中断    
	cli();      
	for (i = 8; i != 0; i--) 
	{
		value >>= 1;
		DQ_OUT;
		DQ_LO;
		s_10us(1);
		DQ_HI;
		DQ_INPUT;
		s_10us(1);
		if (DQ_R) 
		{
			value|=0x80;
		}
		s_10us(3);   //延时30us
	}
	if (init_f & 0x80) //恢复中断状态
	{   
		sei();
	}
	return(value);
}

//DS18B20字节写入
void ds1820_write_byte(unsigned char value) 
{
	unsigned char i;
	//中断保护
	init_f = SREG;   
	//关中断 
	cli();      
	for (i = 8; i != 0; i--) 
	{
		DQ_OUT;
		DQ_LO;
		s_10us(1); //延时10us
		if (value & 0x01) 
		{
			DQ_HI;
		}
		s_10us(4);   //延时40us
		DQ_HI;     
		value >>= 1;
	}
	if (init_f & 0x80)//恢复中断状态
	{   
		sei();
	}
}

//启动ds1820转换
void ds1820_start(void) 
{
	ds1820_reset();
	ds1820_write_byte(0xCC); //勿略ROM
	ds1820_write_byte(0x44); //启动转换
}

//读温度
void ReadTemputer(void)
 {
	unsigned int i,tem3,tem2,tem1;
	unsigned char buf[2], NegativeTem;
	ds1820_reset();
	ds1820_write_byte(0xCC); //勿略ROM
	ds1820_write_byte(0xBE); //读温度
	for (i = 0; i < 2; i++) {
		buf[i] = ds1820_read_byte();
	}
	//uart_send_char(buf[0]);
	//uart_send_char(buf[1]);
	//uart_send_char(0XAA);
	i = buf[1];
	i <<= 8;
	i |= buf[0];
	if((i & 0xF000) == 0xF000) //负温度
	{
		NegativeTem = 1;
		i = ~i;
		i = i + 1;
	}
	else
	{
		NegativeTem = 0;
	}
	tem1 = i & 0x000f;
	tem1 = (tem1*625)/1000;
	i = (i * 10) / 16;        //数值处理  
	//第3位没有显示
	i = i % 1000;  
	//显示第2位
	tem3= i / 100;
	if(NegativeTem == 1)
	{
		TemperatureTen = 14; // - 符号
	}
	else
	{
		TemperatureTen = tem3;
	}
	i = i % 100;  
	//显示第1位
	tem2= i / 10;
	TemperatureOne = tem2;
	TemperatureDecimal = tem1;
}

#endif
