#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

struct stackNode
{
  char data;
  stackNode* next;
};

class stack
{
  public:
    stack();
    void push(char n);
    char peek();
    char pop();
 private:
  stackNode* head;
};

#endif
