#pragma once
#include <iostream>
#include "framework.h"
using namespace std;
#include "Point.h"
#include "Operation.h"

// 3 phan sau day dung de phuc vu cho tinh do dai cua bezier
vector<double> makeArray(vector<Point> pt) {
	vector<double> temp;
	for (int i = 0; i < pt.size(); i++) {
		temp.push_back((double)pt[i].getX());
		temp.push_back((double)pt[i].getY());
	}
	return temp;
}

vector<double> qxy(vector<double> arr, double t) {
	arr[0] += (arr[2] - arr[0]) * t;
	arr[2] += (arr[4] - arr[2]) * t;
	arr[4] += (arr[6] - arr[4]) * t;
	arr[0] += (arr[2] - arr[0]) * t;
	arr[2] += (arr[4] - arr[2]) * t;
	arr[1] += (arr[3] - arr[1]) * t;
	arr[3] += (arr[5] - arr[3]) * t;
	arr[5] += (arr[7] - arr[5]) * t;
	arr[1] += (arr[3] - arr[1]) * t;
	arr[3] += (arr[5] - arr[3]) * t;
	vector<double> temp(0);
	temp.push_back(arr[0] + (arr[2] - arr[0]) * t);
	temp.push_back(arr[1] + (arr[3] - arr[1]) * t);
	return temp;
}

double bezierLength(vector<double> arr, int sampleCount) {
	int ptCount = sampleCount | 40 ;
	long total = 0;
	double lastX = arr[0], lastY = arr[1];
	double dx, dy;
	for (int i = 1; i < ptCount; i++) {
		vector<double> pt = qxy(arr, i / ptCount);
		dx = pt[0] - lastX;
		dy = pt[1] - lastY;
		total += sqrt(dx * dx + dy * dy);
		lastX = pt[0];
		lastY = pt[1];
	}
	dx = arr[6] - lastX;
	dy = arr[7] - lastY;
	total += sqrt(dx * dx + dy * dy);
	return total;
}


class Bezier : public Operation
{
protected:
	Point* point;
public:
	Bezier(Point* p = NULL) { point = p; }

	Point* pPoint = point;
	~Bezier() { delete[] pPoint; } // pt huy bo

	double getLength() override {
		vector<Point> b(0);
		for (int i = 0; i < 4; i++) {
			b.push_back({ point[i].getX(), point[i].getY() });
		}
		vector<double> temp = makeArray(b);
		return bezierLength(temp, 40);
	}
	void move(long dx, long dy)  override {
		for (int i = 0; i < 4; i++)
		{
			point[i].moveP(dx, dy);
		}
	}
	void draw(HDC hdc) override {
		POINT a[4] = {};
		for (int i = 0; i < 4; i++)
		{
			a[i] = { point[i].getX(), point[i].getY() };
		}
		PolyBezier(hdc, a, 4);
	};
	void zoom(double d) override {
		for (int i = 0; i < 4; i++)
		{
			point[i].zoom(d);
		}
	};
};
