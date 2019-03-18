/***************************************************************************/
// 程序：LED3264电子日历
// 模块：光敏电阻调节亮度模块	
// 文件：_Dimming.h
// 作者：卜晓旸
// 版本：1.9.7
// 日期：2012年2月10日
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
