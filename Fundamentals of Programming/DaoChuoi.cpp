#include <stdio.h>

void Swap(char* a, char* b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

void DaoChuoi(char* s)
{
	char* p = s;
	while (*p) p++;
	for (--p; s < p; ++s, --p)
		Swap(s, p);
}

int main()
{
	char a[80] = "Nhan Chi So";
	printf("Nhap a: ");
	gets_s(a);
	DaoChuoi(a);
	printf(a);
}
