#pragma once
#include "MyIterator.h"
#include "MyNode.h"
#include "NodeT.h"
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

class MyQueue
{
public:
	MyQueue();
	~MyQueue();
	void clear();
	void save_queue();
	int get_elem(size_t index);
	NodeT* get_elem_tree(size_t index);
	void pop_front();
	bool contains(int number);
	size_t get_size();
	void push_back(int newnumber);
	void push_back(NodeT* tree);
	MyIterator* create_iterator();
	class MyListIterator : public MyIterator
	{
	public:
		MyListIterator(MyNode* start);
		bool has_next() override;
		int next() override;
	private:
		MyNode* current;
	};
private:
	MyNode* head = nullptr;
	MyNode* last = nullptr;
	size_t size;
};