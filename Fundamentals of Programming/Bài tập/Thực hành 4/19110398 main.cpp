//MSSV: 19110398
//Ho ten: Le Dinh Nguyen
//Lop: 19TTH2
//Bai: Lab4 - Ex1 == Lab2 - Ex1
//IDE: VS_2013
#include<stdio.h>
#include<iostream>
int main()
{
	int a, b, c;
	printf("nhap gia ban: "); scanf_s("%d", &a);
	
	while (a!=0)
	{
		printf("nhap gia mua thuc te: "); scanf_s("%d", &b);
		c = a - b;
		printf("loi nhuan la %d\n", c);
		printf("nhap gia ban: "); scanf_s("%d", &a);
	}
	system("pause");
	return 0;
}