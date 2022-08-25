#include "Ellipse.h"

/*--------------------------------------------*
 *					Ellipse					  *
 *--------------------------------------------*/

bool _Ellipse::isPointInside(Point p) const
{
	double dx = p.getX() - T.getX(), dy = p.getY() - T.getY();
	return (pow(dx / xR, 2) + pow(dy / yR, 2) - 1) < exp(-4);
}

bool _Ellipse::isPointInLine(Point p) const
{
	double dx = p.getX() - T.getX(), dy = p.getY() - T.getY();
	double x = pow(dx / xR, 2) + pow(dy / yR, 2) - 1;
	return (x >= -0.01 && x <= 0.01);
}

bool _Ellipse::intersection(_Shape* aS, HDC hdc, COLORREF c) const
{
	bool check = 0;
	for (int i = T.getX() - xR; i <= T.getX() + xR; i++)
		for (int j = T.getY() - yR; j <= T.getY() + yR; j++)
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

//void _Ellipse::set(double x1, double y1, double x2, double y2)
//{
//	T.set((x1 + x2) / 2, (y1 + y2) / 2);
//	xR = fabs((x2 - x1)) / 2;
//	yR = fabs((y2 - y1)) / 2;
//}
//
//void _Ellipse::set2(double xB, double yB)
//{
//	double x1 = T.getX() - xR, y1 = T.getY() - yR;
//	set(x1, y1, xB, yB);
//}

/*--------------------------------------------*
 *					Circle					  *
 *--------------------------------------------*/

bool _Circle::isPointInside(Point p) const
{
	double dx = p.getX() - T.getX(), dy = p.getY() - T.getY();
	return (sqrt(pow(dx, 2) + pow(dy, 2)) - xR) <= exp(-4);
}

