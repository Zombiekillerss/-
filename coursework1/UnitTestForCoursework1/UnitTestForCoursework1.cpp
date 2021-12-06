#include "pch.h"
#include "CppUnitTest.h"
#include "../coursework1/MyCalculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/*
bool isarith();
	void arithtopolish();
	double resultarith();
	string getpolish();
	double getresult();
	void setarithexp(string expression);
*/
namespace UnitTestForCoursework1
{
	TEST_CLASS(UnitTestForCoursework1)
	{
	public:
		
		TEST_METHOD(isarith_test)
		{
			string str;
			MyCalculator calc;
			calc.setarithexp(str);
			Assert::IsTrue(!calc.isarith());
			str = "(90";
			calc.setarithexp(str);
			Assert::IsTrue(!calc.isarith());
			str = "lkj";
			calc.setarithexp(str);
			Assert::IsTrue(!calc.isarith());
			str = "(90)+89+78+9";
			calc.setarithexp(str);
			Assert::IsTrue(calc.isarith());
			str = "tg(90)+89+78+9";
			calc.setarithexp(str);
			Assert::IsTrue(calc.isarith());
			str = "ln(90)+89+78+9";
			calc.setarithexp(str);
			Assert::IsTrue(calc.isarith());
			str = "log(90)+89+78+9";
			calc.setarithexp(str);
			Assert::IsTrue(calc.isarith());
			str = "arccos(90)+89+78+9";
			calc.setarithexp(str);
			Assert::IsTrue(calc.isarith());
			str = "sqrt(90)+89/78+9";
			calc.setarithexp(str);
			Assert::IsTrue(calc.isarith());
			str = "sin(90)+89*78+9";
			calc.setarithexp(str);
			Assert::IsTrue(calc.isarith());
			str = "cos(90)+89^78+9";
			calc.setarithexp(str);
			Assert::IsTrue(calc.isarith());
			str = "ctg(90)+89-78+9";
			calc.setarithexp(str);
			Assert::IsTrue(calc.isarith());
		}
		TEST_METHOD(arithtopolish_test)
		{
			bool flag;
			string str;
			MyCalculator calc;
			calc.setarithexp(str);
			Assert::IsTrue(!calc.isarith());
			str = "(90";
			calc.setarithexp(str);
			Assert::IsTrue(!calc.isarith());
			str = "lkj";
			calc.setarithexp(str);
			Assert::IsTrue(!calc.isarith());
			str = "(90)+89+78+9";
			calc.setarithexp(str);
			Assert::IsTrue(calc.isarith());
		}
	};
}
