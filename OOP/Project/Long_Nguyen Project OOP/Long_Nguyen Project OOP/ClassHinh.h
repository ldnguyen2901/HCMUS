#pragma once
#include "framework.h"
#include "Diem.h"

//const double PI = atan(1) * 4;

class Hinh
{
public:
	virtual void dichuyen(double dx, double dy) = NULL;
	virtual void phongto_thunho(double s) = NULL;
	virtual void xoay(double rad) = NULL;
	virtual bool DiemTrongHinh(Diem p) const = NULL;
	virtual bool DiemTrenBien(Diem p) const = NULL;
	virtual bool PhanGiao(Hinh* aS, HDC hdc, COLORREF c = RGB(77, 255, 195)) const = NULL;
	virtual void Ve(HDC hdc, COLORREF c = RGB(0, 0, 0)) const = NULL;
}; 
