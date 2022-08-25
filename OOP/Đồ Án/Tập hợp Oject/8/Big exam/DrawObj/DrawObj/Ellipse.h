#pragma once
#include "stdafx.h"
#include "Point.h"
inline double sqr(double a) 
{
	return a * a;
}

const double PI = atan(1) * 4;

class CEllipse {
	Point T;
	double xR, yR;
public:
	CEllipse(double xT = 400, double yT = 300, double a = 200, double b = 100) 
		: T(xT, yT), xR(a), yR(b) {}
	void move(double dx, double dy) { T.move(dx, dy);  }
	void set(double xT, double yT) { T = Point(xT, yT); xR = 0; yR = 0; }
	void set(double x1, double y1, double x2, double y2);
	void set2(double xB, double yB);
	void scale(double s) { xR *= s; yR *= s; }
	void draw(HDC hdc) const { Ellipse(hdc, T.getX()-xR, T.getY()-yR, T.getX() + xR, T.getY() + yR); }
	bool isPointInside(Point p) const;
	bool isInside(double x, double y) const { return isPointInside(Point(x, y)); }
	double getArea() const { return  PI * xR * yR; }
};


class CCircle : public CEllipse
{
public:
	CCircle(double xT = 300, double yT = 400, double r = 150) : 
		CEllipse(xT, yT, r, r) {}
};


int FindEllipse(CEllipse ae[], int n, double x, double y);

