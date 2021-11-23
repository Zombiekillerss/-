#include "MyQueue.h"

template <class T> MyQueue<T>::MyQueue()
{
	size = 0;
	head = nullptr;
}

template <class T> MyQueue<T>::~MyQueue()
{
	clear();
}

template <class T> void MyQueue<T>::pop_front()
{
	if (head)
	{
		MyNode* current = head->next;
		delete head;
		head = current;
		size--;
	}
}

template <class T> void MyQueue<T>::clear()
{
	while (size) pop_front();
}

template <class T> void MyQueue<T>::save_queue()
{
	size = 0;
}

template <class T> size_t MyQueue<T>::get_size()
{
	return size;
}

template <class T> int MyQueue<T>::get_elem(size_t index)//get element
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

template <class T> void MyQueue<T>::push_back(int newnumber)
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

template <class T> MyQueue<T>::MyListIterator::MyListIterator(MyNode* start)
{
	current = start;
}

template <class T> T* MyQueue<T>::create_iterator()
{
	return new MyListIterator(head);
}

template <class T> bool MyQueue<T>::MyListIterator::has_next()
{
	return current;
}

template <class T> int MyQueue<T>::MyListIterator::next()
{
	if (current)
	{
		int temp = current->number;
		current = current->next;
		return temp;
	}
	return 0;
}