#include <stdio.h> 
#include <stdlib.h>

bool LaSoNguyenTo(int n)
{
	int a;
	if (n == 2 || n == 3) return true;
	if (n <= 1) return false;
	if (n % 2 == 0) return false;
	a = 3;
	while (a <= n / a && n % a)
		a += 2;
	return a > n / a;
}
// Tim so nguyen nho nhat dung sau a
int SoNgToKeTiep(int a)
{
	do
		a++;
	while (!LaSoNguyenTo(a));
	return a;
}


int main()
{
	int n, N;
	char fname[80] = "d:\\nguyento.bin";
	FILE* fp;
	printf("Chuong trinh tao tap tin co N so nguyen to dau tien\n");
	fp = fopen(fname, "wb");
	if (fp == NULL)
		exit(printf("Khong the mo file %s\n.", fname));
	printf("Nhap N: "); scanf("%d", &N);
	n = 2;
	for (int i = 0; i < N; i++)
	{
		fwrite(&n, sizeof(n), 1, n);
		n = SoNgToKeTiep(n);
	}
	printf("Da tao xong tap tin %s\n", fname);
	fclose(fp);
}

