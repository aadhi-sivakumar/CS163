#include "stack.h"

stack::stack() 
{
  head = NULL;
}

void stack::push(char n)
{
  stackNode* number = new stackNode();
  number->next = head;
  number->data = n;
  head = number;
}

char stack::peek()
{
  if (head != NULL) 
  {
    return head->data;
  }
  else 
  {
    return NULL;
  }
}

char stack::pop()
{
  if (head != NULL) 
  {
    stackNode* number = head;
    char next = number->data;
    head = number->next;
    delete number;
    return next;
  }
  else 
  {
    return NULL;
  }
}