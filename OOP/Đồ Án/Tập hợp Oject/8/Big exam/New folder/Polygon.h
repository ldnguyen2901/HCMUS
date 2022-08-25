#pragma once
#include "framework.h"
#include "Point.h"
#include "Ellipse.h"


class _Polygon : public _Shape
{
protected:
	int vertices;
	Point* points;
public:
	//Constructor and Destructor
	static Point pointsDefault[];
	_Polygon(int num_vers = 3, Point* p = pointsDefault) : vertices(num_vers) { setPoints(num_vers, p); }
	~_Polygon() { delete[] points; }
	//setter
	virtual void setPoints(int n, Point* p);
	//getter
	int getVertice() const { return vertices; }
	Point getCenter() const;
	//operation
	void move(double dx, double dy);
	void scale(Point Center, double s);
	void scale(double s) { scale(getCenter(), s); }
	void rotate(Point Center, double rad);
	void rotate(double rad) { rotate(getCenter(), rad); }
	//check
	virtual bool check(int num_vers, Point* p) const;
	bool isPointInside(Point p) const;
	bool isPointInLine(Point p) const;
	//other method
	double getArea() const;
	bool intersection(_Shape* aS, HDC hdc, COLORREF c = RGB(156, 200, 30)) const;
	//void draw(HDC hdc) const;
	void draw(HDC hdc, COLORREF c = RGB(0, 100, 100)) const;
};

