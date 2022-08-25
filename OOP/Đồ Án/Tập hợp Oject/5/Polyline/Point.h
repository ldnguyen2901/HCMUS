#pragma once
#include <iostream>
using namespace std;


class Point {

	long x, y;
public:
	Point(long xx, long yy) : x(xx), y(yy) {}
	Point() : x(0), y(0) {}
	~Point() {}
	void setX(long xx) {
		x = xx;
	}
	void setY(long yy) {
		y = yy;
	}
	long getX() const {
		return x;
	}
	long getY() const {
		return y;
	}
	void moveP(long dx, long dy) { x += dx, y += dy; }
	void zoom(double d) { x =x*d, y =y*d; }
};
	

