//header guard
#ifndef BST_H
#define BST_H


class bst
{
  public:
    //constructor
    bst();
    // destuctor
    ~bst();
    
    //bst functions
    bst* insertNode(bst* root, int val);
    bool removeNode(int val);
    bool searchBST(bst* root, int val);
    void printBST(bst* node);

  private:
    //bst 
    int data;
    bst* left;
    bst* right;
    bst* root;
};


#endif
