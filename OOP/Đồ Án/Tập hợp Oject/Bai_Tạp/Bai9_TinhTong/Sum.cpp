#include<iostream>
#include<memory.h>
#include"sum.h"
using namespace std;
typedef int Item;

const int epz = 10;

bool Stack::push(Item x)
{
	if (full()) {
		//return false;
		Item* newSt = new Item(size + epz);
		memcpy(newSt, st, size * sizeof(Item));
		delete[]st;
		st = newSt;
		top = st + size;
		size += epz;
	}
	*top++ = x;
	return true;
}


bool Stack::pop(Item* px)
{
	if (empty()) return false;
	*px = *--top;
	return true;
}
