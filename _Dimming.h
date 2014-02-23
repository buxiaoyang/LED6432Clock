/***************************************************************************/
// 程序：LED3264电子日历
// 模块：光敏电阻调节亮度模块	
// 文件：_Dimming.h
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

#ifndef _DIMMING_H_
#define _DIMMING_H_

uint16 AD_time_count;

void StartAD()
{
	ADCSRA=0x00;
	ADMUX=0x40;
	ADCSRA=(1<<ADEN)|(1<<ADSC)|(1<<ADIF)|0x07;   //128分频，连续转换
}

void GetDispalyLight()
{
	uint8 ten_1;
	uint16 adc_data0,adc_l0,adc_h0;
	adc_l0=ADCL;
	adc_h0=ADCH;
	adc_data0=adc_h0<<8|adc_l0;                  
	adc_data0=adc_data0>>1;               //放弃一位的精度
	adc_data0-=35;                        //修正
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
