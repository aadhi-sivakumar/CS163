//header guard
#ifndef TREE_H
#define TREE_H
#include <cstring>


class tree
{
  public:
    //constructor
    tree(char newData);
    // destuctor
    ~tree();
    //tree functions
    char getData();
    tree* getLeft();
    tree* getRight();
    void setLeft(tree* newLeft);
    void setRight(tree* newRight);
    void printNode();
  private:
    //tree variables
    char data;
    tree* left;
    tree* right;
};


#endif
