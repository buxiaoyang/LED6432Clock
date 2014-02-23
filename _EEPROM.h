/***************************************************************************/
// ����LED3264��������
// ģ�飺EEPROM ��д
// �ļ���_EEPROM.h
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
#ifndef _EEPROM_SELF_H_
#define _EEPROM_SELF_H_

void SaveRunParameter()
{
	cli(); //�ر������ж�
	if(eeprom_is_ready())
	{
		eeprom_write_byte(0x00, 0xCC);
		eeprom_write_byte(0x01, display_light_Mode);
		eeprom_write_byte(0x02, display_light);
		eeprom_write_byte(0x03, moveSpeed);
		eeprom_write_byte(0x04, Mode);
		eeprom_write_byte(0x05, AjustTimeMode);
		eeprom_write_byte(0x06, AjustTimeTen);
		eeprom_write_byte(0x07, AjustTimeOne);
		eeprom_write_byte(0x08, Display_color);
		eeprom_write_byte(0x09, Display_BigNumber_Font);
	}
	sei(); //ʹ���ж�
}

void ReadRunParameter()
{
	cli(); //�ر������ж�
	if(eeprom_is_ready())
	{
		if(eeprom_read_byte(0x00) == 0xCC)
		{
			display_light_Mode = 	eeprom_read_byte(0x01);
			display_light = 		eeprom_read_byte(0x02);
			moveSpeed = 			eeprom_read_byte(0x03);
			//Mode = 					eeprom_read_byte(0x04);
			AjustTimeMode = 		eeprom_read_byte(0x05);
			AjustTimeTen = 			eeprom_read_byte(0x06);
			AjustTimeOne = 			eeprom_read_byte(0x07);	
			Display_color = 		eeprom_read_byte(0x08);
			Display_BigNumber_Font = eeprom_read_byte(0x09);
		}
		SET_DISPLAY_LIGHT;
	}
	sei(); //ʹ���ж�
}

#endif
