#include "tree.h"
#include <iostream>
#include <cstring>
using namespace std;

//constructor
tree::tree(char newData) 
{ 
    data = newData;
    right = NULL;
    left = NULL;
}

//destructer
tree::~tree()
{ 
  
}

//print tree node
void tree::printNode()
{
  cout << data << " ";
}

//get tree node's data
char tree::getData() 
{
    return data;
}

//getter for right node
tree* tree::getRight() 
{ 
    return right;
}

//getter for left node
tree* tree::getLeft() 
{ 
    return left;
}

//setter for right node
void tree::setRight(tree* newRight)
{ 
    right = newRight;
}

//setter for left node
void tree::setLeft(tree* newLeft)
{ 
    left = newLeft;
}

