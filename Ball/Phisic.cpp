#include "Phisic.h"
#include <math.h>


void Phisic::Trajectoy(double *x, double *y, double angle, double speed)
{
	*x += 0.01;
	*y = ((*x*tan(angle)) - ((10 * (i*i) * 1) / (2 * pow(speed, 2)*pow(cos(angle), 2))));
	*x = 10 * *x;
	*y = 10 * *y;
}

Phisic::Phisic()
{
}


Phisic::~Phisic()
{
}
