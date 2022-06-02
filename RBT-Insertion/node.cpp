#include <iostream>
#include "node.h"
using namespace std;

//Constructor
Node::Node() 
{ 
  left = NULL;
  right = NULL;
  parent = NULL;
  data = 0;
  color = 1;
}
//Destructor
Node::~Node() 
{ 
  left = NULL;
  right = NULL;
  parent = NULL;
}
//Getters
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

int Node::getColor() 
{
  return color;
}

//Setters
void Node::setLeft(Node* newLeft) 
{
  left = newLeft;
}

void Node::setRight(Node* newRight) 
{
  right = newRight;
}

void Node::setParent(Node* newParent) 
{
  parent = newParent;
}

void Node::setData(int newData) 
{
  data = newData;
}

void Node::setColor(int newColor) 
{
  color = newColor;
}
