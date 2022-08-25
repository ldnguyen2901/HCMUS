//MSSV: 19110398
//Ho ten: Le Dinh Nguyen
//Lop: 19TTH2
//Bai: Lab4 - Ex2
//IDE: VS_2013
#include<stdio.h>
#include<iostream>
int main()
{
	int a, b, c, d = 50000, e = 17000, f = 12500, g = 6000,sum=0;
	printf("nhap so luong phong ngu: "); scanf_s("%d", &a);
	printf("nhap so luong phong tam: "); scanf_s("%d", &b);
	printf("nhap so luong oto: "); scanf_s("%d", &c);
	while (a != 0 && b != 0 && c != 0)
	{
		sum = d + (a*e + b*f + c*g);
		printf("tong thiet hai cua nguoi dung: %d\n", sum);
		printf("nhap so luong phong ngu: "); scanf_s("%d", &a);
		printf("nhap so luong phong tam: "); scanf_s("%d", &b);
		printf("nhap so luong oto: "); scanf_s("%d", &c);
	}
	system("pause");
	return 0;
}