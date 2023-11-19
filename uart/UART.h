/*
 * UART.h
 *
 * Created: 19.11.2023 00:51:22
 *  Author: Root
 */ 


#ifndef UART_H_
#define UART_H_

void uart_begin(uint8_t uart_hiz);
void uart_write(uint8_t veri);
void uart_char(char *karakter);
void uart_int(int veri);

#endif /* UART_H_ */