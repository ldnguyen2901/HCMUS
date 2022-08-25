#pragma once
#include "DaGiac.h"



class Hcn : public DaGiac
{
public:
	//hàm khởi tạo và hàm huỷ
	Hcn(double x = 50, double y = 100, double w = 150, double h = 100) : DaGiac(4) { setDiems(x, y, w, h); }
	~Hcn() {}
	//setter
	void setDiems(double x, double y, double w, double h);
};



class Hvuong : public Hcn
{
public:
	//hàm khởi tạo và hàm huỷ
	Hvuong(double x = 50, double y = 100, double e = 150) : Hcn(x, y, e, e) {}
	~Hvuong() {}
};

void Hcn::setDiems(double x, double y, double w, double h)
{
	Diems[0] = Diem(x, y);
	Diems[1] = Diem(x + w, y);
	Diems[2] = Diem(x + w, y + h);
	Diems[3] = Diem(x, y + h);
}

