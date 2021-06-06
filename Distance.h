#ifndef Distance_h
#define Distance_h
#define RADIUS 6371
#define PI 3.14
extern float lat_arr[1000];
extern float long_arr[1000];
#include "stdint.h"
#include "tm4c123gh6pm.h"
#include <math.h>
float degreestoradians(float);
float distance_calculate(float,float,float,float);
#endif
