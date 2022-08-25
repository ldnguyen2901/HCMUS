#include <stdio.h>
#include <string.h>

struct MonHoc {
	char maMH[16];
	char tenMH[64];
};

MonHoc * TimKiem(MonHoc a[], int n, char ma[])
{
	for (int i = 0; i < n; i++)
		if (_stricmp(a[i].maMH, ma) == 0)
			return &a[i];
	return NULL;
}


int main()
{
	static MonHoc am[] = {
		"MTH00055", "Co So Lap Trinh",
		"TTH105", "Toan Roi Rac",
		"TTH802", "Mang May Tinh",
		"TT503", "Lap Trinh Web"
	};
	int na = sizeof(am) / sizeof(am[0]);
	char maMon[32];
	printf("Nhap ma mon hoc can tim ten: ");
	scanf("%s", maMon);
	MonHoc* p = TimKiem(am, na, maMon);
	if (p)
		printf("Mon %s co ten la: %s\n", maMon, p->tenMH);
	else
		printf("Mon %s khong ton tai.\n", maMon);
}