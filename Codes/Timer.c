#include "Timer.h"
void SysTickInit(){
NVIC_ST_CTRL_R=0;
NVIC_ST_RELOAD_R=0X00FFFFFF;
NVIC_ST_CURRENT_R=0;
NVIC_ST_CTRL_R=0X00000005;
}
void delay1ms(){
SysTickInit();
NVIC_ST_RELOAD_R=80000-1;
NVIC_ST_CURRENT_R=0;
while((NVIC_ST_CTRL_R&0X00010000)==0);
}

void delayXms( uint32_t X){
unsigned long i;
	for(i=0;i<X;i++){
	delay1ms();
	}
}
