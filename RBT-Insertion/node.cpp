#include "node.h"
#include <iostream>
using namespace std;

//Constructer
rbtNode::rbtNode() 
{
    root = NULL;
}

//destructor
rbtNode::~rbtNode()
{
  
}
void rbtNode::rotateLeft(node* newnode)
{
 // cout << "entering rotateLeft" << endl;
  node* temp = newnode->right;
  newnode->right = temp->left;
  if (temp->left != NULL)
  {
    temp->left->parent = newnode;
  }

  temp->parent = newnode->parent;
  if (newnode->parent == NULL)
  {
    this->root = temp;
  }
  else if (newnode == newnode->parent->left)
  {
    newnode->parent->left = temp;
  }
  else
  {
    newnode->parent->right = temp;
  }
  temp->left = newnode;
  newnode->parent = temp;
   
}

void rbtNode::rotateRight(node* newnode)
{
 // cout << "entering rotateRight" << endl;
  node* tempLeft = newnode->left;
  newnode->left = tempLeft->right;
  if (tempLeft->right != NULL)
  {
    tempLeft->right->parent = newnode;
  }
  tempLeft->parent = newnode->parent;
  if (newnode->parent == NULL)
  {
    this->root = tempLeft;
  }
  else if (newnode == newnode->parent->right)
  {
    newnode->parent->right = tempLeft;
  }
  else
  {
    newnode->parent->left = tempLeft;
  }
  tempLeft->right = newnode;
  newnode->parent = tempLeft;
}
void rbtNode::maintainRBT(node *newnode)
{
 // cout << "entering MaintainRBT" << endl;
  node* uncle;
  bool RED = true;
  bool BLACK = false;
  // check added node is the root
 /* if (newnode->parent == NULL) 
  {
    newnode->color = false;
    return;
  } 
*/

  while (newnode->parent->color == RED) // Parent color is RED
  { 
   // cout << "parent-color is RED" << endl;
    if (newnode->parent == newnode->parent->parent->right)
    {
      // cout << "uncle parent left" << endl;
      uncle = newnode->parent->parent->left;
      if (uncle != NULL && uncle->color == RED)
      {
        uncle->color = BLACK;
        newnode->parent->color = BLACK;
        newnode->parent->parent->color = RED; 
        newnode = newnode->parent->parent;
      }
      else
      {
        
        if (newnode == newnode->parent->left)
        {
          newnode = newnode->parent;
          rotateRight(newnode);
        }
        newnode->parent->color = BLACK;
        newnode->parent->parent->color = RED;
        rotateLeft(newnode->parent->parent);
      }
    }
    else
    {
      uncle = newnode->parent->parent->right;
      if (uncle != NULL && uncle->color == RED)
      {
        uncle->color = BLACK;
        newnode->parent->color = BLACK;
        newnode->parent->parent->color = RED;
        newnode = newnode->parent->parent;
      }
      else
      {
        if (newnode == newnode->parent->right)
        {
          newnode = newnode->parent;
          rotateLeft(newnode);
        }

        newnode->parent->color = BLACK;
        newnode->parent->parent->color = RED;
        rotateRight(newnode->parent->parent);
      }
    }
    if (newnode == this->root)
    {
	newnode->color = BLACK;
      break;
    }
    root->color = BLACK;
}
}
void rbtNode::addkey(int data)
{
  //cout << "inserting Key : " << data << endl;
  node* newnode = new node;
  newnode->parent = NULL;
  newnode->data = data;
  newnode->left = newnode->right = NULL;
  newnode-> color = true;

  nodePtr parent = NULL;
  nodePtr curr = this->root;
  
  while (curr != NULL)
    {
    //  cout << "processing: " <<  curr->data << endl;
      parent = curr;
      if (newnode->data < curr->data)
      {
        curr = curr->left;
      }
      else
      {
        curr = curr->right;
      }      
    }

    newnode->parent = parent;

    if (parent == NULL)
    {
      this->root = newnode;
    }
    else if (newnode->data < parent->data)
    {
      parent->left = newnode;
    }
    else
    {
      parent->right = newnode;
    }
  


  // if new node is a root node, simply return
    if (newnode->parent == NULL) 
    {
      newnode->color = false;
    // this->printRBT();
      return;
    }

    // if the grandparent is null, simply return
    if (newnode->parent->parent == NULL)
    {
    // this->printRBT();
      return;
    }
   
    this->maintainRBT(newnode);
   // this->printRBT();
}
void rbtNode::printRBT()
{
  printRBT("", this->root, true);
}

void rbtNode::printRBT(const string &prefix, node* curr, bool isLeft)
{
  if (curr != NULL)
  {
    if (prefix != "") 
    {
      cout << prefix;
      if (isLeft == true) 
      {
        cout << "├──";
      } 
      else
      {
        cout << "└──";
      }
    }

    // print the value of the node
    cout << curr->data << (curr->color ? "- Red" : "- Black") << endl;
    //cout << "enter a key to continue" << endl;
    //cin >> testIn;

    if (prefix != "") 
    {
      printRBT(prefix + (isLeft ? "│   " : "    "), curr->left, true);
      printRBT(prefix + (isLeft ? "│   " : "    "), curr->right, false);
    } 
    else 
    {
      printRBT(" ", curr->left, true);
      printRBT(" ", curr->right, false);
    }
  }

}

