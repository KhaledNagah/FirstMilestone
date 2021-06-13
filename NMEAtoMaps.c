#include "NMEAtoMaps.h"
float NMEAtoMaps(float x){
	return (int)(x/100)+((((int)(x))%100)+x-(int)(x))/60;
}