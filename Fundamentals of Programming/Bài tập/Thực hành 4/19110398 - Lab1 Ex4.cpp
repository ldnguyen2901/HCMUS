//MSSV: 19110398
//Ho ten: Le Dinh Nguyen
//Lop: 19TTH2
//Bai: Lab4 - Ex4
//IDE: VS_2013
#include<stdio.h>    
#include<stdlib.h>  
#include<iostream>
int main(){
	int a[10], n, i, m;
	system("cls");
	printf("nhap so chuyen doi: ");
	scanf("%d", &n);
	m=n;
	for (i = 0; n>0; i++)
	{
		a[i] = n % 2;
		n = n / 2;
	}
	printf("\nNhi phan cua so %d duoc chuyen doi la: ",m);
	for (i = i - 1; i >= 0; i--)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}