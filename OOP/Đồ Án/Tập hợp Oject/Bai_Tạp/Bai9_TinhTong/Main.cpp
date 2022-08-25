#include<iostream>
#include<memory.h>
#include"sum.h"

void sum(int a)
{
	Stack s;
	int x, y, sum = 0;
	while (a != 0)
	{
		s.push(a % 10);
		a = int(a / 10);
	}
	//s.display();
	cout << "Sum of each number: ";
	while (s.pop(&x))
	{
		sum += x;
		cout << x;
		if (s.empty())
			cout << " = ";
		else
			cout << " + ";
	}
	cout << sum;
}

void main()
{
	int a;
	cout << "In put number that need to analys: ";
	cin >> a;
	sum(a);
}