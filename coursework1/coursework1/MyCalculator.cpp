#include "MyCalculator.h"

MyCalculator::MyCalculator()
{
	result = 0;
	isarithmetic = false;
}

MyCalculator::MyCalculator(string arith)
{
	result = 0;
	this->arith = arith;
	isarithmetic = false;
}

bool MyCalculator::isarith()
{
	int nesting = 0;//nesting brackets
	size_t i = 0;
	bool flag = !arith.empty(); // string validation
	for (i = 0; i < arith.size() && flag; i++) // walks through the line and looks if numbers, functions and signs are entered correctly
	{
		flag = (myfind("cos",i, 3) == i || myfind("sin", i, 3) == i
			|| myfind("ctg", i, 3) == i || myfind("log", i, 3) == i);
		if (flag)
		{
			i += 2;
		}
		else 
		{
			flag =(myfind("tg", i, 2) == i || myfind("ln", i, 2) == i || myfind("pi", i, 2) == i);
			if (flag)
			{
				i++;
			}
			else
			{
				flag = (myfind("sqrt", i, 4) == i);
				if (flag)
				{
					i += 3;
				}
				else
				{
					flag =  myfind("arccos", i, 6) == i;
					if (flag)
					{
						i += 4;
					}
					else
					{
						flag = arith[i] != ' ' && (isdigit(arith[i]) ||
							arith[i] == '+' || arith[i] == '-' ||
							arith[i] == '*' || arith[i] == '/' || arith[i] == '^' || arith[i] == ',' || arith[i] == ')' || arith[i] == '('
							|| arith[i] == 'e');
					}
				}
			}
		}
	}
	flag = flag && mycount('(') == mycount(')');
	if (flag)// if there are no extra characters
	{
		for (i = 0; i < arith.size() && flag; i++)
		{
			switch (arith[i])
			{
			case '(':
				nesting++;
				if (i + 1 < arith.size()) flag = (arith[i + 1] != ')');
				else flag = false;
				break;
			case ')':
				nesting--;
				if (i > 0) flag = (arith[i - 1] != '(');
				else flag = false;
				break;
			}
			flag = flag && !(nesting < 0);
			if ((arith[i] == 'c' || arith[i] == 's' || arith[i] == 'l') && flag)
			{
				if (arith[i + 1] == 'n') // if ln
				{
					if (i + 2 < arith.size()) flag = (arith[i + 2] == '(' || arith[i + 3] == '(');
					else flag = false;
					i += 1;
				}
				else if (arith[i + 2] == 'n' || arith[i + 2] == 's' || arith[i + 2] == 'g') // if sin cos log
				{
					if (i + 3 < arith.size()) flag = (arith[i + 3] == '(');
					else flag = false;
					i += 2;
				}
				else // if sqrt
				{
					if (i + 4 < arith.size()) flag = (arith[i + 4] == '(');
					else flag = false;
					i += 3;
				}
			}
			else if ((arith[i] == '+' || arith[i] == '-') && flag)
			{
				if (i + 1 < arith.size())
					flag = (isdigit(arith[i + 1]) || arith[i + 1] == '(' || arith[i + 1] == 'c'
						|| arith[i + 1] == 's' || arith[i + 1] == 't' || arith[i + 1] == 'l' || arith[i + 1] == 'a' || arith[i + 1] == 'p'
						|| arith[i + 1] == 'e');
				else if (i > 0)
					flag = (isdigit(arith[i - 1]) || arith[i - 1] == ')' || arith[i - 1] == 'i' || arith[i - 1] == 'e'
						|| (arith[i] == '-' && arith[i - 1] == '('));
				else if (i == 0 && arith[i] == '-') flag = true;
				else flag = false;
			}
			else if ((arith[i] == '*' || arith[i] == '/' || arith[i] == '^') && flag)
			{
				if (i  > 0)
				{
					flag = (arith[i - 1] != '(' && arith[i - 1] != 's' && arith[i - 1] != 'n' && arith[i - 1] != 't'
						&& arith[i - 1] != 'g' && arith[i - 1] != '+' && arith[i - 1] != '-' && arith[i - 1] != '*'
						&& arith[i - 1] != '^' && arith[i - 1] != '/');
					if (i + 1 < arith.size() && flag)
					{
						flag = (arith[i + 1] != ')' && arith[i + 1] != '+' && arith[i + 1] != '-' && arith[i + 1] != '*'
							&& arith[i + 1] != '^' && arith[i + 1] != '/');
					}
					else flag = false;
				}
				else flag = false;
			}
			else if ((arith[i] == 'a') && flag)
			{
				if (i + 6 < arith.size()) flag = flag && (arith[i + 6] == '(');
				else flag = false;
				i += 5;
			}
			else if ((arith[i] == 't') && flag)
			{
				if (i + 2 < arith.size()) flag = (arith[i + 2] == '(');
				else flag = false;
				i++;
			}
			else if (arith[i] == ',' && flag)
			{
				if (i > 0)
				{
					flag = isdigit(arith[i - 1]);
					for (int j = i - 1; j > 0 && flag && arith[j] != '(' && arith[j] != '+' && arith[j] != '-' && arith[j] != '*' && arith[j] != '/'
						&& arith[j] != '^'; j--)
					{
						flag = flag && arith[j] != ',';
					}
				}
				else flag = false;
				if (i + 1 < arith.size())
				{
					flag = isdigit(arith[i + 1]);
					for (size_t j = i + 1; j < arith.size() && flag && arith[j] != ')' && arith[j] != '+' && arith[j] != '-' 
						&& arith[j] != '*' && arith[j] != '/' && arith[j] != '^'; j++)
					{
						flag = arith[j] != ',';
					}
				}
				else flag = false;
			}
			else if ((isdigit(arith[i])) && flag)
			{
				if (i > 0)
				{
					flag = isdigit(arith[i-1])|| arith[i - 1]==',' || arith[i - 1] == '+' || arith[i - 1] == '-'
						|| arith[i - 1] == '/' || arith[i - 1] == '^' || arith[i - 1] == '*' || arith[i - 1] == '(';

				}
				if (i + 1 < arith.size())
				{
					flag = isdigit(arith[i + 1]) || arith[i + 1] == ',' || arith[i + 1] == '+' || arith[i + 1] == '-'
						|| arith[i + 1] == '/' || arith[i + 1] == '^' || arith[i + 1] == '*' || arith[i + 1] == ')';
				}
			}
			else if ((arith[i] == 'p' || arith[i] == 'e') && flag)
			{
				if (i + 2 < arith.size() && arith[i] == 'p') flag =(arith[i + 2] == '+' || arith[i + 2] == '-'
					|| arith[i + 2] == '/' || arith[i + 2] == '^' || arith[i + 2] == '*' || arith[i + 2] == ')');
				if (i > 0)
					flag = (arith[i - 1] == '+' || arith[i - 1] == '-' || arith[i - 1] == '/' || arith[i - 1] == '^' 
						|| arith[i - 1] == '*' || arith[i - 1] == '(');
				if (i + 1 < arith.size() && arith[i] == 'e')flag = (arith[i + 1] == '+'
					|| arith[i + 1] == '-' || arith[i + 1] == '/' || arith[i + 1] == '^' || arith[i + 1] == '*' || arith[i + 1] == ')');
			}
		}
	}
	if (!flag && arith.empty())
		cout << "the string is empty" << endl;
	else if(!flag)
		cout << "you entered a non-valid arithmetic expression at position (from 0): " << i - 1 << "- <<< " << arith[i - 1] << " >>> !!" << endl;
	isarithmetic = flag;
	return flag;
}

void MyCalculator::arithtopolish()
{
	if (!isarithmetic)
		isarithmetic = isarith();
	if (isarithmetic)
	{
		string changestr, strfomypolish;
		Liststring list;
		for (size_t i = 0; i < arith.size(); i++)
		{
			if (isdigit(arith[i]) || arith[i] == 'c' || arith[i] == 'p' || arith[i] == 'e'
				|| arith[i] == 's' || arith[i] == 't' || arith[i] == 'l' || arith[i] == 'a')
			{
				for (; checksign(i, arith) == -1 && i < arith.size(); i++) // if a function then writes a function
				{
					changestr += arith[i];
					strfomypolish += arith[i];
				}
				changestr += ' ';
				strfomypolish += ' ';
			}
			if (checksign(i, arith) == 1) // if i - '-'
			{
				if (i > 0)
				{
					if (checksign(i - 1, arith) == 5)
					{
						i++;
						strfomypolish += '~';
						for (; checksign(i, arith) == -1; i++)
						{
							changestr += arith[i];
							strfomypolish += arith[i];
						}
						changestr += ' ';
						changestr += '-';
						changestr += ' ';
						strfomypolish += ' ';
					}
				}
				else if (i == 0)
				{
					i++;
					strfomypolish += '~';
					for (; checksign(i, arith) == -1; i++)
					{
						changestr += arith[i];
						strfomypolish += arith[i];
					}
					changestr += ' ';
					changestr += '-';
					changestr += ' ';
					strfomypolish += ' ';
				}
			}
			switch (checksign(i, arith))
			{
			case 0://if +
				while (list.get_size())
				{
					if (list.get_elem(0) != "(")
					{
						changestr += list.get_elem(0);
						strfomypolish += list.get_elem(0);
						changestr += ' ';
						strfomypolish += ' ';
						list.pop_front();
					}
					else break;
				}
				list.push_front("+");
				break;
			case 1://if -
				while (list.get_size())
				{
					if (list.get_elem(0) != "(")
					{
						changestr += list.get_elem(0);
						strfomypolish += list.get_elem(0);
						changestr += ' ';
						strfomypolish += ' ';
						list.pop_front();
					}
					else break;
				}
				list.push_front("-");
				break;
			case 2://if *
				while (list.get_size())
				{
					if (list.get_elem(0) != "("
						&& list.get_elem(0) != "-" && list.get_elem(0) != "+")
					{
						changestr += list.get_elem(0);
						strfomypolish += list.get_elem(0);
						changestr += ' ';
						strfomypolish += ' ';
						list.pop_front();
					}
					else break;
				}
				list.push_front("*");
				break;
			case 3://if ^
				while (list.get_size())
				{
					if (list.get_elem(0) != "("
						&& list.get_elem(0) != "-" && list.get_elem(0) != "+")
					{
						changestr += list.get_elem(0);
						strfomypolish += list.get_elem(0);
						changestr += ' ';
						strfomypolish += ' ';
						list.pop_front();
					}
					else break;
				}
				list.push_front("^");
				break;
			case 4://if /
				while (list.get_size())
				{
					if (list.get_elem(0) != "("
						&& list.get_elem(0) != "-" && list.get_elem(0) != "+")
					{
						changestr += list.get_elem(0);
						strfomypolish += list.get_elem(0);
						changestr += ' ';
						strfomypolish += ' ';
						list.pop_front();
					}
					else break;
				}
				list.push_front("/");
				break;
			case 5:// if (
				list.push_front("(");
				break;
			case 6://if )
				while (list.get_elem(0) != "(")
				{
					changestr += list.get_elem(0);
					strfomypolish += list.get_elem(0);
					changestr += ' ';
					strfomypolish += ' ';
					list.pop_front();
				}
				list.pop_front();

				break;
			}
		}
		while (list.get_size())//inserts remaining operations
		{
			changestr += list.get_elem(0);
			strfomypolish += list.get_elem(0);
			changestr += ' ';
			strfomypolish += ' ';
			list.pop_front();
		}
		polish = changestr;// reverse polish notation
		mypolish = strfomypolish;// Polish notation with unary minus highlighting if any
	}
	else throw logic_error("expression entered incorrectly!");
}

double MyCalculator::resultarith()
{
	isarithmetic = isarith();
	if(isarithmetic) arithtopolish();
	if (isarithmetic)
	{
		string number, save, chanarith = arith;
		Liststring liststring;
		size_t i, j;
		for (i = 0, j = 0; i < mypolish.size() && j < chanarith.size(); i++)
		{
			if (mypolish[i] == ' ')
				continue;
			if (checksign(j,arith) != -1 && checksign(j, arith) != 6 && j + 1 != arith.size())
				j++;
			if (mypolish[i] != ' ' && checksign(i, mypolish) == -1)
			{
				for (; i < mypolish.size() && mypolish[i] != ' '; i++)// writes a function or number to a list
				{
					number += mypolish[i];
					if(mypolish[i] == arith[j] && j + 1 != arith.size())j++;
					if (mypolish[i + 1] == ' ')
					{
						save = number;
						liststring.push_front(save);
						number = "";
					}
				}
				if (arith[j] == ')' && liststring.get_size() > 1)
				{
					switch (liststring.get_elem(1)[0])
					{
					case 't': //if tg
						result = tan(mystringtodouble(liststring.get_elem(0)));
						liststring.pop_front();
						liststring.pop_front();
						liststring.push_front(mydoubletostring(result));
						break;
					case 'c'://if cos or ctg
						if (liststring.get_elem(1)[1] == 'o')
						{
							result = cos(mystringtodouble(liststring.get_elem(0)));
							liststring.pop_front();
							liststring.pop_front();
							liststring.push_front(mydoubletostring(result));
						}
						else
						{
							result = cos(mystringtodouble(liststring.get_elem(0))) / sin(mystringtodouble(liststring.get_elem(0)));
							liststring.pop_front();
							liststring.pop_front();
							liststring.push_front(mydoubletostring(result));
						}
						break;
					case 's'://if sin or sqrt
						if (liststring.get_elem(1)[1] == 'i')
						{
							result = sin(mystringtodouble(liststring.get_elem(0)));
							liststring.pop_front();
							liststring.pop_front();
							liststring.push_front(mydoubletostring(result));
						}
						else
						{
							result = sqrt(mystringtodouble(liststring.get_elem(0)));
							liststring.pop_front();
							liststring.pop_front();
							liststring.push_front(mydoubletostring(result));
						}
						break;
					case 'l': // if ln or log
						if (liststring.get_elem(1)[1] == 'n')
						{
							result = log(mystringtodouble(liststring.get_elem(0)));
							liststring.pop_front();
							liststring.pop_front();
							liststring.push_front(mydoubletostring(result));
						}
						else
						{
							result = log10(mystringtodouble(liststring.get_elem(0)));
							liststring.pop_front();
							liststring.pop_front();
							liststring.push_front(mydoubletostring(result));
						}
						break;
					case 'a':// if arccos
						result = acos(mystringtodouble(liststring.get_elem(0)));
						liststring.pop_front();
						liststring.pop_front();
						liststring.push_front(mydoubletostring(result));
						break;
					default:
						j--;
					}
					if (j + 1 != arith.size()) j++;
				}
				continue;
			}
			switch(checksign(i, mypolish))
			{
			case 0:// if +
				result = mystringtodouble(liststring.get_elem(1)) + mystringtodouble(liststring.get_elem(0));
				liststring.pop_front();
				liststring.pop_front();
				liststring.push_front(mydoubletostring(result));
				break;
			case 1:// if -
				result = mystringtodouble(liststring.get_elem(1)) - mystringtodouble(liststring.get_elem(0));
				liststring.pop_front();
				liststring.pop_front();
				liststring.push_front(mydoubletostring(result));
				break;
			case 2:// if *
				result = mystringtodouble(liststring.get_elem(1)) * mystringtodouble(liststring.get_elem(0));
				liststring.pop_front();
				liststring.pop_front();
				liststring.push_front(mydoubletostring(result));
				break;
			case 3:// if ^
				result = pow(mystringtodouble(liststring.get_elem(1)), mystringtodouble(liststring.get_elem(0)));
				liststring.pop_front();
				liststring.pop_front();
				liststring.push_front(mydoubletostring(result));
				break;
			case 4:// if /
				result = mystringtodouble(liststring.get_elem(1)) / mystringtodouble(liststring.get_elem(0));
				liststring.pop_front();
				liststring.pop_front();
				liststring.push_front(mydoubletostring(result));
				break;
			}
			if (arith[j] == ')' && liststring.get_size() > 1)
			{
				switch (liststring.get_elem(1)[0])
				{
				case 't':
					result = tan(mystringtodouble(liststring.get_elem(0)));
					liststring.pop_front();
					liststring.pop_front();
					liststring.push_front(mydoubletostring(result));
					break;
				case 'c':
					if (liststring.get_elem(1)[1] == 'o')
					{
						result = cos(mystringtodouble(liststring.get_elem(0)));
						liststring.pop_front();
						liststring.pop_front();
						liststring.push_front(mydoubletostring(result));
					}
					else
					{
						result = cos(mystringtodouble(liststring.get_elem(0))) / sin(mystringtodouble(liststring.get_elem(0)));
						liststring.pop_front();
						liststring.pop_front();
						liststring.push_front(mydoubletostring(result));
					}
					break;
				case 's':
					if (liststring.get_elem(1)[1] == 'i')
					{
						result = sin(mystringtodouble(liststring.get_elem(0)));
						liststring.pop_front();
						liststring.pop_front();
						liststring.push_front(mydoubletostring(result));
					}
					else
					{
						result = sqrt(mystringtodouble(liststring.get_elem(0)));
						liststring.pop_front();
						liststring.pop_front();
						liststring.push_front(mydoubletostring(result));
					}
					break;
				case 'l':
					if (liststring.get_elem(1)[1] == 'n')
					{
						result = log10(mystringtodouble(liststring.get_elem(0)));
						liststring.pop_front();
						liststring.pop_front();
						liststring.push_front(mydoubletostring(result));
					}
					else
					{
						result = log(mystringtodouble(liststring.get_elem(0)));
						liststring.pop_front();
						liststring.pop_front();
						liststring.push_front(mydoubletostring(result));
					}
					break;
				case 'a':
					result = acos(mystringtodouble(liststring.get_elem(0)));
					liststring.pop_front();
					liststring.pop_front();
					liststring.push_front(mydoubletostring(result));
					break;
				}
				if (j + 1 != arith.size()) j++;
			}
			
		}
		result = mystringtodouble(liststring.get_elem(0));
	}
	return result;
}

string MyCalculator::getpolish()
{
	return polish;//outputs reverse polish notation
}

double MyCalculator::getresult()
{
	return result;// outputs the result
}

void MyCalculator::setarithexp(string expression)
{
	arith = expression; // overwrites arithmetic expression
}

int MyCalculator::mycount(const char ch)//counts the number of characters
{
	int count = 0;
	for (size_t i = 0; i < arith.size(); i++)
	{
		if (arith[i] == ch)count++;
	}
	return count;
}

int MyCalculator::checksign(size_t index, string str)
{
	switch (str[index])
	{
	case '+':
		return 0;
		break;
	case '-':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '^':
		return 3;
		break;
	case '/':
		return 4;
		break;
	case '(':
		return 5;
		break;
	case ')':
		return 6;
		break;
	default:
		return -1;
		break;
	}
}

int MyCalculator::myfind(const char* ch, size_t index, int len)//finds a string within a stringand returns either - 1 = not found or the first occurrence
{
	int current = 0;
	size_t i;
	bool flag = false;
	for (i = index; i < arith.size() && !flag; i++)
	{
		if (arith[i] == ch[0])
		{
			for (int j = 0; j < len && !flag; j++)
			{
				flag = true;
				if (arith[i + j] != ch[j])
					flag = false;
			}
			if (flag) i = i - 1;
		}
	}
	if (flag) return i;
	else return -1;
}

int MyCalculator::myfind(const string ch, size_t index, int len)//finds a string within a stringand returns either - 1 = not found or the first occurrence
{
	int current = 0;
	size_t i;
	bool flag = false;
	for (i = index; i < arith.size() && !flag; i++)
	{
		if (arith[i] == ch[0])
		{
			for (int j = 0; j < len && flag; j++)
			{
				flag = true;
				if (arith[i + j] != ch[j])
					flag = false;
			}
			if (flag) i = i - len + 2;
		}
	}
	if (flag) return i;
	else return -1;
}

double MyCalculator::mystringtodouble(string number)//converts a string to a number
{
	double numdouble = 0;
	int degree = 1, minus = 0;
	size_t i;
	if (number[0] == 'p')
		numdouble = (double)pi;
	else if (number[0] == 'e')
		numdouble = (double)e;
	else
	{
		for (i = 0; i < number.size() && number[i] != ','; i++)
		{
			if (number[i] == '~' || number[i] == '-')
			{
				minus = 1;
				continue;
			}
			numdouble = numdouble * pow(10, i - minus) + (double)number[i] - 48;
		}
		if (i < number.size()) if (number[i] == ',')
		{
			for (++i; i < number.size(); i++, degree++)
			{
				numdouble = numdouble + ((double)number[i] - 48) * pow(10, -degree);
			}
		}
		if (minus) numdouble *= -1;
	}
	return numdouble;
}

string MyCalculator::mydoubletostring(double number)//converts a number to a string
{
	int num;
	double changenum = number;
	string str;
	if (number < 0)
	{
		str += '-';
		changenum *= -1;
	}
	num = changenum;
	changenum -= num;
	if (num == 0) str += '0';
	while (num > 0)
	{
		str += (char)(num % 10 + 48);
		num /= 10;
	}
	if (changenum > 0)
	{
		str += ',';
		for (int i = 0; i < 2; i++)
		{
			num = changenum * 10;
			str += (char)(num + 48);
			changenum *= 10;
			changenum -= num;
		}
	}
	return str;
}

ostream& operator<<(ostream& out, const MyCalculator& calc)//outputs reverse polish notation and the result
{
	if (calc.isarithmetic)
	{
		out << "Reverse Polish notation of the entered expression: " << calc.polish << endl;
		out << "result: " << calc.result << endl;
	}
	else out << "you entered the wrong value!" << endl;
	return out;
}
