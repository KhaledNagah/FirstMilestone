#include "sevensegment.h"
#include "Timer.h"

void display (float distance)
{
		int x=100;
	
		int units, tens, hundreds,temp;
		double counter;
		while(x){
			float distance2;
			distance2=distance;
			units = (int)distance2 %10;
			units=units<<4;
			distance2/=10;
			tens = (int)distance2 % 10;
			tens=tens<<4;
			distance2/=10;
			hundreds=(int)distance2%10;
			hundreds=hundreds<<4;
			

			GPIO_PORTB_DATA_R = (	GPIO_PORTB_DATA_R &= 0xf0)  | (0xf3);
			GPIO_PORTB_DATA_R = (	GPIO_PORTB_DATA_R &= 0x0f)  | (hundreds);
			delay1ms();
			GPIO_PORTB_DATA_R = (	GPIO_PORTB_DATA_R &= 0xf0)  | (0xf5);
			GPIO_PORTB_DATA_R = (	GPIO_PORTB_DATA_R &= 0x0f)  | (tens);
			delay1ms();
			GPIO_PORTB_DATA_R = (	GPIO_PORTB_DATA_R &= 0xf0)  | (0xf6);

			GPIO_PORTB_DATA_R = (	GPIO_PORTB_DATA_R &= 0x0f)  | (units);
			delay1ms();
			x--;
		}
		GPIO_PORTB_DATA_R|=0x07;
return;
}
