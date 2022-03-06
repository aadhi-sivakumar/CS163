#ifndef TREE_H
#define TREE_H
#include <cstring>

// Linked list node

class tree
{
  public:
    tree(char newData);
    char getData();
    tree* getLeft();
    tree* getRight();
    void setLeft(tree* newLeft);
    void setRight(tree* newRight);
    ~tree();
  private:
    char data;
    tree* left;
    tree* right;
};


#endif
