#pragma once

class PhanSo
{
	int tu, mau;
public:
	PhanSo(int t, int m = 1) { Set(t, m); }
	PhanSo(double t) { Set(round(t), 1); }
	PhanSo Cong(PhanSo b) const;
	PhanSo operator += (PhanSo b);	
	void Set(int t, int m);
	void RutGon();
	void Xuat() const;
	friend ostream& operator << (ostream &os, PhanSo p);
};

inline PhanSo operator + (PhanSo a, PhanSo b)
{
	PhanSo c = a;
	return c += b;
}

inline PhanSo PhanSo::operator += (PhanSo b)
{ 
	Set(tu * b.mau + mau * b.tu, mau * b.mau);
	return *this;
}

inline ostream& operator << (ostream &os, PhanSo p)
{
	os << p.tu;
	if (p.tu != 0 && p.mau != 1)
		os << "/" << p.mau; 
	return os;
}

