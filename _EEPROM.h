/***************************************************************************/
// 程序：LED3264电子日历
// 模块：EEPROM 读写
// 文件：_EEPROM.h
// 作者：卜晓旸
// 版本：1.9.7
// 日期：2012年2月10日
// 功能：时分数字静态显示，年月日周温度滚动显示。可选亮度模式，时间补偿。
// 芯片：Atmega16
// 容丝：低位0xA4 10100100 高位0xD1 11010001
// 编译：AVR GCC
// 引脚定义：	PD0：按键MODE 
//				PD1: 按键显示模式
//				PD2：显示屏控制LAT
//				PD3：显示屏控制SCK
//				PD4：显示屏信号R1
//				PD5：显示屏信号R2
// 				PD7：温度传感器DS18B20
//				PC6：按键UP
//				PC7：按键DOWN
//				PB0：显示屏控制A
//				PB1：显示屏控制B
//				PB2：显示屏控制C
//				PB3：显示屏控制EN
//				PB4：显示屏控制D
//				PB6：显示屏数据G1
//				PB7：显示屏数据G2
//				PA0: 光敏电阻
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
