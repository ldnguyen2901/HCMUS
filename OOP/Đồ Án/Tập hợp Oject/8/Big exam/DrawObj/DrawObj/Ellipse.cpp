#include "stdafx.h"
#include "Ellipse.h"


void CEllipse::set(double x1, double y1, double x2, double y2)
{
	T.set((x1 + x2) / 2, (y1 + y2) / 2);
	xR = fabs((x2 - x1)) / 2; yR = fabs((y2 - y1)) / 2;
}

void CEllipse::set2(double x2, double y2)
{
	double x1 = T.getX() - xR,
		y1 = T.getY() - yR;
	set(x1, y1, x2, y2);
}

bool CEllipse::isPointInside(Point p) const
{
	double dx = p.getX() - T.getX(), dy = p.getY() - T.getY();
	return sqr(dx/xR) + sqr(dy/yR) <= 1 ;
}

int FindEllipse(CEllipse ae[], int n, double x, double y)
{
	for (int i = n - 1; i >= 0; i--)
		if (ae[i].isInside(x, y))
			return i;
	return -1;
}
