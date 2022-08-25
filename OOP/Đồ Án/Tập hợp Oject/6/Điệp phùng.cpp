#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
#define X 150
#define Y 150


class DrawCircle2
{
public:
	DrawCircle2();
	bool inputCircle2(int a, int b);
	void drawCircle2(Mat img);
	void drawCircle3(Mat img);
private:
	int  x0, y0, r0;
};

bool DrawCircle2::inputCircle2(int a, int b) {
	cout << "Tam x0 cua  hinh tron : "; cin >> x0;
	cout << "Tam y0 cua  hinh tron : "; cin >> y0;
	cout << "Nhap ban kinh hinh tron : "; cin >> r0;
	int c = b - y0;
	int alpha1 = 1 + a * a;
	int alpha2 = a * c - x0;
	float alpha3 = x0 * x0 - r0 * r0 + c * c;
	float alpha = alpha2 * alpha2 - alpha3 * alpha1;
	printf("alpha=%f \n", alpha);
	if (alpha >= 0) {
		return true;
	}
	else return false;
}
//---------------------------------------------------------------------------------


DrawCircle2::DrawCircle2()
{
	this->r0 = r0;
}

void DrawCircle2::drawCircle2(Mat img) {
	cv::circle(img, Point(x0, y0), r0, cv::Scalar(0, 0, 255), 1);
}

void DrawCircle2::drawCircle3(Mat img) {
	cv::circle(img, Point(x0, y0), r0, cv::Scalar(0, 0, 255), -1);
}
//-----------------------------------------------------------------------------------
class DrawEliptic
{
public:
	DrawEliptic();
	int inputEliptic(int A, int B);
	void drawEliptic(Mat img);
	void drawEliptic2(Mat img);
	
private:
	int  x0, y0, a, b;
};

int DrawEliptic::inputEliptic(int A, int B) {
	cout << "Tam x0 cua elip: "; cin >> x0;
	cout << "Tam y0 cua  elip: "; cin >> y0;
	cout << "truc y (truc be) elip: "; cin >> b;
	cout << "truc x (truc lon): "; cin >> a;
	int c = B - y0;
	//printf("c=  %d - %d=%d \n", B, y0, c);
	float alp1 = b*b + a*a * A * A;
	//printf("alp1= %d + %d * %d * %d =%f \n", b , a , A , A,alp1);
	float alp2 = A * a * c*a - b*b * x0;
	float alp3 = x0 * x0 * b*b + a*a * c * c - a*a*b * b;
	float alpha = alp2 * alp2 - alp3 * alp1;
	//printf("alp2= %d * %d * %d - %d * %d =%f \n", A ,a , c , b , x0,alp2);
	//printf("alp3= %d * %d * %d + %d * %d * %d - %d * %d =%f \n", x0 , x0 , b ,a , c , c , a , b, alp3);
	//printf("alpha=%f* %f - %f * %f =%f \n", alp2 , alp2 , alp3 , alp1, alpha);
	//printf("alpha=%f \n", alpha);
	if (alpha >= 0) {
		return 1;
	}
	else return 0;
}
DrawEliptic::DrawEliptic()
{
	this->x0 = x0;
	this->y0 = y0;
	this->a = a;
	this->b = b;
}

void DrawEliptic::drawEliptic(Mat img) {
	double angle = 90;
	double startAngle = 90;
	double endAngle = 470;
	cv::ellipse(img, cv::Point(x0, y0), cv::Size(b,a), angle, startAngle, endAngle, cv::Scalar(0, 0, 255), 1);

}

void DrawEliptic::drawEliptic2(Mat img) {
	double angle = 90;
	double startAngle = 90;
	double endAngle = 470;
	cv::ellipse(img, cv::Point(x0, y0), cv::Size(b, a), angle, startAngle, endAngle, cv::Scalar(0, 255, 0), -1);

}
//------------------------------------------------------------------------------------------
class consider
{
public:
	consider(int a, int b){
		x = a;
		y = b;
	}
	int intersect(int a, int b, consider zz5, consider zz6);
private:
	int x, y;
};


int consider::intersect(int a, int b, consider z5, consider z6) {
	
	int alp1, alp2, slope, x, y;
	//alp1 = y1 - y2;
	alp1 = z5.y - z6.y;
	alp2 = z6.x - z5.x;
	if (alp2 == 0)
	{
		slope = 0;
	}
	else
	{
		slope = -alp1 / alp2;
	}
	if (slope == a)
	{
		printf(" line is parallel \n ");
		return 0;
	}
	else
	{
		x = (alp1 * z5.x + alp2 * z5.y - alp2 * b) / (alp1 + alp2 * a);
		y = a * x + b;
		//printf("toa do giao : x=%d,   y=%d  \n", x, y);
		consider z77(x,y);
		//printf("z7.x=%d \n", z77.x);
		//printf("z7.y=%d \n", z77.y);
		//return z7.x, z7.y;
		int z = 0;
		//printf("zz5.x=%d \n", zz5.x);
		if (z5.x <= z6.x)
		{
			if (z77.x >= z5.x && z77.x <= z6.x)
			{
				z = z + 1;
				//printf("z=%d \n", z);
			}
		}
		else
		{
			if (z77.x >= z6.x && z77.x <= z5.x)
			{
				z = z + 1;
				//printf("z=%d \n", z);
			}
		}
		if (z5.y <= z6.y)
		{
			if (z77.y >= z5.y && z77.y <= z6.y)
			{
				z = z + 1;
				//printf("z=%d \n", z);
			}
		}
		else
		{
			if (z77.y >= z6.y && z77.y <= z5.y)
			{
				z = z + 1;
				//printf("z=%d \n", z);
			}
		}
		//printf("z truoc dieu kien if, z=%d \n", z);
		return z;
	}
	
}
/*
consider::consider()
{
	this->x = 0;
	this->y = 0;
}*/

//------------------------------------------------------------------------------------------
class DrawRetangle
{
public:
	DrawRetangle();
	int inputRetangle(int a, int b);
	void drawRetangle(Mat img);
	void drawRetangle2(Mat img);
private:
	int  x0, y0, length, width;
	
};

int DrawRetangle::inputRetangle(int a, int b) {
	cout << "Original point Retangle x0 = : "; cin >> x0;
	cout << "Original point Retangle y0 =: "; cin >> y0;
	cout << "Length of Retangle =: "; cin >> length;
	cout << "Width of Retangle =: "; cin >> width;
	// consider have been intersected:
	int x1, x2, x3, y1, y2, y3;
	x1 = x0 + length; y1 = y0;
	x2 = x0 + length; y2 = y0 + width;
	x3 = x0; y3 = y0 + width;


	int z, z1 = 0;
	int alp1 = 0;
	int alp2 = 0;
	int slope = 0;
	int x = 0, y = 0;
	int n = 4;
	int zad = 0;
	int AD[2][4] = { {x0, x1, x2, x3 }, {y0, y1, y2, y3} };

	for (int zad = 0; zad < n-1; zad++)
	{
		printf("iteration i= %d \n", zad);
		consider z4(AD[0][zad], AD[1][zad]), z5(AD[0][zad + 1], AD[1][zad + 1]);
		consider zz(1, 1);
		//zz.intersect(a, b, z4, z5);
		if (zz.intersect(a, b, z4, z5) >= 2)
		{
			z1 = z1 + 1;
		}
	} 
	consider z4(AD[0][0], AD[1][0]), z5(AD[0][n - 1], AD[1][n - 1]);
	consider zz(1, 1);
	if (zz.intersect(a, b, z4, z5) >= 2)
	{
		z1 = z1 + 1;
	}

	printf("TOTAL z1=%d \n", z1);
	return z1;
};

	
DrawRetangle::DrawRetangle()
{
	this->x0 = x0;
	this->y0 = y0;
	this->length = length;
	this->width = width;
}

void DrawRetangle::drawRetangle(Mat img) {
	cv::rectangle(img, cv::Rect(x0, y0, length, width), cv::Scalar(255, 0, 0), 1);
}

void DrawRetangle::drawRetangle2(Mat img) {

	cv::rectangle(img, cv::Rect(x0, y0, length, width), cv::Scalar(255, 0, 0), -1);
}

class DrawTriangle
{
public:
	DrawTriangle();
	bool inputTriangle(int a, int b);
	void drawTriangle(Mat img);
	void drawTriangle2(Mat img);
private:
	
	int AP[2][3];
};

bool DrawTriangle::inputTriangle(int a, int b) {
	printf("TRIANGLE \n");
	int z, z1 = 0, alp1, alp2, slope;
	int x = 0, y = 0, n=3;
	for (int i = 0; i < n; i++)
	{
		cout << " diem thu i= " << i << endl;
		cout << "x= " ; cin >> AP[0][i];
		cout << "y= " ; cin >> AP[1][i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		//z = 0;
		consider z4(AP[0][i], AP[1][i]), z5(AP[0][i + 1], AP[1][i + 1]);
		consider zz(1, 1);
		//zz.intersect(a, b, z4, z5);
		if (zz.intersect(a, b, z4, z5) >= 2)
		{
			z1 = z1 + 1;
		}
	}
	consider z4(AP[0][0], AP[1][0]), z5(AP[0][n - 1], AP[1][n - 1]);
	consider zz(1, 1);
	if (zz.intersect(a, b, z4, z5) >= 2)
	{
		z1 = z1 + 1;
	}

	printf("TOTAL z1=%d \n", z1);
		if (z1>=2)
	{
		return true;
	}
	else
	{
		return false;
	}
}


DrawTriangle::DrawTriangle()
{
	this->AP[2][3] = AP[2][3];
}


void DrawTriangle::drawTriangle2(Mat img) {
	int lineType = cv::LINE_8;
	int n = 3;
	cv::Point arr_points[1][5];
	for (int i = 0; i < n; i++)
	{
		arr_points[0][i] = cv::Point(AP[0][i], AP[1][i]);
	}
	const cv::Point* ppt[1] = { arr_points[0] };
	int npt[] = { n };
	cv::Scalar color = cv::Scalar(0, 255, 0);
	cv::fillPoly(img,
		ppt,
		npt,
		1,
		color,
		lineType);
}
/**/
void DrawTriangle::drawTriangle(Mat img) {
	int n = 3;
	for (int i = 0; i < n - 1; i++)
	{
		line(img, Point(AP[0][i], AP[1][i]), Point(AP[0][i + 1], AP[1][i + 1]), cv::Scalar(0, 0, 255), 1);
	}
	line(img, Point(AP[0][n - 1], AP[1][n - 1]), Point(AP[0][0], AP[1][0]), cv::Scalar(0, 0, 255), 1);
}


class DrawSquare
{
public:
	DrawSquare();
	int inputSquare(int a, int b);
	void drawSquare(Mat img);
	void drawSquare2(Mat img);
private:
	int  x0, y0, length;
	int x1, x2, x3, y1, y2, y3;
};

int DrawSquare::inputSquare(int a, int b) {
	cout << "Original point Square x0 = : "; cin >> x0;
	cout << "Original point Square y0 =: "; cin >> y0;
	cout << "Length of Square =: "; cin >> length;
	int width = length;
	x1 = x0 + length; y1 = y0;
	x2 = x0 + length; y2 = y0 + width;
	x3 = x0; y3 = y0 + width;

	int z , z1 = 0;
	int alp1 = 0;
	int alp2 = 0;
	int slope = 0;
	int x = 0, y = 0;
	int n = 4;
	/**/
	int zad = 0;
	int AD[2][4] = { {x0, x1, x2, x3 }, {y0, y1, y2, y3} };
	for (int zad = 0; zad < n - 1; zad++)
	{
		printf("iteration i= %d \n", zad);
		consider z4(AD[0][zad], AD[1][zad]), z5(AD[0][zad + 1], AD[1][zad + 1]);
		consider zz(1, 1);
		//zz.intersect(a, b, z4, z5);
		if (zz.intersect(a, b, z4, z5) >= 2)
		{
			z1 = z1 + 1;
		}
	}
	consider z4(AD[0][0], AD[1][0]), z5(AD[0][n - 1], AD[1][n - 1]);
	consider zz(1, 1);
	if (zz.intersect(a, b, z4, z5) >= 2)
	{
		z1 = z1 + 1;
	}
	printf("TOTAL z1 = %d \n", z1);
	return z1;
	};
DrawSquare::DrawSquare()
{
	this->x0 = x0;
	this->y0 = y0;
	this->length = length;
}

void DrawSquare::drawSquare(Mat img) {
	cv::rectangle(img, cv::Rect(x0, y0, length, length), cv::Scalar(255, 0, 0), 1);
}

void DrawSquare::drawSquare2(Mat img) {

	cv::rectangle(img, cv::Rect(x0, y0, length, length), cv::Scalar(255, 0, 0), -1);
}

class DrawPolygone
{
public:
	DrawPolygone();
	int inputPolygone(int a, int b);
	void drawPolygone(Mat img);
	void drawPolygone2(Mat img);
private:
	int n;
	int AP[2][100];
};

int DrawPolygone::inputPolygone(int a, int b) {
	cout << "the number vertex of polygon " << endl; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << " diem thu i= "<< endl << i ;
		cout << "x= " ; cin >> AP[0][i];
		cout << "y= " ; cin >> AP[1][i];
	}
	int z,z1=0 , alp1, alp2, slope;
	int x = 0, y = 0;
	for (int i = 0; i < n - 1; i++)
	{
		consider z4(AP[0][i], AP[1][i]), z5(AP[0][i + 1], AP[1][i + 1]);
		consider zz(1, 1);
		if (zz.intersect(a, b, z4, z5) >= 2)
		{
			z1 = z1 + 1;
		}
	}
	consider z4(AP[0][0], AP[1][0]), z5(AP[0][n - 1], AP[1][n - 1]);
	consider zz(1, 1);
	if (zz.intersect(a, b, z4, z5) >= 2)
	{
		z1 = z1 + 1;
	}
	printf("TOTAL z1=%d \n", z1);
	return z1;
}

DrawPolygone::DrawPolygone()
{
	this->AP[2][100]= AP[2][100];
	this->n = n;
}

void DrawPolygone::drawPolygone(Mat img) {
	int lineType = cv::LINE_8;

	cv::Point arr_points[1][5];
	for (int i = 0; i < n; i++)
	{
		arr_points[0][i] = cv::Point(AP[0][i], AP[1][i]);
	}
	const cv::Point* ppt[1] = { arr_points[0] };
	int npt[] = { n };
	cv::Scalar color = cv::Scalar(255, 255, 255);
	cv::fillPoly(img,
		ppt,
		npt,
		1,
		color,
		lineType);
}
/**/
void DrawPolygone::drawPolygone2(Mat img) {
	for (int i = 0; i < n-1; i++)
	{
		line(img, Point(AP[0][i], AP[1][i]), Point(AP[0][i+1], AP[1][i+1]), cv::Scalar(255, 255, 255), 1);
	}
	line(img, Point(AP[0][n-1], AP[1][n-1]), Point(AP[0][0], AP[1][0]), cv::Scalar(255, 255, 255), 1);
}

int main() {
	Mat img = Mat(500, 800, CV_8UC3);
	img = cv::Scalar(0, 0, 0);
	
	DrawCircle2 c2;
	int x = 0, y = 0, h = 0, k = 0;
	int a, b, A_max = 500, B_max = 800, x1_line, y1_line, x2_line, y2_line;
	cout << "Phuong trinh y=Ax+B" << endl;
	cout << "Nhap A: "; cin >> a;
	cout << "Nhap B: "; cin >> b;
	int Z[2][10]; //  dong1=> toa do x, dong 2=> toa do y;
	int i = 0;
	//------------------------------------------------------------
	// case1: x=0
	int y1;
	y1 = b;
	printf("giao voi x=0:  y1=%d \n", y1);
	if (b >= 0 && b <= B_max)
	{
		Z[0][i] = 0;
		Z[1][i] = y1;
		i = i + 1;
	}

	// case2: x=A_max;
	int y2;
	y2 = a * A_max + b;
	printf(" giao voi x=%d:    y2=%d \n", A_max, y2);
	if (y2 >= 0 && y2 <= B_max)
	{
		Z[0][i] = A_max;
		Z[1][i] = y2;
		i = i + 1;
	}
	// case3: y=0;
	int x3;
	x3 = -b / a;
	printf(" giao voi y=0:    x3 = %d \n", x3);

	if (x3 >= 0 && x3 <= A_max)
	{
		Z[1][i] = 0;
		Z[0][i] = x3;
		i = i + 1;
	}
	// case4: y=B_max;
	int x4;
	x4 = (B_max - b) / a;
	printf(" giao voi y=%d:    x4 = %d \n", B_max, x4);

	if (x4 >= 0 && x4 <= A_max)
	{
		Z[1][i] = B_max;
		Z[0][i] = x4;
		i = i + 1;
	}

	printf("finally i=%d \n", i);
	int z = i;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < z; j++)
			printf("%d\t", Z[i][j]);
		printf("\n");
	}

	x1_line = Z[0][0];
	y1_line = Z[1][0];
	x2_line = Z[0][1];
	y2_line = Z[1][1];

	//------------------------------------------------------------
	// ve duong thang qua 2 diem:

	line(img, Point(x1_line, y1_line), Point(x2_line, y2_line), Scalar(0, 0, 255), 1);
	
	
	/**/
	// VE DUONG TRON:
	printf("VE DUONG TRON: \n");
	if (c2.inputCircle2(a, b) == true)
	{
		cout << "Duong thang cat duong tron hahaha " << endl;
		c2.drawCircle3(img);
	}
	else
	{
		c2.drawCircle2(img);
	}
	
	// VE HINH CHU NHAT:
	printf("VE HINH CHU NHAT \n");

	DrawRetangle d;
	
	//printf("z=%d \n", d);
	if (d.inputRetangle(a, b) != 0)
	{
		cout << "Duong thang cat Retangle hahaha " << endl;
		d.drawRetangle2(img);
	}
	else
	{
		printf("hem co cat  \n");
		d.drawRetangle(img);
	}
	
	//
	
	// VE HINH VUONG:
	printf("VE HINH VUONG: \n");

	DrawSquare s;

	//printf("z=%d \n", d);
	if (s.inputSquare(a, b) != 0)
	{
		cout << "Duong thang cat Square hahaha " << endl;
		s.drawSquare2(img);
	}
	else
	{
		printf("hem co cat  \n");
		s.drawSquare(img);
	}
	
	//VE ELLIPTIC:
	printf("VE ELLIPTIC: \n");
	DrawEliptic e;
	if (e.inputEliptic(a, b) == 1)
	{
		cout << "Duong thang cat ellip hahaha " << endl;
		e.drawEliptic2(img);
	}
	else
	{
		cout << "Duong thang KO cat ellip hahaha " << endl;
		e.drawEliptic(img);
	}
	
	// VE TAM GIAC:
	printf("VE TAM GIAC: \n");
	DrawTriangle t;
	if (t.inputTriangle(a, b) ==true)
	{
		cout << "Duong thang cat Triangle hahaha " << endl;
		t.drawTriangle2(img);
	}
	else
	{
		cout << "Duong thang KO cat Triangle hahaha " << endl;
		t.drawTriangle(img);
	}
	//t.drawTriangle(img);
	
	
	
	// VE POLYGON:
	printf("VE DA GIAC \n");

    DrawPolygone p;


if (p.inputPolygone(a, b)>1)
{
	printf("duong thang cat da giac \n");
	p.drawPolygone(img);
}
else
{
	printf("duong thang KO cat da giac \n");
	p.drawPolygone2(img);
}

//ImpShow(img);
	cv::imshow("Image", img);
	cv::waitKey(0);
	return 0;
}