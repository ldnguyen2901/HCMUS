/*
 HO VA TEN : VONG VINH PHU 
 MSSV : 19110413
 MON : LAP TRINH HUONG DOI TUONG
*/

#include"UintN.h"
#include <ctime>
bool CheckPrime2N(UintN& num1,UintN& num2) 
{
	if (UintN::isPrime(num1) == true && UintN::isPrime(num2) == true)
	{
		cout << num1 << " & " << num2 << " are prime number \n";
		return true;
	}
	else if (UintN::isPrime(num1) == true && UintN::isPrime(num2) == false)
	{
		cout << num2 << " is not prime number \n";
		cout << num1 << " is a prime number\n";
		return true;
	}
	else if (UintN::isPrime(num1) == false && UintN::isPrime(num2) == true)
	{
		cout << num1 << " is not prime number \n";
		cout << num2 << " is a prime number\n";
		return true;
	}
	else
	{
		cout <<"they aren't prime number\n";
		return false;
	}

}
void findthenextprime(UintN& num1, UintN& num2)
{
	if (CheckPrime2N(num1, num2))
	{
		if (num1 > num2)
		{
			cout << "the next prime number bigger than " << num1 << " & " << num2 << " is " << UintN::nextPrime(num1) << endl;
		}
		else
		{
			cout << "the next prime number bigger than " << num1 << " & " << num2 << " is " << UintN::nextPrime(num2) << endl;
		}
		
	}
	else
	{
		if (num1 > num2)
		{
			cout << "the next prime number bigger than " << num1 << " & " << num2 << " is " << UintN::nextPrime(num1) << endl;
		}
		else
		{
			cout << "the next prime number bigger than " << num1 << " & " << num2 << " is " << UintN::nextPrime(num2) << endl;
		}
	}
}

int main() {
	clock_t time_req;
	UintN a, b, c;
	cin >> a >> b;
	//-------test tim so nguyen to -------
	
	time_req = clock();
	findthenextprime(a, b);
	time_req = clock() - time_req;
	cout << "Using Find the next prime function, it took " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
	
	//-------test toan tu -------
	/*
	time_req = clock();
	cout << a << " + " << b << " = " << a + b << endl;
	time_req = clock() - time_req;
	cout << "operator + it took " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
	cout << "\n";
	time_req = clock();
	cout << a << " - " << b << " = " << a - b << endl;
	time_req = clock() - time_req;
	cout << "operator - it took " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
	cout << "\n";
	time_req = clock();
	cout << a << " * " << b << " = " << a * b << endl;
	time_req = clock() - time_req;
	cout << "operator * it took " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
	cout << "\n";
	time_req = clock();
	cout << a << " / " << b << " = " << a / b << endl;
	time_req = clock() - time_req;
	cout << "operator / it took " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
	cout << "\n";
	time_req = clock();
	cout << a << " % " << b << " = " << a % b << endl;
	time_req = clock() - time_req;
	cout << "operator % it took " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
	*/
	//-------test phep gan-------
	/*
	c=a;
	cout << a  << " and " << c << endl;
	c = a + b;
	cout << a << " + " << b << "=" << c << endl;
	c = a - b;
	cout << a << " - " << b << "=" << c << endl;
	c = a * b;
	cout << a << " * " << b << "=" << c << endl;
	c = a / b;
	cout << a << " / " << b << "=" << c << endl;
	c = a % b;
	cout << a << " % " << b << "=" << c << endl;
	c = a + "5";
	cout << a << " + " << "5" << "=" << c << endl;
	*/
	//-------test phep gan toan tu-------
	/*
	UintN d;
	cin >> d;
	cout << d << " + " << a << "=";
	d += a;
	cout << d << endl;
	cout << d << " - " << a;
	d -= a;
	cout << d << endl;
	cout << d << " * " << a << "=" ;
	d *= a;
	cout << d << endl;
	cout << d << " / " << a << "=" ;
	d /= a;
	cout << d << endl;
	cout << d << " % " << a << "=" ;
	d %= a;
	cout << d << endl; */
	//-------test phep so sanh------
	/*if (a == b)
	{
		cout << "Equal";
	}
	else if (a!=b)
	{
		cout << "Not Equal\n";
	}
	if (a > b)
	{
		cout << "Greater";
	}
	else if (a < b)
	{
		cout << "less";
	}*/
	
}