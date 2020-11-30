#include<avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
#include"string.h"

#include"lcd.h"


volatile uint8_t DATA_RX[8];
volatile uint8_t RX_POS=0;
volatile uint8_t PACKET_Received=0;

void main()
{
    USARTInit(51);
	InitADC();
	uint16_t adc_value;
	//uint8_t FSR1,FSR2,FSR3,FSR4,FSR5,FSR6,FSR7,FSR8;
    
	char arr[7];
	InitLCD(0);
	LCDClear();
	LCDWriteStringXY(5,0,"Welcome");
   _delay_ms(10);
	LCDClear();
	LCDWriteStringXY(0,0,"Heater Control System");
   _delay_ms(10);
   unsigned char FSR1;
   	LCDClear();
    sei();

    while (1)
         {
       
	              LCDClear();
				 /* LCDData(DATA_RX[5]);
		          LCDData(DATA_RX[6]);
				  LCDData(DATA_RX[7]);*/

                 FSR1=(((DATA_RX[5]-'0')*10) +(DATA_RX[6]-'0'));
                 LCDWriteIntXY(0,0,FSR1,3);
				 
				 write("FSR1:");
				 itoa(FSR1,arr,10);
				 write(arr);
				 //USARTWriteChar(DATA_RX[5]);
                 //USARTWriteChar(DATA_RX[6]);
				 //USARTWriteChar(DATA_RX[7]);
      			 USARTWriteChar('\n');

				  /*FSR1=DATA_RX[0];
				  FSR2=DATA_RX[1];
				  FSR3=DATA_RX[2];
				  FSR4=DATA_RX[3];
				  FSR5=DATA_RX[4];
				  FSR6=DATA_RX[5];
				  FSR7=DATA_RX[6];
				  FSR8=DATA_RX[7];*/


				 /* LCDWriteIntXY(0,0,DATA_RX[0],2);
				  LCDWriteIntXY(3,0,DATA_RX[1],2);
				  LCDWriteIntXY(6,0,DATA_RX[2],2);
				  LCDWriteIntXY(9,0,DATA_RX[3],2);
				  LCDWriteIntXY(12,0,DATA_RX[4],2);
				  LCDWriteIntXY(0,1,DATA_RX[5],2);
				  LCDWriteIntXY(3,1,DATA_RX[6],2);
				  LCDWriteIntXY(6,1,DATA_RX[7],2);
				  LCDWriteIntXY(9,1,DATA_RX[8],2);*/




				  _delay_ms(500);


		    
		 }	

}




ISR(USART_RXC_vect)
{
		DATA_RX[RX_POS]=UDR;
		//if((DATA_RX[RX_POS]==0x0A)||(RX_POS==7))
		if(DATA_RX[RX_POS]==0x0A)
		{
			RX_POS=0;
		}
		else
			RX_POS++;
			sei();
	
	
}

ISR(USART_TXC_vect)
	 {
		cli();
	 }
