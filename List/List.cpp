#include "List.hpp"

List::~List()
{
    Node* i = first;
    while(i)
    {
        Node* aux = i;
        i = i->next;
        delete aux;
    }
}

bool List::push(const string name, int time)
{
    Node* node = new Node(name,time);
    Node* iter = first;
    Node* prev = NULL;

    while(iter && node->time >= iter->time)
    {
        node->time -= iter->time;
        prev = iter;
        iter = iter->next;
    }

    node->next = iter;

    if(iter)
        iter->time -= node->time;

    if(prev)
        prev->next = node;
    else
        first = node;

    length++;
    return true;
}

bool List::pop()
{
    if(empty())
        return false;

    Node* aux = first;

    first = first->next;
    delete aux;

    length--;
    return true;
}

void List::countTime()
{
    first->time--;

    if(first->time == 0)
        pop();
}

void List::print() const
{
    for(Node* i = first; i; i = i->next)
        cout << "\t" << i->name << "\t" << i->time << endl;
    cout << endl;
}