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
void displayMenu();
void recurciveAdd(Node* &root, int value, Node* curr, Node* &newptr);
void manualAdd(Node* &root, Node* &newptr);
void fileAdd(Node* &root, Node* &newptr);
bool search(Node* curr, int num, Node* &newptr);
void print(Node* curr, int space);
void maintain(Node* &root, Node* curr);

int main() 
{
  int count = 1;
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

    //if user enters add
    if (strcmp(option, "ADD") == 0)
    {
      //Asks if they are entering manually or by file name
      cout << "Would you like to add numbers to the Red-Black Tree manually(type 'MANUAL') or by file name (type 'FILE')?" << endl;
      char name[100];
      cin >> name;

      //convert name to uppercase
      for (int i=0; i < strlen(name); i++)
		  {		
   		  name[i] = toupper(name[i]);
		  }	

      //Adding through direct input
      if(strcmp(name, "MANUAL") == 0)
      {
        manualAdd(root, newptr);
      }
      //if user wants to input by file
      else if(strcmp(name, "FILE") == 0)
      {
        fileAdd(root, newptr);
      }
    }
    //if user enters print
    else if (strcmp(option, "PRINT") == 0)
    {   
      
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
      bool found = search(root, number, newptr);
      if (found == true)
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
	cout << "ADD--->Type 'ADD' to add to the Red-Black Tree: " << endl;
  cout << "PRINT--->Type 'PRINT' to print the Red-Black Tree: " << endl;
	cout << "DELETE--->Type 'DELETE' to delete from the Red-Black Tree: " << endl;
  cout << "SEARCH--->Type 'SEARCH' to see if a number is in the Red-Black Tree: " << endl;
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
    maintain(root, curr->getLeft());
  }
  //adds the right child
  else if (curr->data < value && curr->getRight() == NULL) 
  {
    curr->setRight(new Node(value));
    curr->getRight()->parent = curr;
    newptr = curr;
    maintain(root, curr->getRight());
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
    maintain(root, root);
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
        maintain(root, root);
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
bool search(Node* curr, int num, Node* &newptr) 
{
  bool searchResult = false;

  if (curr->data == num) 
  {
    newptr = curr;
    return true;
  }
  else 
  {
    if (curr->data > num && curr->getLeft() != NULL) 
    {
      searchResult = search(curr->getLeft(), num, newptr);
    }
    else if (curr->data < num && curr->getRight() != NULL)
    {
      searchResult = search(curr->getRight(), num, newptr);
    }
    if (searchResult)
    {
      return true;
    }
  }
  return false; 
}

//print


