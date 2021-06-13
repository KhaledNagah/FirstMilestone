#include "Distance.h"
//lat_arr is the latitude array we get from the UART
//long_arr is the longitude array we get from the UART
float degreestoradians(float degrees)
{
	return (degrees*PI)/180;
}
int distance_calculate(float lat_previous,float lat_current,float long_previous,float long_current)
{
	float a;
	float c;
	float dlat=degreestoradians(lat_current-lat_previous);
	float dlong=degreestoradians(long_current-long_previous);
	lat_previous=degreestoradians(lat_previous);
	lat_current=degreestoradians(lat_current);
	a=sin(dlat/2)*sin(dlat/2)+sin(dlong/2)*sin(dlong/2)*cos(lat_previous)*cos(lat_current);
	c=2*atan2(sqrt(a),sqrt(1-a));
	return RADIUS*c *1000;
}