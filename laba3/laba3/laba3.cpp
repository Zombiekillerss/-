#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    MyBST<MyIterator> tree;
    tree.insert(9);
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(6);
    tree.insert(5);
    tree.insert(7);
    tree.insert(10);
    tree.insert(89);
    cout << tree.contains(4) << endl;
    cout << tree.contains(5) << endl;
    cout << tree.contains(6) << endl;
    cout << tree.contains(7) << endl;
    cout << tree.contains(10) << endl;
    MyIterator* iterator;
    iterator = tree.create_dft_iterator();
    while (iterator->has_next())
    {
        cout << iterator->next() << ',';
    }
    return 0;
}
