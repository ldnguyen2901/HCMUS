#include<iostream>
#include "Complex.h"

int main()
{
	Complex a(2, 3), b(1, 7), c(0, 0),d(0,0), e(0, 0), f(0, 0);
	c = a.Add(b);
	d = a.Sub(b);
	e = a.Mul(b);
	f = a.Div(b);
	a.print(); std::cout << "\n";
	b.print(); std::cout << "\n";
	c.print(); std::cout << "\n";
	d.print(); std::cout << "\n";
	e.print(); std::cout << "\n";
	f.print(); std::cout << "\n";
	return 0;
}