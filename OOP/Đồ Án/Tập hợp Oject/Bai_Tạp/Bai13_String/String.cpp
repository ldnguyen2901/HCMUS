#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"String.h"


using namespace std;

void String::print() const
{
	cout << "Output string: " << p;
}

void String::input()
{
	cout << "Please input the string: ";
	delete[] p;
	static char q[1000];
	cin.getline(q, 1000);
	p = _strdup(q);
}

void String::set(const char* s)
{
	if (p)
		delete p;
	if (!p)
	{
		p = NULL;
		return;
	}
	p = new char(strlen(s) + 1);
	strcpy(p, s);
}

String& String::concat(const String& sz)
{
	char* q = new char[getLength() + sz.getLength() + 1];
	strcpy(q, p);
	strcat(q, sz.p);
	delete[]p;
	p = q;
	cout << p;
	return *this;
}