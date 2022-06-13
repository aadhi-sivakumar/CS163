
#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    int data;  
    bool color = true; //true means RED
    node * left;
    node * right;
    node * parent;
};
typedef node *nodePtr;

class rbtNode 
{
private:
  nodePtr root;
  nodePtr TNULL;

 public:
  //constructor
  rbtNode();
  //destructor
  ~rbtNode();

  //functions
  void addkey(int data);
  void maintainRBT(node* node);
  void rotateLeft(node* node);
  void rotateRight(node* node);
  void printRBT();
  void printRBT(const string &prefix,node* curr, bool isLeft); 


//private: 
 //  node* root;
};


