#include "MyNode.h"

MyNode::MyNode(int newnumber, MyNode* next)
{
	this->next = next;
	this->number = newnumber;
}
