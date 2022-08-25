#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"String.h"


using namespace std;


int main()
{

	
	//b.print();
	//cout << "\n";
	/*b.set("a variable string");
	b.print();
	cout << "\n";*/
	
	String b("This is a string 1: ");
	b.input();
	b.print();
	//b.set("Hello");
	cout << "String 1 is: ";
	cout << "\nLength of string 1: " << b.getLength() << endl;
	cout << "\nString up: ";
	b.Upcase();
	cout << "\nString lower: ";
	b.Lowcase();
	cout << endl;
	
	cout << "\n-------------------------\n";
	String c("This is a string 2:");
	c.input();
	c.print();
	cout << "\nlength of string 2: " << c.getLength() << endl;
	cout << "\nString up: ";
	c.Upcase();
	cout << "\nString lower: ";
	c.Lowcase();
	cout << endl;
	
	cout << "\nConcat:  ";
	b.concat(c);
	cout << "\nReverse:";
	b.Reverse();
	
	

	cout << "\n" ;

	return 0;
}