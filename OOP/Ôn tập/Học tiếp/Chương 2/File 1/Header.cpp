#include<iostream>
using namespace std;
#include "Complex.h"

void Complex::print() const
{
	cout << "(" << re << "," << im << ")";
}

Complex Complex::Add(Complex b) const
{
	Complex r(re + b.re, im + b.im);
	return r;
	//return Complex();
}

Complex Complex::Sub(Complex b) const
{
	//return Complex (re - b.re, im - b.im);
	//return r;
	return Add(b.Minus());
}

Complex Complex::Mul(Complex b) const
{
	return Complex(re * b.re - im * b.im, re * b.im + im * b.re);
}

Complex Complex::Div(Complex b) const
{
	return Mul(b.Conjugare()).Div(b.abs());
}

double Complex::abs() const
{
	return sqrt(re * re + im * im);
}
