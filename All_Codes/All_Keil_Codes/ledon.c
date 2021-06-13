#include "ledon.h"

void LedOn (float distance)
{
	if( distance >= 100)
		GPIO_PORTF_DATA_R|=0x08;
	return;
}