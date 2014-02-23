/***************************************************************************/
// 程序：LED3264电子日历
// 模块：PCF8563时钟芯片驱动
// 文件：_PCF8563.h
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

#ifndef _PCF8563_H_
#define _PCF8563_H_

unsigned char syserr;

unsigned char write_buff[8],read_buff[8];
unsigned char time[7]={
		 	  		   0x40/*秒*/,
					   0x59/*分*/,
					   0x23/*时*/,
					   0x29/*天*/,
					   0x05/*星期*/,
					   0x02/*月/世纪*/,
					   0x08/*年*/
};

uint16 freshTimeCount = 0;

//清除指定区域指定长度的数据
void clear(unsigned char *p,unsigned char num)
{
 for(;num>0;num--)
 	{
	 *p=0;
	 p++;
	}
}

//功能描述: 向PCF8563指定地址写入一条数据
void PCF8536_wt(unsigned int add,unsigned char data)
{
 unsigned char t;
 t=add>>8;
 t<<=1;
 i2cstart();
 if(i2cwt(W_ADD_COM+t)==SLAW)
 	{
	 i2cwt(add);
	 i2cwt(data);
	}
 else syserr=ERR_SLAW;
 i2cstop();
}

//功能描述: 向PCF8563地址连续的寄存器写入系列数据
void PCF8536_wt_p(unsigned int add,unsigned char *p,unsigned char num)
{
 unsigned char t;
 t=add>>8;
 t<<=1;
 i2cstart();
 if(i2cwt(W_ADD_COM+t)==SLAW)
 	{
	 i2cwt(add);
	 for(;num>0;num--)
	 	{
		 i2cwt(*p);
		 p++;
		 asm("nop");
		}
	}
 else syserr=ERR_SLAW;
 i2cstop();
}

//读PCF8563
void PCF8536_rd(unsigned int add,unsigned char *p,unsigned char num)
{
 unsigned char t;
 t=add>>8;
 t<<=1;
 i2cstart();
 if(i2cwt(W_ADD_COM+t)==SLAW)
 	{
	 i2cwt(add);
	}
 else syserr=ERR_SLAW;
 
 i2cstart();
 if(i2cwt(R_ADD_COM+t)==SLAW)
 	{
	 i2cwt(add);
	}
 else syserr=ERR_SLAW;
 
 for(;num>0;num--)
 	{
	 *p=i2crd();
	 p++;
	} 
}

//功能描述: PCF8563初始化
void PCF8563_init(void)
{
 clear(write_buff,8);
 clear(read_buff,8);
 
 PCF8536_wt(0x00,0x20);//写寄存器1，停止计时
 //PCF8536_wt_p(0x02,time,7);//设定时间
 PCF8536_wt(0x00,0x00);//写寄存器1，开始计时
}

//刷新时间寄存器及相关数组内容
void Updata_time(void)
{
	PCF8536_rd(0x02,time,7);//读取时间

	time[0]=time[0]&0x7F;
	time[1]=time[1]&0x7F;
	time[2]=time[2]&0x3F;
	time[3]=time[3]&0x3F;
	time[4]=time[4]&0x07;
	time[5]=time[5]&0x1F;
	//time_tmp[]="00:00:00",data_tmp[]="2008.01.01",*week_tmp;
	//处理时间
	SecondOne = time[0]&0x0F;
	SecondTen = time[0]>>4;
	MinuteOne = time[1]&0x0F;
	MinuteTen = time[1]>>4;
	HourOne	= time[2]&0x0F;
	HourTen	= time[2]>>4;
	//处理日期
	DayOne = time[3]&0x0F;
	DayTen = time[3]>>4;
	MonthOne = time[5]&0x0F;
	MonthTen = time[5]>>4;
	YearOne = time[6]&0x0F;
	YearTen = time[6]>>4;
	//处理星期
	Week = (time[4]&0x0F)+1;
}

void Write_time(void)
{
	uint8 timeWriteBuffer[7] = {(SecondTen<<4)| SecondOne, 
								(MinuteTen<<4)| MinuteOne, 
								(HourTen<<4)| HourOne,
								(DayTen<<4)| DayOne,
								Week-1,
								(MonthTen <<4)| MonthOne,	
								(YearTen <<4)| YearOne,
	};
	PCF8536_wt_p(0x02, timeWriteBuffer, 7);
}

void AjustTimerMonthly()
{
	if(DayTen == 0 && DayOne == 1) // 每个月的一号 
	{
		if(HourTen == 0 && HourOne == 3) //三点
		{
			if(MinuteTen  == 3 && MinuteOne  == 0) //30分
			{
				if(AjustTimeMode && !AjustTimeIsAjusted) //加时间
				{
					uint8 temp = MinuteTen*10 + MinuteOne;
					temp = temp + AjustTimeTen*10 + AjustTimeOne;
					MinuteTen = temp/10;
					MinuteOne = temp%10;
					Write_time();
					AjustTimeIsAjusted = 1;
				}
				else if(!AjustTimeMode && !AjustTimeIsAjusted) //减时间
				{
					uint8 temp = MinuteTen*10 + MinuteOne;
					temp = temp - AjustTimeTen*10 - AjustTimeOne;
					MinuteTen = temp/10;
					MinuteOne = temp%10;
					Write_time();
					AjustTimeIsAjusted = 1;
				}
			}
			else if(MinuteTen  == 5)
			{
				AjustTimeIsAjusted = 0;
			}

		}
	}
}

#endif
