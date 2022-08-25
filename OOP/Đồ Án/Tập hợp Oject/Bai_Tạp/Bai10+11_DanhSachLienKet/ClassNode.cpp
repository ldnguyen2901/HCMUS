#include<iostream>
#include"Classnode.h"

using namespace std;

void List::push(Item value)
{
	Node* X;
	X = new(Node);
	X-> data = value;
	X->next = NULL;
	if (Top == NULL)
		Top = X;
	else
	{
		X->next = Top;
		Top = X;
	}
}

bool List::pop(Item* x)
{
	if (empty())
		return false;
	Node* X;
	X = Top;
	*x = X->data;
	Top = X->next;
	delete(X);
	return true;
}

void List::display()
{
	Node* X;
	if (empty())
	{
		cout << "Memory is overflow" << endl;
		return;
	}
	X = Top;
	while (X != NULL)
	{
		cout << X->data << " ";
		X = X->next;
	}
	cout << endl;
}


