/*
 HO VA TEN : VONG VINH PHU
 MSSV : 19110413
 MON : LAP TRINH HUONG DOI TUONG
*/
#pragma once
#include<iostream>
#include<string>
using namespace std;
const int N = 4;
class UintN
{
private:
	unsigned int* BigNum = new unsigned int[N];
public:
	//Khoi Tao
	UintN();
	UintN(string num);
	UintN(const UintN&);
	~UintN() { delete[] BigNum; BigNum = NULL; } // Ham huy bo ( Deconstructor )
	// thao tac voi bits
	/* ---------- */
	// Ham Static xu ly string 
	static int convertCharToInt(char c);
	static char convertIntToChar(int x);
	static string divStrFor2(string strSource);
	static string mulStrFor2(string strSource);
	static string addStrWith1(string strSource);
	static string output(const UintN& num);
	// Xu Ly bits
	void onBit(int locate); //  bit on
	void offBit(int locate); // bit off
	bool getBit(int index) const; // get bit 
	UintN operator~() const; // not 
	friend UintN operator^(const UintN&, const UintN&); //Xor
	friend UintN operator&(const UintN&, const UintN&); // And
	UintN operator<<(const int x) const; // Shift left bits
	UintN operator>>(const int x) const; // Shift right bits
	// toan tu
	/* ---------- */
	/* Input/Output UintN */
	UintN& operator=(const UintN&);
	UintN& operator=(const string& num);
	friend ostream& operator<<(ostream&, const UintN&);
	friend istream& operator>>(istream&, UintN&);
	/* so sanh */
	friend bool operator==(const UintN&, const UintN&);
	friend bool operator!=(const UintN&, const UintN&);
	friend bool operator>(const UintN&, const UintN&);
	friend bool operator<(const UintN&, const UintN&);
	friend bool operator>=(const UintN&, const UintN&);
	friend bool operator<=(const UintN&, const UintN&);
	/* Phep Toan co ban */
	friend UintN operator+(const UintN&, const UintN&);
	friend UintN operator+(const string&, const UintN&);
	friend UintN operator+(const UintN&, const string&);
	UintN& operator+=(const UintN&);
	UintN& operator+=(const string&);
	friend UintN operator-(const UintN&, const UintN&);
	friend UintN operator-(const string&, const UintN&);
	friend UintN operator-(const UintN&, const string&);
	UintN& operator-=(const UintN&);
	UintN& operator-=(const string&);
	friend UintN operator*(const UintN&, const UintN&);
	friend UintN operator*(const string&, const UintN&);
	friend UintN operator*(const UintN&, const string&);
	UintN& operator*=( const UintN&);
	UintN& operator*=( const string&);
	friend UintN operator/(const UintN&, const UintN&);
	friend UintN operator/(const string&, const UintN&);
	friend UintN operator/(const UintN&, const string&);
	UintN& operator/=(const UintN&);
	UintN& operator/=(const string&);
	friend UintN operator%(const UintN&, const UintN&);
	friend UintN operator%(const string&, const UintN&);
	friend UintN operator%(const UintN&, const string&);
	UintN& operator%=(const UintN&);
	UintN& operator%=(const string&);
	/* Prime Number */
	static bool isPrime(UintN&);
	static UintN nextPrime(UintN& num);
};
