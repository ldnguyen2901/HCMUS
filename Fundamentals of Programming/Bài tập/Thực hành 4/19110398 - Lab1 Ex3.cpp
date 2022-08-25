//MSSV: 19110398
//Ho ten: Le Dinh Nguyen
//Lop: 19TTH2
//Bai: Lab4 - Ex3
//IDE: VS_2013
#include<stdio.h>
#include<iostream>
int main()
{
	int a, max, min;
	printf("nhap 1 so nguyen: "); scanf_s("%d", &a);
	max = a; min = a;
	while (a != 0)
	{
		if (a >= max) max = a;
		else if(a<=min) min = a;
		printf("nhap 1 so nguyen: "); scanf_s("%d", &a);
	}
	printf("Max = %d\nMin = %d\n", max, min);
	system("pause");
	return 0;
}