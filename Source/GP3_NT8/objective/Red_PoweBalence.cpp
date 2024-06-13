#include "Red_PoweBalence.h"

//Deprecated code
int URedPowerBalance::sliderValuChack(float Value)
{
	int PowerZoneIndex {0};
	if (Value > 0.9 || Value < 0.09)
	{
		PowerZoneIndex = 1;
	}
	else if (Value > 0.75 && Value < 0.9 || Value > 0.09 && Value < 0.29)
	{
		PowerZoneIndex = 2;
	}
	else if (Value > 0.1 && Value < 0.75)
	{
		PowerZoneIndex = 3;
	}
	return PowerZoneIndex;
}


int URedPowerBalance::SliderValueCheck(float Value, float RedBarHigher, float RedBarLower, float YellowBarLower, float YellowBarHigher)
{
	int PowerZoneIndex {0};
	if(Value < YellowBarHigher && Value > YellowBarLower)
	{
		PowerZoneIndex = 2;
		return PowerZoneIndex;
	}
	if(Value < RedBarHigher && Value > RedBarLower)
	{
		PowerZoneIndex = 3;
		return PowerZoneIndex;
	}
	return PowerZoneIndex;
	
	/*if(Value > YellowBarHigher || Value < YellowBarLower)
	{
		PowerZoneIndex = 1;
	}
	else if(Value < YellowBarHigher && Value > RedBarHigher ||
		Value > YellowBarLower && Value < RedBarLower)
	{
		PowerZoneIndex = 2;
	}
	else if(Value > RedBarLower && Value < RedBarHigher)
	{
		PowerZoneIndex = 3;
	}*/
}

