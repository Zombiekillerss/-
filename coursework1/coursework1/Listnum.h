#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class Listnum
{
public:
    Listnum();
    ~Listnum();
    void push_back(double newnumber);
    void push_front(double newnumber);
    void pop_back();
    void pop_front();
    void insert(double newnumber, size_t index);
    double get_elem(size_t index);
    void remove(size_t index);
    size_t get_size();
    void clear();
    void set(size_t index, double newnumber);
    bool isEmpty();
    void push_front(Listnum newlist);
    friend ostream& operator<< (ostream& out, const Listnum& list);
private:
    class Node
    {
    public:
        double number;
        class Node* next;
        Node(double newnumber = 0.0, Node* next = nullptr)
        {
            this->next = next;
            this->number= newnumber;
        }
        ~Node(){};
    };
    Node* head;
    size_t size;
};