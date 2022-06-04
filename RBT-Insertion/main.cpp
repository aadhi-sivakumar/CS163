//Author: Aadhi Sivakumar
//Assignment: Red-Black Tree Part 1 - Insertion
//Description: Insertion of Red-Black Tree. Insert Node into a Red-Black Tree and print it out.
//Sources: Dad helped me with the maintain function, looked at tutorials in canvas and youtube to figure out the cases.
//https://www.youtube.com/watch?v=5IBxA-bZZH8 - Insertion

#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include "node.h"
using namespace std;

//Function Prototypes
//display function
void displayMenu();
//search function
//bool searchRBT(Node* root, int data);
//print functions
void printRBT(Node* root);
void printRBT(const string& prefix, Node* root, bool isLeft);
//insert functions
void recurciveAdd(Node* &root, int value, Node* curr, Node* &newptr);
void manualAdd(Node* &root, Node* &newptr);
void fileAdd(Node* &root, Node* &newptr);
//remove function
//Node* remove(Node* root, int data);
//Node* findMinNode(Node* node);
//check
void maintain(Node* root);

int main() 
{
  //declaring variables
  Node* root = NULL;
  Node* newptr = NULL;
  char option[100];
  //welcome message
  cout << "Welcome to Red-Black Tree!" << endl;

  do
  {
    //show the display menu
    displayMenu();

    //input from user
    cin >> option;
    cout << endl;

    //converts user input to uppercase so it can accept any input upper or lower case or mix.
    for (int i=0; i < strlen(option); i++)
		{		
   		option[i] = toupper(option[i]);
		}	

    //if user enters add, add direct input
    if (strcmp(option, "ADD") == 0)
    {
      manualAdd(root, newptr);
    }
    //if user wants to input by file
    else if(strcmp(option, "READ") == 0)
    {
      fileAdd(root, newptr);
    }
    //if user enters print
    else if (strcmp(option, "PRINT") == 0)
    {   
      printRBT(root);
    }
    /*else if (strcmp(option, "REMOVE") == 0)
    {
      cout << "Enter the number you want to delete" << endl;
      int number = 0;
      cin >> number;

      Node* temp = NULL;
      temp = remove(root, number);
    }
    //if user enters search
    else if (strcmp(option, "SEARCH") == 0)
    {
      cout << "Enter the number you want to search for: " << endl;
      int number;
      cin >> number;
      bool searchResult = false;
      searchResult = searchRBT(root, number);
      if (searchResult)
      {
        cout << "Number: " << number << " exists in the Binary Tree." << endl;
      }
      else
      {
        cout << "Number: " << number << " does not exist in the Binary Tree." << endl;
      }
    }*/
    //if user enters quit
    else if(strcmp(option, "QUIT") == 0)
    {
      break;
    }
    else
    {
      cout << "Invalid Input, please enter a valid option." << endl;
    }  
  }
  while (strcmp(option,"QUIT") != 0);

  return 0;
}
//display menu
void displayMenu()
{
  	cout << endl;
	cout << "Select an option:" << endl << endl; 
	cout << "ADD--->Type 'ADD' to add to the Red-Black Tree manually: " << endl;
  	cout << "READ--->Type 'READ' to add to the Red-Black Tree by file: " << endl;
  	cout << "PRINT--->Type 'PRINT' to print the Red-Black Tree: " << endl;
  	/*cout << "SEARCH--->Type 'SEARCH' to see if a number is in the Red-Black Tree: " << endl;
	cout << "REMOVE--->Type 'REMOVE' to remove a number from the Red-Black Tree: " << endl;*/
  	cout << "QUIT--->Type 'QUIT' to exit the program:  " << endl;
}

//recursive add
void recurciveAdd(Node* &root, int value, Node* curr, Node* &newptr) 
{
  //adds the left child
  if (curr->data >= value && curr->getLeft() == NULL) 
  {
    curr->setLeft(new Node(value));
    curr->getLeft()->parent = curr;
    newptr = curr;
    maintain(curr->getLeft());
  }
  //adds the right child
  else if (curr->data < value && curr->getRight() == NULL) 
  {
    curr->setRight(new Node(value));
    curr->getRight()->parent = curr;
    newptr = curr;
    maintain(curr->getRight());
  }
  //iterates through the left side of the tree and adds the node
  else if (curr->data >= value) 
  {
    recurciveAdd(root, value, curr->getLeft(), newptr);
  }
  //iterates through the right side of the tree and adds the node
  else if (curr->data < value) 
  {
    recurciveAdd(root, value, curr->getRight(), newptr);
  }
}
//manual add
void manualAdd(Node* &root, Node* &newptr) 
{
  cout << "Enter a number between 1-999: " << endl;
  int num;
  cin >> num;

  if (num > 999 || num < 1)
  {
    cout << "Invalid input. Enter a number between 1-999." << endl;
  }
  //if root is empty
  else if (root == NULL && (num <= 999 || num >= 1)) 
  {
      root = new Node(num);
      root->parent = NULL;
      //checks to see if the properties are maintained
      maintain(root);
  }
  //if root is not empty
  else if (root != NULL && (num <= 999 || num >= 1))
  {
    //adds the node
    recurciveAdd(root, num, root, newptr);
  }
}
  //add through file
void fileAdd(Node* &root, Node* &newptr) 
{
  cout<<"File choice available: " << endl;
  cout<<"numbers.txt"<<endl;
  cout<<"Enter a file name: ";
  char fileName[100];
  cin >> fileName;

   if(strcmp(fileName,"numbers.txt") ==0)
  {
    ifstream numbers;
    //opens file
    numbers.open("numbers.txt");
    string numbersInFile;
    int input;
    //read in numbers from file
    numbers >> numbersInFile;
    
    while(!numbers.eof())
    {
      //converts string to integer
      input=stoi(numbersInFile);
      //If root is empty
      if (root == NULL) 
      {
        root = new Node(input);
        root->parent = NULL;
        //checks to see if properties are maintained
        maintain(root);
      }
      // if root is not empty
      else if (root != NULL) 
      {
        recurciveAdd(root, input, root, newptr);
      }
      //read in numbers from file
      numbers >> numbersInFile;
    }
    numbers.close();
  }
  else
  {
    cout<<"The file does not exist."<<endl;
  }    
}
//search
/*bool searchRBT(Node* root, int data)
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
    return searchRBT(root->left, data); 
  }
  else
  {
     return searchRBT(root->right, data);
  }
}*/

//print
void printRBT(const string& prefix, Node* root, bool isLeft)
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
    cout << root->data << (root->color ? "- Red" : "- Black") << endl;

    if (prefix != "")
	  {
  		printRBT( prefix + (isLeft ? "│   " : "    "), root->left, true);
      printRBT( prefix + (isLeft ? "│   " : "    "), root->right, false);
	  }
	  else
	  {
       printRBT(" ", root->left, true );
       printRBT(" ", root->right, false);
	  }
  }   
}

void printRBT(Node* root)
{
  printRBT("", root, false);    
}

//remove
/*Node* remove(Node* root, int data)
{
  // check for empty
  if (root == NULL)
  {
    return NULL;
  }
  if (data < root->data)
  {
    root->left = remove(root->left, data);
    maintain(root);
  }
  else if (data > root->data)
  {
    root->right = remove(root->right, data);
    maintain(root);
  }

  // if key is same as root's key, then This is the node
  // to be deleted
  else 
  {
    // node has no child
    if (root->left==NULL & root->right==NULL)
    {   
      delete(root);
      maintain(root);
      return NULL;
    }
    // node with only one child or no child
    else if (root->left == NULL)
    {
        Node* temp = root->right;
        delete(root);
	maintain(root);
        return temp;
    }
    else if (root->right == NULL)
    {
      Node* temp = root->left;
      delete(root);
      maintain(root);
      return temp;
    }

    // node with two children: Get the inorder successor
    Node* temp = findMinNode(root->right);

    // Copy the inorder successor's content to this node
    root->data = temp->data;

    // Delete the inorder successor
    root->right = remove(root->right, temp->data);
  }
  return root;
}
Node* findMinNode(Node* node)
{
  Node* currNode = node;

  // loop down to find the leftmost leaf 
  while ((currNode != NULL) && (currNode->left != NULL))
  {
      currNode = currNode->left;
  }
  return currNode;
}*/
void maintain(Node* x)
{ 
  // check added node is the root
 if (x->getParent() == NULL)
 {
   x->color = false;
 }
 else
 {
    Node* y = NULL;
    Node* z = NULL; 
    y = x->getParent();
    if (y->getParent() != NULL)
    {
	    z = y->getParent();
    }
    if (y->color == true) // is newnode parent is red
    {
    	Node* s = NULL; // to hold pointer for uncle
    	if ( y->getParent()->getLeft() == y)
	    { 
 	      if (y->getParent()->getRight() != NULL)
        {
		      s = y->getParent()->getRight();
	       }
      }
	    else if (y->getParent()->getLeft() != NULL)
	    {
		    s =  y->getParent()->getLeft();
	    }
	    else
	    {
	     //cout << "no siblings" << endl;
	    }
	  {
    if (s != NULL)
	  {
	     if (s->color == false)
       {
          Node* a = x;
          Node* b = x->getParent();
          Node* c = b->getParent();
          b->color = false; 
          a->color = true;
          c->color = true;
		      maintain(c);
        }
        else
        {
          y->color = false;
          s->color = false;
          z->color = true;
          maintain(z);
	      }
      }
	    else
	    {
	
	  	  y->color = false;
        z->color = true;
        maintain(z);
	    }
    }
  }
  }
}
