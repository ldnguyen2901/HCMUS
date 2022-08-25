#pragma once
#pragma once
#include "framework.h"
#include <iostream>
#include <math.h>

using namespace std;

const double PI = atan(1) * 4;

const int MAX_DiemS = 1000;

class Diem
{
	double x, y;
public:
	Diem(double xx = 0, double yy = 0) : x(xx), y(yy) {} // hàm khởi tạo
	~Diem() {} // hàm huỷ
	//setter
	void set(double xx, double yy) { x = xx; y = yy; }
	//getter
	double layX() const { return x; }
	double layY() const { return y; }
	//operation
	void dichuyen(double dx, double dy) { x += dx; y += dy; }
	void phongto_thunho(Diem tam, double tile);
	void xoay(Diem T, double rad);
	double khoangcach(Diem a) const;
};

double Diem::khoangcach(Diem a) const
{
	double dx = this->layX() - a.layX(), dy = this->layY() - a.layY();
	return sqrt(pow(dx, 2) + pow(dy, 2));
}

void Diem::xoay(Diem tam, double rad)
{
	double cosa = cos(rad * PI / 180);
	double sina = sin(rad * PI / 180);
	double X = (x - tam.x) * cosa - (y - tam.y) * sina + tam.x;
	y = (x - tam.x) * sina + (y - tam.y) * cosa + tam.y;
	x = X;
}

void Diem::phongto_thunho(Diem tam, double tile)
{
	x = (x - tam.layX()) * tile + tam.layX();
	y = (y - tam.layY()) * tile + tam.layY();
}

