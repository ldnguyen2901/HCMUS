#pragma once
#include<iostream>
using namespace std;
typedef int Item;

class Stack
{
	Item* st, * top;
	int size;
	void init(int sz) {
		top = st = new Item[size = sz];
	}
	void cleanUp() { delete[] st; }
public:
	Stack(int sz = 20) { init(sz); }
	~Stack() { cleanUp(); }
	bool empty() { return top <= st; }
	bool full() { return top - st >= size; }
	bool push(Item x);
	bool pop(Item* px);
};