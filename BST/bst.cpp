#include "bst.h"
#include <iostream>
#include <cstring>
using namespace std;

//constructor
bst::bst() 
{ 
}

//destructer
bst::~bst()
{ 
  
}

//print bst
void bst::printBST(bst* root)
{
}

//insert Node
bst* bst::insertNode(bst* root, int data) 
{

    if (root == NULL)
    { 
    	bst* newNode = new bst();
	newNode->data = data;
    	newNode->left = NULL;
    	newNode->right = NULL;
        root = newNode; 
    }	
    else
    {
	if (data <= root->data)
	{
	    root->left = insertNode(root->left, data);
	}
	else if (data > root->data)
	{
	   root->right = insertNode(root->right, data);
	}
    }    
    return root;
}

//Remove Node
bool bst::removeNode(int data)
{
  return true;
}
//search Node
bool bst::searchBST(bst* root, int data)
{
  if (root == NULL)
  {
     cout << "root is empty" << endl;
     return false;
  }
  else if (root->data == data) 
  {
     cout << "found it" << endl;
	  return true;
  }
  else if (data <= root->data)
  {
     cout << "Proessing : " << root->data << " moving left next " << endl;
  
  
	     return searchBST(root->left, data); 
  }
  else
  {
       cout << "processing : " << root->data << " moving right next " << endl;
      	  return searchBST(root->right, data);
  }
}




