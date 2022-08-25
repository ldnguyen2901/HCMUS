#pragma once
#pragma once
#include "framework.h"
#include "Diem.h"
#include "ClassHinh.h"

class Elipse : public Hinh
{
protected:
	Diem T;
	double xR, yR;
public:
	//hàm khởi tạo và hàm huỷ
	Elipse(double xT = 700, double yT = 300, double a = 200, double b = 100) : T(xT, yT), xR(a), yR(b) {};
	~Elipse() {}
	//setter
	void set(double xT, double yT) { T = Diem(xT, yT); xR = 0; yR = 0; }
	//operation
	void dichuyen(double dx, double dy) override { T.dichuyen(dx, dy); }
	void phongto_thunho(double s) override { xR *= s; yR *= s; }
	void xoay(double rad) override { if (rad == 90 || rad == -90) { double temp = xR; xR = yR; yR = temp; } }
	void Ve(HDC hdc, COLORREF c = RGB(0, 100, 100)) const override { Ellipse(hdc, T.layX() - xR, T.layY() - yR, T.layX() + xR, T.layY() + yR); }
	//kiemtra
	bool DiemTrongHinh(Diem p) const override;
	bool DiemTrenBien(Diem p) const override;
	//PhanGiao
	bool PhanGiao(Hinh* aS, HDC hdc, COLORREF c = RGB(156, 200, 30)) const;// phần giao
};


class Htron : public Elipse
{
public:
	Htron(double xT = 400, double yT = 400, double a = 150) : Elipse(xT, yT, a, a) {};
	~Htron() {}
};

bool Elipse::DiemTrongHinh(Diem p) const
{
	double dx = p.layX() - T.layX(), dy = p.layY() - T.layY();
	return (pow(dx / xR, 2) + pow(dy / yR, 2)) < 1;
}

bool Elipse::DiemTrenBien(Diem p) const
{
	double r = 0.015;
	double dx = p.layX() - T.layX(), dy = p.layY() - T.layY();
	double x = pow(dx / xR, 2) + pow(dy / yR, 2) - 1;
	return (fabs(x) <= r);
}

bool Elipse::PhanGiao(Hinh* aS, HDC hdc, COLORREF c) const
{
	bool check = 0;
	for (double i = T.layX() - xR; i <= T.layX() + xR; i++)
		for (double j = T.layY() - yR; j <= T.layY() + yR; j++)
		{
			Diem t(i, j);
			if (this->DiemTrongHinh(t) && aS->DiemTrongHinh(t))
			{
				SetPixel(hdc, i, j, c);
				check = 1;
			}
			if ((this->DiemTrenBien(t) && aS->DiemTrongHinh(t)) || (this->DiemTrongHinh(t) && aS->DiemTrenBien(t)) || (this->DiemTrenBien(t) && aS->DiemTrenBien(t)))
			{
				Ellipse(hdc, i - 0.5, j - 0.5, i + 0.5, j + 0.5);
				check = 1;
			}
		}
	return check;
}