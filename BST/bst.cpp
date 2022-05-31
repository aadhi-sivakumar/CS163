#include "bst.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//constructor
bst::bst() 
{ 
}

//destructer
bst::~bst()
{ 
  
}

//arrage BST
bst* bst::findMinNode(bst* node)
{
    bst* currNode = node;
 
    /* loop down to find the leftmost leaf */
    while ((currNode != NULL) && (currNode->left != NULL))
    {
        currNode = currNode->left;
    }
 
    return currNode;
}
 

void bst::printBST(const std::string& prefix, bst* root, bool isLeft)
{
    if( root != NULL )
    {
        if (prefix != "")
        {
	   cout << prefix;
	   if (isLeft == true)
           {
              cout <<  "├──";
	   }
	   else
           {
              cout << "└──";
	   }
	}

        // print the value of the node
        cout << root->data << endl;

        if (prefix != "")
	{
		printBST( prefix + (isLeft ? "│   " : "    "), root->left, true);
       		printBST( prefix + (isLeft ? "│   " : "    "), root->right, false);
	}
	else
	{
               printBST(" ", root->left, true );
               printBST(" ", root->right, false);
	}
    }   
}

void bst::printBST(bst* root)
{
    printBST("", root, false);    
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
        return newNode; 
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
bst* bst::removeNode(bst* root, int data)
{ 
    // check for empty
    if (root == NULL)
    {
        return NULL;
    }
    
    if (data < root->data)
    {
        root->left = removeNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = removeNode(root->right, data);
    }
    // if key is same as root's key, then This is the node
    // to be deleted
    else 
    {
        // node has no child
        if (root->left==NULL and root->right==NULL)
        {   delete(root);
            return NULL;
        }
        // node with only one child or no child
        else if (root->left == NULL)
        {
            bst* temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            bst* temp = root->left;
            delete(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        bst* temp = findMinNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}
//search Node
bool bst::searchBST(bst* root, int data)
{
  if (root == NULL)
  {
     return false;
  }
  else if (root->data == data) 
  {
     return true;
  }
  else if (data <= root->data)
  {
     return searchBST(root->left, data); 
  }
  else
  {
     return searchBST(root->right, data);
  }
}




