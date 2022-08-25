//lab5 - ex 3
#include<stdio.h>
#include<conio.h>
#define Max 100000
void nhap(int a[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (n > 6)break;
        printf("so nguoi phu thuoc thu %d la: ", i);
        scanf_s("%d", &a[i]);
    }
}
void xuat(int a[], int n)
{
    printf("\n\nso nguoi phu thuoc\tso luong nhan vien");
    for (int i = 0; i <= n; i++)
    {
        if (n > 6)break;
        printf("\n\t%d\t\t\t%d",i, a[i]);
    }
}
void main()
{
    int z[] = {43,35,24,11,5,7}, a = 5;
    //printf("Nhap so nguoi phu thuoc: ");scanf_s("%d", &a);
    nhap(z, a);
    xuat(z, a);
    getchar();
}