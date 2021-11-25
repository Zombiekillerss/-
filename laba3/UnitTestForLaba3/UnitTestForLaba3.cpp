#include "pch.h"
#include "../laba3/BinarySearchTree.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForLaba3
{
	TEST_CLASS(UnitTestForLaba3)
	{
	public:
		TEST_METHOD(MyQueue_contains_test)
		{
			MyQueue list;
			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
			Assert::IsTrue(list.contains(1) && list.contains(2) && list.contains(3));
		}
		TEST_METHOD(MyBST_contains_and_insert_and_remove_and_destructor_test)
		{
			MyBST tree;
			try
			{
				tree.insert(3);
				tree.insert(3);
				Assert::IsTrue(false);
			}
			catch(logic_error e)
			{
				Assert::AreEqual(e.what(), "the tree element already exists!");
			}
			tree.insert(1);
			tree.insert(2);
			tree.insert(0);
			tree.insert(90);
			tree.insert(91);
			tree.insert(5);
			Assert::IsTrue(tree.contains(1) && tree.contains(3) && tree.contains(2) 
				&& tree.contains(0) && tree.contains(90) && tree.contains(91) && tree.contains(5));
		}
		TEST_METHOD(MyBST_create_dft_iterator_test)
		{
			MyBST tree;
			try
			{
				MyIterator* iterator = tree.create_dft_iterator();
				Assert::IsTrue(false);
			}
			catch (out_of_range e)
			{
				Assert::AreEqual("the tree does not exist!", e.what());
			}
			tree.insert(3);
			tree.insert(1);
			tree.insert(2);
			tree.insert(0);
			tree.insert(90);
			tree.insert(91);
			tree.insert(5);
			MyIterator* iterator = tree.create_dft_iterator();
			Assert::IsTrue(iterator->next() == 3);
			Assert::IsTrue(iterator->next() == 1);
			Assert::IsTrue(iterator->next() == 0);
			Assert::IsTrue(iterator->next() == 2);
			Assert::IsTrue(iterator->next() == 90);
			Assert::IsTrue(iterator->next() == 5);
			Assert::IsTrue(iterator->next() == 91);
		}
		TEST_METHOD(MyBST_create_bft_iterator_test)
		{
			MyBST tree;
			try
			{
				MyIterator* iterator = tree.create_dft_iterator();
				Assert::IsTrue(false);
			}
			catch (out_of_range e)
			{
				Assert::AreEqual("the tree does not exist!", e.what());
			}
			tree.insert(3);
			tree.insert(1);
			tree.insert(2);
			tree.insert(0);
			tree.insert(90);
			tree.insert(91);
			tree.insert(5);
			MyIterator* iterator = tree.create_bft_iterator();
			Assert::IsTrue(iterator->next() == 3);
			Assert::IsTrue(iterator->next() == 1);
			Assert::IsTrue(iterator->next() == 90);
			Assert::IsTrue(iterator->next() == 0);
			Assert::IsTrue(iterator->next() == 2);
			Assert::IsTrue(iterator->next() == 5);
			Assert::IsTrue(iterator->next() == 91);
		}
		TEST_METHOD(MyQueue_save_queue_test)
		{
			MyQueue list;
			list.push_back(90);
			list.push_back(92);
			list.push_back(93);
			list.push_back(3);
			list.push_back(4);
			list.save_queue();
			list.~MyQueue();
			Assert::IsTrue(list.contains(90)&& list.contains(92) && list.contains(93) && list.contains(3)
				&& list.contains(4));
		}
	};
}
