#include "pch.h"
#include "CppUnitTest.h"
#include "../laba1/Listnum.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForLaba1
{
	TEST_CLASS(UnitTestForLaba1)
	{
	public:
		
		TEST_METHOD(isEmpty_test)
		{
			Listnum list;
			Assert::IsTrue(list.isEmpty() == 1);
			list.push_back(1);
			Assert::IsTrue(list.isEmpty() == 0);
		}
		TEST_METHOD(push_back_number_test)
		{
			Listnum list;
			list.push_back(1);
			Assert::IsTrue(list.isEmpty() == 0);
			Assert::IsTrue(list.get_elem(0) == 1);
			Assert::IsTrue(list.get_size() == 1);
			list.push_back(2);
			Assert::IsTrue(list.get_elem(0) == 1);
			Assert::IsTrue(list.get_elem(1) == 2);
			Assert::IsTrue(list.get_size() == 2);
		}
		TEST_METHOD(push_front_number_test)
		{
			Listnum list;
			list.push_front(1);
			Assert::IsTrue(list.isEmpty() == 0);
			Assert::IsTrue(list.get_elem(0) == 1);
			list.push_front(2);
			Assert::IsTrue(list.get_elem(0) == 2);
			Assert::IsTrue(list.get_elem(1) == 1);
			Assert::IsTrue(list.get_size() == 2);
			list.push_back(3);
			Assert::IsTrue(list.get_elem(0) == 2);
			Assert::IsTrue(list.get_elem(1) == 1);
			Assert::IsTrue(list.get_elem(2) == 3);
			Assert::IsTrue(list.get_size() == 3);
		}
		TEST_METHOD(pop_back_test)
		{
			Listnum list;
			list.pop_back();
			Assert::IsTrue(list.isEmpty() == 1);
			list.push_front(1);
			list.pop_back();
			Assert::IsTrue(list.isEmpty() == 1);
			Assert::IsTrue(list.get_size() == 0);
			list.push_front(2);
			list.push_back(3);
			list.pop_back();
			Assert::IsTrue(list.get_size() == 1);
			Assert::IsTrue(list.get_elem(0) == 2);
			list.push_back(5);
			list.push_back(4);
			list.pop_back();
			Assert::IsTrue(list.get_size() == 2);
			Assert::IsTrue(list.get_elem(1) == 5);
		}
		TEST_METHOD(pop_front_test)
		{
			Listnum list;
			list.pop_front();
			Assert::IsTrue(list.isEmpty() == 1);
			list.push_front(1);
			list.pop_front();
			Assert::IsTrue(list.isEmpty() == 1);
			Assert::IsTrue(list.get_size() == 0);
			list.push_front(2);
			list.push_back(3);
			list.pop_front();
			Assert::IsTrue(list.get_size() == 1);
			Assert::IsTrue(list.get_elem(0) == 3);
			list.push_back(4);
			list.push_back(5);
			list.pop_front();
			Assert::IsTrue(list.get_size() == 2);
			Assert::IsTrue(list.get_elem(0) == 4);
			Assert::IsTrue(list.get_elem(1) == 5);
		}
		TEST_METHOD(insert_test)
		{
			Listnum list;
			list.insert(1,0);
			Assert::IsTrue(list.isEmpty() == 1);
			Assert::IsTrue(list.get_size() == 0);
			list.pop_back();
			list.push_front(2);
			list.push_back(3);
			list.insert(5, 1);
			Assert::IsTrue(list.get_size() == 3);
			Assert::IsTrue(list.get_elem(1) == 5);
			list.push_back(4);
			list.push_back(6);
			list.insert(80, 0);
			Assert::IsTrue(list.get_size() == 6);
			Assert::IsTrue(list.get_elem(0) == 80);
			Assert::IsTrue(list.get_elem(1) == 2 && list.get_elem(2) == 5 && list.get_elem(3) == 3 && list.get_elem(4) == 4 && list.get_elem(5) == 6);
		}
		TEST_METHOD(remove_test)
		{
			Listnum list;
			list.remove(987);
			Assert::IsTrue(list.get_size() == 0 && list.isEmpty() == 1);
			list.push_front(2);
			list.remove(888);
			Assert::IsTrue(list.get_size() == 1);
			list.remove(0);
			Assert::IsTrue(list.get_size() == 0 && list.isEmpty() == 1);
			list.push_back(3);
			list.push_back(4);
			list.push_back(5);
			list.remove(2);
			Assert::IsTrue(list.get_size() == 2 && list.get_elem(0) == 3 && list.get_elem(1) == 4);
			list.push_back(5);
			list.remove(1);
			Assert::IsTrue(list.get_size() == 2 && list.get_elem(0) == 3 && list.get_elem(1) == 5);
		}
		TEST_METHOD(clear_test)
		{
			Listnum list;
			list.clear();
			Assert::IsTrue(list.isEmpty() == 1 && list.get_size() == 0);
			list.push_front(2);
			list.clear();
			Assert::IsTrue(list.isEmpty() == 1 && list.get_size() == 0);
			list.push_back(3);
			list.push_back(4);
			list.push_back(5);
			list.clear();
			Assert::IsTrue(list.isEmpty() == 1 && list.get_size() == 0);
		}
		TEST_METHOD(set_test)
		{
			Listnum list;
			list.set(0, 0);
			Assert::IsTrue(list.get_elem(0) == -1 && list.get_size() == 0);
			list.push_back(3);
			list.set(0, 1);
			Assert::IsTrue(list.get_elem(0) == 1 && list.get_size() == 1);
			list.push_back(4);
			list.push_back(5);
			list.set(1, 90);
			Assert::IsTrue(list.get_elem(0) == 1 && list.get_elem(2) == 5 && list.get_elem(1) == 90 && list.get_size() == 3);
			list.set(2, 100);
			Assert::IsTrue(list.get_elem(0) == 1 && list.get_elem(2) == 100 && list.get_elem(1) == 90 && list.get_size() == 3);
		}
		TEST_METHOD(push_front_list_test)
		{
			Listnum list1, list2;
			list1.push_front(2);
			list2.push_front(list1);
			Assert::IsTrue(list2.get_size() == 1 && list2.get_elem(0) == 2);
			list1.push_back(3);
			list1.push_back(4);
			list1.push_back(5);
			Assert::IsTrue(list2.get_size() == 1 && list2.get_elem(0) == 2);
			list2.push_front(list1);
			Assert::IsTrue(list2.get_size() == 5 && list2.get_elem(0) == 2 
				&& list2.get_elem(1) == 3 && list2.get_elem(2) == 4 && list2.get_elem(3) == 5
				&& list2.get_elem(4) == 2);
			list2.push_front(90);
			Assert::IsTrue(list2.get_size() == 6 && list2.get_elem(0) == 90 && list2.get_elem(1) == 2 && list2.get_elem(2) == 3 && list2.get_elem(3) == 4 && list2.get_elem(4) == 5 && list2.get_elem(5) == 2);
		}
	};
}
