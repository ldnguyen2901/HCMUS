#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cmath>
using namespace std;
class point
{
private:
	float x, y;

public:
	point(float x = 0, float y = 0)
	{
		this->x = x;
		this->y = y;
	}
	void input()
	{
		cout << "Toa do x = "; cin >> x;
		cout << "\nToa do y = "; cin >> y;
	}
	float getx()
	{
		return this->x;
	}
	float gety()
	{
		return this->y;
	}
	void move(float a = 0, float b = 0)
	{
		this->x += a;
		this->y += b;
	}
	float length(point a)
	{
		return sqrt((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y));
	}
	void output()
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}
	~point() {};
};

class HCN
{
protected:
	point x, y;

public:
	HCN(point a = 0, point b = 0)
	{
		this->x = a;
		this->y = b;
	}
	void input()
	{

	}
	float chieudai()
	{
		return x.getx() - y.getx();
	}
	float chieurong()
	{
		return x.gety() - y.gety();
	}
	float Chuvi_hcn()
	{
		return (chieudai() + chieurong()) * 2;
	}
	float S_hcn()
	{
		return chieudai() * chieurong();
	}
	bool is_inside()
	{

	}
	~HCN() {};
};

int main()
{
	point a(1, 1), b(2, 3);
	a.move(2, 3);
	a.output();
	HCN xyz(a, b);
	cout << "chu vi hinh chu nhat = " << xyz.Chuvi_hcn() << endl;
	cout << "dien tich hinh chu nhat = " << xyz.S_hcn() << endl;
}