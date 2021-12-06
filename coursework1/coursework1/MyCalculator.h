#pragma once
#include <string>
#include <iostream>
#include "Liststring.h"
#include "Listnum.h"
#include <cmath>
#define pi 3.141592653589793
#define e 2.718281828459045

using namespace std;

class MyCalculator
{
public:
	MyCalculator();
	MyCalculator(string arith);
	bool isarith();
	void arithtopolish();
	double resultarith();
	string getpolish();
	double getresult();
	void setarithexp(string expression);
	friend ostream& operator<< (ostream& out, const MyCalculator& calc);
private:
	int mycount(const char ch);
	int checksign(size_t index, string str);
	int myfind(const char* ch, size_t index, int len);
	int myfind(const string ch, size_t index, int len);
	double mystringtodouble(string number);
	string mydoubletostring(double number);
	string arith;
	string mypolish;
	string polish;
	double result;
	bool isarithmetic;
};