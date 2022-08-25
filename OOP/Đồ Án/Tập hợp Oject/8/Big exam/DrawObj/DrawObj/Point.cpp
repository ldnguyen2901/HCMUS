#include "stdafx.h"
#include <iostream>
using namespace std;

#include "Point.h"

void Point::rotate(Point T, double goc)
{
	double cosa = cos(goc);
	double sina = sin(goc);
	double X = (x - T.x)*cosa - (y - T.y)*sina + T.x;
	y = (x - T.x)*sina + (y - T.y)*cosa + T.y;
	x = X;
}

void Point::input()
{
	cin >> x >> y;
}

void Point::output() const
{
	cout << "(" << x << "," << y << ")";
}

void Point::draw(HDC hdc, COLORREF c) const
{
	SetPixel(hdc, int(x), int(y), c);
}

void Point::mark(HDC hdc, int size, COLORREF c) const
{
	for (int i = -size; i <= size; i++)
		SetPixel(hdc, x + i, y, c);
	for (int i = -size; i <= size; i++)
		SetPixel(hdc, x, y + i, c);
}
