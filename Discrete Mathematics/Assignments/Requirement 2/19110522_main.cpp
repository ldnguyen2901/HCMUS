/*
* MSSV: 19110522
* Ho va Ten: Bui Thi Thanh Xuan
* Assignment: bai2
* Created_at: 02/12/2021
* IDE: Visual Studio 2019
*/
#include <iostream>
#include <fstream>
#include<string>
#include <stdlib.h>
using namespace std;
#define MAX 100

//Cac ham trong bai
int cap_maTran(ifstream& f1);
void khoitao_Matrix(int** arr, int m, int n);
void gan_Matrix(int** a, ifstream& fileIn, int& soDinh);
bool ktDOTHIVOHUONG(int** a, int& soDinh);
void isConnected(int** a, int& soDinh);

// Ham tim cap cua ma tran vuong (xem ma tran co may dong)
int cap_maTran(ifstream& fileIn)
{
	int num = 0, vertex = 0;
	char ch;
	fileIn.get(ch);
	while (fileIn) {
		while (fileIn && ch != '\n') {
			num = num + 1;
			fileIn.get(ch);
		}
		vertex = vertex + 1;
		fileIn.get(ch);
	}
	fileIn.clear();
	fileIn.seekg(0, SEEK_SET); //con tro chi vi: dich chuyen con tro chi vi trong file len dau tien
	return vertex;
}

//ham cap phat mot mang hai chieu voi hang va cot bang cap cua ma tran
void khoitao_Matrix(int** arr, int m, int n)
{
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = count;
			//cout << arr[i][j] << "\t";
		}
		//cout << ("\n");
	}
	//cout << "\n";
}

//ham gan gia tri trong file vao ma tran da cap phat
void gan_Matrix(int** a, ifstream& fileIn, int& soDinh)
{
	for (int i = 0; i < soDinh; i++)
	{
		for (int j = 0; j < soDinh; j++)
		{
			a[i][j] = 0;
			fileIn >> a[i][j];
			//cout << a[i][j] << "\t";
		}
		//cout << "\n";
	}


}

//Ham kiem tra do thi co vo huong khong
bool ktDOTHIVOHUONG(int** a, int& soDinh)
{
	for (int i = 0; i < soDinh - 1; i++)
	{
		if (a[i][i] != 0) return 0;
		/*for (int j = i + 1; j < soDinh; j++)
			if (a[i][j] != a[j][i])
				return 0;*/
	}
	return 1;

}

//Ham dem so va xuat so thanh phan lien thong
void isConnected(int** a, int& soDinh)
{
	//Em lam Thuat toan giong a Lam chi a!
	if (ktDOTHIVOHUONG(a, soDinh))
	{

		int nhan[MAX] = { 0 };
		for (int i = 0; i < soDinh; i++)
		{
			nhan[i] = i + 1;
			//cout << nhan[i] << "\t";
		}
		int m;
		for (int j = 0; j < soDinh; j++)
		{
			for (int i = 0; i < soDinh; i++)
			{
				if (a[j][i] != 0)
				{
					nhan[i] = nhan[j];
					m = i;
					for (int k = 0; k < soDinh; k++)
					{
						if (a[m][k] != 0)
							nhan[k] = nhan[m];
					}
				}
			}
		}
		// Dem so thanh phan lien thong va luu cac phan tu khac nhau trong mang temp[]
		int temp[MAX] = { 0 };
		int component = 1;
		temp[0] = nhan[0];

		for (int i = 1; i < soDinh; i++) {
			int count = 0;
			for (int j = 0; j < component; j++) {
				if (nhan[i] == temp[j])
					count++;
			}
			if (count == 0) {
				temp[component] = nhan[i];
				component++;
			}
		}

		//in so thanh phan lien thong
		int h = 0;
		cout << "So luong thanh phan lien thong: " << component << "\n";
		for (int i = 1; i <= component; i++)
		{
			cout << "\nThanh phan " << i << ":" << " ";
			for (int t = 0; t < soDinh; t++)
			{
				if (nhan[t] == temp[h]) cout << t + 1 << " ";
			}
			h++;
		}
		cout << endl;
	}
	else cout << "khong phai do thi vo huong";
}
int main()
{
	ifstream fileIn;
	fileIn.open("input_dothi.txt", ios_base::in); //mo file

	int vertex = cap_maTran(fileIn); // dinh cua do thi
	int** adjmatrix, row, column; // khai bai ma tran ke, so hang, so cot 
	row = vertex; column = vertex; // gan so hang so cot bang voi dinh do thi

	// cấp phát
	adjmatrix = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++) adjmatrix[i] = (int*)malloc(sizeof(int) * column);

	khoitao_Matrix(adjmatrix, row, column);
	gan_Matrix(adjmatrix, fileIn, vertex);
	isConnected(adjmatrix, vertex);

	fileIn.close(); //dong file 

	// Giải phóng bộ nhớ đã dùng để lưu địa chỉ mảng sau khi đã tạo mảng
	for (int j = 0; j < row; j++) free(adjmatrix[j]);

	free(adjmatrix);
	system("pause");
	return 0;
}
