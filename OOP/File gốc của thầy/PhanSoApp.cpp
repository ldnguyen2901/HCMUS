#include <iostream>
using namespace std;
#include "PhanSo.h"

int main()
{
	PhanSo a(3, 9), b(2, 5);
	cout << "Ung dung phan so.\n";
	cout << a << endl;
	cout << b << endl;
	cout << a + b << endl;
	a += b;
	cout << a << endl;
	PhanSo d = a + b;
	d.Xuat();
	d = a + 5; cout << endl;
	d.Xuat(); cout << endl;
	(6 + a).Xuat(); cout << endl;
	(6.2 + a).Xuat(); cout << endl;
	(6.9 + a).Xuat(); cout << endl;
	(7 + a).Xuat(); cout << endl;
	return 0;
}