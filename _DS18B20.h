/***************************************************************************/
// ����LED3264��������
// ģ�飺DS18B20�¶ȴ���������ģ��
// �ļ���_DS18B20.h
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

#ifndef	_DS18B20_H_
#define	_DS18B20_H_

uint16 ReadDS18B20Count;
//�жϱ�־
unsigned char init_f;     

//��ʱ����
void s_10us(unsigned int _10us)
{
	unsigned int aa;
	for(;_10us>=1;_10us--)
	{
		for(aa=0;aa<=66;aa++)
		{;}
	}
}	

void _delay_100ms(unsigned int _100ms)
{
	for(;_100ms>=1;_100ms--)
	{
		s_10us(10000);
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
	s_10us(60);    //��ʱ600us
	DQ_HI;
	DQ_INPUT;
	s_10us(5);     //��ʱ50us
	i = DQ_R;
	s_10us(50);    //��ʱ500us
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
		s_10us(3);   //��ʱ30us
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
		s_10us(1); //��ʱ10us
		if (value & 0x01) 
		{
			DQ_HI;
		}
		s_10us(4);   //��ʱ40us
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
	unsigned char buf[2], NegativeTem;
	ds1820_reset();
	ds1820_write_byte(0xCC); //����ROM
	ds1820_write_byte(0xBE); //���¶�
	for (i = 0; i < 2; i++) {
		buf[i] = ds1820_read_byte();
	}
	//uart_send_char(buf[0]);
	//uart_send_char(buf[1]);
	//uart_send_char(0XAA);
	i = buf[1];
	i <<= 8;
	i |= buf[0];
	if((i & 0xF000) == 0xF000) //���¶�
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
	i = (i * 10) / 16;        //��ֵ����  
	//��3λû����ʾ
	i = i % 1000;  
	//��ʾ��2λ
	tem3= i / 100;
	if(NegativeTem == 1)
	{
		TemperatureTen = 14; // - ����
	}
	else
	{
		TemperatureTen = tem3;
	}
	i = i % 100;  
	//��ʾ��1λ
	tem2= i / 10;
	TemperatureOne = tem2;
	TemperatureDecimal = tem1;
}

#endif