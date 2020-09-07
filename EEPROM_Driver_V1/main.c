#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "eeprom.h"
#include "I2C.h"

void main(void)
{
	unsigned char v1,v2,v3;
   // Write your code here
	EEpromInit();
	_delay_ms(500);
	while (1)
	{

		//EEpromWriteByte(1,50);
		//_delay_ms(500);
        //
		//EEpromWriteByte(3,100);
		//_delay_ms(500);

		DDRA = 0xFF;
		PORTA= 0x00;

		v1 = EEpromReadByte(1);
		v2 = EEpromReadByte(3);

		v3 = v1+v2;
		if (v3 == 150)
		{
			PORTA = 0xFF;
		}
		else
		{
			PORTA = 0x00;
		}
	}
}
