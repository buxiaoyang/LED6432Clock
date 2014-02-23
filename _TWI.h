/***************************************************************************/
// 程序：LED3264电子日历
// 模块：I2C 驱动
// 文件：_TWI.h
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

#ifndef _TWI_H_
#define _TWI_H_

//功能描述: i2c通信初始化
void twi_init(void)
{
 TWCR= 0x00; //disable twi
 TWBR= (1<<6) | (1<<5) | (1<<2); //set bit rate
 TWSR= 0x00; //set prescale
 TWAR= 0x00; //set slave address
 TWCR= (1<<TWEN); //enable twi
}

//i2c通信开始
void i2cstart(void)
{ 
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN); 
   	while (!(TWCR & (1<<TWINT)));
}

//i2c写数据,返回TWI状态
unsigned char i2cwt(unsigned char data)
{ 
	TWDR = data;
   	TWCR = (1<<TWINT) | (1<<TWEN);
   	while (!(TWCR & (1<<TWINT)));
   	asm("nop");
   	return(TWSR&0b11111000);
}

//i2c读数据
unsigned char i2crd(void)
{
   	TWCR= (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
   	while (!(TWCR & (1<<TWINT)));
   	return(TWDR);
}

//功能描述: i2c停止
void i2cstop(void)
{ 
   TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}

#endif
