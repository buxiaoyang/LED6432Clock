/***************************************************************************/
// ����LED3264���ӹ���
// ģ�飺������
// ���ߣ������D
// �汾��1.0
// ���ڣ�2012��1��13��
// ���ܣ�ʱ�����־�̬��ʾ�����������¶ȹ�����ʾ
// оƬ��Atmega8
// ���룺AVR GCC
// ���Ŷ��壺PD6-���⴫������PC0-ʱ��оƬSCK��PC1-ʱ��оƬSDA��PC7-��������PD4-�¶ȴ�������
// 
//	
//
//
/***************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h> 
#include "_PinsValues.h"
#include "_Matrix.h"
#include "_DS18B20.h"
#include "_Display.h"
#include "_TWI.h"
#include "_PCF8563.h"
#include "_Key.h"
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
	timer0_init(); //��ʼ����ʱ��
	timer2_init();
	PCF8563_init();
	ReadDS18B20Count = 0;
	ds1820_reset();  
	clearScreen();	
	sei(); //ʹ���ж�
}

int main()
{
	init_devices();
	//Write_time();
	ds1820_start();    
	_delay_ms(1000);     
	ReadTemputer(); 
	Updata_time();
	FreshDisplayBufferNormal();
	while(1)
	{
		//675 us 0.000675s
		display();	
		Scan_Key();
	}
}

