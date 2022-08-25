#pragma once
#include "framework.h"
#include "Point.h"
#include "Shape.h"

const double PI = atan(1) * 4;

/*--------------------------------------------*
 *					Ellipse					  *
 *--------------------------------------------*/

class _Ellipse : public _Shape
{
protected:
	Point T;
	double xR, yR;
public:
	//constructor and destructor
	_Ellipse(double xT = 700, double yT = 300, double a = 200, double b = 100) : T(xT, yT), xR(a), yR(b) {};
	~_Ellipse() {}
	//setter
	void set(double xT, double yT) { T = Point(xT, yT); xR = 0; yR = 0; }
	//operation
	void move(double dx, double dy) override { T.move(dx, dy); }
	void scale(double s) override { xR *= s; yR *= s; }
	void rotate(double rad) override { if (rad == 90 || rad == -90) { double temp = xR; xR = yR; yR = temp; } }
	void draw(HDC hdc, COLORREF c = RGB(0, 100, 100)) const override { Ellipse(hdc, T.getX() - xR, T.getY() - yR, T.getX() + xR, T.getY() + yR); }
	//check
	bool isPointInside(Point p) const override;
	bool isPointInLine(Point p) const override;
	//intersection
	bool intersection(_Shape* aS, HDC hdc, COLORREF c = RGB(156, 200, 30)) const;
};

/*--------------------------------------------*
 *					Circle					  *
 *--------------------------------------------*/

class _Circle : public _Ellipse
{
public:
	_Circle(double xT = 400, double yT = 400, double a = 150) : _Ellipse(xT, yT, a, a) {};
	~_Circle() {}
};
