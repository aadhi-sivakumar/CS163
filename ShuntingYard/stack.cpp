#include "stack.h"

//constructor
stack::stack() 
{
  
}
//destructor
stack::~stack() 
{
  
}

//pushing into the stack
void stack::push(char value)
{
  node* temp = new node();
  temp->data = value;
  temp->next = head;
  head = temp;
}
//push for the tree with pointer 
void stack::pushNode(tree* value)
{
  treeNode* temp = new treeNode();
  temp->data = value;
  temp->next = headTree;
  headTree = temp;
}
//peeking the top value of the stack
char stack::peek()
{
  if (head != NULL) 
  {
    return head->data;
  }
  else 
  {
    cout << "Stack is empty.";
    return '\0';
  }
}
////peek for the tree with pointer 
tree* stack::peekNode()
{
  if (headTree != NULL) 
  {
    return headTree->data;
  }
  else 
  {
    cout << "Stack is empty.";
    return NULL;
  }
}
//pop stack node
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
    cout << "The stack is empty from Pop." << endl;
  }
}
////pop for the tree with pointer 
void stack::popNode()
{
  if (headTree != NULL) 
  {
   
    treeNode* temp = headTree;
    headTree = headTree->next;
    delete temp;
  }
  else 
  {
    cout << "The stack is empty from Pop." << endl;
  }
}
//checks if the stack is empty
bool stack::isEmpty()
{
  if (head == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}
