/***************************************************************************/
// ����LED3264��������
// ģ�飺����
// �ļ���_USART.h
// ���ߣ������D
// �汾��1.9.7
// ���ڣ�2012��2��10��
/***************************************************************************/

#ifndef _USART_H_
#define _USART_H_

void USART_Init()
{
	// ͨ�Ų���: 8 Data, 1 Stop, No Parity  
	// ������: 
	//����8Mʱ����������  UBRRL=0x33; 
	UCSRB=0x00;  
	UCSRA=0x00; 	     //���ƼĴ������� 
	UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);  //�����ͺͽ��� 
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0); //8λ����λ+1λֹͣλ 
	UCSRA=0x01; 
	UBRRH=0x00;  
	UBRRL=0x33;//����������Ϊ9600 
}

void uart_send_char( unsigned char data )
{
    UDR = data;   
    while(!(UCSRA&(1<<UDRE)));    
}

#endif
