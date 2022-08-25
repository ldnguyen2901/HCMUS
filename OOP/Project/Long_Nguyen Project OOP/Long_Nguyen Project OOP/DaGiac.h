#pragma once
#include "framework.h"
#include "Diem.h"
#include "Ellipse.h"
#include <iostream>

using namespace std;

class DaGiac : public Hinh
{
protected:
	int dinh;
	Diem* Diems;
public:
	//hàm khởi tạo và hàm huỷ
	static Diem DiemsDefault[];
	DaGiac(int num_vers = 4, Diem* p = NULL) : dinh(num_vers) { layDiems(num_vers, p); }
	~DaGiac() { delete[] Diems; }
	//setter
	virtual void layDiems(int n, Diem* p);
	//getter
	Diem layTam() const;
	//operation
	void dichuyen(double dx, double dy) override;
	void phongto_thunho(Diem Center, double s);
	void phongto_thunho(double s) override { phongto_thunho(layTam(), s); }
	void xoay(Diem Center, double rad);
	void xoay(double rad) override { xoay(layTam(), rad); }
	//kiemtra
	bool DiemTrongHinh(Diem p) const override;
	bool DiemTrenBien(Diem p) const override;
	//other method
	bool PhanGiao(Hinh* aS, HDC hdc, COLORREF c = RGB(156, 200, 30)) const override;
	void Ve(HDC hdc, COLORREF c = RGB(0, 100, 100)) const override;
};

Diem DaGiac::DiemsDefault[] = { Diem(50, 50), Diem(50, 150), Diem(200,150) };

void DaGiac::layDiems(int n, Diem* p)
{
	if (p == NULL)
	{
		Diems = new Diem[dinh = n];
		memcpy(Diems, DiemsDefault, n * sizeof(Diem));
	}
	else
	{
		Diems = new Diem[dinh = n];
		memcpy(Diems, p, n * sizeof(Diem));
	}
}

Diem DaGiac::layTam() const
{
	double xx = 0, yy = 0;
	for (int i = 0; i < dinh; i++)
	{
		xx += Diems[i].layX();
		yy += Diems[i].layY();
	}
	return Diem(xx / dinh, yy / dinh);
}

void DaGiac::dichuyen(double dx, double dy)
{
	for (int i = 0; i < dinh; i++)
		Diems[i].dichuyen(dx, dy);
}

void DaGiac::phongto_thunho(Diem Center, double s)
{
	for (int i = 0; i < dinh; i++)
		Diems[i].phongto_thunho(Center, s);
}

void DaGiac::xoay(Diem Center, double rad)
{
	for (int i = 0; i < dinh; i++)
		Diems[i].xoay(Center, rad);
}

#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

bool DaGiac::DiemTrongHinh(Diem p) const
{
	int count = 0;
	double x_in;
	Diem p1, p2;
	for (int i = 0; i < dinh; i++) // chạy trên các đỉnh
	{
		p1 = Diems[i]; // đỉnh thứ nhất
		p2 = Diems[(i + 1) % dinh];// đỉnh kế tiếp
		if (p.layY() > MIN(p1.layY(), p2.layY()) && p.layY() <= MAX(p1.layY(), p2.layY()))
			// kiểm tra xem là cái p có nằm giữ 2 y của p1 và p2
			if (p.layX() <= MAX(p1.layX(), p2.layX()))
				// xét điểm x xem có đang nằm giữ 2 điểm x của p1 và p2
				if (p1.layY() != p2.layY())
					// xét 2 điểm y có bằng không?
				{
					// nếu thỏa các điều kiện trên thì ta sẽ có biến x_in
					x_in = (p.layY() - p1.layY()) * (p2.layX() - p1.layX()) / (p2.layY() - p1.layY()) + p1.layX();
					if (p1.layX() == p2.layX() || p.layX() < x_in)
						// xét từ trái qua xem cái điểm x_in có đụng hình ko?
						count++;
				}
	}
	return (count % 2 != 0);
}

bool DaGiac::DiemTrenBien(Diem p) const
{
	double  d;
	double r = 0.03;
	for (int i = 0; i < dinh; i++)
	{
		d = p.khoangcach(Diems[i]) + p.khoangcach(Diems[(i + 1) % dinh]) - Diems[i].khoangcach(Diems[(i + 1) % dinh]);
		// d = ap + bp - ab
		if (fabs(d) <= r) //fabs là trị truyệt đối
			return true;
	}
	return false;
}

bool DaGiac::PhanGiao(Hinh* aS, HDC hdc, COLORREF c) const
{
	bool check = 0;
	double x_min = Diems[0].layX(), y_min = Diems[0].layY(), x_max = Diems[0].layX(), y_max = Diems[0].layY();
	for (int i = 1; i < dinh; i++)
	{
		if (x_min > Diems[i].layX())
			x_min = Diems[i].layX();
		if (x_max < Diems[i].layX())
			x_max = Diems[i].layX();
		if (y_min > Diems[i].layY())
			y_min = Diems[i].layY();
		if (y_max < Diems[i].layY())
			y_max = Diems[i].layY();
	}
	for (double i = x_min; i <= x_max; i++)
		for (double j = y_min; j <= y_max; j++)
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


void DaGiac::Ve(HDC hdc, COLORREF c) const
{
	static POINT apt[MAX_DiemS];

	for (int i = 0; i < dinh; i++)
	{
		apt[i].x = Diems[i].layX();
		apt[i].y = Diems[i].layY();
	}
	Polygon(hdc, apt, dinh);
}
