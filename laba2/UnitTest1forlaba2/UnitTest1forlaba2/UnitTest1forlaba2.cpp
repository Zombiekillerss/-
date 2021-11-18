#include "pch.h"
#include "CppUnitTest.h"
#include "../../laba2/SearchAndSorts.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1forlaba2
{
	TEST_CLASS(UnitTest1forlaba2)
	{
	public:
		TEST_METHOD(RandomArray_test)
		{
			int size, *arrnum;
			size = 0;
			try
			{
				arrnum = RandomArray(size, 100);
				Assert::IsTrue(false);
			}
			catch (underflow_error exception)
			{
				Assert::AreEqual("size must be > 0", exception.what());
			}
			size = 2;
			try
			{
				arrnum = RandomArray(size, -90);
				Assert::IsTrue(false);
			}
			catch (underflow_error exception)
			{
				Assert::AreEqual("max must be > -1", exception.what());
			}
			arrnum = RandomArray(size, 10);
			bool flag = true;
			for (int i = 0; i < size && flag; i++)
			{
				if (!(arrnum[i] >= 0 && arrnum[i] < 11)) flag = false;
			}
			Assert::IsTrue(flag);
			delete[] arrnum;
		}
		TEST_METHOD(BinarySearch_test)
		{
			int *arr = new int[8];
			for (int i = 0; i < 8; i++)
			{
				arr[i] = i;
			}
			try
			{
				BinarySearch(arr, 0, 7, 8);
				Assert::IsTrue(false);
			}
			catch (invalid_argument exception)
			{
				Assert::AreEqual("number is entered incorrectly", exception.what());
			}
			delete[] arr;
			arr = nullptr;
			try
			{
				BinarySearch(arr, 0, 7, 8);
				Assert::IsTrue(false);
			}
			catch (invalid_argument exception)
			{
				Assert::AreEqual("array is empty", exception.what());
			}
			arr = new int[8];
			for (int i = 0; i < 8; i++)
			{
				arr[i] = i;
			}
			try
			{
				BinarySearch(arr, 0, -9, 7);
				Assert::IsTrue(false);
			}
			catch (underflow_error exception)
			{
				Assert::AreEqual("range is entered incorrectly", exception.what());
			}
			for (int i = 7; i > -1; i--)
			{
				arr[7 - i] = i;
			}
			try
			{
				BinarySearch(arr, 0, 7, 7);
				Assert::IsTrue(false);
			}
			catch (logic_error exception)
			{
				Assert::AreEqual("array is not sorted", exception.what());
			}
			for (int i = 1; i < 9; i++)
			{
				arr[i - 1] = i;
			}
			int number;
			number = BinarySearch(arr, 0, 7, 7);
			Assert::IsTrue(number == 6);
			delete[] arr;
		}
		TEST_METHOD(QuickSort_test)
		{
			int* arr = nullptr;
			try
			{
				QuickSort(arr, 0, 90);
				Assert::IsTrue(false);
			}
			catch (invalid_argument exception)
			{
				Assert::AreEqual("array is empty", exception.what());
			}
			arr = RandomArray(10, 20);
			try
			{
				QuickSort(arr, 0, -90);
				Assert::IsTrue(false);
			}
			catch (out_of_range exception)
			{
				Assert::AreEqual("range is entered incorrectly", exception.what());
			}
			QuickSort(arr, 0, 9);
			Assert::IsTrue(CorrectArray(arr, 10));
			delete[] arr;
		}
		TEST_METHOD(InsertionSort_test)
		{
			int* arr = nullptr;
			try
			{
				InsertionSort(arr, 67);
				Assert::IsTrue(false);
			}
			catch (invalid_argument exception)
			{
				Assert::AreEqual("array is empty", exception.what());
			}
			arr = RandomArray(10, 20);
			try
			{
				InsertionSort(arr, 0);
				Assert::IsTrue(false);
			}
			catch (underflow_error exception)
			{
				Assert::AreEqual("range is entered incorrectly", exception.what());
			}
			InsertionSort(arr, 10);
			Assert::IsTrue(CorrectArray(arr, 10));
			delete[] arr;
		}
		TEST_METHOD(CorrectArray_test)
		{
			int* arr = nullptr;
			try
			{
				CorrectArray(arr, 67);
				Assert::IsTrue(false);
			}
			catch (invalid_argument exception)
			{
				Assert::AreEqual("array is empty", exception.what());
			}
			arr = new int[8];
			for (int i = 0; i < 8; i++)
			{
				arr[i] = i;
			}
			try
			{
				CorrectArray(arr, -10);
				Assert::IsTrue(false);
			}
			catch (underflow_error exception)
			{
				Assert::AreEqual("range is entered incorrectly", exception.what());
			}
			Assert::IsTrue(CorrectArray(arr, 8));
			delete[] arr;
		}
		TEST_METHOD(BogoSort_test)
		{
			int* arr = nullptr;
			try
			{
				BogoSort(arr, 67);
				Assert::IsTrue(false);
			}
			catch (invalid_argument exception)
			{
				Assert::AreEqual("array is empty", exception.what());
			}
			arr = RandomArray(3, 20);
			try
			{
				BogoSort(arr, 0);
				Assert::IsTrue(false);
			}
			catch (underflow_error exception)
			{
				Assert::AreEqual("range is entered incorrectly", exception.what());
			}
			BogoSort(arr, 3);
			Assert::IsTrue(CorrectArray(arr, 3));
			delete[] arr;
		}
		TEST_METHOD(CountingSort_test)
		{
			char* string = nullptr;
			try
			{
				CountingSort(string, 67);
				Assert::IsTrue(false);
			}
			catch (invalid_argument exception)
			{
				Assert::AreEqual("array is empty", exception.what());
			}
			string = new char[4];
			string[0] = 'd';
			string[1] = 's';
			string[2] = 'a';
			string[3] = '\0';
			try
			{
				CountingSort(string, 0);
				Assert::IsTrue(false);
			}
			catch (underflow_error exception)
			{
				Assert::AreEqual("range is entered incorrectly", exception.what());
			}
			CountingSort(string, 3);
			Assert::AreEqual("ads", string);
			delete[] string;
		}
		TEST_METHOD(MaxChar_test)
		{
			char* string = nullptr;
			try
			{
				MaxChar(string, 67);
				Assert::IsTrue(false);
			}
			catch (invalid_argument exception)
			{
				Assert::AreEqual("array is empty", exception.what());
			}
			string = new char[4];
			string[0] = 'd';
			string[1] = 's';
			string[2] = 'a';
			string[3] = '\0';
			try
			{
				MaxChar(string, -190);
				Assert::IsTrue(false);
			}
			catch (underflow_error exception)
			{
				Assert::AreEqual("range is entered incorrectly", exception.what());
			}
			Assert::IsTrue('s' == MaxChar(string, 3));
			delete[] string;
		}
	};
}
