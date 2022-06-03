#include "node.h"
#include <iostream>
using namespace std;

//Constructer
Node::Node(int newData) 
{
  left = NULL;
  right = NULL;
  color = true;
  data = newData;
}

//destructor
Node::~Node()
{
  
}

//getters
Node* Node::getLeft()
{
  return left;
}
Node* Node::getRight() 
{
  return right;
}
Node* Node::getParent() 
{
  return parent;
}
int Node::getData()
{
  return data;
}
bool Node::getColor() 
{
  return color;
}

//setters
void Node::setRight(Node* newright) 
{
  right = newright;
}
void Node::setLeft(Node* newleft) 
{
  left = newleft;
}
void Node::setParent(Node* newparent) {
  parent = newparent;
}
