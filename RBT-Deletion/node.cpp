#include "node.h"
#include <iostream>
using namespace std;

//Constructer
rbtNode::rbtNode() 
{
   // root = NULL;
    TNULL = new node;
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    TNULL->parent = nullptr; 
    root = TNULL;
}

//destructor
rbtNode::~rbtNode()
{
  
}
//rotating ledt
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
//rotating right
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
//mainting the properties of a red black tree
void rbtNode::maintainRBT(node *newnode)
{
 // cout << "entering MaintainRBT" << endl;
  node* uncle;
  bool RED = true;
  bool BLACK = false;
  // check added node is the root
  /*
 if (newnode->parent == NULL) 
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
//add node
void rbtNode::addkey(int data)
{
  //cout << "inserting Key : " << data << endl;
  node* newnode = new node;
  newnode->parent = nullptr;
  newnode->data = data;
  newnode->left = newnode->right = TNULL;
  newnode-> color = true;

  node* parent = nullptr;
  node* curr = this->root;
  
  while (curr != TNULL)
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

    if (parent == nullptr)
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
    //this->printRBT();
      return;
    }

    // if the grandparent is null, simply return
    if (newnode->parent->parent == NULL)
    {
     //this->printRBT();
      return;
    }
   
    this->maintainRBT(newnode);
  // this->printRBT();
}
void rbtNode::printRBT()
{
  printRBT("", this->root, true);
}

//print tree
void rbtNode::printRBT(const string &prefix, node* curr, bool isLeft)
{
  if (curr != TNULL)
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
    cout << curr->data << (curr->color ? "(Red)" : "(Black)") << endl;
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
//finds smallest node
nodePtr rbtNode::leastNode(nodePtr curr)
{
    while (curr->left != TNULL) 
    {
      curr = curr->left;
    }
    return curr;
}

//void  rbtNode::transplantNodes(node* fromNode, node* toNode) 
void  rbtNode::transplantNodes(nodePtr fromNode, nodePtr toNode) 
{
    if (fromNode->parent == NULL)
    {
      this->root = toNode;
    } 
    else if (fromNode == fromNode->parent->left) 
    {
      fromNode->parent->left = toNode;
    } 
    else
    {
      fromNode->parent->right = toNode;
    }
    if (toNode != NULL)
    {
      toNode->parent = fromNode->parent;
    }
}
//void rbtNode::maintainRBTDelete(node* x)
//maintain for delete function
void rbtNode::maintainRBTDelete(nodePtr x)
{
   nodePtr sibling;
   bool BLACK = false;
   bool RED = true;
  
  
    while (x != this->root && x->color == BLACK) 
    {
       //cout << "inside while loop " << endl;
      if (x == x->parent->left)
      {
        sibling = x->parent->right;
        if (sibling->color == RED) 
        {
          // case 3.1
          sibling->color = BLACK;
          x->parent->color = RED;
          rotateLeft(x->parent);
          sibling = x->parent->right;
        }

        if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
          // case 3.2
          sibling->color = RED;
          x = x->parent;
        } 
        else 
        {
          if (sibling->right->color == BLACK)
          {
            // case 3.3
            sibling->left->color = BLACK;
            sibling->color = RED;
            rotateRight(sibling);
            sibling = x->parent->right;
          }

          // case 3.4
          sibling->color = x->parent->color;
          x->parent->color = BLACK;
          sibling->right->color = BLACK;
          rotateLeft(x->parent);
          x = root;
        }
      }
      else
      {
        sibling = x->parent->left;
        if (sibling->color == RED) 
        {
          // case 3.1
          sibling->color = BLACK;
          x->parent->color = RED;
          rotateRight(x->parent); 
          sibling = x->parent->left;
        }

        if (sibling->right->color == BLACK) 
        {
          // case 3.2
          sibling->color = RED;
          x = x->parent;
        } 
        else 
        {
          if (sibling->left->color == BLACK)
          {
            // case 3.3
            sibling->right->color = BLACK;
            sibling->color = RED;
            rotateLeft(sibling);
            sibling = x->parent->left;
          }

          // case 3.4
          sibling->color = x->parent->color;
          x->parent->color = BLACK;
          if (sibling->left != NULL)
          {
             sibling->left->color = BLACK;
             rotateRight(x->parent);
          }
         
         
          x = this->root;
        }
      }
    }
   // cout << "outside while" << endl;
    x->color = BLACK;
}
void rbtNode::removekey(int data)
{
  removekey(this->root, data);
}
//void rbtNode::removekey(node* curr, int data)
void rbtNode::removekey(nodePtr curr, int data)
{
   
  //declaring node pointers

     nodePtr z = TNULL;
     nodePtr x = TNULL;
     nodePtr y = TNULL;
     
  
    // cout << "Entering removeKey - working good so far" << endl;
    
  //case 1
    while (curr != TNULL) 
    {
      if (curr->data == data)
      {
        z = curr;
      }
  //case 2
      if (curr->data <= data)
      {
        curr = curr->right;
      } 
      else
      {
        curr = curr->left;
      }
    }
//case 3
    if (z == TNULL)
    {
      cout << "Couldn't find data in the tree" << endl;
      return;
    }

    y = z;
    int y_original_color = y->color;
  //case 4
    if (z->left == TNULL) 
    {
      x = z->right;
      transplantNodes(z, z->right);
    } 
    //case 5
    else if (z->right == TNULL)
    {
      x = z->left;
      transplantNodes(z, z->left);
    }
    else 
    {
      y = leastNode(z->right);
      y_original_color = y->color;
      x = y->right;
      //case 6
      if (y->parent == z)
      {
        x->parent = y;
      } 
     //case 7
      else
      {
        transplantNodes(y, y->right);
        if (y != TNULL)
        {
          y->right = z->right;
          y->right->parent = y;
        }
       
      }

      transplantNodes(z, y);
      if (y != TNULL)
      {
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
      }
      
    }
   
    delete z;
    if (y_original_color == 0) 
    {
      maintainRBTDelete(x);
    }
}
//search
bool rbtNode::searchRBT(int data)
{
  bool result = searchRBT(this->root, data);
  return result;
}
//search
bool rbtNode::searchRBT(nodePtr curr, int data)
{
  //case 1
  if (curr == NULL)
  {
    return false;
  }
  //case 2
  else if (curr->data == data)
  {
    return true;
  }
  //case 3
  else if (data <= curr->data)
  {
    return searchRBT(curr->left, data);
  }
    //case 4
  else
  {
     return searchRBT(curr->right, data);
  }
}