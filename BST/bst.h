//header guard
#ifndef BST_H
#define BST_H
#include <string>
using namespace std;
class bst
{
  public:
    //constructor
    bst();
    // destuctor
    ~bst();
    
    //bst functions
    bst* findMinNode(bst* root);
    bst* insertNode(bst* root, int val);
    bst* removeNode(bst*root, int val);
    bool searchBST(bst* root, int val);
    void printBST(bst* node);
    void printBST(const string& prefix, bst* root, bool isLeft);

  private:
    //bst 
    int data;
    bst* left;
    bst* right;
    bst* root;
};


#endif