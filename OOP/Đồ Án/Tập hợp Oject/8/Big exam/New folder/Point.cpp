#include <iostream>
#include "Point.h"
#include <math.h>

const double PI = atan(1) * 4;

using namespace std;

const int MAX_POINTS = 1000;

void Point::input()
{
	cout << "Input point:" << endl;
	cout << "Input x:"; cin >> x;
	cout << "Input y:"; cin >> y;
}

void Point::print() const
{
	cout << "Your point: [" << x << ", " << y << "]" << endl;
}

double Point::distance(Point a) const
{
	double dx = this->getX() - a.getX(), dy = this->getY() - a.getY();
	return sqrt(pow(dx, 2) + pow(dy, 2));
}

void Point::rotate(Point center, double rad)
{
	double cosa = cos(rad * PI / 180);
	double sina = sin(rad * PI / 180);
	double X = (x - center.x) * cosa - (y - center.y) * sina + center.x;
	y = (x - center.x) * sina + (y - center.y) * cosa + center.y;
	x = X;
}

void Point::scale(Point center, double tile)
{
	x = (x - center.getX()) * tile + center.getX();
	y = (y - center.getY()) * tile + center.getY();
}

void Point::mark(HDC hdc, int size, COLORREF c)
{
	SetPixel(hdc, x, y, c);
	for (int i = 0; i < size; i++)
	{
		SetPixel(hdc, x - i, y, c);
		SetPixel(hdc, x + i, y, c);
		SetPixel(hdc, x, y - i, c);
		SetPixel(hdc, x, y + i, c);
	}
}

Point Point::setVector(Point b) const
{
	Point c;
	c.x = b.getX() - this->getX();
	c.y = b.getY() - this->getY();
	return c;
}

double Point::calculateAngle(Point vtb) const
{
	double t = (this->getX() * vtb.getX() + this->getY() * vtb.getY());
	double m;
	m = sqrt(pow(this->getX(), 2) + pow(this->getY(), 2)) * sqrt(pow(vtb.getX(), 2) + pow(vtb.getY(), 2));
	return acos(t / m);
}

void Point::draw(HDC hdc) const
{
	Ellipse(hdc, x - 2, y - 2, x + 2, y + 2);
}

