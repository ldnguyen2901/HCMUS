#include "Ellipse.h"

/*--------------------------------------------*
 *					Ellipse					  *
 *--------------------------------------------*/

bool _Ellipse::isPointInside(Point p) const
{
	double r = 0.015;
	double dx = p.getX() - T.getX(), dy = p.getY() - T.getY();
	return (pow(dx / xR, 2) + pow(dy / yR, 2) ) < 1;
}

bool _Ellipse::isPointInLine(Point p) const
{
	double r = 0.015;
	double dx = p.getX() - T.getX(), dy = p.getY() - T.getY();
	double x = pow(dx / xR, 2) + pow(dy / yR, 2) - 1;
	return (fabs(x) <= r);
}

bool _Ellipse::intersection(_Shape* aS, HDC hdc, COLORREF c) const
{
	bool check = 0;
	for (double i = T.getX() - xR; i <= T.getX() + xR; i++)
		for (double j = T.getY() - yR; j <= T.getY() + yR; j++)
		{
			Point t(i, j);
			if (this->isPointInside(t) && aS->isPointInside(t))
			{
				SetPixel(hdc, i, j, c);
				check = 1;
			}
			if ((this->isPointInLine(t) && aS->isPointInside(t)) || (this->isPointInside(t) && aS->isPointInLine(t)) || (this->isPointInLine(t) && aS->isPointInLine(t)))
			{
				Ellipse(hdc, i - 0.5, j - 0.5, i + 0.5, j + 0.5);
				check = 1;
			}
		}
	return check;
}

