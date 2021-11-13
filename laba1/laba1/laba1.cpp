#include <iostream>
#include "Listnum.h"
using namespace std;

int main()
{
	Listnum list1;
	int number;
	cout << "enter the number you want to add to the list(-1 = exit the input)" << endl;
	do
	{
		cout << "enter the number ";
		cin >> number;
		if (number != -1) list1.push_back(number);
	} while (number != -1);
    cout << list1 << endl;
	return 0;
}