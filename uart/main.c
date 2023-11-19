/*
 * uart.c
 *
 * Created: 19.11.2023 00:50:27
 * Author : Root
 */ 

#include <avr/io.h>
#include "UART.h"
#define F_CPU 16000000UL
#define baud 9600
#define baud_calisma (F_CPU/16/baud)-1//mikrokontrolcü veri kaðýdý üzerinden frekans hýzýna göre baud denklemi seçilmelidir.
#include <util/delay.h>

int main(void)
{
    uart_begin(baud_calisma);
	uart_char("hello world");uart_char("\r\n");
	uart_int(1023);

	while (1) 
    {
		
    }
}

