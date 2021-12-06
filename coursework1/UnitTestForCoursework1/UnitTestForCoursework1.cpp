#include "pch.h"
#include "CppUnitTest.h"
#include "../coursework1/MyCalculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
			bool flag = true;
			size_t i;
			string str;
			MyCalculator calc;
			str = "tg(pi/4)-log(90)";
			calc.setarithexp(str);
			calc.arithtopolish();
			str = "tg pi 4 / log 90 - ";
			for (i = 0; i < calc.getpolish().size() && i < str.size() && flag; i++)
			{
				if (str[i] == calc.getpolish()[i])
					flag = true;
				else flag = false;
			}
			if (i != calc.getpolish().size())
				flag = false;
			Assert::IsTrue(flag);
			str = "-cos(pi/4)-sin(90)^2+ctg(pi/2)+ln(90)*sqrt(900)+arccos(-1/2)";
			calc.setarithexp(str);
			calc.arithtopolish();
			str = "cos - pi 4 / sin 90 2 ^ - ctg pi 2 / + ln 90 sqrt 900 * + arccos 1 - 2 / + ";
			for (i = 0; i < calc.getpolish().size() && i < str.size() && flag; i++)
			{
				if (str[i] == calc.getpolish()[i])
					flag = true;
				else flag = false;
			}
			if (i != calc.getpolish().size())
				flag = false;
			Assert::IsTrue(flag);
			try
			{
				str = "-cos(pi/4";
				calc.setarithexp(str);
				calc.arithtopolish();
			}
			catch(logic_error exp)
			{
				Assert::AreEqual("expression entered incorrectly!", exp.what());
			}
		}
		TEST_METHOD(resultarith_test)
		{
			string str;
			MyCalculator calc;
			str = "sin(pi/2)-sin(pi/2)";
			calc.setarithexp(str);
			calc.resultarith();
			Assert::IsTrue(calc.getresult() == 0.00000000);
			str = "tg(pi/4)-tg(pi/4)";
			calc.setarithexp(str);
			calc.resultarith();
			Assert::IsTrue(calc.getresult() == 0);
			str = "cos(pi/2)-cos(pi/2)";
			calc.setarithexp(str);
			calc.resultarith();
			Assert::IsTrue(calc.getresult() == 0);
			str = "sin(pi/2)-sin(pi/2)";
			calc.setarithexp(str);
			calc.resultarith();
			Assert::IsTrue(calc.getresult() == 0);
			str = "ctg(pi/2)-ctg(pi/2)";
			calc.setarithexp(str);
			calc.resultarith();
			Assert::IsTrue(calc.getresult() == 0);
			str = "ln(e)-ln(e)";
			calc.setarithexp(str);
			calc.resultarith();
			Assert::IsTrue(calc.getresult() == 0);
			str = "log(e)-log(e)";
			calc.setarithexp(str);
			calc.resultarith();
			Assert::IsTrue(calc.getresult() == 0);
			str = "sqrt(25)-sqrt(25)";
			calc.setarithexp(str);
			calc.resultarith();
			Assert::IsTrue(calc.getresult() == 0);
			str = "arccos(1)-arccos(1)";
			calc.setarithexp(str);
			calc.resultarith();
			Assert::IsTrue(calc.getresult() == 0);
			str = "tg(pi/4-tg(pi/4))";
			calc.setarithexp(str);
			calc.resultarith();
			Assert::IsTrue(calc.getresult() == -0.19);
		}
	};
}
