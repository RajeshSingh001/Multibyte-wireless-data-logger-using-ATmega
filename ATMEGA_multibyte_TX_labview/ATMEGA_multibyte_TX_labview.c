#include<avr/io.h>
#include<util/delay.h>
//#include <avr/interrupt.h>
//#include"string.h"

#include"lcd.h"

void main()
{
    USARTInit(51);
	InitADC();
	uint16_t adc_value;
	uint8_t FSR1;
	char arr[10];
	InitLCD(0);
	LCDClear();
	LCDWriteStringXY(5,0,"Welcome");
   _delay_ms(10);
	LCDClear();
	LCDWriteStringXY(0,0,"Heater Control System");
   _delay_ms(10);
   	LCDClear();
     while (1)
   {
   		
        adc_value=ReadADC(0);
       	FSR1=adc_value/2;
		LCDWriteStringXY(0,0,"Temp:")
		LCDWriteIntXY(6,0,FSR1,2);
		write("FSR1:");
	/*	USARTWriteChar('F');
		USARTWriteChar('S');
		USARTWriteChar('R');
		USARTWriteChar(':');*/
		itoa(FSR1,arr,10);
		write(arr);
     	USARTWriteChar('\n');
	//	USARTWriteChar(FSR1);
		_delay_ms(100);

	}
   
   }
		
	



