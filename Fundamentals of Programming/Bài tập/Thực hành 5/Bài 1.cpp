//Nhập mảng số nguyên. Sau đó, chương trình phải tính được (trung bình) của mảng
//và đồng thời đếm được có bao nhiêu phần tử lớn hơn mean của mảng
#include<stdio.h>
#include<conio.h>
#define Max 100000
void mangnhap(int a[],unsigned int &n)
{
    for (int i = 1; i <= n; i++)
        scanf_s("%d", &a[i]);
}
void mangxuat(int a[], unsigned int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d\t", a[i]);
}
float trungbinh (int a[], unsigned int n)
{
    float c=0;
    for (int i = 1; i <= n; i++)
        c += a[i];
    c /= n;
    return c;
}
int count(int a[], unsigned int n, float z)
{
    unsigned int count = 0;
    for (int i = 1; i <= n; i++)
        if (z < a[i]) count++;
    return count;
}
void main()
{
    int a[Max];
    unsigned int n,t;
    float x;
    printf("nhap so luong mang so nguyen: "); scanf_s("%d", &n);
    mangnhap(a, n);
    x = trungbinh(a, n);
    printf("trung binh: %.2f", x);
    t = count(a, n, x);
    printf("\nco %d phan tu trong mang lon hon %.2f la: ",t,x);
    for (int i = 1; i <= n; i++)
        if (x < a[i])printf("%d\t",a[i]);
    getchar();
}