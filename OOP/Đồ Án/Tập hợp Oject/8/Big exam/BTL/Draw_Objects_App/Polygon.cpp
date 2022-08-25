#include <iostream>
#include "Polygon.h"

using namespace std;

Point _Polygon::pointsDefault[] = { Point(50, 50), Point(50, 150), Point(200,150) };

void _Polygon::setPoints(int n, Point* p)
{
	if (p == NULL)
	{
		points = new Point[vertices = n];
		memcpy(points, pointsDefault, n * sizeof(Point));
	}
	else
	{
		points = new Point[vertices = n];
		memcpy(points, p, n * sizeof(Point));
	}
}

Point _Polygon::getCenter() const
{
	double xx = 0, yy = 0;
	for (int i = 0; i < vertices; i++)
	{
		xx += points[i].getX();
		yy += points[i].getY();
	}
	return Point(xx / vertices, yy / vertices);
}

void _Polygon::move(double dx, double dy)
{
	for (int i = 0; i < vertices; i++)
		points[i].move(dx, dy);
}

void _Polygon::scale(Point Center, double s)
{
	for (int i = 0; i < vertices; i++)
		points[i].scale(Center, s);
}

void _Polygon::rotate(Point Center, double rad)
{
	for (int i = 0; i < vertices; i++)
		points[i].rotate(Center, rad);
}

#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

bool _Polygon::isPointInside(Point p) const
{
	int count = 0;
	double xinters;
	Point p1, p2;
	for (int i = 0; i < vertices; i++)
	{
		p1 = points[i];
		p2 = points[(i + 1) % vertices];
		if (p.getY() > MIN(p1.getY(), p2.getY()) && p.getY() <= MAX(p1.getY(), p2.getY()))
			if (p.getX() <= MAX(p1.getX(), p2.getX()))
				if (p1.getY() != p2.getY())
				{
					xinters = (p.getY() - p1.getY()) * (p2.getX() - p1.getX()) / (p2.getY() - p1.getY()) + p1.getX();
					if (p1.getX() == p2.getX() || p.getX() < xinters)
						count++;
				}
	}
	return (count % 2 != 0);
}

bool _Polygon::isPointInLine(Point p) const
{
	double a, b, d;
	double r = 0.01;
	for (int i = 0; i < vertices; i++)
	{
		d = p.distance(points[i]) + p.distance(points[(i + 1) % vertices]) - points[i].distance(points[(i + 1) % vertices]);
		if (fabs(d) <= 0.03)
			return true;
	}
	return false;
}

bool _Polygon::intersection(_Shape* aS, HDC hdc, COLORREF c) const
{
	bool check = 0;
	double x_min = points[0].getX(), y_min = points[0].getY(), x_max = points[0].getX(), y_max = points[0].getY();
	for (int i = 1; i < vertices; i++)
	{
		if (x_min > points[i].getX())
			x_min = points[i].getX();
		if (x_max < points[i].getX())
			x_max = points[i].getX();
		if (y_min > points[i].getY())
			y_min = points[i].getY();
		if (y_max < points[i].getY())
			y_max = points[i].getY();
	}
	for (double i = x_min; i <= x_max; i++)
		for (double j = y_min; j <= y_max; j++)
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

const int MAX_POINTS = 1000;

void _Polygon::draw(HDC hdc, COLORREF c) const
{
	static POINT apt[MAX_POINTS];
	for (int i = 0; i < vertices; i++)
	{
		apt[i].x = points[i].getX();
		apt[i].y = points[i].getY();
	}
	Polygon(hdc, apt, vertices);
}