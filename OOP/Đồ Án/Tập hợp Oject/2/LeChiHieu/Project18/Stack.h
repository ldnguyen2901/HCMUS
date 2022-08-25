#pragma once
#pragma once

#include <stdio.h>
#include "Node.h"
class Stack
{
private:
	Node* Top;
public:
	Stack();
	~Stack();
	int IsEmpty();
	Node* newNode(Data x);
	void Push(Data x);
	int Pop(Data& x);
	Node* GetTop();
};