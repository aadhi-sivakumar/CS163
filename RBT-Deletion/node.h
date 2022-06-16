
#include <iostream>
#include <string.h>
using namespace std;

struct node
{
//struct variable
  int data;  
  bool color = true; //true means RED
  node* left;
  node* right;
  node* parent;
};
typedef node *nodePtr;

class rbtNode 
{
  private:
  node* root;
  node* TNULL;

 public:
  //constructor
  rbtNode();
  //destructor
  ~rbtNode();

  //functions
  //functions needed for insert
  void addkey(int data);
  void maintainRBT(node* node);
  void rotateLeft(node* node);
  void rotateRight(node* node);

  //functions needed for delete
  void removekey(int data);
  void removekey(nodePtr curr, int data);
  void transplantNodes(nodePtr fromNode, nodePtr toNode);
  void maintainRBTDelete(nodePtr nodeX);
  nodePtr leastNode(nodePtr curr);

  //functions needed for search
  bool searchRBT(int data);
  bool searchRBT(nodePtr curr, int data);
 
  // functions needed for print
  void printRBT();
  void printRBT(const string &prefix,node* curr, bool isLeft);
 
};


