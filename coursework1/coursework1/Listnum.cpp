#include "Listnum.h" 

Listnum::Listnum()
{
    size = 0;
    head = nullptr;
}

Listnum::~Listnum()
{
    clear();
}

void Listnum::push_back(double newnumber)
{
    if (!head) head = new Node(newnumber); // creates a list with newnumber
    else
    {
        Node* current = head;
        while (current->next) current = current->next; // moves the current list while the next item exists
        current->next = new Node(newnumber); // adds newnumber to the end of the list
    }
    size++;
}

void Listnum::push_front(double newnumber)
{
    if (!head) head = new Node(newnumber); // creates a list with newnumber
    else
    {
        Node* first = new Node(newnumber); // creates a list with newnumber
        first->next = head; // the next elements of the list are equal to the elements of the old list
        head = first; // the list is updated
    }
    size++;
}

void Listnum::pop_back()
{
    if (head)
    {
        Node* current = head, * previous = nullptr;
        while (current->next)
        {
            previous = current; // keeps the last element of the list
            current = current->next; // moves the current list while the next item exists
        }
        delete current; // clears memory 
        current = nullptr;
        if (previous) previous->next = current; // updates the pointer
        else head = nullptr;
        size--;
    }
}

void Listnum::pop_front()
{
    if (head)
    {
        Node* current = head->next;
        delete head;
        head = current;
        size--;
    }
}

void Listnum::insert(double newnumber, size_t index)
{
    if (size >= index + 1)
    {
        Node* current = head;
        if (!index) push_front(newnumber); // if index = 0 then add newnumber to the beginning
        else
        {
            for (size_t i = 1; i < index; i++, current = current->next); // move the current list item to index
            Node* newelem = new Node(newnumber);  // creates a list with newnumber
            newelem->next = current->next; // insert the list item before index element
            current->next = newelem;
            size++;
        }
    }
}

double Listnum::get_elem(size_t index)//get element
{
    if (size >= index + 1)
    {
        Node* current = head;
        for (size_t i = 0; i < index; i++, current = current->next); // moves the current list to index inclusive
        return current->number; // returns index number
    }
    else
    {
        throw out_of_range("index is entered incorrectly"); // error message
    }
}

void Listnum::remove(size_t index)
{
    if (size >= index + 1)
    {
        if (index == 0) pop_front(); // delete first element
        else if (index + 1 == size) pop_back(); // delete last element
        else
        {
            Node* current = head, * next;
            for (size_t i = 1; i < index - 1; i++, current = current->next);  // moves the current list to index
            next = current->next;
            current->next = next->next;
            delete next;
            next = nullptr;
            size--;
        }
    }
}

size_t Listnum::get_size()
{ 
    return size;
}

void Listnum::clear()
{
    while (size) pop_front();
}

void Listnum::set(size_t index, double newnumber)
{
    if (size >= index + 1)
    {
        Node* current = head;
        for (size_t i = 0; i < index; i++, current = current->next); // moves the current list to index inclusive
        current->number = newnumber;
    }
}

bool Listnum::isEmpty()
{
    return head == nullptr;
}

ostream& operator<< (ostream& out, const Listnum& list)
{
    Listnum current;
    current.head = list.head;
    while (current.head)
    {
        out << current.head->number;
        if (current.head->next) out << ',';
        current.head = current.head->next;
    }
    current.size = 0;  // since size = 0 the destructor will not delete the memory
    return out;
}

void Listnum::push_front(Listnum newlist)
{
    if (newlist.head)
    {
        Node* current = newlist.head;
        Listnum main;
        while (current)
        {
            main.push_back(current->number);
            current = current->next;
        }
        current = head;
        while (current)
        {
            main.push_back(current->number);
            current = current->next;
        }
        clear(); // the head is cleared
        head = main.head;
        size = main.size;
        main.size = 0; // since size = 0 the destructor will not delete the memory
        newlist.size = 0; // since size = 0 the destructor will not delete the memory
    }
}
