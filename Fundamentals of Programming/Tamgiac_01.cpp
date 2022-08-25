#include <stdio.h>

bool LaTamGiac(double a, double b, double c)
{
	return (a + b > c && b + c > a && c + a > b);
}

/*
void NhapTamGiac(double* pa, double* pb, double* pc)
{
	bool b;
	do {
		scanf_s("%lf%lf%lf", pa, pb, pc);
		if (!(b = LaTamGiac(*pa, *pb, *pc)))
			printf("Nhap lai 3 canh tam giac: ");
	} while (!b);
}
*/

void NhapTamGiac(double* pa, double* pb, double* pc)
{
	scanf_s("%lf%lf%lf", pa, pb, pc);
	while (!LaTamGiac(*pa, *pb, *pc))
	{
		printf("Nhap lai 3 canh tam giac: ");
		scanf_s("%lf%lf%lf", pa, pb, pc);
	} 
}

int main()
{
	double a, b, c;
	printf("Nhap 3 canh tam giac: ");
	NhapTamGiac(&a, &b, &c);
	printf("%.2lf, %.2lf, %.2lf la ba canh cua tam giac", a,b,c);
	if (a == b && b == c)
		printf(" deu");
	else {
		if (a * a == b * b + c * c || b * b == c * c + a * a || c * c == a * a + b * b)
			printf(" vuong");
		if (a == b || b == c)
			printf(" can");
	}
}
