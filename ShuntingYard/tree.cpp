#include <iostream>
#include <cstring>
#include "tree.h"

using namespace std;

tree::tree(char newData) 
{ //constructer
    data = newData;
    right = NULL;
    left = NULL;
}

char tree::getData() 
{
    return data;
}

tree* tree::getRight() 
{ //getter for right node
    return right;
}

tree* tree::getLeft() 
{ //getter for left node
    return left;
}

void tree::setRight(tree* newRight)
{ //setter for right node
    right = newRight;
}

void tree::setLeft(tree* newLeft)
{ //setter for left node
    left = newLeft;
}


tree::~tree()
{ 
  //destructer
}

