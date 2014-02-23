/***************************************************************************/
// 程序：LED3264电子日历
// 模块：字模
// 文件：_Matrix.h
// 作者：卜晓旸
// 版本：1.9.7
// 日期：2012年2月10日
// 功能：时分数字静态显示，年月日周温度滚动显示。可选亮度模式，时间补偿。
// 芯片：Atmega8
// 容丝：低位0x24 高位0xD1
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

#ifndef _MATRIX_H_
#define _MATRIX_H_

/*******************大数字字库靠左***********************/
const uint8 BIG_NUMBER_L[0x0A][0x2A] PROGMEM = 
{
/*--  文字: 0    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x07,0x80,0x0F,0xC0,0x3F,0xE0,0x38,0x70,0x70,0x70,0x70,0x38,0x70,
0x38,0x60,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,
0x60,0x38,0x70,0x38,0x70,0x30,0x70,0x70,0x3C,0xE0,0x1F,0xE0,0x0F,
0x80,0x06,0x00,

/*--  文字: 1    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x03,0x00,0x1F,0x00,0xFF,0x00,0xFF,0x00,0xC7,0x00,0x07,0x00,0x07,
0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,
0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x7F,
0xF8,0x7F,0xF8,

/*--  文字: 2    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x0F,0xC0,0x3F,0xF0,0x3F,0xF8,0x30,0x38,0x00,0x38,0x00,0x18,0x00,
0x18,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x70,0x00,0xE0,0x01,0xC0,
0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x00,0x38,0x00,0x70,0x00,0x7F,
0xF8,0x7F,0xF8,

/*--  文字: 3    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x1F,0x80,0x3F,0xE0,0x3F,0xF0,0x20,0x78,0x00,0x38,0x00,0x38,0x00,
0x70,0x00,0xE0,0x1F,0xC0,0x1F,0xC0,0x1F,0xF0,0x00,0x38,0x00,0x38,
0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x60,0xF0,0x7F,0xF0,0x7F,
0xC0,0x0E,0x00, 

/*--  文字: 4    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x01,0xE0,0x01,0xE0,0x03,0xE0,0x03,0xE0,0x06,0xE0,0x0E,0xE0,0x1C,
0xE0,0x18,0xE0,0x30,0xE0,0x70,0xE0,0x60,0xE0,0xE0,0xE0,0xC0,0xE0,
0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,
0xE0,0x00,0xE0,

/*--  文字: 5    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x3F,0xF8,0x3F,0xF8,0x3F,0xF8,0x38,0x00,0x38,0x00,0x38,0x00,0x38,
0x00,0x3F,0x80,0x3F,0xE0,0x3F,0xF0,0x00,0x78,0x00,0x38,0x00,0x38,
0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x38,0x70,0xF0,0x7F,0xF0,0x3F,
0xC0,0x0E,0x00, 

/*--  文字: 6    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x03,0xC0,0x0F,0xE0,0x1F,0xF0,0x3C,0x00,0x70,0x00,0x70,0x00,0xE0,
0x00,0xE7,0xC0,0xFF,0xE0,0xFF,0xF0,0xF0,0x78,0xE0,0x38,0xE0,0x38,
0xE0,0x38,0xE0,0x38,0xE0,0x38,0x70,0x78,0x78,0x70,0x3F,0xE0,0x1F,
0xC0,0x07,0x00,

/*--  文字: 7    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0xFF,0xF8,0xFF,0xF8,0xFF,0xF0,0x00,0x70,0x00,0x70,0x00,0x60,0x00,
0xE0,0x00,0xC0,0x01,0xC0,0x01,0xC0,0x03,0x80,0x03,0x80,0x03,0x00,
0x07,0x00,0x07,0x00,0x0E,0x00,0x0E,0x00,0x1C,0x00,0x1C,0x00,0x1C,
0x00,0x38,0x00, 

/*--  文字: 8    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x0F,0x80,0x3F,0xE0,0x7F,0xF0,0x70,0x70,0xE0,0x70,0xE0,0x70,0x70,
0x70,0x79,0xE0,0x1F,0xC0,0x1F,0x80,0x3F,0xE0,0x70,0xF0,0xE0,0x70,
0xE0,0x38,0xC0,0x38,0xE0,0x38,0xE0,0x38,0xF0,0xF0,0x7F,0xF0,0x3F,
0xC0,0x06,0x00, 

/*--  文字: 9    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x1F,0x80,0x3F,0xC0,0x7F,0xE0,0xE0,0x70,0xE0,0x70,0xC0,0x30,0xC0,
0x38,0xE0,0x38,0xE0,0x78,0xF0,0xF8,0x7F,0xF8,0x3F,0xB8,0x00,0x30,
0x00,0x30,0x00,0x70,0x00,0x70,0x00,0xE0,0x43,0xE0,0x7F,0xC0,0x7F,
0x00,0x1C,0x00

};

/*******************滚动栏字库***********************/
const uint8 SCROLL[][0x0A] PROGMEM =
{

/*--  文字:  0  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7C,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x7C,

/*--  文字:  1  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x10,0x30,0x50,0x10,0x10,0x10,0x10,0x10,0x10,0xFE,

/*--  文字:  2  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x38,0x44,0x82,0x82,0x04,0x08,0x10,0x20,0x40,0xFE,

/*--  文字:  3  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7C,0x82,0x02,0x02,0x3C,0x02,0x02,0x82,0x82,0x7C,

/*--  文字:  4  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x06,0x0C,0x14,0x24,0x44,0x84,0xFE,0x04,0x04,0x04,

/*--  文字:  5  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x80,0x80,0xFC,0x02,0x02,0x02,0x82,0x82,0x7C,

/*--  文字:  6  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7C,0x82,0x80,0x80,0xFC,0x82,0x82,0x82,0x82,0x7C,

/*--  文字:  7  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7E,0x82,0x02,0x04,0x08,0x10,0x20,0x20,0x20,0x20,

/*--  文字:  8  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7C,0x82,0x82,0x82,0x7C,0x82,0x82,0x82,0x82,0x7C,

/*--  文字:  9  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7C,0x82,0x82,0x82,0x82,0x7E,0x02,0x02,0x82,0x7C,

/*--  文字:  10年  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x40,0x7E,0x88,0x7E,0x48,0x48,0xFE,0x08,0x08,0x08,

/*--  文字:  11月  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7E,0x42,0x42,0x7E,0x42,0x42,0x7E,0x42,0x46,0x82,

/*--  文字:  12周  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7E,0x92,0xBA,0x92,0xBA,0x82,0xBA,0xAA,0xBA,0x86,

/*--  文字:  13度  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x08,0x7E,0x54,0x7E,0x5C,0x40,0x5C,0x54,0x48,0x96,

/*--  文字:  14一  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,

/*--  文字:  15二  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0xFF,0x00,0x00,

/*--  文字:  16三  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x7E,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0xFF,

/*--  文字:  17四  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFF,0xA9,0xA9,0xA9,0xA9,0xA9,0xC7,0x81,0xFF,0x81,

/*--  文字:  18五  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7E,0x10,0x10,0x10,0x7C,0x14,0x14,0x14,0x14,0xFF,

/*--  文字:  19六  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x30,0x18,0x08,0xFF,0x00,0x24,0x24,0x66,0x66,0xC2,

/*--  文字:  20日  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7F,0x41,0x41,0x41,0x7F,0x41,0x41,0x41,0x41,0x7F,

/*--  文字:  21.  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,

/*--  文字:  22空格  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  文字:  23时  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x02,0xE2,0xBF,0xA2,0xEA,0xAA,0xA2,0xAA,0xE6,0x02,

/*--  文字:  24分  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x38,0x24,0x24,0x42,0xBD,0x24,0x24,0x24,0x44,0x8C,

/*--  文字:  25亮  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x10,0xFF,0x3C,0x24,0x3C,0xFF,0x81,0x3C,0x24,0x47,

/*--  文字:  26每  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x20,0x3E,0x40,0xBE,0x2A,0xFF,0x32,0x7E,0x02,0x04,

/*--  文字:  27+  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x40,0x40,0x40,0xF7,0x55,0x55,0x55,0x57,0x50,0xB0,

/*--  文字:  28设  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x5C,0x14,0xD4,0x76,0x40,0x5C,0x54,0x54,0x68,0x56,

/*--  文字:  29置  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7E,0x5A,0x7E,0xFF,0x7E,0x42,0x7E,0x7E,0x42,0xFF,

/*--  文字:  30：  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x00,0x60,0x60,

/*--  文字:  31自  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x10,0x10,0x7E,0x42,0x7E,0x42,0x7E,0x42,0x7E,0x42,

/*--  文字:  32手  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x04,0x7E,0x08,0x7E,0x08,0xFF,0x08,0x08,0x28,0x18,

/*--  文字:  33减  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x02,0x02,0xBF,0x62,0x3A,0x22,0x7A,0xBB,0x22,0x45,

/*--  文字:  34校  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x48,0x48,0x7E,0xD4,0x62,0x54,0xD4,0x48,0x54,0x62,

/*--  文字:  35电  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x10,0xFE,0x92,0xFE,0x92,0x92,0xFE,0x10,0x12,0x1E,

/*--  文字:  36子  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x04,0x08,0x10,0xFE,0x10,0x10,0x10,0x50,0x30,

/*--  文字:  37历  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x40,0x50,0x7E,0x52,0x52,0x52,0x52,0x52,0xA4,

/*--  文字:  38 -   --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x00,0x00,0x7E,0x7E,0x00,0x00,0x00,0x00,

/*--  文字:  39B  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7E,0x41,0x41,0x41,0x7E,0x41,0x41,0x41,0x41,0x7E,

/*--  文字:  40X  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x41,0x41,0x22,0x14,0x08,0x14,0x22,0x22,0x41,0x41,

/*--  文字:  41Y  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x41,0x41,0x41,0x22,0x14,0x08,0x08,0x08,0x08,0x08,

/*--  文字:  42日  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0x82,0xFE

};


/*******************中文字库***********************/

const uint8 CHINESE[][0x20] PROGMEM =
{
/*--  文字:  0自  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x02,0x00,0x03,0x80,0x06,0x00,0x1F,0xFC,0x1F,0xFC,0x18,0x0C,0x1F,0xFC,0x1F,0xFC,
0x18,0x0C,0x1F,0xFC,0x1F,0xFC,0x18,0x0C,0x1F,0xFC,0x1F,0xFC,0x18,0x0C,0x18,0x0C,
/*--  文字:  1手  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x08,0x3F,0xFC,0x3F,0xFC,0x01,0x80,0x01,0x80,0x3F,0xFC,0x1F,0xF8,0x01,0x80,
0x7F,0xFF,0x7F,0xFE,0x01,0x80,0x01,0x80,0x01,0x80,0x07,0x80,0x07,0x80,0x00,0x00,
/*--  文字:  2动  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x00,0x30,0x3E,0x30,0x3F,0x30,0x01,0xFE,0x01,0xFE,0x7F,0x36,0x7F,0x36,
0x18,0x76,0x18,0x66,0x36,0x66,0x76,0xE6,0x7E,0xC6,0x39,0xDE,0x03,0x9C,0x00,0x00,
/*--  文字:  3M  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x60,0x06,0x70,0x0E,0x70,0x0E,0x78,0x1E,0x78,0x1E,0x7C,0x3E,0x6C,0x36,
0x6E,0x76,0x66,0x66,0x67,0xC6,0x63,0xC6,0x61,0x86,0x61,0x86,0x70,0x0E,0x70,0x0E,
/*--  文字:  4T  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x3F,0xFF,0x3F,0xFF,0x30,0xC3,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,
0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x07,0xF8,0x07,0xF8,
/*--  文字:  5 2  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x03,0xFC,0x0F,0xFE,0x0E,0x07,0x1C,0x03,0x18,0x07,0x18,0x0E,0x00,0x1C,
0x00,0x38,0x00,0x70,0x00,0xE0,0x01,0xC0,0x03,0x80,0x07,0x00,0x1F,0xFF,0x1F,0xFFF
};

#endif


