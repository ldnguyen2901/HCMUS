#include "Shape.h"

const double PI = atan(1) * 4;

double sumOfArea(_Shape* aS[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += aS[i]->getArea();
	return sum;
}


