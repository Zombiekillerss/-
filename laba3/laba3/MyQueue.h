#pragma once
#include "MyIterator.h"
#include "MyNode.h"
#include <iostream>
using namespace std;

template <class T>
class MyQueue
{
public:
	MyQueue();
	~MyQueue();
	void clear();
	void save_queue();
	int get_elem(size_t index);
	void pop_front();
	size_t get_size();
	void push_back(int newnumber);
	T* create_iterator();
	class MyListIterator : public T
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
	int size = 0;
};