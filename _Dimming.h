/***************************************************************************/
// ����LED3264��������
// ģ�飺���������������ģ��	
// �ļ���_Dimming.h
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

#ifndef _DIMMING_H_
#define _DIMMING_H_

uint16 AD_time_count;

void StartAD()
{
	ADCSRA=0x00;
	ADMUX=0x40;
	ADCSRA=(1<<ADEN)|(1<<ADSC)|(1<<ADIF)|0x07;   //128��Ƶ������ת��
}

void GetDispalyLight()
{
	uint8 ten_1;
	uint16 adc_data0,adc_l0,adc_h0;
	adc_l0=ADCL;
	adc_h0=ADCH;
	adc_data0=adc_h0<<8|adc_l0;                  
	adc_data0=adc_data0>>1;               //����һλ�ľ���
	adc_data0-=35;                        //����
	ten_1=(adc_data0)/60;
	display_light = 8 - ten_1;
	if(display_light > 8)
	{
		display_light = 8;
	}
	else if(display_light < 1)
	{
		display_light = 1;
	}
	SET_DISPLAY_LIGHT;
}

#endif
