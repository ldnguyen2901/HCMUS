#include <stdio.h>
#include <string.h>

const int MAX = 100;
struct QuocGia {
	char TenNuoc[MAX];
	char ThuDo[MAX];
	int DanSo, DienTich;
};

int Tim(QuocGia a[], int n, char* s)
{
	for (int i = 0; i < n; i++)
		if (_stricmp(a[i].TenNuoc, s) == 0)
			return i;
	return -1;
}

void XuatQuocGia(QuocGia q)
{
	printf("Quoc Gia: %s\nThu Do: %s\nDan So: %d nguoi\nDien Tich: %d km2", q.TenNuoc, q.ThuDo, q.DanSo, q.DienTich);
}

int main()
{
	static QuocGia aQ[] =
	{
		{ "Viet Nam", "Ha Noi", 95261021, 331212 },
		{ "Phap", "Paris", 66259012, 632834 },
		{ "Trung Quoc", "Bac Kinh", 1373541278, 9572900 },
		{ "Hoa Ky", "Washington", 323995528, 9526468 },
		{ "Anh", "Luan don", 63742977, 242900 }
	};
	int N = sizeof(aQ) / sizeof(aQ[0]);
	char nuoc[MAX];
	printf("Nhap nuoc: ");
	gets_s(nuoc, MAX);
	int j = Tim(aQ, N, nuoc);
	if (j >= 0)
		XuatQuocGia(aQ[j]);
	else
		printf("Khong tim thay\n");
}
