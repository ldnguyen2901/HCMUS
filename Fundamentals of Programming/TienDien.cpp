#include <stdio.h>
double TinhTienDien1(int k)
{
	double tien;
	if (k <= 50)
		tien = k * 1484.0;
	else if (k <= 100)
		tien = 50 * 1484. + (k - 50) * 1533.;
	else if (k <= 200)
		tien = 50 * 1484. + 50 * 1533. + (k - 100) * 1786.;
	else if (k <= 300)
		tien = 50 * 1484. + 50 * 1533. + 100 * 1786. + (k - 200) * 2242.;
	else if (k <= 400)
		tien = 50 * 1484. + 50 * 1533. + 100 * 1786. + 100 * 2242. + (k - 300) * 2503.;
	else
		tien = 50 * 1484. + 50 * 1533. + 100 * 1786. + 100 * 2242. + 100 * 2503. + (k - 400) * 2587.;
	return tien;
}

double TinhTienDien2(int k)
{
	double tien = 0;
	if (k > 400) {
		tien = (k - 400) * 2587.;
		k = 400;
	}
	if (k > 300) {
		tien += (k - 300) * 2503.;
		k = 300;
	}
	if (k > 200) 	{
		tien += (k - 200) * 2242.;
		k = 200;
	}
	if (k > 100) {
		tien += (k-100) * 1786.;
		k = 100;
	}
	if (k > 50) {
		tien += (k - 50) * 1533.;
		k = 50;
	}
	tien += k*1484.;
	return tien;
}



int main()
{
	int k;
	printf("Nhap so KWh tieu thu: ");
	scanf_s("%d", &k);
	printf("So tien phai tra tinh cach 1: %.2lf\n", TinhTienDien1(k));
	printf("So tien phai tra tinh cach 2: %.2lf\n", TinhTienDien2(k));
}

