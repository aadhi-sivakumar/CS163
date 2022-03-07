//header guard
#ifndef STACK_H
#define STACK_H

#include "tree.h"
#include <iostream>
using namespace std;

//stack node
struct node
{
  char data;
  node* next;
};

//tree node
struct treeNode
{
  tree* data;
  treeNode* next;
};

class stack
{
  public:
    //constructor
    stack();
    //destructor
    ~stack();
    //stack functions
    void push(char value);
    char peek();
    void pop();
    bool isEmpty();
    //pushNode, popNode, peekNode for the treeNode structure
    void pushNode(tree* value);
    void popNode();
    tree* peekNode();
 private:
  //stack variables
  node* head = NULL;
  treeNode* headTree = NULL;
};

#endif
