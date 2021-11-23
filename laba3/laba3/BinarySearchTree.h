#pragma once
#include <iostream>
using namespace std;

/*bool contains(int); // поиск элемента в дереве по ключу
2. void insert(int); // добавление элемента в дерево по ключу. Должен
работать за O(logN)
3. void remove(int); // удаление элемента дерева по ключу
4. Iterator create_dft_iterator(); // создание итератора, реализующего один из
методов обхода в глубину(depth - first traverse)
5. Iterator create_bft_iterator() // создание итератора, реализующего методы
обхода в ширину(breadth - first traverse)*/

class MyBST
{
public:
	bool contains(int number);
	void insert(int newnumber);
	void remove(int number);
	MyIterator create_dft_iterator();
	MyIterator create_bft_iterator();
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

class MyQueue
{
public:
	MyQueue();
	~MyQueue();
	void clear();
	void save_queue();
	int get_elem(size_t index);
	void pop_front();
	size_t get_size();
	void push_back(int newnumber);
	Node* get_head();
private:
	Node* head = nullptr;
	size_t size;
};

class Node
{
public:
	int number;
	Node* next;
	Node(int newnumber = 0, Node* next = nullptr)
	{
		this->next = next;
		this->number = newnumber;
	}
};

class MyIterator
{
public:
	MyIterator(Node* start = nullptr);
	~MyIterator() {};
	bool has_next();
	int next();
private:
	Node* current;
};
