#include "BinarySearchTree.h"

template <class T> bool MyBST<T>::contains(int number)
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

template <class T>void MyBST<T>::insert(int newnumber)
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

template <class T> void MyBST<T>::remove(int number)
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

template <class T> T* MyBST<T>::create_dft_iterator()
{
	if (head)
	{
		MyQueue<MyIterator> list;
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
		return list.create_iterator();
	}
	throw out_of_range("lol");
}
