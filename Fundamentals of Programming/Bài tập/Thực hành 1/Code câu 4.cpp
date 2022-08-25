#include<iostream>
using namespace std;
#include <stdio.h>
#include<string>
void main()
{
    int x, t;
    float y, z;
    printf("Gia SP goc: "); scanf_s("%d", &x); cin.ignore(1);
    printf("SP ban duoc hay khong(1 la co, 0 la khong): "); fflush(stdin); scanf_s("%d",&t);
    if (t == 1)
    {
        y = x + x * 60 / 100;
        z = y * 40 / 100;
        printf("chu Sp nhan: %f \nCua hang nhan: %f", y, z);
    }
    else
    {
        y = x * 80 / 100;
        z = 0;
	printf("Chu Sp nhan %f \nCua hang nhan: %f", y, z);
    }
}