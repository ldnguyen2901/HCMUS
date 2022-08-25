#include <iostream>
using namespace std;
#include "PhanSo.h"
int tinhUSCLN(int a, int b)
{
	if (b == 0) return a;
	return tinhUSCLN(b, a%b);
}

PhanSo PhanSo::Cong(PhanSo b) const
{
	return PhanSo(tu * b.mau + mau * b.tu, mau * b.mau);
}

void PhanSo::Set(int t, int m)
{
	tu = t;
	mau = m;
	RutGon();
}

void PhanSo::RutGon()
{
	int u = tinhUSCLN(tu, mau);
	tu /= u;
	mau /= u;
	if (mau < 0)
		tu = -tu, mau = -mau;
}

void PhanSo::Xuat() const
{
	cout << tu;
	if (tu != 0 && mau != 1)
		cout << "/" << mau;
}

