#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

struct node
{
  char data;
  node* next;
};

class stack
{
  public:
    //constructor
    stack();
    //destructor
    ~stack();
    void push(char value);
    char peek();
    void pop();
    bool isEmpty();
    node* getNext(node* n);
 private:
  node* head = NULL;
};

#endif
