/*
 * UART.c
 *
 * Created: 19.11.2023 00:51:37
 *  Author: Root
 */ 

#include <avr/io.h>
#include "UART.h"

void uart_begin(uint8_t uart_hiz){
	
	UBRR0H=(uart_hiz>>8);
	UBRR0L=uart_hiz;
	
	UCSR0B=(1<<TXEN0) | (1<<RXEN0);
	UCSR0C=(1<<UCSZ00) | (1<<UCSZ01);	
}
void uart_write(uint8_t veri){
	
	while(!(UCSR0A & (1<<UDRE0)));

	UDR0=veri;
}

void uart_char(char *karakter){
	
	uint8_t sayac=0;
	while(karakter[sayac]!='\0'){
		uart_write(karakter[sayac]);
		sayac++;
	}	
}
void uart_int(int veri){
	
	volatile int basamak_sayi=10;
	volatile int basamak=1;
	int i;
	if(veri>9)
	{
		for(i=0; i<veri; i++)
		{
			if(i>basamak_sayi)
			{
				basamak_sayi*=10;
				basamak++;
			}
		}
		char g_veri[basamak];
		int j,sayi;
		for(j=0; j<basamak; j++)
		{
			sayi='0'+(veri%basamak_sayi)/(basamak_sayi/10);
			g_veri[j]=sayi;
			basamak_sayi=basamak_sayi/10;
		}
		int f;
		for(f=0; f<basamak; f++)
		{
			
			uart_write(g_veri[f]);
		}
	}
	else
	{
		char v='0'+veri;
		uart_write(v);
	}
	
}