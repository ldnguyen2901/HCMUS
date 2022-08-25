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

const int MAX = 100;

int main()
{
	int x;
	char fname[80] = "d:\\nguyento.bin";
	FILE* fp;
	int a[MAX], n;

	printf("Chuong trinh doc tap tin cac so nguyen.\n");
	fp = fopen(fname, "rb");
	if (fp == NULL)
		exit(printf("Khong the mo file %s\n.", fname));

	while((n = fread(a, sizeof(int), MAX, fp)) != 0)
		for (int i = 0; i < n; i++)
			printf("%6d", a[i]);
	printf("\n");
	
	fclose(fp);
}
