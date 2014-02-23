/***************************************************************************/
// 程序：LED3264电子日历
// 模块：EEPROM 读写
// 文件：_EEPROM.h
// 作者：卜晓旸
// 版本：1.9.7
// 日期：2012年2月10日
/***************************************************************************/
#ifndef _EEPROM_SELF_H_
#define _EEPROM_SELF_H_

void SaveRunParameter()
{
	cli(); //关闭所有中断
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
	sei(); //使能中断
}

void ReadRunParameter()
{
	cli(); //关闭所有中断
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
	sei(); //使能中断
}

#endif
