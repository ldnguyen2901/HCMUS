#include <iostream>
#include <string>
#include <vector>
#include "Form.h"
using namespace std;
#include "Main.h"

void main()
{
	string Input;
	do 
	{
		cout << "\nEnter (Press 0 to pause):  ";
		getline(cin, Input);
		DeleteSpace(Input);
		Main* main = new Main();
		vector<string> M;
		MoveString(Input, M);
		cout << "\nEqual: " << main->calValue(M) << endl;
	} 
	while (Input != "0");
}