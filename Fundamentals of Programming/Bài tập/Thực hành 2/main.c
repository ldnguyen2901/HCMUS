//MSSV: 19110490
//Ho va ten: Vu Duc Tri	
//Lop: 19TTH2C
//IDE: Visual Studio 2015
//Bai tap: Assignment 1
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void cau1()
{
	int bimat, dudoan, count = 1;
	const int max = 100, min = 1;
	srand(time(NULL));
	bimat = (rand() % (max - min - 1) + min);
	do
	{
		printf("nhap so du doan: "); scanf_s("%d", &dudoan);
		if (dudoan < bimat)
		{
			printf("Lon hon\n"); count++;
		}
		else if (dudoan > bimat)
		{
			printf("Nho hon\n"); count++;
		}
		else
			printf("Ban da doan trung so bi mat sau %d lan\n\n", count);
	} while (dudoan != bimat);
}
void cau2()
{
	unsigned long long int a, b;
	printf("Tich cac so nguyen to\n");
	printf("Nhap so nguyen duong: "); scanf_s("%d", &a);
	printf("%d = ", a);
	for (b = 2; b < a;)
	{
		if (!(a%b))
		{
			printf("%d x ", b);
			a /= b;
		}
		else++b;
	}
	printf("%d\n", a);
}
void main()
{
	cau1();
	cau2();
	getchar();
}