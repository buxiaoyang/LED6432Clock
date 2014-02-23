/***************************************************************************/
// ����LED3264��������
// ģ�飺���������ţ��궨��
// �ļ���_PinsValues.h
// ���ߣ������D
// �汾��1.9.7
// ���ڣ�2012��2��10��
/***************************************************************************/

#ifndef _PINSVALUES_H_
#define _PINSVALUES_H_
/*�������Ͷ���*/
#define uint8	 unsigned char
#define uint16	 unsigned short 
#define uint32	 unsigned long 

#define LS138_E_DDR		DDRB
#define LS138_E_PORT	PORTB
#define LS138_E_BIT		PB3

#define LS138_A_DDR		DDRB
#define LS138_A_PORT	PORTB
#define LS138_A_BIT		PB0
#define LS138_A_H		LS138_A_PORT |= (1<<LS138_A_BIT)
#define LS138_A_L		LS138_A_PORT &= ~(1<<LS138_A_BIT)

#define LS138_B_DDR		DDRB
#define LS138_B_PORT	PORTB
#define LS138_B_BIT		PB1
#define LS138_B_H		LS138_B_PORT |= (1<<LS138_B_BIT)
#define LS138_B_L		LS138_B_PORT &= ~(1<<LS138_B_BIT)

#define LS138_C_DDR		DDRB
#define LS138_C_PORT	PORTB
#define LS138_C_BIT		PB2
#define LS138_C_H		LS138_C_PORT |= (1<<LS138_C_BIT)
#define LS138_C_L		LS138_C_PORT &= ~(1<<LS138_C_BIT)

#define LS138_D_DDR		DDRB
#define LS138_D_PORT	PORTB
#define LS138_D_BIT		PB4
#define LS138_D_H		LS138_D_PORT |= (1<<LS138_D_BIT)
#define LS138_D_L		LS138_D_PORT &= ~(1<<LS138_D_BIT)

#define HC595_D0_DDR		DDRD
#define HC595_D0_PORT		PORTD
#define HC595_D0_BIT		PD4
#define HC595_D0_H		HC595_D0_PORT |= (1<<HC595_D0_BIT)
#define HC595_D0_L		HC595_D0_PORT &= ~(1<<HC595_D0_BIT)

#define HC595_D1_DDR		DDRD
#define HC595_D1_PORT		PORTD
#define HC595_D1_BIT		PD5
#define HC595_D1_H		HC595_D1_PORT |= (1<<HC595_D1_BIT)
#define HC595_D1_L		HC595_D1_PORT &= ~(1<<HC595_D1_BIT)

#define HC595_D2_DDR		DDRA
#define HC595_D2_PORT		PORTA
#define HC595_D2_BIT		PA1
#define HC595_D2_H		HC595_D2_PORT |= (1<<HC595_D2_BIT)
#define HC595_D2_L		HC595_D2_PORT &= ~(1<<HC595_D2_BIT)

#define HC595_D3_DDR		DDRA
#define HC595_D3_PORT		PORTA
#define HC595_D3_BIT		PA2
#define HC595_D3_H		HC595_D3_PORT |= (1<<HC595_D3_BIT)
#define HC595_D3_L		HC595_D3_PORT &= ~(1<<HC595_D3_BIT)

#define HC595_LAT_DDR		DDRD
#define HC595_LAT_PORT		PORTD
#define HC595_LAT_BIT		PD2
#define HC595_LAT_H		HC595_LAT_PORT |= (1<<HC595_LAT_BIT)
#define HC595_LAT_L		HC595_LAT_PORT &= ~(1<<HC595_LAT_BIT)

#define HC595_SCK_DDR		DDRD
#define HC595_SCK_PORT	PORTD
#define HC595_SCK_BIT		PD3
#define HC595_SCK_H		HC595_SCK_PORT |= (1<<HC595_SCK_BIT)
#define HC595_SCK_L		HC595_SCK_PORT &= ~(1<<HC595_SCK_BIT)

#define KEY_UP_DDR		DDRC
#define KEY_UP_PORT		PORTC
#define KEY_UP_PIN		PINC
#define KEY_UP_BIT		PC6
#define KEY_UP_H		KEY_UP_PIN & (1<<KEY_UP_BIT)
#define KEY_UP_L		!(KEY_UP_PIN & (1<<KEY_UP_BIT))

#define KEY_DOWN_DDR		DDRC
#define KEY_DOWN_PORT		PORTC
#define KEY_DOWN_PIN		PINC
#define KEY_DOWN_BIT		PC7
#define KEY_DOWN_H			KEY_DOWN_PIN & (1<<KEY_DOWN_BIT)
#define KEY_DOWN_L			!(KEY_DOWN_PIN & (1<<KEY_DOWN_BIT))

#define KEY_MODE_DDR		DDRD
#define KEY_MODE_PORT		PORTD
#define KEY_MODE_PIN		PIND
#define KEY_MODE_BIT		PD0
#define KEY_MODE_H			KEY_MODE_PIN & (1<<KEY_MODE_BIT)
#define KEY_MODE_L			!(KEY_MODE_PIN & (1<<KEY_MODE_BIT))

#define KEY_DISPLAY_COLOR_DDR		DDRD
#define KEY_DISPLAY_COLOR_PORT		PORTD
#define KEY_DISPLAY_COLOR_PIN		PIND
#define KEY_DISPLAY_COLOR_BIT		PD1
#define KEY_DISPLAY_COLOR_H			KEY_DISPLAY_COLOR_PIN & (1<<KEY_DISPLAY_COLOR_BIT)
#define KEY_DISPLAY_COLOR_L			!(KEY_DISPLAY_COLOR_PIN & (1<<KEY_DISPLAY_COLOR_BIT))

#define DQ_DDR		DDRD
#define DQ_PORT		PORTD
#define DQ_PIN		PIND
#define DQ_BIT		PD7
#define DQ_INPUT 	DQ_DDR &= ~(1 << DQ_BIT)    
#define DQ_OUT 		DQ_DDR |= (1 << DQ_BIT)    
#define DQ_LO 		DQ_PORT &= ~(1 << DQ_BIT)  
#define DQ_HI 		DQ_PORT |= (1 << DQ_BIT)   
#define DQ_R 		DQ_PIN & (1 << DQ_BIT)     


#define YearThousand RunParameter[0]
#define YearHundred RunParameter[1]
#define YearTen RunParameter[2]
#define YearOne RunParameter[3]
#define MonthTen RunParameter[4]
#define MonthOne RunParameter[5]
#define DayTen RunParameter[6]
#define DayOne RunParameter[7]
#define HourTen RunParameter[8]
#define HourOne RunParameter[9]
#define MinuteTen RunParameter[10]
#define MinuteOne RunParameter[11]
#define SecondTen RunParameter[12]
#define SecondOne RunParameter[13]
#define Week RunParameter[14]
#define TemperatureTen RunParameter[15]
#define TemperatureOne RunParameter[16]
#define TemperatureDecimal RunParameter[17]
#define display_light_Mode RunParameter[18]
#define display_light RunParameter[19]
#define moveSpeed RunParameter[20]
#define Mode RunParameter[21]
#define AjustTimeMode RunParameter[22]
#define AjustTimeTen RunParameter[23]
#define AjustTimeOne RunParameter[24]
#define AjustTimeIsAjusted  RunParameter[25]
#define Display_color  RunParameter[26]
#define Display_BigNumber_Font  RunParameter[27]
#define Voice_Mode  RunParameter[28]

#define SET_DISPLAY_LIGHT OCR0= (display_light-1)*25+1

#define W_ADD_COM 0xa2
#define R_ADD_COM 0xa3
#define SLAW 0x18
#define ERR_SLAW 1

#define DS18B20_Delay 5

//uint8 display_light; /* ��Ļ���� 1 �� 8 */
//uint8 moveSpeed; /* ���������ٶ� 1 �� 8 */
//uint8 Mode; /* ����ģʽ 0���������� 1�������� 2�������� 3�������� 4������ʱ 5�����ڷ� 6����������  */
			  /* 7����������ģʽ 8����������  9������У��ʱ�� 10�����ñ�ʱ 26�������ٶ� 27���������� 28����ʾ��ӭ���� */

uint8 RunParameter[29] = {	2,	//0 ��ǧλ
							0, 	//1 ���λ
							1, 	//2 ��ʮλ
							2, 	//3 ���λ
							0,	//4 ��ʮλ
							1,	//5 �¸�λ
							1,	//6 ��ʮλ
							7,	//7 �ո�λ
							2,	//8 ʱʮλ
							2,	//9 ʱ��λ
							1, 	//10 ��ʮλ
							9,	//11 �ָ�λ
							0,	//12 ��ʮλ
							0,	//13 ���λ
							2,	//14 ����
							2,	//15 �¶�ʮλ
							3,	//16 �¶ȸ�λ
							4,	//17 �¶�С��
							0, 	//18 ����ģʽ 0���Զ� 1���ֶ�
							7,	//19 ����
							1,	//20 �ٶ�
							0,	//21 ����ģʽ 
							0,	//22 У��ʱ�� 0���� 1����
							0,	//23 У��ʱ�� ʮλ
							0,	//24 У��ʱ�� ��λ
							0,	//25 �Ƿ��Ѿ�Уʱ״̬λ 0��δУʱ 1����Уʱ
							0,	//26 ��ʾģʽ 0������ 1������ 2������ 3����׻��� 4���̵׻���
							0,  //27 ���������� 0 1 2
							0	//28 ������ʱģʽ 0:���� 1:���� 2:�ر� 
						};

#endif
