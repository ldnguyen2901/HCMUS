#pragma once
#include "pch.h"
#include "Point.h"
#include "Operation.h"
class Line: public Operation
{
protected:
	int n; // So diem cua polyline
	Point* point;		
public:
	Line(int m, Point* p = NULL) : n(m) { point = p; }//pt thiet lap

	Point* pPoint = point; // dung cho pt huy bo
	~Line() { delete[] pPoint; }// pt huy bo
	
	double get1Length(Point begin,Point end) {
		return sqrt(pow(end.getX() - begin.getX(), 2) + pow(end.getY() - begin.getY(), 2));
	}

	double getLength() override {
		int result = 0;
		for (int i = 0; i < n-1; i++)
		{
			result += get1Length(point[i], point[i+1]);
		}
		return result;
	}
	
	void move(long dx, long dy)  override {
		for (int i = 0; i < n; i++)
		{
			point[i].moveP(dx, dy);
		}
	}
	
	void draw(HDC hdc) override {
		POINT a[100] = {};
		for (int i = 0; i < n; i++)
		{
			a[i] = { point[i].getX(), point[i].getY() };
		}
		Polyline(hdc, a, n);
	};

	void zoom(double d) override {
		for (int i = 0; i < n; i++)
		{
			point[i].zoom(d);
		}
	};

};