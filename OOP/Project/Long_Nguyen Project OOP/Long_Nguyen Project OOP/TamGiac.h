#pragma once
#pragma once
#include "DaGiac.h"

class TamGiac : public DaGiac
{
public:
	//hàm khởi tạo và hàm huỷ
	static Diem DiemsDefault_Tri[3];
	TamGiac(Diem* p = NULL) : DaGiac(3) { setDiems(p); }
	~TamGiac() {}
	//setter
	void setDiems(Diem* p);

};

Diem TamGiac::DiemsDefault_Tri[] = { Diem(500,400), Diem(200,550), Diem(700,550) };

void TamGiac::setDiems(Diem* p)
{
	if (p == NULL)
	{
		Diems = new Diem[3];
		memcpy(Diems, DiemsDefault_Tri, 3 * sizeof(Diem));
	}
	else
	{
		Diems = new Diem[3];
		memcpy(Diems, p, 3 * sizeof(Diem));
	}
}