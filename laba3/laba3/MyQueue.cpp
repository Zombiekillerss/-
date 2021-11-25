#include "MyQueue.h"

MyQueue::MyQueue()
{
	size = 0;
	head = nullptr;
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
	if (size >= index + 1)
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
	if (size >= index + 1)
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
	if (!head) head = new MyNode(newnumber); // creates a list with newnumber
	else
	{
		MyNode* current = head;
		while (current->next) current = current->next; // moves the current list while the next item exists
		current->next = new MyNode(newnumber); // adds newnumber to the end of the list
	}
	size++;
}

void MyQueue::push_back(NodeT* tree)
{
	if (!head && tree)
	{
		head = new MyNode(0);
		if (!head->tree && tree)
		{
			head->tree = tree; // creates a list with tree
			size++;
		}
	}
	else if (tree)
	{
		MyNode* current = head;
		while (current->next)current = current->next; // moves the current list while the next item exists
		current->next = new MyNode(0);
		current->next->tree = tree;  // creates a list with tree
		size++;
	}
	else throw out_of_range("lol");
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