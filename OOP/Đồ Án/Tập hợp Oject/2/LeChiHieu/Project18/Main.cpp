#include "Main.h"
#include <math.h>
#include <stdio.h>
using namespace std;

Main::Main() {}

Main::~Main() {}

int Main::prioritize(string x) // ưu tiên Toán tử
{
	if (x == "sqrt" || x == "sin" || x == "cos" || x == "cosin" || x == "exp" || x == "log" || x == "abs"
		|| x == "tan" || x == "ceil" || x == "floor" || x == "round")
		return 3;
	if (x == "*" || x == "/" || x == "%" || x == "^")
		return 2;
	else if (x == "+" || x == "-")
		return 1;
	else if (x == "(") // có thể để hoặc bỏ
		return 0;

	return -1;
}

int Main::classify(string x) // phân loại số và toán tử (2 ngôi và 1 ngôi)
{
	if (x == "sqrt" || x == "exp" || x == "sin" ||
		x == "cos" || x == "cosin" || x == "log" || x == "abs"
		|| x == "tan" || x == "ceil" || x == "floor" || x == "round")
		return 3;
	if (x == "*" || x == "/" || x == "%" || x == "+" || x == "-" || x == "^")
		return 2;
	else
		return 1;
}
//int Main::Special(string x)
//{
//	if (x == "sqrt" || x == "exp" || x == "sin" ||
//		x == "cos" || x == "cosin" || x == "log")
//	{
//		int a = 1;
//		return a;
//	}
//}

string Main::calValue(string b, string x, string a) //công thưc tính toán
{
	float fResult = 0;

	if (x == "sqrt")
		fResult = double(sqrt(atof(a.c_str()))); // atof(a.c_str()) dùng để chuyển 1 string thành 1 số thực
	if (x == "cos" || x == "cosin")
		fResult = double(cos(atof(a.c_str())));
	if (x == "sin")
		fResult = double(sin(atof(a.c_str())));
	if (x == "log")
		fResult = double(log(atof(a.c_str())));
	if (x == "exp")
		fResult = double(exp(atof(a.c_str())));
	if (x == "abs")
		fResult = double(abs(atof(a.c_str())));
	if (x == "tan")
		fResult = double(tan(atof(a.c_str())));
	if (x == "ceil")
		fResult = int(ceil(atof(a.c_str())));
	if (x == "floor")
		fResult = int(floor(atof(a.c_str())));
	if (x == "round")
		fResult = int(round(atof(a.c_str())));
	if (x == "^")
	{
		fResult = 1;

		for (int i = 1; i <= int(atof(a.c_str())); i++)
			fResult = fResult * atof(b.c_str());
	}

	if (x == "%")
		fResult = int(atof(b.c_str())) % int(atof(a.c_str()));

	if (x == "*")
		fResult = atof(b.c_str()) * atof(a.c_str());
	else if (x == "/")
		fResult = atof(b.c_str()) / atof(a.c_str());
	else if (x == "+")
		fResult = atof(b.c_str()) + atof(a.c_str());
	else if (x == "-")
		fResult = atof(b.c_str()) - atof(a.c_str());

	string strResult = to_string(fResult); // vì ta vẫn còn làm việc với Stack mà stack top kiểu dữ liệu string
	return strResult;                      // vì thế dùng hàm to_string để chuyển 1 số thực thành 1 string
}

float Main::calValue(vector<string> M)
{
	float Result = 0;

	Stack* Sh = new Stack(); // Stack Toán hạng
	Stack* St = new Stack(); // Stack Toán tử

	for (int i = 0; i < M.size(); i++)
	{
		if (classify(M[i]) == 1 && M[i] != "(" && M[i] != ")") // nếu M[i] là số và khác "(" và khác ")"
			Sh->Push(M[i]);
		if (classify(M[i]) == 2) // nếu M[i] là toán tử 2 ngôi
		{
			while (!St->IsEmpty() && (prioritize(M[i]) <= prioritize(St->GetTop()->Info)))
			{
				string a = "";
				Sh->Pop(a);
				string x = "";
				St->Pop(x);
				string b = "";
				Sh->Pop(b);
				Sh->Push(this->calValue(b, x, a));
			}
			St->Push(M[i]);
		}
		if (classify(M[i]) == 3) // nếu M[i] là các hàm 1 ngôi
		{
			while (!St->IsEmpty() && (prioritize(M[i]) < prioritize(St->GetTop()->Info)))
			{
				string a = "";
				Sh->Pop(a);
				string x = "";
				St->Pop(x);
				string b = "";
				Sh->Push(this->calValue(b, x, a));
			}
			St->Push(M[i]);
		}
		if (M[i] == "(")
			St->Push(M[i]);
		if (M[i] == ")")
		{
			while (St->GetTop()->Info != "(")
			{

				string a = "";
				Sh->Pop(a);
				string x = "";
				St->Pop(x);
				string b = "";
				Sh->Pop(b);
				Sh->Push(this->calValue(b, x, a));
			}
			string c = "";
			St->Pop(c);
			while (!St->IsEmpty() &&
				(St->GetTop()->Info == "sqrt" || St->GetTop()->Info == "sin" 
					|| St->GetTop()->Info == "cos" || St->GetTop()->Info == "exp"
					|| St->GetTop()->Info == "abs"
					|| St->GetTop()->Info == "cosin" || St->GetTop()->Info == "log"
					|| St->GetTop()->Info == "tan" || St->GetTop()->Info == "ceil"
					|| St->GetTop()->Info == "floor" || St->GetTop()->Info == "round"))
			{
				string a = "";
				Sh->Pop(a);
				string x = "";
				St->Pop(x);
				string b = "";
				Sh->Push(this->calValue(b, x, a));
			}
		}
	}

	while (!St->IsEmpty()) // nếu vòng lặp kết thúc nhưng Stack toán tử không rỗng
	{
		string a = "";
		Sh->Pop(a);
		string x = "";
		St->Pop(x);
		string b = "";
		Sh->Pop(b);
		Sh->Push(this->calValue(b, x, a));
	}


	string strResult = "";
	Sh->Pop(strResult); // Kết quả là phần tử duy nhất của Stack Toán hạng
	Result = atof(strResult.c_str()); // xuất kết quả ra số
	return Result;
}