#pragma once

class MyNode
{
public:
	int number;
	MyNode* next;
	MyNode(int newnumber, MyNode* next = nullptr);
};