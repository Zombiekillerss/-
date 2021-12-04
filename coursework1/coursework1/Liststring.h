#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class Liststring
{
public:
    Liststring();
    ~Liststring();
    void push_back(string newch);
    void push_front(string newch);
    void pop_back();
    void pop_front();
    void insert(string newch, size_t index);
    string get_elem(size_t index);
    void remove(size_t index);
    size_t get_size();
    void clear();
    void set(size_t index, char newch);
    bool isEmpty();
    void push_front(Liststring newlist);
    friend ostream& operator<< (ostream& out, const Liststring& list);
private:
    class Node
    {
    public:
        string ch;
        class Node* next;
        Node(string newch = nullptr, Node* next = nullptr)
        {
            this->next = next;
            this->ch = newch;
        }
        ~Node(){};
    };
    Node* head;
    Node* last;
    size_t size;
};