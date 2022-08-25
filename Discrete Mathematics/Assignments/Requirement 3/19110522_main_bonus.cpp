#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include<vector>
#include <set>
using namespace std;
#define INT_MAX 1000000

//Cac ham trong bai
int so_dong_file(ifstream& fileIn);
int tim_cap_matrix(ifstream& fileIn);
void khoitao_matrix(int** arr, int& vertex);
void readFile(ifstream& fileIn, int** a, int& loaiDoThi, int& start, int& end);
void read_file_ten_dinh(ifstream& fileIn, vector <int> num_vertex, vector <string> &name_vertex);
void output_path(ofstream& FileOut,vector<int> input, int start, int end,vector <string> &name_vertex);
int min_vector(vector<int> input);
int min_index_vector(vector<int> input, int min);
void khoi_tao_dijkstra_matrix(int** a, int& vertex);
void Dijkstra(int** a, int& vertex, int& start, int& end,vector <string> &name_vertex);

//Ham dem so dong cua file
int so_dong_file(ifstream& fileIn)
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
	fileIn.seekg(0, ios::beg); //con tro chi vi: dich chuyen con tro chi vi trong file len dau tien
	return vertex;
}
//Ham doc File tim de cap ma tran
int tim_cap_matrix(ifstream& fileIn)
{
	fileIn.open("thong_tin_dinh.txt", ios_base::in);
	int loaiDoThi, vertex;
	fileIn >> loaiDoThi;
	fileIn >> vertex;
	fileIn.clear();
	fileIn.seekg(0, ios::beg); //con tro chi vi: dich chuyen con tro chi vi trong file len dau tien
	fileIn.close();
	return vertex;
}
//Ham khoi tao ma tran co so dong va so cot bang cap cua ma tran
void khoitao_matrix(int** arr, int& vertex)
{

	for (int i = 0; i < vertex; i++)
	{
		for (int j = 0; j < vertex; j++)
		{
			arr[i][j] = 0;
		}
	}
}
//Ham doc file thong tin dinh
void readFile(ifstream& fileIn, int** a, int& loaiDoThi, int& start, int& end)
{
	fileIn.open("thong_tin_dinh.txt", ios_base::in);
	int row = so_dong_file(fileIn); // Hàm đọc số dòng trong file
	string s;
	int vertex;
	fileIn >> loaiDoThi;
	fileIn >> vertex;
	for (int i = 2; i < row; i++)
	{
		getline(fileIn, s);
		string temp;
		vector<int> boba; // length === 3
		for (int j = 0; j <= s.length(); j++)
		{
			if (s[j] >= '0' && s[j] <= '9')
				temp += s[j];
			else
			{
				if (!temp.empty()) {
					int h = stoi(temp);
					boba.push_back(h);
				}
				temp = "";
			}
		}
		// boba = [1 , 2 , 3]
		if (boba.size() == 3) {
			if (loaiDoThi == 0) {
				a[boba[0] - 1][boba[1] - 1] = boba[2];
				a[boba[1] - 1][boba[0] - 1] = boba[2];
			}
			else
			{
				a[boba[0] - 1][boba[1] - 1] = boba[2];
			}
		}

	}
	fileIn >> start;
	fileIn >> end;
	fileIn.close();
}
//Ham doc file ten dinh
void read_file_ten_dinh(ifstream& fileIn,vector <int> num_vertex,vector <string> &name_vertex)
{
	fileIn.open("ten_dinh.txt", ios_base::in);
	while (!fileIn.eof())
	{
		string s;
		string temp_1;
		string temp_2;
		int count = 0;
		getline(fileIn, s);
		for (int i = 0; i < 2; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				temp_1 += s[i];
				count++;
			}
			else break;
		}
		int h = stoi(temp_1);
		num_vertex.push_back(h);
		temp_1 = "";
		for (int i = count + 1; i < s.length(); i++)
		{
			temp_2 += s[i];
		}
		name_vertex.push_back(temp_2);
		
		temp_2 = "";
		
	}
	fileIn.close();
}
// Ham in ra duong di
void output_path(ofstream &FileOut,vector<int> input, int start, int end,vector <string>& name_vertex)
{
	vector <int> path;
	int save = end;
	if (start < end)
	{
		while (1)
		{
			for (int j = input.size(); j >= 0; j--)
			{
				if (j == save)
				{
					path.push_back(save);
					save = input[j];
					break;
				}
			}
			if (save == start)
			{
				path.push_back(save);
				break;
			}
		}
	}
	else
	{
		while (1)
		{
			for (int j = 0; j < input.size(); j++)
			{
				if (j == save)
				{
					path.push_back(save);
					save = input[j];
					break;
				}
			}

			if (save == start)
			{
				path.push_back(save);
				break;
			}
		}
	}
	reverse(path.begin(), path.end()); //Dao nguoc thu tu vector 
	// print path
	for (int i = 0; i < path.size(); i++) 
	{
		int k;
		if (i == path.size() - 1)
		{
			k = path[i];
			cout << name_vertex.at(k);
			break;
		}
		k = path[i];
		cout << name_vertex.at(k) << " -> ";

	}

	// print path bai 3
	for (int i = 0; i < path.size(); i++)
	{
		int k;
		if (i == path.size() - 1)
		{
			k = path[i];
			FileOut << name_vertex.at(k);
			break;
		}
		k = path[i];
		FileOut << name_vertex.at(k) << " -> ";

	}
}
// Ham khoi tao ma tran o vi tri neu khong co trong so thi duoc gan la INT_MAX
void khoi_tao_dijkstra_matrix(int** a, int& vertex)
{
	for (int i = 0; i < vertex; i++)
	{
		for (int j = 0; j < vertex; j++)
		{
			if (a[i][j] == 0) a[i][j] = INT_MAX;
		}
	}
}
//Ham tim phan tu be nhat trong vector
int min_vector(vector<int> input)
{
	int min = input[0];
	for (int i = 0; i < input.size(); i++) {
		if (input[i] < min)
		{
			min = input[i];

		}
	}
	return min;
}
//Ham tim vi tri cua phan tu be nhat trong vector
int min_index_vector(vector<int> input, int min)
{
	auto it = find(input.begin(), input.end(), min);
	int index = it - input.begin();
	return index;
}
//Ham tim duong di ngan nhat
void Dijkstra(int** a, int& vertex, int& start, int& end,vector <string>& name_vertex)
{
	ofstream FileOut;
	FileOut.open("ket_qua_bonus_19110522.txt", ios_base::out);
	start--; end--;
	if (start == end)
	{
		cout << "Tong chi phi di chuyen = 0" << endl;
		cout << "Duong di ngan nhat cua do thi la: " << name_vertex[start] << endl;
		FileOut << "Tong chi phi di chuyen = 0" << endl;
		FileOut << "Duong di ngan nhat cua do thi la: " << name_vertex[start] << endl;
		FileOut.close();
		system("pause");
	}
	vector <int> dist;
	vector <int> previous;
	set <int> visited;
	for (int i = 0; i < vertex; i++)
	{
		dist.push_back(INT_MAX);
		previous.push_back(0);
	}
	dist[start] = 0;
	int min = min_vector(dist);
	int u = min_index_vector(dist, min);

	while (1)
	{
		visited.insert(u);
		for (int v = 0; v < vertex; v++)
		{

			if (!visited.count(v))
			{
				int alt = dist[u] + a[u][v];
				if (alt < dist[v])
				{
					dist[v] = alt;
					previous[v] = u;
				}
			}
		}

		for (int i = 0; i < dist.size(); i++)
		{
			if (visited.count(i))
			{
				dist[i] = INT_MAX;
			}

		}
		min = min_vector(dist);
		u = min_index_vector(dist, min);
		if (u == end) break;


	}
	//Ghi ra file 
	if (dist[end] == INT_MAX)
	{
		cout << "Khong co duong di ngan nhat";
		FileOut << "Khong co duong di ngan nhat";
	}
	FileOut << "Tong chi phi di chuyen = " << dist[end] << endl;
	FileOut << "Duong di ngan nhat cua do thi la: ";
	// xuat ra man hinh
	cout << "Tong chi phi di chuyen = " << dist[end] << endl;
	cout << "Duong di ngan nhat cua do thi la: ";
	output_path(FileOut, previous, start, end, name_vertex);
	cout << endl;
	FileOut.close();
}
int main()
{
	ifstream fileIn;
	int loaiDoThi, ** adjmatrix;
	int start, end;
	int vertex = tim_cap_matrix(fileIn);
	vector <int> num_vertex;
	vector <string> name_vertex;
	// cấp phát
	adjmatrix = (int**)malloc(sizeof(int*) * vertex);
	for (int i = 0; i < vertex; i++) adjmatrix[i] = (int*)malloc(sizeof(int) * vertex);

	khoitao_matrix(adjmatrix, vertex);
	readFile(fileIn, adjmatrix, loaiDoThi, start, end);
	read_file_ten_dinh(fileIn,num_vertex,name_vertex);
	khoi_tao_dijkstra_matrix(adjmatrix, vertex);
	Dijkstra(adjmatrix, vertex, start, end,name_vertex);
	//Giải phóng bộ nhớ đã dùng để lưu địa chỉ mảng sau khi đã tạo mảng
	for (int j = 0; j < vertex; j++) free(adjmatrix[j]); free(adjmatrix);

	system("pause");
	return 0;
}