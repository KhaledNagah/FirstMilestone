#include "Ports.h"
#include "Distance.h"
#include "UART.h"
#include "ledon.h"	
#include "sevensegment.h"
#include "stdio.h"
#include "parse.h"
#include "NMEAtoMaps.h"
#include <math.h>
void SystemInit(){}
int main(){
	char arr[70]; //This array contains the characters of the sentence starting with $GPGGA which contains latitude & longitude to be parsed
	char test[9]; //This array contains the characters of the latitude to be sent to the terminal
	char test2[9];//This array contains the characters of the longitude to be sent to the terminal
	double lat_arr[500]; //Array for the latitudes
	double long_arr[500];//Array for the longitudes
	int distance=0;
	char c; // It is used to know that we are in the $GPGGA sentence to capture this sentence and parse it
	int flag=0; //This flag becomes one if we captured the GPGGC sentence so we will parse
	int flag2=200; //We start capturing the $GPGGA sentence after reading 200 characters to make sure that it is syntically correct
	int counter=0; //counts the coordinates got from the GPS
	int k; //Index for arr
	int y=9; // Index for test & test2 arrays 
	PortsInit();
	init_UART0();
	init_UART7();
	while(1){	
		c=read_UART7();
		if (c=='G'&&flag2<=0)
		{
			c=read_UART7();
		  if (c=='G'){
				arr[0]='$';arr[1]='G';arr[2]='P';arr[3]='G';
				k=4;
				while(k<70)
				{
					arr[k]=c;
					c=read_UART7();
					k++;
				}
				flag=1;
			}
		}
		flag2--;
		if(flag==1) {
				
				if(counter<5){ //We start strong in the latitude and longitude arrays after getting 5 coordinates 
					lat_arr[counter]=parse_lat(arr);
					lat_arr[counter]=NMEAtoMaps(lat_arr[counter]);
					long_arr[counter]=parse_long(arr);
					long_arr[counter]=NMEAtoMaps(long_arr[counter]);
				}
				else{
					lat_arr[counter]=parse_lat(arr);
					lat_arr[counter]=NMEAtoMaps(lat_arr[counter]);
					long_arr[counter]=parse_long(arr);
					long_arr[counter]=NMEAtoMaps(long_arr[counter]);
					distance+=(distance_calculate(lat_arr[counter-1],lat_arr[counter],long_arr[counter-1],long_arr[counter]));
					display(distance);
				}
				sprintf(test,"%f",lat_arr[counter]); //stores the latitude in test array to be sent to the terminal character by character
				while(y){
				write_UART0(test[9-y]);
					y--;
				}
				y=9;				
				write_UART0(',');
				sprintf(test2,"%f",long_arr[counter]); //stores the longitude in test2 array to be sent to the terminal character by character
				while(y){
				write_UART0(test2[9-y]);
					y--;
				}
				y=9;
				write_UART0('\r');
				write_UART0('\n');
				counter++;
				flag=0;	
		}		
		LedOn(distance);
	}
}
	
