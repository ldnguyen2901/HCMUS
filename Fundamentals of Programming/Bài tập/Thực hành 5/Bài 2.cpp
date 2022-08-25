//lab5 - ex 2
#include<stdio.h>
#include<conio.h>
#define Max 100000

void main()
{
    unsigned long int a=16000000,x,y=0,z=0,t=0;
    printf("nhap thu nhap ca nhan(don vi: vnd): "); scanf("%ld", &a);
    if (a <= 10000000)printf("duoc mien thue suat");
    else if (a > 10000000 && a <= 15000000)
    {
        x = (a - 10000000) * 0.05; 
        printf("thue suat thu nhap cua ca nhan trong 1 thang la %ld\n", x);
    }
    else if (a > 15000000 && a <= 20000000)
    {
        x = 250000 + (a - 15000000) * 0.1; 
        printf("thue suat thu nhap cua ca nhan trong 1 thang la %ld\n", x);
    }
    else if (a > 20000000)
    {
        x = 250000 + 500000 + (a - 20000000) * 0.15;
        printf("thue suat thu nhap cua ca nhan trong 1 thang la %ld\n", x);
    }
    getchar();
}