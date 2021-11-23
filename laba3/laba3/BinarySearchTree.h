#pragma once
#include "MyQueue.h"
#include "MyIterator.h"
#include "MyNode.h"
#include "MyIterator.h"
using namespace std;

template<class T>
class MyQueue;

/*bool contains(int); // поиск элемента в дереве по ключу
2. void insert(int); // добавление элемента в дерево по ключу. Должен
работать за O(logN)
3. void remove(int); // удаление элемента дерева по ключу
4. Iterator create_dft_iterator(); // создание итератора, реализующего один из
методов обхода в глубину(depth - first traverse)
5. Iterator create_bft_iterator() // создание итератора, реализующего методы
обхода в ширину(breadth - first traverse)*/
template<class T>
class MyBST
{
public:
	bool contains(int number);
	void insert(int newnumber);
	void remove(int number);
	T* create_dft_iterator();
	//T* create_bft_iterator();
private:

	class NodeT
	{
	public:
		int number;
		NodeT* root;
		NodeT* left;
		NodeT* right;
		NodeT(int newnumber, NodeT* left = nullptr, NodeT* right = nullptr)
		{
			this->root = nullptr;
			this->left = left;
			this->right = left;
			this->number = newnumber;
		}
	};
	size_t count = 0;
	NodeT* head = nullptr;
};
