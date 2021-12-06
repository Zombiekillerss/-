#include <iostream>
#include "MyCalculator.h"
using namespace std;


int main()
{
    string str;
    //str += "(2+2)*tg(pi/4)-tg(pi/4)*(2+2)";
    str = "(90)+89+78+9";
    MyCalculator calc(str);
    str = "log(90)+89+78+9";
    calc.setarithexp(str);
    calc.isarith();
    //col.arithtopolish();
    //col.resultarith();
    /*cout << str << endl;
    cout << col << endl;*/
}
