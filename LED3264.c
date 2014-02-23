/***************************************************************************/
// ����LED3264��������
// ģ�飺������	
// �ļ���LED3264.c
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
//				PA1����ʾ������G1
//				PA2����ʾ������G2
//				PA0: ��������
/***************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h> 
#include <avr/eeprom.h>
#include "_PinsValues.h"
#include "_Matrix.h"
//#include "_USART.h"
#include "_DS18B20.h"
#include "_EEPROM.h"
#include "_Display.h"
#include "_TWI.h"
#include "_PCF8563.h"
#include "_Voice.h"
#include "_Key.h"
#include "_Dimming.h"
#include "_Timers.h"
#include "_Infrared.h"

void init_devices()
{
	cli(); //�ر������ж�
	MCUCR  = 0x00;
	//MCUCSR = 0x80;//��ֹJTAG
	GICR   = 0x00;//�ر��ⲿ�ж�
	LED_SCREEN_INI(); //��ʼ��LED����
	Key_Init();
	Voice_Init();
	//USART_Init();
	timer0_init(); //��ʼ����ʱ��
	timer2_init();
	PCF8563_init();
	ReadDS18B20Count = 0;
	AD_time_count = 0;
	KEY_Time_count = 0;
	ds1820_reset();  
	clearScreen();	
	sei(); //ʹ���ж�
}

int main()
{
	uint8 currentlyHourVoice;//��ǰСʱ��������������ʱ
	init_devices();
	ds1820_start();   
	_delay_100ms(6);   
	ReadTemputer();
	if(KEY_MODE_L) //�ж��Ƿ���س�ʼ������
	{
		_delay_ms(10);
		if(KEY_MODE_L)
		{
			display_light_Mode = 	1;
			display_light = 		1;
			moveSpeed = 			1;
			Mode = 					0;
			AjustTimeMode = 		0;
			AjustTimeTen = 			0;
			AjustTimeOne = 			0;	
			Display_color = 		0;
			Display_BigNumber_Font = 0;
			SET_DISPLAY_LIGHT;
			SaveRunParameter();
		}
	}
	ReadRunParameter();
	Show_welcome();
	Updata_time();
	FreshDisplayBufferNormal();
	SPEEK_TIME_Status = 1;
	while(1)
	{
		//675 us 0.000675s
		if( Mode == 0)
		{
			Updata_time();
			//������ʱ��ʼ
			if(Voice_Mode == 0)//����ģʽ
			{
				if(MinuteTen == 0 && MinuteOne == 0 && SecondTen == 0 && SecondOne < 10 && inVoice == 0)
				{
					inVoice = 1;
					SPEEK_TIME_Status = 1;
				}
			}
			else if(Voice_Mode == 1) //����ģʽ
			{
				currentlyHourVoice = HourTen*10 + HourOne;
				if(currentlyHourVoice > 6 && currentlyHourVoice <= 23)
				{
					if(MinuteTen == 0 && MinuteOne == 0 && SecondTen == 0 && SecondOne < 10 && inVoice == 0)
					{
						inVoice = 1;
						SPEEK_TIME_Status = 1;
					}
				}
			}
			else //�ر�ģʽ
			{
			
			}
			//������ʱ����
			FreshDisplayBufferCount ++;
			if(FreshDisplayBufferCount > 10000)
			{
				AjustTimerMonthly();
				FreshDisplayBufferNormal();
				FreshDisplayBufferCount = 0;
			}	
		}
		display();	
		Scan_Key();
	}
}

