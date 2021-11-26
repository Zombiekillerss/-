#include "BinarySearchTree.h"

MyBST::~MyBST()
{
	while (count)
	{
		remove(head->number);
	}
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
		count = 1;
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
		else throw logic_error("the tree element already exists!");
	}
}

void MyBST::remove(int number)
{
	if (contains(number))
	{
		NodeT* current = head;
		int last = count;
		while (number != current->number) // moves to element with number
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
		NodeT* remove = current;
		if ((!remove->left) && (!remove->right)) // if there is no left or right element, then the element is a sheet
		{
			current->number = remove->number;
			NodeT* removeel = remove;
			if (remove->root)
			{
				if (remove->root->right)
				{
					if (remove->root->right->number == current->number)
						remove->root->right = nullptr;
					else
						remove->root->left = nullptr;
				}
			}
			else remove = nullptr;
			delete removeel;
			removeel = nullptr;
			count--;
		}
		else if (!remove->left && remove->right)
		{
			if (current->root)
			{
				current = current->root;
				current->right = remove->right;
				remove->right->root = current;
				delete remove;
				remove = nullptr;
				count--;
			}
			else
			{
				head = remove->right;
				head->root = nullptr;
				delete remove;
				remove = nullptr;
				count--;
			}
		}
		else if (!remove->right && remove->left)
		{
			if (current->root)
			{
				current = current->root;
				current->left = remove->left;
				remove->left->root = current;
				delete remove;
				remove = nullptr;
				count--;
			}
			else
			{
				head = remove->left;
				head->root = nullptr;
				delete remove;
				remove = nullptr;
				count--;
			}
		}
		else // if there is both right and left
		{
			remove = remove->right;
			while (remove->left)
				remove = remove->left;
			current->number = remove->number;
			current = remove->root;
			if(current->right)if(current->right->number == remove->number)
				current->right = remove->right;
			if(current->left)if (current->left->number == remove->number)
				current->left = remove->right;
			if (remove->right)
				remove->right->root = current;
			delete remove;
			remove = nullptr;
			count--;
		}
	}
}

MyIterator* MyBST::create_dft_iterator()
{
	if (head)
	{
		MyQueue list;
		NodeT* current = head;
		while (count > list.get_size())
		{
			while (current->left) // moves all the way to the left and adds elements
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
				current = current->root; // goes to the root
				if (current->right)
				{
					if (!list.contains(current->right->number))
					{
						current = current->right;
						break;
					}
				}
				if (current->left)
				{
					if (!list.contains(current->left->number))
					{
						current = current->left;
						break;
					}
				}
			}
		}
		list.save_queue(); // prevents all items from being deleted
		return list.create_iterator();
	}
	throw out_of_range("the tree does not exist!");
}

MyIterator* MyBST::create_bft_iterator()
{
	if (head)
	{
		MyQueue list, list1;
		list.push_back(head);
		for (size_t i = 0; i < count; i++)
		{
			if (list.get_elem_tree(i)->left)
				list.push_back(list.get_elem_tree(i)->left);
			if (list.get_elem_tree(i)->right)
				list.push_back(list.get_elem_tree(i)->right);
		}
		for (size_t i = 0; i < list.get_size(); i++)
			list1.push_back(list.get_elem_tree(i)->number);
		list1.save_queue();
		return list1.create_iterator();
	}
	throw out_of_range("the tree does not exist!");
}
