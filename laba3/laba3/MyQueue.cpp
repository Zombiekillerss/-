#include "MyQueue.h"

MyQueue::MyQueue()
{
	size = 0;
	head = nullptr;
	last = nullptr;
}

MyQueue::~MyQueue()
{
	clear();
}

void MyQueue::pop_front()
{
	if (head)
	{
		MyNode* current = head->next;
		delete head;
		head = current;
		size--;
	}
}

void MyQueue::clear()
{
	while (size) pop_front();
}

void MyQueue::save_queue()
{
	size = 0;//resets the length of the queue so that the destructor does not delete all elements of the queue
}

size_t MyQueue::get_size()
{
	return size;
}

bool MyQueue::contains(int number)
{
	MyNode* current = head;
	while (current)
	{
		if (current->number == number)
			return true;
		current = current->next;
	}
	return false;
}

int MyQueue::get_elem(size_t index)//get element
{
	if (size == index + 1)
	{
		return last->number;
	}
	else if (size > index + 1)
	{
		MyNode* current = head;
		for (size_t i = 0; i < index; i++, current = current->next); // moves the current list to index inclusive
		return current->number; // returns index number
	}
	else
	{
		throw out_of_range("index is entered incorrectly"); // error message
	}
}

NodeT* MyQueue::get_elem_tree(size_t index)
{
	if (size == index + 1)
	{
		return last->tree;
	}
	else if (size > index + 1)
	{
		MyNode* current = head;
		for (size_t i = 0; i < index; i++, current = current->next); // moves the current list to index inclusive
		return current->tree; // returns tree
	}
	else
	{
		throw out_of_range("index is entered incorrectly"); // error message
	}
}

void MyQueue::push_back(int newnumber)
{
	if (!head)
	{
		head = new MyNode(newnumber); // creates a list with newnumber
		last = head;
	}
	else
	{
		last->next = new MyNode(newnumber); // adds newnumber to the end of the list
		last = last->next;
	}
	size++;
}

void MyQueue::push_back(NodeT* tree)
{
	if (!head && tree)
	{
		head = new MyNode(0);
		last = head;
		head->tree = tree; // creates a list with tree
		size++;
	}
	else if (tree)
	{
		last->next = new MyNode(0);
		last = last->next;
		last->tree = tree;  // creates a list with tree
		size++;
	}
	else throw out_of_range("the tree does not exist!");
}

MyQueue::MyListIterator::MyListIterator(MyNode* start)
{
	current = start;
}

MyIterator* MyQueue::create_iterator()
{
	return new MyListIterator(head);
}

bool MyQueue::MyListIterator::has_next()
{
	return current;
}

int MyQueue::MyListIterator::next()
{
	if (current)
	{
		int temp = current->number;
		current = current->next;
		return temp;
	}
	return 0;
}