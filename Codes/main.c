#include "Ports.h"
#include "Distance.h"
#include "UART.h"
#include "ledon.h"	
#include "sevensegment.h"
#include "stdio.h"
void SystemInit(){}
int Counter=0; //counts the coordinates i got from the GPS

int main(){
	float distance=0;
	PortsInit();
	lat_arr[0]=49.9917;
	lat_arr[1]=50.0049;
	long_arr[0]=8.41321;
	long_arr[1]=8.42182;
	distance+=distance_calculate(lat_arr[0],lat_arr[1],long_arr[0],long_arr[1]);
	distance=124;
	LedOn(distance);
	display(distance);
	}
	