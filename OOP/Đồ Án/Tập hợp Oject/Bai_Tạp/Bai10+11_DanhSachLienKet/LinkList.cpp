#include<iostream>
#include"Classnode.h"

using namespace std;

void printHEX(int n)
{
	long temp = n;
	static char hTab[] = "0123456789ABCDEF";
	List s;
	int x;
	do
	{
		s.push(n % 16);
		n /= 16;
	} while (n);
	cout << "Number " << temp << " in HEX is ";
	while (s.pop(&x))
		cout << hTab[x];
}

void Exchange(long n, int h)
{
	long temp = n;
	if ((n < 0) || (h < 2) || (h > 36))
	{
		cout << "The value is not available to exchange" << endl;
		return;
	}
	static char hTab[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	List s;
	int x;
	do
	{
		s.push(n % h);
		n /= h;
	} while (n);
	cout << "Number " << temp << " in system " << h << " = ";
	while (s.pop(&x))
		cout << hTab[x];
}

bool CheckPrimeNumber(int n)
{
	if (n < 2)
		return false;
	else
	{
		if (n == 2)
			return true;
		else
		{
			for (int i = 2; i < n / 2; i++)
				if (n % i == 0)
					return false;
		}
	}
	return true;
}

void PrimeFactorAnalysis(long a)
{
	List s, countS;
	int x, y, count;
	int so_bi_chia = a;
	int so_nt = 0;
	for (int i = 2; i <= a; i++)
	{
		if (CheckPrimeNumber(i) == true)
		{
			count = 0;
			while (so_bi_chia != 1)
			{
				if (so_bi_chia % i == 0)
				{
					so_bi_chia = so_bi_chia / i;
					so_nt = i;
					count++;
					if (count <= 1)
						s.push(so_nt);
				}
				else
				{
					if (count != 0)
						countS.push(count);
					break;
				}
			}
			if (so_bi_chia == 1)
			{
				if (count != 0)
					countS.push(count);
				break;
			}

		}
	}
	cout << "Analysic to prime factor : " << a << " = ";
	while (s.pop(&x) && countS.pop(&y))
	{
		cout << x;
		if (y == 1)
		{
			if (s.empty() == false)
				cout << " * ";
		}
		else
		{
			cout << " ^ " << y;
			if (s.empty() == false)
				cout << " * ";
		}
	}
	cout << endl;
}


void sum(long a)
{
	List s;
	int x,y, sum = 0;
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
	long a;
	int h;
	cout << "input a: ";
	cin >> a;
	printHEX(a);
	cout << endl;
	cout << "Input sysytem you want: "; 
	cin >> h;
	Exchange(a, h);
	cout << endl;
	PrimeFactorAnalysis(a);
	sum(a);
}
