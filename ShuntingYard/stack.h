#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

struct node
{
  int data;
  node* next;
};

class stack
{
  public:
    //constructor
    stack();
    //destructor
    ~stack();
    
    void push(int value);
    int peek();
    void pop();
 private:
  node* head = NULL;
};

#endif
