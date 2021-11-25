#include <iostream>
#include "BinarySearchTree.h"

int main()
{
	MyBST tree;
	try
	{
		tree.insert(1);
		tree.insert(1);
	}
	catch (logic_error e)
	{
		cout << e.what() << endl;
	}
	tree.insert(3);
	tree.insert(2);
	tree.insert(0);
	tree.insert(90);
    MyIterator* iterator;
    iterator = tree.create_bft_iterator();
    while (iterator->has_next())
    {
        cout << iterator->next() << ',';
    }
    return 0;

}
