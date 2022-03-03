#include "stack.h"

stack::stack() 
{
  
}

stack::~stack() 
{
  
}

void stack::push(int value)
{
  node* temp = new node();
  temp->data = value;
  temp->next = head;
  head = temp;
}

int stack::peek()
{
  if (head != NULL) 
  {
    return head->data;
  }
  else 
  {
    cout << "Stack is empty.";
  }
}

void stack::pop()
{
  if (head != NULL) 
  {
    node* temp = head;
    head = head->next;
    delete temp;
  }
  else 
  {
    cout << "The stack is empty." << endl;
  }
}
