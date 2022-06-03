#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node 
{
 public:
  //constructor
  Node(int newData);

  //destructor
  ~Node();
  //Variables
  Node* left;
  Node* right;
  Node* parent;
  bool color; //True is Red, False is black
  int data;
  //Function
  //getters
  Node* getLeft();
  Node* getRight();
  Node* getParent();
  int getData();
  bool getColor();
  //setters
  void setLeft(Node* newLeft);
  void setRight(Node* newRight);
  void setParent(Node* newParent);
};

#endif