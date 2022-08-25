#pragma once
#include <sstream>
#include <vector>
#include <string>
#include "Stack.h"
class Main
{
public:
	Main();
	~Main();
	int prioritize(string x);
	int classify(string x);
	// int Special(string x);
	string calValue(string b, string x, string a);
	float calValue(vector<string> M);
};
