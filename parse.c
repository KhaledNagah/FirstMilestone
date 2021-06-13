#include "parse.h"

float parse_lat(char* GpsData)
{
	int length = 70;
	int i = 0;
	int Count = 0;
	char Latitude[9];
	float Lat;
	int j = 0, k = 0;
	int start = 0;
	int  End = 0;
	int temp = 0;
	int flag = 0;
	for (i = 0; i < length; i++)
	{
		if (GpsData[i] == ',')
		{
			Count++;
		}
		if (Count == 2&&temp==0)
		{
			start = i + 1;
			temp = 1;
		}
		if (Count == 3&&flag==0)
		{
			End = i - 1;
			flag = 1;
			break;
		}
	}
	for (j = start, k = 0; j <= End; j++, k++)
	{
		Latitude[k] = GpsData[j];
	}
	Lat = atof(Latitude);
	return Lat;
}
float parse_long(char* GpsData)
{
	int length=70;
	int i = 0;
	int Count = 0;
	char Longitude[9];
	float Longt;
	int j = 0, k = 0;
	int start= 0;
	int  End = 0;
	int temp = 0;
	int flag = 0;
		for (i = 0; i < length; i++)
		{

			if (GpsData[i] == ',')
			{
				Count++;
			}
			if (Count == 4 && temp == 0)
			{
				start = i + 1;
				temp = 1;
			}
			if (Count == 5 && flag == 0)
			{

				End = i - 1;
				flag = 1;
				break;
			}
		}
		for (j = start, k = 0; j <= End; j++, k++)
		{
			Longitude[k] = GpsData[j];
		}
		Longt = atof(Longitude);
	return Longt;
}
