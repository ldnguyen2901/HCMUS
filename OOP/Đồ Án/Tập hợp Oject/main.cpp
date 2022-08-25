#include "main.h"
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>


#define MAX 100

using namespace std;

// Define prototype
bool isOperator(string ch);
bool isNumber(string ch);
int priority(string ch);
bool isCorrectBracket(string s);
bool isCorrectRealNumber(string s);
bool isFunction(string s);
double calc_func(string func, string num);
string calc_2_opt(string opt1, string opt2, string opt);
string trim(string s);
string trim_0(string s);
string process_func(string s);
string calc(string s);

// Functions implementation
bool isOperator(string ch) {

	if (ch.length() > 1) return false;

	return (ch == "+") ? true :
		(ch == "-") ? true :
		(ch == "*") ? true :
		(ch == "/") ? true :
		(ch == "^") ? true : false;
}

bool isNumber(string ch) {

	if (isOperator(ch)) return false;

	for (int i = 0; i < ch.length(); i++) {
		if ((int(ch[i]) >= 48 && int(ch[i]) <= 57) || ch[i] == '.') continue;
		else {
			return false;
		}
	}
	return true;
}

int priority(string ch) {
	if (ch == "+" || ch == "-") return 1;
	if (ch == "*" || ch == "/") return 2;
	if (ch == "^") return 3;
}

bool isCorrectBracket(string s) {

	string x = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == ')') x += s[i];
	}

	Stack<char> stack;
	for (int i = 0; i < x.length(); i++) {
		if (x[i] == '(') {
			stack.push(x[i]);
		}
		else if (x[i] == ')') {
			if (stack.get() != '(') return false;
			stack.pop();
		}
	}
	return true;
}

bool isCorrectRealNumber(string s) {

	bool isMeetDot = false;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '.') {
			if (!isMeetDot) isMeetDot = true;
			else {
				return false;
			}
		}
		else if (
			s[i] == '+' ||
			s[i] == '-' ||
			s[i] == '*' ||
			s[i] == '/' ||
			s[i] == '^' ||
			s[i] == '(' ||
			s[i] == ')') {

			isMeetDot = false;
		}
	}

	return true;
}

bool isFunction(string s) {
	if (int(s[0]) >= 97 && int(s[0] <= 122)) return true;
	else return false;
}

double calc_func(string func, string num) {
	double _num = stod(num);

	if (func == "sqrt") {
		return (double)sqrt(_num);
	}
	else if (func == "exp") {
		return (double)exp(_num);
	}
	else if (func == "sin") {
		return (double)sin(_num);
	}
	else if (func == "cos") {
		return (double)cos(_num);
	}
	else if (func == "tan") {
		return (double)tan(_num);
	}
	else if (func == "cot") {
		return (double)(1/tan(_num));
	}
	else if (func == "abs") {
		return (double)fabs(_num);
	}
	// Add these lines if you want to add more functions
//	else if (func == "name func") {
//		return (double)["name func"](_num);
//	}
}

string calc_2_opt(string opt1, string opt2, string opt) {

	double s1, s2, res;

	// Xử lí toán hạng 1
	s1 = stod(opt1);

	// Xử lí toán hạng 2
	s2 = stod(opt2);

	// Thực hiện tính toán
	if (opt == "+") {
		res = s2 + s1;
	}
	else if (opt == "-") {
		res = s2 - s1;
	}
	else if (opt == "*") {
		res = s2 * s1;
	}
	else if (opt == "/") {
		res = s2 / s1;
	}
	else if (opt == "^") {
		res = pow(s2, s1);
	}

	return std::to_string(res);
}

string trim(string s) {
	string x = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') x += s[i];
	}
	return x;
}

string trim_0(string s) {
	string res = s;

	while (res[res.length() - 1] == '0') {
		res.erase(res.length() - 1);
	}
	if (res[res.length() - 1] == '.') res.erase(res.length() - 1);

	return res;
}

/*
	This function is used to process the function value
	If inside the function is an expression or expression containing another functions
	-> calc(expression);
*/
string process_func(string s) {
	string x = "";	// string contains function name
	int i = 0;		// index variable of string s

	while (s[i] != '(') {	// Run until we meet '('
		x += s[i];			// Add each letter of function name
		i++;				// Increase i to reach to next letter
	}
	i++;					// Passing the '('
	string num = "";		// string contain the value inside the bracket
	while (i < s.length() - 1) {	// Run until before the last ')' -> make sure we take all value inside bracket
		num += s[i];				// Add each letter of that value
		i++;						// The same with above case
	}

	// After getting 2 categories, x is the function name and num is value inside bracket
	// -> calc_func(x, calc(num))
	// In this case, calc() function is called because we don't know in the string num
	// Do it have any expression or expression which contains function ??
	return std::to_string(calc_func(x, calc(num)));
}

/*
	This function is used to solve a string expression
	Input can be:
		"1+2+3"
		"1+2/(1+1)"
		"1+sqrt(16)"
		"1+sqrt(-(sqrt(16))+8)"
		...
*/
string calc(string s) {
	string infix[MAX];
	string component = "";

	// Convert input string to array which contains each components
	int in_idx = 0;
	int i = 0;
	while (i < s.length()) {
		if (int(s[i]) >= 97 && int(s[i] <= 122)) {
			string x = "";
			int cntOpenBracket = 0;
			while (1) {
				if (s[i] == '(') cntOpenBracket++;
				if (s[i] == ')') {
					cntOpenBracket--;
					if (cntOpenBracket == 0) break;
				}
				x += s[i];
				i++;
			}
			x += s[i];

			// I used component variable here in the case before function name is a substract operator
			// In this case, we exactly know that x is the function, so we need to call process_func() to solve it
			// And return it as a number
			infix[in_idx++] = component + process_func(x);

			// After solving, we need to reset component variable for the next time, if any
			component = "";
		}
		else if (s[i] == '+' ||
			s[i] == '-' ||
			s[i] == '*' ||
			s[i] == '/' ||
			s[i] == '^' ||
			s[i] == '(' ||
			s[i] == ')') {
			if (s[i] == '-') {
				if (i == 0) {
					component += s[i];
				}
				else if (s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/' || s[i - 1] == '^' || s[i - 1] == '(') {
					if (component == "-") component = "";
					else if (component == "+") component = "-";
					else component = "-";
				}
				else {
					infix[in_idx++] = s[i];
				}
			}
			else if (s[i] == '+') {
				if (i == 0) {
					// Do nothing
				}
				else if (s[i - 1] == '+' || 
					s[i - 1] == '-' || 
					s[i - 1] == '*' || 
					s[i - 1] == '/' || 
					s[i - 1] == '^' || 
					s[i - 1] == '(') {
					if (component == "-") component = "-";
					else if (component == "+") component = "";
					else component = "";
				}
				else {
					infix[in_idx++] = s[i];
				}
			}
			else {
				infix[in_idx++] = s[i];
			}
		}
		else {
			if (i + 1 < s.length()) {
				if (s[i + 1] == '+' ||
					s[i + 1] == '-' ||
					s[i + 1] == '*' ||
					s[i + 1] == '/' ||
					s[i + 1] == '^' ||
					s[i + 1] == '(' ||
					s[i + 1] == ')') {
					infix[in_idx++] = component + s[i];
					component = "";
				}
				else {
					component += s[i];
				}
			}
			else {
				infix[in_idx++] = component + s[i];
				component = "";
			}
		}
		i++;
	}

	//	for (i = 0; i < in_idx; i++) cout << infix[i] << " ";
	//	std::system("pause");

	// Convert infix to postfix
	string postfix[MAX];
	int pos_idx = 0;
	Stack<string> stack;

	for (int i = 0; i < in_idx; i++) {

		string t = infix[i];

		if (isNumber(t) || (t[0] == '-' && t.length() > 1)) {
			postfix[pos_idx++] = infix[i];
		}
		else if (t == "(") {
			stack.push(t);
		}
		else if (isOperator(t)) {
			if (stack.isEmpty()) stack.push(t);
			else {

				if (stack.get() == "(") stack.push(t);
				else {
					int prior = priority(t);

					// TH1: dấu +, -
					if (prior == 1) {
						postfix[pos_idx++] = stack.pop();
						stack.push(t);
					}
					// TH2: dấu *, /
					else if (prior == 2) {
						// Nếu toán tử ở đỉnh stack là +, - 
						// => Độ ưu tiên nhỏ hơn => Không pop(), chỉ push()
						if (priority(stack.get()) == 1) stack.push(t);

						// Nếu toán tử ở đỉnh stack
						// => Cùng độ ưu tiên => pop(), sau đó push()
						else if (priority(stack.get()) == 2 || priority(stack.get()) == 3) {
							postfix[pos_idx++] = stack.pop();
							stack.push(t);
						}
					}
					// TH3: dấu ^
					else if (prior == 3) {
						// Nếu toán tử là +,-,*,/ -> độ ưu tiên nhỏ hơn => chỉ push()
						if (priority(stack.get()) == 1 || priority(stack.get()) == 2) stack.push(t);

						// Ở đỉnh stack là dấu ^ thì mới pop(), sau đó push()
						else if (priority(stack.get()) == 3) {
							postfix[pos_idx++] = stack.pop();
							stack.push(t);
						}
					}
				}
			}
		}
		else if (t == ")") {
			while (stack.get() != "(") {
				postfix[pos_idx++] = stack.pop();
			}

			// Pop dấu "(" ra sau khi xử lí xong dấu ")"
			stack.pop();
		}
	}

	while (!stack.isEmpty()) {
		postfix[pos_idx++] = stack.pop();
	}

	//	for (i = 0; i < in_idx; i++) cout << posfix[i] << " ";
	//	std::system("pause");

	// Process posfix
	// Quy tắc:
	// + Nếu là toán hạng -> push()
	// + Nếu là toán tử -> opt1 = pop(), opt2 = pop()
	//					-> Tính res = opt2 [toán tử] opt1 -> push(res)

	// TH chỉ có 1 toán hạng
	if (pos_idx == 1) {
		return trim_0(postfix[0]);
	}

	for (i = 0; i < pos_idx; i++) {
		string t = postfix[i];

		// TH: là toán hạng hoặc là hàm
		if (isNumber(t) || (t[0] == '-' && t.length() > 1)) stack.push(t);

		// TH là toán tử
		if (isOperator(t)) {
			string opt1 = stack.pop();
			string opt2 = stack.pop();

			stack.push(calc_2_opt(opt1, opt2, t));
		}
	}

	// Process result
	string res = stack.pop();

	return trim_0(res);
}

int main() {

	
	string s;
	cout << "Enter an infix Expression:";
	getline(cin, s);
	cout << "Result:";

	if (!isCorrectBracket(s)) {
		cout << "Wrong input!";
		std::system("pause");
		return 0;
	}
	if (!isCorrectRealNumber(s)) {
		cout << "Wrong input!";
		std::system("pause");
		return 0;
	}

	s = trim(s);

	cout << calc(s) << endl;

	std::system("pause");
}