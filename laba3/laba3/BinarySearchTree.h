#pragma once
#include <iostream>
using namespace std;

/*bool contains(int); // ����� �������� � ������ �� �����
2. void insert(int); // ���������� �������� � ������ �� �����. ������
�������� �� O(logN)
3. void remove(int); // �������� �������� ������ �� �����
4. Iterator create_dft_iterator(); // �������� ���������, ������������ ���� ��
������� ������ � �������(depth - first traverse)
5. Iterator create_bft_iterator() // �������� ���������, ������������ ������
������ � ������(breadth - first traverse)*/

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
