/*
 * uart.c
 *
 * Created: 21-Apr-22 11:50:57 PM
 * Author : Faisal
 */ 

#include <avr/io.h>
#include <util/delay.h>

void uart_init(void){
	UCSRB = 1 << TXEN;                                    // 1. Enable the transmitting pin
	UCSRC = (1 << UCSZ1) | (1 << UCSZ0) | (1 << URSEL);   // 2. Set the data size and enable writing to UCSRC
	UBRRL = 0x33;                                         // 3. define the baud rate
}

void uart_send(unsigned char ch){
	while(! (UCSRA & (1 << UDRE)));
	UDR = ch;
}

int main()
{
	char str[] = "Hello from AVR! \n\r";
	uart_init();

	while(1)
	{

		int i = 0;
		for (i=0; str[i] != '\0'; i++)
			uart_send(str[i]);
		_delay_ms(1000);
		
	}
	return (0);
}
