#include "Liststring.h" 

Liststring::Liststring()
{
    size = 0;
    head = nullptr;
    last = nullptr;
}

Liststring::~Liststring()
{
    clear();
}

void Liststring::push_back(string newch)
{
    if (!head)
    {
        head = new Node(newch); // creates a list with newnumber
        last = head;
    }
    else
    {
        last->next = new Node(newch); // adds newnumber to the end of the list
        last = last->next;
    }
    size++;
}

void Liststring::push_front(string newch)
{
    if (!head)
    {
        head = new Node(newch); // creates a list with newnumber
        last = head;
    }
    else
    {
        Node* first = new Node(newch); // creates a list with newnumber
        first->next = head; // the next elements of the list are equal to the elements of the old list
        head = first; // the list is updated
    }
    size++;
}

void Liststring::pop_back()
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
        if (previous)
        {
            previous->next = current; // updates the pointer
            last = previous;
        }
        else head = nullptr;
        size--;
    }
}

void Liststring::pop_front()
{
    if (head)
    {
        Node* current = head->next;
        delete head;
        head = current;
        size--;
    }
}

void Liststring::insert(string newch, size_t index)
{
    if (size >= index + 1)
    {
        Node* current = head;
        if (!index) push_front(newch); // if index = 0 then add newnumber to the beginning
        else
        {
            for (size_t i = 1; i < index; i++, current = current->next); // move the current list item to index
            Node* newelem = new Node(newch);  // creates a list with newnumber
            newelem->next = current->next; // insert the list item before index element
            current->next = newelem;
            size++;
        }
    }
}

string Liststring::get_elem(size_t index)//get element
{
    if (size > index + 1)
    {
        Node* current = head;
        for (size_t i = 0; i < index; i++, current = current->next); // moves the current list to index inclusive
        return current->ch; // returns index number
    }
    else if (size == index + 1) return last->ch;
    else
    {
        throw out_of_range("index is entered incorrectly"); // error message
    }
}

void Liststring::remove(size_t index)
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

size_t Liststring::get_size()
{ 
    return size;
}

void Liststring::clear()
{
    while (size) pop_front();
}

void Liststring::set(size_t index, char newch)
{
    if (size >= index + 1)
    {
        Node* current = head;
        for (size_t i = 0; i < index; i++, current = current->next); // moves the current list to index inclusive
        current->ch = newch;
    }
}

bool Liststring::isEmpty()
{
    return head == nullptr;
}

ostream& operator<< (ostream& out, const Liststring& list)
{
    Liststring current;
    current.head = list.head;
    while (current.head)
    {
        out << current.head->ch;
        if (current.head->next) out << ' ';
        current.head = current.head->next;
    }
    current.size = 0;  // since size = 0 the destructor will not delete the memory
    return out;
}

void Liststring::push_front(Liststring newlist)
{
    if (newlist.head)
    {
        Node* current = newlist.head;
        Liststring main;
        while (current)
        {
            main.push_back(current->ch);
            current = current->next;
        }
        current = head;
        while (current)
        {
            main.push_back(current->ch);
            current = current->next;
        }
        clear(); // the head is cleared
        head = main.head;
        size = main.size;
        main.size = 0; // since size = 0 the destructor will not delete the memory
        newlist.size = 0; // since size = 0 the destructor will not delete the memory
    }
}
