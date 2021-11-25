#pragma once
#include "NodeT.h"

class MyNode
{
public:
	int number;
	MyNode* next;
	NodeT* tree;
	MyNode(int newnumber, NodeT* tree = nullptr, MyNode* next = nullptr);
};