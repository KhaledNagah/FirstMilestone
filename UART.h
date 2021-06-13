#ifndef UART_h
#define UART_h
#include "stdint.h"
#include "Timer.h"
#include "tm4c123gh6pm.h"
/*void UARTInit();
uint8_t UARTReads();
void UARTWrites(uint8_t n);*/

#define GPIO_PA10_M 0x03

void init_UART0(void);

uint8_t available_UART0(void);

uint8_t read_UART0(void);

void write_UART0(char data);

void init_UART7(void);

uint8_t available_UART7(void);

uint8_t read_UART7(void);

void write_UART7(uint8_t data);

#endif