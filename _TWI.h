/***************************************************************************/
// ����LED3264��������
// ģ�飺I2C ����
// �ļ���_TWI.h
// ���ߣ������D
// �汾��1.9.7
// ���ڣ�2012��2��10��
/***************************************************************************/

#ifndef _TWI_H_
#define _TWI_H_

//��������: i2cͨ�ų�ʼ��
void twi_init(void)
{
 TWCR= 0x00; //disable twi
 TWBR= (1<<6) | (1<<5) | (1<<2); //set bit rate
 TWSR= 0x00; //set prescale
 TWAR= 0x00; //set slave address
 TWCR= (1<<TWEN); //enable twi
}

//i2cͨ�ſ�ʼ
void i2cstart(void)
{ 
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN); 
   	while (!(TWCR & (1<<TWINT)));
}

//i2cд����,����TWI״̬
unsigned char i2cwt(unsigned char data)
{ 
	TWDR = data;
   	TWCR = (1<<TWINT) | (1<<TWEN);
   	while (!(TWCR & (1<<TWINT)));
   	asm("nop");
   	return(TWSR&0b11111000);
}

//i2c������
unsigned char i2crd(void)
{
   	TWCR= (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
   	while (!(TWCR & (1<<TWINT)));
   	return(TWDR);
}

//��������: i2cֹͣ
void i2cstop(void)
{ 
   TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}

#endif
