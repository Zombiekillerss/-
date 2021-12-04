#pragma once
#include <string>
#include <iostream>
#include "Liststring.h"
#define _USE_MATH_DEFINES
//M_E=e
//M_PI=pi
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
	friend ostream& operator<< (ostream& out, const MyCalculator& calc);
private:
	int mycount(const char ch);
	int checksign(int index);
	bool ispolish(string str);
	int myfind(const char* ch, int index, int len);
	int myfind(const string ch, int index, int len);
	string arith;
	string polish;
	double result;
	bool isarithmetic;
};