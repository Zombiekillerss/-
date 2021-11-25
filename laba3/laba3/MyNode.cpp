#include "MyNode.h"

MyNode::MyNode(int newnumber, NodeT* tree, MyNode* next)
{
	this->next = next;
	this->number = newnumber;
	this->tree = tree;
}
