#pragma once
#include "MyQueue.h"
#include "MyIterator.h"
#include "MyNode.h"
#include "NodeT.h"
#include "MyIterator.h"
using namespace std;

class MyBST
{
public:
	~MyBST();
	bool contains(int number);
	void insert(int newnumber);
	void remove(int number);
	MyIterator* create_dft_iterator();
	MyIterator* create_bft_iterator();
private:
	size_t count = 0;
	NodeT* head = nullptr;
};

