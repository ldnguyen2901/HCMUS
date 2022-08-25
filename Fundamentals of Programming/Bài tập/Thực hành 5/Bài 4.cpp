//lab5 - ex 4
#include<stdio.h>
#include<conio.h>
#define max 100

void NhapMaTran(int a[][100],  int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf_s("%d", &a[i][j]);
        }
}
void XuatMaTran(int a[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}
//int doixung(int a[max][max], int n)
//{
//    for (int i = 0; i < n; i++)
//        for (int j = i + 1; j < n; j++)
//        {
//            if (a[i][j] == a[j][i])
//                return 1;
//            return 0;
//        }
//}
int kiemtradoixung(int a[max][max], int n)
{
    int k, j;
    for (k = 0; k < n; k++)
        for (j = 0; j < n && a[k][j] == a[j][k]; j++);
    return k == j;
}
void main()
{
    int a[max][max];
    int i, j, n;
    printf("nhap kich thuoc ma tran vuong cap: "); scanf_s("%d", &n);
    printf("nhap vao ma tran:\n");
    NhapMaTran(a,n);
    XuatMaTran(a,n);
    if (kiemtradoixung(a, n) == 1)
        printf("ma tran co doi xung qua duong cheo chinh");
    else
        printf(" ma tran khong doi xung qua duong cheo chinh");

    getchar();
}