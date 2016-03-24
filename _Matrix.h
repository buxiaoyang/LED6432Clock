/***************************************************************************/
// 程序：LED3264电子日历
// 模块：字模
// 文件：_Matrix.h
// 作者：卜晓旸
// 版本：1.9.7
// 日期：2012年2月10日
/***************************************************************************/

#ifndef _MATRIX_H_
#define _MATRIX_H_

/*******************大数字字库靠左***********************/
const uint8 BIG_NUMBER_STYLE1[0x0A][0x2A] PROGMEM = 
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

/*******************大数字字库靠左***********************/
const uint8 BIG_NUMBER_STYLE2[0x0A][0x2A] PROGMEM = 
{
/*--  文字: 0    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,
0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,
0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xFF,0xF8,0xFF,
0xF8,0xFF,0xF8,

/*--  文字: 1    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,
0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,
0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,
0x00,0x07,0x00,

/*--  文字: 2    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0x00,0x38,0x00,0x38,0x00,0x38,0x00,
0x38,0x00,0x38,0x00,0x38,0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0xE0,0x00,
0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xFF,0xF8,0xFF,
0xF8,0xFF,0xF8,

/*--  文字: 3    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0x00,0x38,0x00,0x38,0x00,0x38,0x00,
0x38,0x00,0x38,0x00,0x38,0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0x00,0x38,
0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0xFF,0xF8,0xFF,
0xF8,0xFF,0xF8, 

/*--  文字: 4    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,
0x38,0xE0,0x38,0xE0,0x38,0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0x00,0x38,
0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,
0x38,0x00,0x38,

/*--  文字: 5    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,
0x00,0xE0,0x00,0xE0,0x00,0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0x00,0x38,
0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0xFF,0xF8,0xFF,
0xF8,0xFF,0xF8, 

/*--  文字: 6    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,
0x00,0xE0,0x00,0xE0,0x00,0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0xE0,0x38,
0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xFF,0xF8,0xFF,
0xF8,0xFF,0xF8,

/*--  文字: 7    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0x00,0x38,0x00,0x38,0x00,0x38,0x00,
0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,
0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,
0x38,0x00,0x38, 

/*--  文字: 8    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,
0x38,0xE0,0x38,0xE0,0x38,0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0xE0,0x38,
0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xFF,0xF8,0xFF,
0xF8,0xFF,0xF8, 

/*--  文字: 9    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,
0x38,0xE0,0x38,0xE0,0x38,0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0x00,0x38,
0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0xFF,0xF8,0xFF,
0xF8,0xFF,0xF8
};

/*******************大数字字库靠左***********************/
const uint8 BIG_NUMBER_STYLE3[0x0A][0x2A] PROGMEM = 
{
/*--  文字: 0    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x3F,0xE0,0x7F,0xF0,0xFF,0xF8,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,
0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,
0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xFF,0xF8,0x7F,
0xF0,0x3F,0xE0,

/*--  文字: 1    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x07,0x00,0x0F,0x00,0x1F,0x00,0x1F,0x00,0x1F,0x00,0x07,0x00,0x07,
0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,
0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0xFF,0xF8,0xFF,
0xF8,0xFF,0xF8,

/*--  文字: 2    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x3F,0xE0,0x7F,0xF0,0xFF,0xF8,0xE0,0x38,0x00,0x38,0x00,0x38,0x00,
0x38,0x00,0x38,0x00,0x38,0x3F,0xF8,0x7F,0xF0,0xFF,0xE0,0xE0,0x00,
0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xFF,0xF8,0xFF,
0xF8,0xFF,0xF8,

/*--  文字: 3    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x3F,0xE0,0x7F,0xF0,0xFF,0xF8,0xE0,0x38,0x00,0x38,0x00,0x38,0x00,
0x38,0x00,0x38,0x00,0x38,0x1F,0xF0,0x1F,0xE0,0x1F,0xF0,0x00,0x38,
0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0xE0,0x38,0xFF,0xF8,0x7F,
0xF0,0x3F,0xE0, 

/*--  文字: 4    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0xE1,0xC0,0xE1,0xC0,0xE1,0xC0,0xE1,0xC0,0xE1,0xC0,0xE1,0xC0,0xE1,
0xC0,0xE1,0xC0,0xE1,0xC0,0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0x01,0xC0,
0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,
0xC0,0x01,0xC0,

/*--  文字: 5    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,
0x00,0xE0,0x00,0xE0,0x00,0xFF,0xE0,0xFF,0xF0,0xFF,0xF8,0x00,0x38,
0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0xE0,0x38,0xFF,0xF8,0x7F,
0xF0,0x3F,0xE0, 

/*--  文字: 6    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,
0x00,0xE0,0x00,0xE0,0x00,0xFF,0xE0,0xFF,0xF0,0xFF,0xF8,0xE0,0x38,
0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xFF,0xF8,0x7F,
0xF0,0x3F,0xE0,

/*--  文字: 7    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0xFF,0xF8,0xFF,0xF8,0xFF,0xF8,0x00,0x38,0x00,0x38,0x00,0x38,0x00,
0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,
0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,
0x38,0x00,0x38, 

/*--  文字: 8    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x3F,0xE0,0x7F,0xF0,0xFF,0xF8,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,
0x38,0xE0,0x38,0x70,0x70,0x3F,0xE0,0x1F,0xC0,0x3F,0xE0,0x70,0x70,
0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xFF,0xF8,0x7F,
0xF0,0x3F,0xE0, 

/*--  文字: 9    --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x21   --*/
0x3F,0xE0,0x7F,0xF0,0xFF,0xF8,0xE0,0x38,0xE0,0x38,0xE0,0x38,0xE0,
0x38,0xE0,0x38,0xE0,0x38,0xFF,0xF8,0x7F,0xF8,0x3F,0xF8,0x00,0x38,
0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x38,0x00,
0x38,0x00,0x38

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
0xFE,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0x82,0xFE,

/*--  文字:  43速  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x84,0x5F,0xC4,0x5F,0x55,0x5F,0x44,0x4E,0x55,0xBF,

/*--  文字:  44字  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x08,0xFF,0x81,0x7E,0x04,0xFF,0x08,0x08,0x38,0x08,

/*--  文字:  45体  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x24,0x44,0xFF,0x4E,0x55,0x55,0x5F,0x65,0x44,0x44

};


/*******************滚动栏字库***********************/
const uint8 SCROLL_STYLE1[][0x0A] PROGMEM =
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
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

/*******************滚动栏字库***********************/
const uint8 SCROLL_STYLE2[][0x0A] PROGMEM =
{

/*--  文字:  0  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0xFE,

/*--  文字:  1  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,

/*--  文字:  2  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x02,0x02,0x02,0x02,0xFE,0x80,0x80,0x80,0xFE,

/*--  文字:  3  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x02,0x02,0x02,0x02,0xFE,0x02,0x02,0x02,0xFE,

/*--  文字:  4  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x82,0x82,0x82,0x82,0x82,0xFE,0x02,0x02,0x02,0x02,

/*--  文字:  5  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x80,0x80,0x80,0x80,0xFE,0x02,0x02,0x02,0xFE,

/*--  文字:  6  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x80,0x80,0x80,0x80,0xFE,0x82,0x82,0x82,0xFE,

/*--  文字:  7  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,

/*--  文字:  8  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x82,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0xFE,

/*--  文字:  9  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x82,0x82,0x82,0x82,0xFE,0x02,0x02,0x02,0xFE,

/*--  文字:  10年  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x80,0xFE,0x88,0x7E,0x48,0x48,0xFE,0x08,0x08,0x08,

/*--  文字:  11月  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7E,0x42,0x42,0x7E,0x42,0x42,0x7E,0x42,0x42,0x46,

/*--  文字:  12周  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x92,0xBA,0x92,0xBA,0x82,0xBA,0xAA,0xBA,0x86,

/*--  文字:  13度  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xDF,0xD0,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,

/*--  文字:  14一  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,

/*--  文字:  15二  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,

/*--  文字:  16三  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x00,0x00,0x00,0x7C,0x00,0x00,0x00,0x00,0xFE,

/*--  文字:  17四  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0xAA,0xAA,0xAA,0xAA,0xEE,0x82,0x82,0x82,0xFE,

/*--  文字:  18五  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x20,0x20,0x20,0xFC,0x24,0x24,0x24,0x24,0xFE,

/*--  文字:  19六  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x20,0x10,0x10,0xFE,0x44,0x44,0x44,0x44,0x44,0x44,

/*--  文字:  20日  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7E,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0x7E,

/*--  文字:  21.  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,

/*--  文字:  22空格  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

/*******************滚动栏字库***********************/
const uint8 SCROLL_STYLE3[][0x0A] PROGMEM =
{

/*--  文字:  0  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7C,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x7C,

/*--  文字:  1  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x10,0x30,0x50,0x10,0x10,0x10,0x10,0x10,0x10,0xFE,

/*--  文字:  2  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7C,0x82,0x02,0x02,0x02,0x7C,0x80,0x80,0x80,0xFE,

/*--  文字:  3  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7C,0x82,0x02,0x02,0x02,0x7C,0x02,0x02,0x82,0x7C,

/*--  文字:  4  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x88,0x88,0x88,0x88,0x88,0xFE,0x08,0x08,0x08,0x08,

/*--  文字:  5  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x80,0x80,0x80,0x80,0xFC,0x02,0x02,0x82,0x7C,

/*--  文字:  6  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x80,0x80,0x80,0x80,0x80,0xFC,0x82,0x82,0x82,0x7C,

/*--  文字:  7  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0xFE,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,

/*--  文字:  8  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7C,0x82,0x82,0x82,0x82,0x7C,0x82,0x82,0x82,0x7C,

/*--  文字:  9  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7C,0x82,0x82,0x82,0x82,0x7E,0x02,0x02,0x02,0x02,

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
0xBC,0x42,0x40,0x40,0x40,0x40,0x40,0x40,0x42,0x3C,

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
0x20,0x10,0xFE,0x00,0x44,0x44,0x44,0x44,0x44,0x82,

/*--  文字:  20日  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x7E,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0x7E,

/*--  文字:  21.  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,

/*--  文字:  22空格  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=8x10   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

/*******************中文字库***********************/

const uint8 CHINESE[][0x20] PROGMEM =
{
	/*--  0 数  --*/ 
	0x08,0x40,0x49,0x40,0x2A,0x40,0x08,0x84,
	0xFF,0xFE,0x19,0x08,0x2C,0x88,0x4A,0x88,
	0x10,0x88,0xFE,0x90,0x22,0x50,0x22,0x20,
	0x14,0x50,0x18,0x88,0x25,0x0E,0x42,0x04,
	
	/*--  1 字  --*/ 
	0x02,0x00,0x01,0x00,0x3F,0xFC,0x20,0x04,
	0x40,0x08,0x1F,0xE0,0x00,0x40,0x00,0x80,
	0x01,0x04,0xFF,0xFE,0x01,0x00,0x01,0x00,
	0x01,0x00,0x01,0x00,0x05,0x00,0x02,0x00,
	
	/*--  2 时  --*/ 
	0x00,0x08,0x04,0x08,0x7E,0x08,0x44,0x08,
	0x47,0xFE,0x44,0x08,0x44,0x08,0x7C,0x88,
	0x44,0x48,0x44,0x48,0x44,0x08,0x44,0x08,
	0x7C,0x08,0x44,0x48,0x00,0x28,0x00,0x10,
	
	/*--  3 钟  --*/ 
	0x10,0x20,0x10,0x20,0x10,0x20,0x1C,0x24,
	0x21,0xFE,0x21,0x24,0x7D,0x24,0x91,0x24,
	0x11,0x24,0xFD,0xFC,0x11,0x24,0x10,0x20,
	0x14,0x20,0x18,0x20,0x10,0x20,0x00,0x20,
	
	/*--  4 阿  --*/ 
	0x00,0x04,0x7F,0xFE,0x44,0x08,0x48,0x08,
	0x48,0x28,0x51,0xF8,0x49,0x28,0x49,0x28,
	0x45,0x28,0x45,0x28,0x45,0x28,0x69,0xE8,
	0x51,0x28,0x40,0x08,0x40,0x28,0x40,0x10,
	
	/*--  5 布  --*/ 
	0x02,0x00,0x02,0x00,0x02,0x08,0xFF,0xFC,
	0x04,0x00,0x09,0x00,0x11,0x08,0x3F,0xFC,
	0x51,0x08,0x91,0x08,0x11,0x08,0x11,0x08,
	0x11,0x28,0x11,0x10,0x01,0x00,0x01,0x00,
	
	/*--  6 电  --*/ 
	0x02,0x00,0x02,0x00,0x02,0x10,0x7F,0xF8,
	0x42,0x10,0x42,0x10,0x7F,0xF0,0x42,0x10,
	0x42,0x10,0x7F,0xF0,0x42,0x10,0x02,0x00,
	0x02,0x04,0x02,0x04,0x01,0xFC,0x00,0x00,
	
	/*--  7 子  --*/ 
	0x00,0x00,0x3F,0xF0,0x00,0x10,0x00,0x20,
	0x00,0x40,0x01,0x80,0x01,0x04,0xFF,0xFE,
	0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
	0x01,0x00,0x01,0x00,0x05,0x00,0x02,0x00,
	
	/*--  8 设  --*/ 
	0x01,0xF0,0x21,0x10,0x11,0x10,0x11,0x10,
	0x01,0x10,0x02,0x0E,0xF4,0x00,0x13,0xF8,
	0x11,0x08,0x11,0x10,0x10,0x90,0x10,0xA0,
	0x14,0x40,0x18,0xB0,0x13,0x0E,0x0C,0x04,
	
	/*--  9 置  --*/ 
	0x3F,0xF8,0x24,0x48,0x3F,0xF8,0x01,0x00,
	0x7F,0xFC,0x01,0x00,0x1F,0xF0,0x10,0x10,
	0x1F,0xF0,0x10,0x10,0x1F,0xF0,0x10,0x10,
	0x1F,0xF0,0x10,0x14,0xFF,0xFE,0x00,0x00,
	
	/*--  10 速  --*/ 
	0x00,0x40,0x40,0x44,0x37,0xFE,0x10,0x40,
	0x07,0xFC,0x04,0x44,0xF4,0x44,0x17,0xFC,
	0x14,0x44,0x10,0xE0,0x11,0x58,0x12,0x48,
	0x14,0x40,0x28,0x46,0x47,0xFC,0x00,0x00,
	
	/*--  11 度  --*/ 
	0x01,0x00,0x00,0x84,0x3F,0xFE,0x22,0x20,
	0x22,0x28,0x3F,0xFC,0x22,0x20,0x23,0xE0,
	0x20,0x00,0x2F,0xF0,0x22,0x20,0x21,0x40,
	0x20,0x80,0x43,0x60,0x8C,0x1E,0x30,0x04,
	
	/*--  12 亮  --*/ 
	0x01,0x08,0x7F,0xFC,0x00,0x10,0x1F,0xF8,
	0x10,0x10,0x10,0x10,0x1F,0xF0,0x00,0x00,
	0x7F,0xFE,0x40,0x22,0x8F,0xF4,0x08,0x20,
	0x08,0x20,0x08,0x22,0x10,0x22,0x60,0x1E,
	
	/*--  13 时  --*/ 
	0x00,0x08,0x04,0x08,0x7E,0x08,0x44,0x08,
	0x47,0xFE,0x44,0x08,0x44,0x08,0x7C,0x88,
	0x44,0x48,0x44,0x48,0x44,0x08,0x44,0x08,
	0x7C,0x08,0x44,0x48,0x00,0x28,0x00,0x10,
	
	/*--  14 间  --*/ 
	0x20,0x04,0x1B,0xFE,0x08,0x04,0x40,0x24,
	0x4F,0xF4,0x48,0x24,0x48,0x24,0x48,0x24,
	0x4F,0xE4,0x48,0x24,0x48,0x24,0x48,0x24,
	0x4F,0xE4,0x48,0x24,0x40,0x14,0x40,0x08,
	
	/*--  15 年  --*/ 
	0x08,0x00,0x08,0x08,0x1F,0xFC,0x11,0x00,
	0x21,0x00,0x41,0x10,0x1F,0xF8,0x11,0x00,
	0x11,0x00,0x11,0x04,0xFF,0xFE,0x01,0x00,
	0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
	
	/*--  16 月  --*/ 
	0x00,0x10,0x0F,0xF8,0x08,0x10,0x08,0x10,
	0x08,0x10,0x0F,0xF0,0x08,0x10,0x08,0x10,
	0x08,0x10,0x0F,0xF0,0x08,0x10,0x08,0x10,
	0x10,0x10,0x10,0x10,0x20,0x50,0x40,0x20,
	
	/*--  17 日  --*/ 
	0x00,0x10,0x1F,0xF8,0x10,0x10,0x10,0x10,
	0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,
	0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
	0x10,0x10,0x1F,0xF0,0x10,0x10,0x00,0x00,
	
	/*--  18 分  --*/ 
	0x00,0x80,0x04,0x80,0x04,0x40,0x08,0x40,
	0x08,0x20,0x10,0x10,0x20,0x08,0x4F,0xEE,
	0x84,0x24,0x04,0x20,0x04,0x20,0x04,0x20,
	0x04,0x20,0x08,0x20,0x11,0x40,0x20,0x80,
	
	/*--  19 秒  --*/ 
	0x04,0x20,0x0E,0x20,0x78,0x20,0x08,0x20,
	0x08,0xA8,0xFE,0xA6,0x08,0xA2,0x1D,0x20,
	0x1A,0x24,0x28,0x24,0x28,0x28,0x48,0x10,
	0x88,0x20,0x08,0x40,0x08,0x80,0x0B,0x00,
	
	/*--  20 份  --*/ 
	0x08,0x20,0x09,0x20,0x09,0x20,0x11,0x10,
	0x12,0x10,0x32,0x0E,0x54,0x04,0x9B,0xF0,
	0x11,0x10,0x11,0x10,0x11,0x10,0x11,0x10,
	0x12,0x10,0x12,0x10,0x14,0xA0,0x10,0x40,
	
	/*--  21 星  --*/ 
	0x00,0x08,0x3F,0xFC,0x20,0x08,0x3F,0xF8,
	0x20,0x08,0x3F,0xF8,0x01,0x00,0x21,0x08,
	0x3F,0xFC,0x21,0x00,0x41,0x10,0xBF,0xF8,
	0x01,0x00,0x01,0x04,0xFF,0xFE,0x00,0x00,
	
	/*--  22 期  --*/ 
	0x22,0x04,0x22,0x7E,0x22,0x44,0x7F,0x44,
	0x22,0x44,0x3E,0x7C,0x22,0x44,0x3E,0x44,
	0x22,0x44,0x22,0x7C,0xFF,0xC4,0x00,0x44,
	0x24,0x44,0x22,0x84,0x41,0x14,0x82,0x08,
	
	/*--  23 周  --*/ 
	0x00,0x08,0x3F,0xFC,0x21,0x08,0x21,0x48,
	0x2F,0xE8,0x21,0x08,0x21,0x28,0x3F,0xF8,
	0x20,0x48,0x27,0xE8,0x24,0x48,0x24,0x48,
	0x24,0x48,0x47,0xC8,0x84,0x28,0x00,0x10,
	
	/*--  24 自  --*/ 
	0x01,0x00,0x02,0x00,0x04,0x10,0x1F,0xF8,
	0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10,
	0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10,
	0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10,
	
	/*--  25 手  --*/ 
	0x00,0x10,0x00,0xF8,0x7F,0x00,0x01,0x00,
	0x01,0x10,0x3F,0xF8,0x01,0x00,0x01,0x00,
	0x01,0x04,0xFF,0xFE,0x01,0x00,0x01,0x00,
	0x01,0x00,0x01,0x00,0x05,0x00,0x02,0x00,
	
	/*--  26 动  --*/ 
	0x00,0x40,0x08,0x40,0x7C,0x40,0x00,0x44,
	0x05,0xFE,0xFE,0x44,0x10,0x44,0x10,0x44,
	0x20,0x44,0x24,0x44,0x42,0x84,0xFE,0x84,
	0x41,0x04,0x01,0x04,0x02,0x28,0x04,0x10,
	
	/*--  27 字  --*/ 
	0x02,0x00,0x01,0x00,0x3F,0xFC,0x20,0x04,
	0x40,0x08,0x1F,0xE0,0x00,0x40,0x00,0x80,
	0x01,0x04,0xFF,0xFE,0x01,0x00,0x01,0x00,
	0x01,0x00,0x01,0x00,0x05,0x00,0x02,0x00,
	
	/*--  28 体  --*/ 
	0x10,0x80,0x10,0x80,0x10,0x80,0x20,0x88,
	0x2F,0xFC,0x62,0xA0,0xA2,0xA0,0x24,0x90,
	0x24,0x90,0x28,0x88,0x2B,0xEE,0x30,0x84,
	0x20,0x80,0x20,0x80,0x20,0x80,0x20,0x80,
	
	/*--  29 校  --*/ 
	0x10,0x40,0x10,0x20,0x10,0x04,0x13,0xFE,
	0xFC,0x00,0x10,0x88,0x31,0x06,0x3A,0x8A,
	0x54,0x88,0x50,0x50,0x90,0x50,0x10,0x20,
	0x10,0x50,0x10,0x88,0x13,0x0E,0x1C,0x04,  
	
	/*--  30 加  --*/ 
	0x10,0x00,0x10,0x00,0x10,0x04,0x12,0x7E,
	0xFF,0x44,0x12,0x44,0x12,0x44,0x12,0x44,
	0x12,0x44,0x22,0x44,0x22,0x44,0x22,0x44,
	0x22,0x44,0x4A,0x7C,0x84,0x44,0x00,0x00,
	
	/*--  31 减  --*/ 
	0x00,0x10,0x40,0x18,0x30,0x14,0x17,0xFE,
	0x04,0x10,0x04,0x10,0x0D,0xD0,0x14,0x14,
	0x25,0xD4,0xE5,0x54,0x25,0x54,0x25,0x58,
	0x25,0xD0,0x25,0x2A,0x08,0x46,0x10,0x82,
	
	/*--  32 每  --*/ 
	0x10,0x00,0x10,0x08,0x1F,0xFC,0x20,0x10,
	0x5F,0xF8,0x12,0x10,0x11,0x10,0x10,0x14,
	0xFF,0xFE,0x12,0x10,0x21,0x10,0x20,0x10,
	0x3F,0xF8,0x00,0x20,0x00,0xA0,0x00,0x40,
	
	/*--  33 颜  --*/ 
	0x10,0x04,0x09,0xFE,0x7F,0x20,0x22,0x44,
	0x14,0xFE,0x7F,0x84,0x44,0x94,0x48,0x94,
	0x52,0x94,0x44,0xA4,0x48,0xA4,0x52,0xA4,
	0x44,0xA4,0x48,0x48,0x90,0x86,0x21,0x02,
	
	/*--  34 色  --*/ 
	0x04,0x00,0x04,0x00,0x07,0xF0,0x08,0x20,
	0x08,0x48,0x1F,0xFC,0x28,0x88,0x48,0x88,
	0x08,0x88,0x0F,0xF8,0x08,0x08,0x08,0x00,
	0x08,0x02,0x08,0x02,0x07,0xFE,0x00,0x00,
	
	/*--  35 单  --*/ 
	0x10,0x10,0x08,0x20,0x04,0x48,0x3F,0xFC,
	0x21,0x08,0x21,0x08,0x3F,0xF8,0x21,0x08,
	0x21,0x08,0x3F,0xF8,0x21,0x00,0x01,0x04,
	0xFF,0xFE,0x01,0x00,0x01,0x00,0x01,0x00,
	
	/*--  36 红  --*/ 
	0x10,0x00,0x10,0x08,0x23,0xFC,0x20,0x20,
	0x44,0x20,0xF8,0x20,0x10,0x20,0x20,0x20,
	0x40,0x20,0xFC,0x20,0x40,0x20,0x00,0x20,
	0x1C,0x20,0xE0,0x24,0x47,0xFE,0x00,0x00,
	
	/*--  37 绿  --*/ 
	0x10,0x08,0x13,0xFC,0x20,0x08,0x21,0xF8,
	0x44,0x08,0xFF,0xFE,0x10,0x40,0x22,0x44,
	0x41,0x4C,0xF9,0x50,0x00,0xE0,0x01,0x50,
	0x1A,0x48,0xE4,0x4E,0x41,0x44,0x00,0x80,
	
	/*--  38 黄  --*/ 
	0x04,0x40,0x04,0x50,0x3F,0xF8,0x04,0x40,
	0x04,0x44,0xFF,0xFE,0x01,0x10,0x1F,0xF8,
	0x11,0x10,0x1F,0xF0,0x11,0x10,0x1F,0xF0,
	0x10,0x00,0x04,0x60,0x18,0x18,0x60,0x04,
	
	/*--  39 底  --*/ 
	0x02,0x00,0x01,0x04,0x3F,0xFE,0x20,0x00,
	0x20,0x70,0x2F,0x80,0x28,0x80,0x28,0x88,
	0x2F,0xFC,0x28,0x80,0x28,0x80,0x28,0x40,
	0x4A,0x40,0x4D,0xA4,0x88,0x94,0x00,0x0C,
	
	/*--  40 语  --*/ 
	0x00,0x08,0x4F,0xFC,0x21,0x00,0x21,0x10,
	0x07,0xF8,0x02,0x10,0xE2,0x14,0x3F,0xFE,
	0x20,0x00,0x20,0x08,0x27,0xFC,0x24,0x08,
	0x2C,0x08,0x34,0x08,0x27,0xF8,0x04,0x08,
	
	/*--  41 音  --*/ 
	0x02,0x00,0x01,0x10,0x3F,0xF8,0x08,0x20,
	0x04,0x20,0x04,0x44,0xFF,0xFE,0x00,0x10,
	0x1F,0xF8,0x10,0x10,0x10,0x10,0x1F,0xF0,
	0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10,
	
	/*--  42 报  --*/ 
	0x10,0x08,0x11,0xFC,0x11,0x08,0x11,0x08,
	0xFD,0x28,0x11,0x10,0x15,0x00,0x19,0xF8,
	0x31,0x08,0xD1,0x90,0x11,0x50,0x11,0x20,
	0x11,0x50,0x11,0x8E,0x51,0x04,0x21,0x00,
	
	/*--  43 正  --*/ 
	0x00,0x08,0x7F,0xFC,0x01,0x00,0x01,0x00,
	0x01,0x00,0x01,0x00,0x11,0x10,0x11,0xF8,
	0x11,0x00,0x11,0x00,0x11,0x00,0x11,0x00,
	0x11,0x00,0x11,0x04,0xFF,0xFE,0x00,0x00,
	
	/*--  44 常  --*/ 
	0x01,0x00,0x11,0x10,0x09,0x20,0x7F,0xFE,
	0x40,0x02,0x8F,0xE4,0x08,0x20,0x0F,0xE0,
	0x01,0x10,0x1F,0xF8,0x11,0x10,0x11,0x10,
	0x11,0x10,0x11,0x50,0x01,0x20,0x01,0x00,
	
	/*--  45 勿  --*/ 
	0x10,0x00,0x10,0x00,0x10,0x04,0x1F,0xFE,
	0x24,0x44,0x44,0x44,0x84,0x44,0x08,0x44,
	0x08,0x84,0x08,0x84,0x10,0x84,0x11,0x04,
	0x21,0x04,0x42,0x04,0x04,0x28,0x08,0x10,
	
	/*--  46 扰  --*/ 
	0x10,0x40,0x10,0x50,0x10,0x48,0x10,0x40,
	0xFC,0x44,0x13,0xFE,0x14,0x40,0x18,0x60,
	0x30,0xA0,0xD0,0xA0,0x10,0xA0,0x10,0xA0,
	0x11,0x22,0x11,0x22,0x52,0x1E,0x24,0x00,
	
	/*--  47 关  --*/ 
	0x10,0x10,0x08,0x18,0x04,0x20,0x04,0x48,
	0x7F,0xFC,0x01,0x00,0x01,0x00,0x01,0x04,
	0xFF,0xFE,0x01,0x00,0x02,0x80,0x02,0x80,
	0x04,0x40,0x08,0x30,0x30,0x0E,0xC0,0x04,
	
	/*--  48 闭  --*/ 
	0x20,0x04,0x1B,0xFE,0x08,0x04,0x40,0x84,
	0x40,0xA4,0x5F,0xF4,0x40,0x84,0x41,0x84,
	0x42,0x84,0x44,0x84,0x48,0x84,0x50,0x84,
	0x40,0x84,0x42,0x84,0x41,0x14,0x40,0x08
};

#endif