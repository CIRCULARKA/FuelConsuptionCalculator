#include "../Headers/add_percentage.h"

void add_percentage(double& value, double percentage)
{
	double temp;
	temp = value / 100.0;
	temp *= percentage;
	value += temp;
}
