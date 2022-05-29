#include "node.h"
#include <cstring>

//Constructor
Node::Node(int newData)
{
  data = newData;
  right = NULL;
  left = NULL;
}

//Destructor
Node::~Node()
{

}

//Getters and Setters for Neighbor Nodes and Student data
Node* Node:: getRight()
{
  return right;
}

void Node::setRight(Node* newRight)
{
  right = newRight;
}
Node* Node:: getLeft()
{
  return left;
}

void Node::setLeft(Node* newLeft)
{
  left = newLeft;
}

int Node::getNewRight(){
    if(right != NULL)
    {
      return right->getData();
    }
    else
    {
      return -1;
    }
}

int Node::getNewLeft()
{
    if(left != NULL)
    {
      return left->getData();
    }
    else
    {
      return -1;
    }
}

int Node:: getData()
{
  return data;
}

void Node::setData(int newData)
{
  data = newData;
}
