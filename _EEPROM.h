/***************************************************************************/
// ����LED3264��������
// ģ�飺EEPROM ��д
// �ļ���_EEPROM.h
// ���ߣ������D
// �汾��1.9.7
// ���ڣ�2012��2��10��
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
