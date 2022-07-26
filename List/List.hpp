#ifndef List_hpp
#define List_hpp

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    string name;
    int time;
    Node* next;

    Node(const string& name="", const int time=0, Node* next=NULL):
        name(name), time(time), next(next){};
};


class List
{
    private:
        Node *first, *last;
        int length;
        int completed;

    public:
        List(): first(NULL), last(NULL), length(0), completed(0){};
        ~List() { while(pop()); };

        bool empty() const { return first == NULL; };
        bool push(const string, const int);
        bool pop();
        void countTime();
        void print() const;
};

#endif