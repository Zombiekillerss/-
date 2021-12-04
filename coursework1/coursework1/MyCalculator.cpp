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
	int nesting = 0;
	bool flag = true;
	for (int i = 0; i < arith.size() && flag; i++)
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
							arith[i] == '*' || arith[i] == '/' || arith[i] == '^' || arith[i] == ',');
					}
				}
			}
		}
	}
	flag = flag && mycount('(') == mycount(')');
	if (flag)
	{
		for (int i = 0; i < arith.size() && flag; i++)
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
				if (i - 1 > 0) flag = (arith[i - 1] != '(');
				else flag = false;
				break;
			}
			flag = !(nesting < 0);
			if ((arith[i] == 'c' || arith[i] == 's' || arith[i] == 'l') && flag)
			{
				if (arith[i + 1] == 'n')
				{
					flag = (arith[i + 2] == '(' || arith[i + 3] == '(');
					i += 1;
				}
				else if (arith[i + 3] == 't')
				{
					flag = (arith[i + 4] == '(');
					i += 3;
				}
				else
				{
					flag = (arith[i + 3] == '(');
					i += 2;
				}
			}
			else if ((arith[i] == '+' || arith[i] == '-') && flag)
			{
				if (i + 1 < arith.size())
					flag = (isdigit(arith[i + 1]) || arith[i + 1] == '(' || arith[i + 1] == 'c'
						|| arith[i + 1] == 's' || arith[i + 1] == 't' || arith[i + 1] == 'l' || arith[i + 1] == 'a' || arith[i + 1] == 'p'
						|| arith[i + 1] == 'e');
				else flag = false;
			}
			else if ((arith[i] == '*' || arith[i] == '/' || arith[i] == '^') && flag)
			{
				if (i - 1 > 0)
				{
					flag = (arith[i - 1] != '(' && arith[i - 1] != 's' && arith[i - 1] != 'n' && arith[i - 1] != 't'
						&& arith[i - 1] != 'g' && arith[i - 1] != '+' && arith[i - 1] != '-' && arith[i - 1] != '*'
						&& arith[i - 1] != '^' && arith[i - 1] != '/');
					if (i + 1 < arith.size())
					{
						flag = (arith[i + 1] != ')' && arith[i + 1] != '+' && arith[i + 1] != '-' && arith[i + 1] != '*'
							&& arith[i + 1] != '^' && arith[i + 1] != '/');
					}
					else flag = false;
				}
				else flag = false;//(cos, sin, tg, ctg, ln, log, sqrt,+, -, *, /, ^, и -a arccos ,M_E=e,M_PI=pi
			}
			else if ((arith[i] == 'a') && flag)
			{
				flag = flag && (arith[i + 6] == '(');
				i += 5;
			}
			else if ((arith[i] == 't') && flag)
			{
				flag = flag && (arith[i + 2] == '(');
				i++;
			}
			else if (arith[i] == ',' && flag)
			{
				if (i - 1 > 0)
				{
					flag = isdigit(arith[i - 1]);
					for (int j = i - 1; j > 0 && flag; j--)
					{
						if (isdigit(arith[j]) || arith[j] == 'i' || arith[j] == 'e' || arith[j] != ',')
							flag = flag && arith[j] != ',' && arith[j] != 'i' && arith[j] != 'e';
					}
				}
				else if (i + 1 < arith.size())
				{
					flag = isdigit(arith[i + 1]);
					for (int j = i + 1; j < arith.size() && flag; j++)
					{
						if (isdigit(arith[j]) || arith[j] == 'i' || arith[j] == 'e' || arith[j] != ',')
							flag = arith[j] != ',' && arith[j] != 'i' && arith[j] != 'e';
					}
				}
				else flag = false;
			}
			else if ((isdigit(arith[i])) && flag)
			{
				flag = i == 0;
				if (i - 1 > 0)
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
			else if ((arith[i] == 'i' || arith[i] == 'e') && flag)
			{
				if (i - 2 > 0)flag = arith[i - 1] == 'p' && (arith[i - 2] == '+' || arith[i - 2] == '-'
					|| arith[i - 2] == '/' || arith[i - 2] == '^' || arith[i - 2] == '*' || arith[i - 2] == '(');
				if (i - 1 > 0)flag = (arith[i - 1] == '+' || arith[i - 1] == '-' || arith[i - 1] == '/' || arith[i - 1] == '^' || arith[i - 1] == '*' || arith[i - 1] == '(');
				if (i + 1 < arith.size())flag = flag && (arith[i + 1] == '+' 
					|| arith[i + 1] == '-' || arith[i + 1] == '/' || arith[i + 1] == '^' || arith[i + 1] == '*' || arith[i + 1] == ')');
			}
			if (!flag)
			{
				cout << "you entered a non-valid arithmetic expression at position (from 0): " << i << "!!" << endl;
			}
		}
	}
	isarithmetic = flag;
	return flag;
}

void MyCalculator::arithtopolish()
{
	if (!isarithmetic)
		isarithmetic = isarith();
	if (isarithmetic)
	{
		string changestr;
		Liststring list;
		for (int i = 0; i < arith.size(); i++)
		{
			if (isdigit(arith[i]) || arith[i] == 'c' || arith[i] == 'p' || arith[i] == 'e'
				|| arith[i] == 's' || arith[i] == 't' || arith[i] == 'l' || arith[i] == 'a')
			{
				for (; checksign(i) == -1; i++)
				{
					changestr += arith[i];
				}
				changestr += ' ';
			}
			if (checksign(i) == 1)
			{
				if (i - 1 > 0)
				{
					if (checksign(i - 1) == 5)
					{
						i++;
						for (; checksign(i) == -1; i++)
						{
							changestr += arith[i];
						}
						changestr += ' ';
					}
				}
				else if (i == 0)
				{
					i++;
					for (; checksign(i) == -1; i++)
					{
						changestr += arith[i];
					}
					changestr += ' ';
				}
			}
			switch (checksign(i))
			{
			case 0:
				if (list.get_size())if (list.get_elem(0) != "(" && list.get_elem(0) != ")")
				{
					changestr += list.get_elem(0);
					list.pop_front();
				}
				list.push_front("+");
				break;
			case 1:
				if (list.get_size())if (list.get_elem(0) != "(" && list.get_elem(0) != ")")
				{
					changestr += list.get_elem(0);
					list.pop_front();
				}
				list.push_front("-");
				break;
			case 2:
				if (list.get_size())if (list.get_elem(0) != "(" && list.get_elem(0) != ")"
					&& list.get_elem(0) != "-" && list.get_elem(0) != "+")
				{
					changestr += list.get_elem(0);
					list.pop_front();
				}
				list.push_front("*");
				break;
			case 3:
				if (list.get_size())if (list.get_elem(0) != "(" && list.get_elem(0) != ")"
					&& list.get_elem(0) != "-" && list.get_elem(0) != "+")
				{
					changestr += list.get_elem(0);
					list.pop_front();
				}
				list.push_front("^");
				break;
			case 4:
				if (list.get_size())if (list.get_elem(0) != "(" && list.get_elem(0) != ")"
					&& list.get_elem(0) != "-" && list.get_elem(0) != "+")
				{
					changestr += list.get_elem(0);
					list.pop_front();
				}
				list.push_front("/");
				break;
			case 5:
				list.push_front("(");
				break;
			case 6:
				while (list.get_elem(0) != "(")
				{
					changestr += list.get_elem(0);
					changestr += ' ';
					list.pop_front();
				}
				list.pop_front();
				break;
			}
		}
		while (list.get_size())
		{
			changestr += list.get_elem(0);
			changestr += ' ';
			list.pop_front();
		}
	}
}

string MyCalculator::getpolish()
{
	return polish;
}

double MyCalculator::getresult()
{
	return result;
}

int MyCalculator::mycount(const char ch)
{
	int count = 0;
	for (int i = 0; i < arith.size(); i++)
	{
		if (arith[i] == ch)count++;
	}
	return count;
}

int MyCalculator::checksign(int index)
{
	switch (arith[index])
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

int MyCalculator::myfind(const char* ch, int index, int len)
{
	int current = 0, i;
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

int MyCalculator::myfind(const string ch, int index, int len)
{
	int current = 0, i;
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

ostream& operator<<(ostream& out, const MyCalculator& calc)
{
	// TODO: вставьте здесь оператор return
	out << "Reverse Polish notation of the entered expression: " << calc.polish << endl;
	out << "result: " << calc.result << endl;
	return out;
}
