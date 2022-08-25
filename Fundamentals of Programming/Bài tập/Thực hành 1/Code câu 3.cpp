#include <stdio.h>
void main()
{
    float x, y;
    float z,sum;
    printf("Nhap muc luong co ban: "); scanf_s("%f", &x);
    printf("Nhap tong doanh thu: "); scanf_s("%f", &y);
    printf("Nhap ty le hoa hong: "); scanf_s("%f", &z);
    sum = x + (y * z);
    printf("Tong luong: %f", sum);
}