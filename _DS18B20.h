#ifndef	_DS18B20_H_
#define	_DS18B20_H_

uint16 ReadDS18B20Count;

//�жϱ�־
unsigned char init_f;     

//��ʱ����
void s_10us(unsigned int ms)
{
	unsigned int aa;
	for(;ms>=2;ms--)
	{
		for(aa=0;aa<=20;aa++)
		{;}
	}
}	

//DS18B20��λ
void ds1820_reset(void) 
{
	unsigned char i;
	//�жϱ���
	init_f = SREG;    
	//���ж�
	cli();      
	DQ_OUT;
	DQ_LO;
	s_10us(25);    //��ʱ500us
	DQ_HI;
	DQ_INPUT;
	s_10us(4);     //��ʱ80us
	i = DQ_R;
	s_10us(25);    //��ʱ500us
	if (init_f & 0x80)  //�ָ��ж�״̬
	{   
		sei();        
	}
}

//DS18B20�ֽڶ�ȡ
unsigned char ds1820_read_byte(void) 
{
	unsigned char i;
	unsigned char value = 0;
	//�жϱ���
	init_f = SREG;
	//���ж�    
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
		s_10us(3);   //��ʱ60us
	}
	if (init_f & 0x80) //�ָ��ж�״̬
	{   
		sei();
	}
	return(value);
}

//DS18B20�ֽ�д��
void ds1820_write_byte(unsigned char value) 
{
	unsigned char i;
	//�жϱ���
	init_f = SREG;   
	//���ж� 
	cli();      
	for (i = 8; i != 0; i--) 
	{
		DQ_OUT;
		DQ_LO;
		s_10us(1);
		if (value & 0x01) 
		{
			DQ_HI;
		}
		s_10us(4);   //��ʱ80us
		DQ_HI;     
		value >>= 1;
	}
	if (init_f & 0x80)//�ָ��ж�״̬
	{   
		sei();
	}
}

//����ds1820ת��
void ds1820_start(void) 
{
	ds1820_reset();
	ds1820_write_byte(0xCC); //����ROM
	ds1820_write_byte(0x44); //����ת��
}

//���¶�
void ReadTemputer(void)
 {
	unsigned int i,tem3,tem2,tem1;
	unsigned char buf[2];
	ds1820_reset();
	ds1820_write_byte(0xCC); //����ROM
	ds1820_write_byte(0xBE); //���¶�
	for (i = 0; i < 2; i++) {
		buf[i] = ds1820_read_byte();
	}
	i = buf[1];
	i <<= 8;
	i |= buf[0];
	tem1 = i & 0x000f;
	tem1 = (tem1*625)/1000;
	i = (i * 10) / 16;        //��ֵ����  
	//��3λû����ʾ
	i = i % 1000;  
	//��ʾ��2λ
	tem3= i / 100;
	TemperatureTen = tem3;
	i = i % 100;  
	//��ʾ��1λ
	tem2= i / 10;
	TemperatureOne = tem2;
	TemperatureDecimal = tem1;
}

#endif
