#pragma once
#include<iostream>
typedef int Item;

class Node
{
	friend class List;
	Item data;
	Node* next;
};

class List
{
	Node* Top;
public:
	List() { Top = NULL; }
	~List() {};
	bool empty() { return Top == NULL; }
	void push(Item value);
	bool pop(Item* x);
	void display();
};