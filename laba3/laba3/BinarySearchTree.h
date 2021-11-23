#pragma once
#include "MyQueue.h"
#include "MyIterator.h"
#include "MyNode.h"
#include "MyIterator.h"
using namespace std;

template<class T>
class MyQueue;

/*bool contains(int); // ����� �������� � ������ �� �����
2. void insert(int); // ���������� �������� � ������ �� �����. ������
�������� �� O(logN)
3. void remove(int); // �������� �������� ������ �� �����
4. Iterator create_dft_iterator(); // �������� ���������, ������������ ���� ��
������� ������ � �������(depth - first traverse)
5. Iterator create_bft_iterator() // �������� ���������, ������������ ������
������ � ������(breadth - first traverse)*/
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
