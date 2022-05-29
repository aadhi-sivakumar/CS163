#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;
//Node Class
class Node
{
  public:
  //Constructor
  Node(int newData);
  //Destructor
  ~Node();
  //Variables
  int data;
  Node* left;
  Node* right;
  //Getters and Setters for Nodes
  Node* getRight();
  void setRight(Node* newRight);
  Node* getLeft();
  void setLeft(Node* newLeft);
  //These two functions are used to re-sort the heap
  int getNewRight();
  int getNewLeft();
  //Getters and setters for Student data
  int getData();
  void setData(int newData);
};

#endif