#include <iostream>
#include <string>
#include <vector>
using namespace std;
int FoundSpace(string str) //tìm khoảng trống
{
	for (int i = 0; i < str.length(); i++)
		if (str[i] == ' ')
			return i;
	return -1;
}

void DeleteSpace(string& str) // xóa khoảng trống
{
	int spacePos;

	while ((spacePos = FoundSpace(str)) != -1)
		str.erase(spacePos, 1);
}

void MoveString(string x, vector<string>& M) // chuyển string thành vector<string> để tối ưu việc lấy dữ liệu
{
	for (int i = 0; i < x.length(); i++) // xét string x
	{
		if (x[i] >= '0' && x[i] <= '9') // nếu phần tử là kí tự số
		{
			if (i < x.length() - 1) // xét từ vị trí i = 0 đến vị trí max - 1 vì phòng trường hợp
			{                       // các số có 2 chữ số sẽ không được liên kết với nhau
				for (int j = i + 1; j <= x.length(); j++) // xét các kí tự sau đó 
				{
					if (
						x[j] == ')' || x[j] == '*' || x[j] == '/' || x[j] == '+' ||
						x[j] == '-' || x[j] == '%' || x[j] == '^' || x[j] == '\0') // nếu là toán tử 2 ngôi hoặc )
					{
						M.push_back(x.substr(i, j - i)); // cắt chuỗi string x từ vị trí i với số lượng j - i
														// và thêm vào vector<string>
						// vd "1+" vì j = 1, thì cắt chuỗi string từ vị trí x[0] = 1 với số lượng j - i = 1 
						// suy ra M[1] là "1"
						i = j - 1; // bước này có thể dùng hoặc có thể bỏ
						break; // thoát khỏi vong lặp
					}
				}
				/*else if (x[] == 's' && x[+1] == 'q' && x[+2] == 'r' && x[+ 3] == 't')
				{
					M.push_back(x.substr(i, 4);
				}*/
			}
			else // còn số cuối cùng thì không ảnh hưởng
			{
				M.push_back(x.substr(i, x.length() - 1)); //lấy phân tử cuối cùng thêm vào M
				break;
			}
		}
		else if (
			x[i] == '(' || x[i] == ')' || x[i] == '*' || x[i] == '/' || // nếu phần tử là toán tử hoặc ( hoặc )
			x[i] == '+' || x[i] == '-' || x[i] == '%' || x[i] == '^')
		{
			string a(1, x[i]);
			M.push_back(a); //thêm phần tử đó vào M
		}
		else if (x[i] == 's' && x[i + 1] == 'q' && x[i + 2] == 'r' && x[i + 3] == 't') // cắt sqrt thành 1 string và gán vào cho phần tử của M
		{
			M.push_back(x.substr(i, 4));
		}
		else if (x[i] == 'c' && x[i + 1] == 'o' && x[i + 2] == 's') // tương tự với cos
		{
			M.push_back(x.substr(i, 3));
		}
		else if (x[i] == 'c' && x[i + 1] == 'o' && x[i + 2] == 's' && x[i + 3] == 'i' && x[i + 4] == 'n') // cosin
		{
			M.push_back(x.substr(i, 5));
		}
		else if (x[i] == 's' && x[i + 1] == 'i' && x[i + 2] == 'n') // sin
		{
			M.push_back(x.substr(i, 3));
		}
		else if (x[i] == 'e' && x[i + 1] == 'x' && x[i + 2] == 'p') // exp
		{
			M.push_back(x.substr(i, 3));
		}
		else if (x[i] == 'l' && x[i + 1] == 'o' && x[i + 2] == 'g') // log
		{
			M.push_back(x.substr(i, 3));
		}
		else if (x[i] == 'a' && x[i + 1] == 'b' && x[i + 2] == 's') // abs
		{
			M.push_back(x.substr(i, 3));
		}
		else if (x[i] == 't' && x[i + 1] == 'a' && x[i + 2] == 'n') // tan
		{
			M.push_back(x.substr(i, 3));
		}
		else if (x[i] == 'c' && x[i + 1] == 'e' && x[i + 2] == 'i' && x[i + 3] == 'l') // ceil
		{
			M.push_back(x.substr(i, 4));
		}
		else if (x[i] == 'f' && x[i + 1] == 'l' && x[i + 2] == 'o' && x[i + 3] == 'o' && x[i + 4] == 'r') // floor
		{
			M.push_back(x.substr(i, 5));
		}
		else if (x[i] == 'r' && x[i + 1] == 'o' && x[i + 2] == 'u' && x[i + 3] == 'n' && x[i + 4] == 'd') // round
		{
			M.push_back(x.substr(i, 5));
		}
	}
	for (int i = 0; i < M.size(); i++)
	{
		cout << M[i] << " ";
	}
}
