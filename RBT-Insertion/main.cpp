//Author: Aadhi Sivakumar
//Assignment: Red-Black Tree Part 1 - Insertion
//Description: Insertion of Red-Black Tree. Insert Node into a Red-Black Tree and print it out.
//Sources: 

#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "node.h"
using namespace std;

//Function Prototypes
//display
void displayMenu();
//search
bool searchRBT(Node* root, int data);
//print
void printRBT(Node* root);
void printRBT(const string& prefix, Node* root, bool isLeft);
//insert
void recurciveAdd(Node* &root, int value, Node* curr, Node* &newptr);
void manualAdd(Node* &root, Node* &newptr);
void fileAdd(Node* &root, Node* &newptr);
//check
//void maintain(Node* &root, Node* curr);

int main() 
{
  Node* root = NULL;
  Node* newptr = NULL;
  char option[100];

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
    else if (strcmp(option, "DELETE") == 0)
    {
      
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
    }
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
  cout << "SEARCH--->Type 'SEARCH' to see if a number is in the Red-Black Tree: " << endl;
	cout << "DELETE--->Type 'DELETE' to delete from the Red-Black Tree: " << endl;
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
    //maintain(root, curr->getLeft());
  }
  //adds the right child
  else if (curr->data < value && curr->getRight() == NULL) 
  {
    curr->setRight(new Node(value));
    curr->getRight()->parent = curr;
    newptr = curr;
    //maintain(root, curr->getRight());
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
  //if root is empty
  if (root == NULL) 
  {
    root = new Node(num);
    root->parent = NULL;
    //checks to see if the properties are maintained
    //maintain(root, root);
  }
  //if root is not empty
  else if (root != NULL)
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
        //maintain(root, root);
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
bool searchRBT(Node* root, int data)
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
}

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
    cout << root->data << endl;

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

