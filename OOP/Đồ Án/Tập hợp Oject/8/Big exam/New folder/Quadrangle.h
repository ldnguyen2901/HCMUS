#pragma once
#include "Polygon.h"

/*--------------------------------------------*
 *					Quadrangle				  *
 *--------------------------------------------*/

class _Quadrangle : public _Polygon
{
public:
	static Point pointsDefault_Quadra[4];
	_Quadrangle(Point* p = pointsDefault_Quadra) : _Polygon(4, p) {}
	~_Quadrangle() {}
};

/*--------------------------------------------*
 *					Trapezoid				  *
 *--------------------------------------------*/

class _Trapezoid : public _Quadrangle
{
	friend class _Trapezoid;
	Point upperLeftPoint;
	double lowerLeftPointX;
	double shortEdge, longEdge, high;
public:
	//constructor and distructor
	_Trapezoid(double x1 = 50, double y = 100, double x2 = 50, double se = 100, double le = 150, double h = 100) : upperLeftPoint(Point(x1, y)), lowerLeftPointX(x2), shortEdge(se), longEdge(le), high(h) { setPoints(x1, y, x2, se, le, h); }
	_Trapezoid(Point p[4]);
	~_Trapezoid() {}
	//setter
	void setPoints(double x1, double y, double x2, double se, double le, double h);
	bool check(Point p[4]) const;
};

/*--------------------------------------------*
 *					Parallelogram			  *
 *--------------------------------------------*/

class _Parallelogram : public _Trapezoid
{
public:
	//constructor and destructor
	static Point pointDefault_Parallel[4];
	_Parallelogram(double x1 = 50, double y = 100, double x2 = 100, double w = 150, double h = 100) : _Trapezoid(x1, y, x2, w, w, h) {}
	_Parallelogram(Point p[4]);
	//check
	bool check(Point p[4]) const;
};

/*--------------------------------------------*
 *					Rectangle				  *
 *--------------------------------------------*/

class _Rectangle : public _Parallelogram
{
public:
	//constructor and destructor
	_Rectangle(double x = 50, double y = 100, double w = 150, double h = 100) : _Parallelogram(x, y, x, w, h) {}
	_Rectangle(Point p[4]);
	~_Rectangle() {}
	//operation
	//void scale(double s);
	//check
	bool check(Point p[4]) const;
	//void set(double x, double y);
	//void set2(double x2, double y2);
	//bool isInside(double x, double y) const { return isPointInside(Point(x, y)); }
	//DrawRectangle(CDC* pDC, Point m_point_s, Point m_point_f, COLORREF color)
};

/*--------------------------------------------*
 *					Square					  *
 *--------------------------------------------*/

class _Square : public _Rectangle
{
public:
	//constructor and destructor
	_Square(double x = 50, double y = 100, double e = 150) : _Rectangle(x, y, e, e) {}
	_Square(Point p[4]);
	~_Square() {}
	//check
	bool check(Point p[4]) const;
};