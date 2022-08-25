#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

inline char* __strdup(const char* s) 
{
	return strcpy(new char[strlen(s) + 1], s);
}

class String
{
	char* p;
public:
	String(const char* s) { p = _strdup(s); }
	String(const String& s) { p = _strdup(s.p); }
	~String() { if (p) delete p; }
	int getLength() const { return strlen(p); }
	void Upcase() {cout << _strupr(p); }
	void Lowcase() { cout << _strlwr(p); }
	void Reverse() { cout << _strrev(p); }
	void print() const;
	void set(const char* s);
	void input();
	String& concat(const String& sz);
};





