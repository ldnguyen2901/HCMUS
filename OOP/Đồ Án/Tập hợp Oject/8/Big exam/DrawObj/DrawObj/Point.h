#pragma once
#include "stdafx.h" 
class Point
{
	double x, y;
public:
	Point(double xx = 0, double yy = 0) : x(xx), y(yy) {}
	void set(double xx, double yy) { x = xx; y = yy; }
	double getX() const { return x; }
	double getY() const { return y; }
	void move(double dx, double dy) { x += dx; y += dy; }
	void rotate(Point T, double goc);
	void input();
	void output() const;
	void draw(HDC hdc, COLORREF c = RGB(0, 0, 0)) const;
	void mark(HDC hdc, int size = 5, COLORREF c = RGB(0, 0, 0)) const;
};