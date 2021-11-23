#include "BinarySearchTree.h"

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
		Node* current = head->next;
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
	size = 0;
}

size_t MyQueue::get_size()
{
	return size;
}

int MyQueue::get_elem(size_t index)//get element
{
	if (size >= index + 1)
	{
		Node* current = head;
		for (size_t i = 0; i < index; i++, current = current->next); // moves the current list to index inclusive
		return current->number; // returns index number
	}
	else
	{
		throw out_of_range("index is entered incorrectly"); // error message
	}
}

void MyQueue::push_back(int newnumber)
{
	if (!head) head = new Node(newnumber); // creates a list with newnumber
	else
	{
		Node* current = head;
		while (current->next) current = current->next; // moves the current list while the next item exists
		current->next = new Node(newnumber); // adds newnumber to the end of the list
	}
	size++;
}

Node* MyQueue::get_head()
{
	return head;
}

MyIterator::MyIterator(Node* start = nullptr)
{
	current = start;
}

bool MyIterator::has_next()
{
	return current;
}

int MyIterator::next()
{
	if (current)
	{
		int temp = current->number;
		current = current->next;
		return temp;
	}
	return 0;
}

bool MyBST::contains(int number)
{
	NodeT* tree = head;
	while (tree)
	{
		if (number < tree->number)
			tree = tree->left;
		else if (number > tree->number)
			tree = tree->right;
		else if (number == tree->number) return true;
	}
	return false;
}

void MyBST::insert(int newnumber)
{
	if (!head)
	{
		head = new NodeT(newnumber);
		count++;
	}
	else
	{
		NodeT* current = head;
		int last = count;
		if (!contains(newnumber))
		{
			while (last == count)
			{
				if (newnumber < current->number)
				{
					if (current->left) current = current->left;
					else
					{
						current->left = new NodeT(newnumber);
						current->left->root = current;
						count++;
					}
				}
				else if (newnumber > current->number)
				{
					if (current->right) current = current->right;
					else
					{
						current->right = new NodeT(newnumber);
						current->right->root = current;
						count++;
					}
				}
			}
		}
		else throw logic_error("lol");
	}
}

void MyBST::remove(int number)
{
	if (contains(number))
	{
		NodeT* current = head;
		int last = count;
		while (number != current->number)
		{
			if (number < current->number)
			{
				current = current->left;
			}
			else if (number > current->number)
			{
				current = current->right;
			}
		}
		NodeT* save = current;
		while (last == count)
		{
			if ((!save->left) && (!save->right))
			{
				current->number = save->number;
				NodeT* removeel = save;
				if (save->root)
				{
					if (save->root->right->number == current->number)
						save->root->right = nullptr;
					else
						save->root->left = nullptr;
				}
				else save = nullptr;
				delete removeel;
				removeel = nullptr;
				count--;
			}
			else if (!save->left)
				save = save->right;
			else if (!save->right)
				save = save->left;
			else
			{
				if (save->number != current->number)
				{
					while (save->left)
						save = save->left;
					if (save->right)
					{
						NodeT* removeel = save;
						current->number = save->number;
						save->root->left = save->right;
						delete removeel;
						removeel = nullptr;
						count--;
					}
					else
					{
						save->root->left = nullptr;
						delete save;
						save = nullptr;
						count--;
					}
				}
				else save = save->right;
			}
		}
	}
}

MyIterator MyBST::create_dft_iterator()
{
	if (head)
	{
		MyQueue list;
		NodeT* current = head;
		int maxcount = 0;
		while(count > list.get_size())
		{
			while (current->left)
			{
				list.push_back(current->number);
				current = current->left;
			}
			if (current->right)
			{
				list.push_back(current->number);
				current = current->right;
				continue;
			}
			else list.push_back(current->number);
			while (current->root && count > list.get_size())
			{
				for (int i = 0; i < maxcount; i++) current = current->root;
				if (current->root->right && current->root->left)
				{
					if (current->root->right)
						current = current->root->right;
					maxcount = 1;
					break;
				}
				else current = current->root;
			}
			if (current->right)
				current = current->right;
		}
		list.save_queue();
		return MyIterator(list.get_head());
	}
	throw out_of_range("lol");
}
