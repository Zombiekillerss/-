#include <iostream>
#include "MyCalculator.h"
using namespace std;


int main()
{
	bool flag = true;
	size_t i;
	string str;
	MyCalculator calc;
	str = "sin(pi/2)-sin(pi/2)";
	calc.setarithexp(str);
	calc.resultarith();
	cout << "you intered " << str << endl;
	cout << calc << endl;
}
