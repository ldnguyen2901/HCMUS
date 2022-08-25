#pragma once
class Complex
{
	double re, im;
public:
	Complex(double r, double i) { re = r; im = i; }
	void set(double r, double i) { re = r; im = i; }
	void print() const; //{cout<<"("<<re<<","<<im<<")";}
	Complex Minus() const { return Complex(-re, -im); }
	Complex Add(Complex b)const;
	Complex Sub(Complex b)const;
	Complex Mul(Complex b)const;
	Complex Div(double r)const { return Complex(re / r, im / r); }
	Complex Conjugare() const { return Complex(re, -im); }
	Complex Div(Complex b)const;
	double abs() const;
};