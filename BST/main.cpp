//Author: Aadhi Sivakumar
//Assignment: Binary Search Tree
//Description:Program that creates a binary search tree and user can perform functions on it.
//Sources: Dad heped me with printing and fixing my segmentation fault
//Used: https://www.youtube.com/watch?v=gcULXE7ViZw for deletion 
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "bst.h"
using namespace std;

//function prototypes
void displayMenu();
bst* simple_tokenizer(string s, bst* bstroot);

int main()
{
   bst* bstroot = new bst();
   bstroot = NULL; 
   char option[100];

   //Welcome Message
   cout << "Welcome to Binary Search Tree!" << endl;

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
      cout << "Would you like to add numbers to the BST by console(type 'CONSOLE') or by file name (type 'FILE')?" << endl;
      char name[100];
      cin >> name;

      //convert name to uppercase
      for (int i=0; i < strlen(name); i++)
		  {		
   		  name[i] = toupper(name[i]);
		  }	

      //Adding through direct input
      if(strcmp(name, "CONSOLE") == 0)
      {
        cin.ignore();
        cout << "Enter sequence of numbers sperated by spaces: " << endl;
         string s;
         getline(cin, s);
         bstroot = simple_tokenizer(s, bstroot);
         cout << endl;
	
      }

      //if user wants to input by file
      else if(strcmp(name, "FILE") == 0)
      {
        cout<<"File choice available: " << endl;
        cout<<"numbers.txt"<<endl;
        cout<<"Enter a file name: ";
        char fileName[100];
        cin >> fileName;

        //if file is there
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
            bstroot = bstroot->insertNode(bstroot, input);
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
    }
    //if user enters print
    else if (strcmp(option, "PRINT") == 0)
    { 
      bstroot->printBST(bstroot);
    }

    //if user enters delete
    else if (strcmp(option, "DELETE") == 0)
    {
      cout << "Enter the number you want to delete" << endl;
      int number = 0;
      cin >> number;
      bst* temp = NULL;
      temp = bstroot->removeNode(bstroot, number); 
    }
    //if user enters search
    else if (strcmp(option, "SEARCH") == 0)
    {
      cout << "Enter the number you want to search for" << endl;
      int number;
      cin >> number;
      bool searchResult = false;
      searchResult = bstroot->searchBST(bstroot, number);
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
  
  //test cases
   // insert bunch
  /*
   bstroot = NULL;
   bstroot = bstroot->insertNode(bstroot,5);
   bstroot = bstroot->insertNode(bstroot,10);
   bstroot = bstroot->insertNode(bstroot, 7);
   bstroot = bstroot->insertNode(bstroot, 1);
   bstroot = bstroot->insertNode(bstroot, 20);
   bstroot = bstroot->insertNode(bstroot, 4);
   bstroot = bstroot->insertNode(bstroot,3);

   //print
   bstroot->printBST(bstroot);

   //Search some
   cout << endl << endl;
   bool searchResult = false;
   searchResult = bstroot->searchBST(bstroot, 10);
   cout << "Searching value: 10 -> " << ( searchResult ? " Found the value " : " Not Found") << endl;
   searchResult = bstroot->searchBST(bstroot, 40);
   cout << "Searching value: 40 -> " << ( searchResult ? " Found the value " : " Not Found") << endl;
   searchResult = bstroot->searchBST(bstroot, 3);
   cout << "Searching value: 3 -> " << ( searchResult ? " Found the value " : " Not Found") << endl;

   //Remove
   cout << endl << "BST before removal " << endl;
   bstroot->printBST(bstroot);

   bst* temp = NULL;

   //remove two child}

   cout << endl << endl;
   cout << "Removing root - 10" << endl << endl;
   temp = bstroot->removeNode(bstroot, 10);
   bstroot->printBST(bstroot);

   //remove one child
 
   cout << endl << "Removing root - 3" << endl << endl;
   temp = bstroot->removeNode(bstroot, 3);
   bstroot->printBST(bstroot);
   //remove root
   cout << endl << "Removing root - 5" << endl << endl;
   temp = bstroot->removeNode(bstroot, 5);
   bstroot->printBST(bstroot);
   */
   return 0;
}
//user display menu with available options
void displayMenu()
{
  cout << endl;
	cout << "Select an option:" << endl << endl; 
	cout << "ADD--->Type 'ADD' to add to the Binary Search Tree: " << endl;
  cout << "PRINT--->Type 'PRINT' to print the Binary Search Tree: " << endl;
	cout << "DELETE--->Type 'DELETE' to delete from the Binary Search Tree: " << endl;
  cout << "SEARCH--->Type 'SEARCH' to see if a number is in the Binary Search Tree: " << endl;
	cout << "QUIT--->Type 'QUIT' to exit the program: " << endl << endl;
}

bst* simple_tokenizer(string s, bst* bstroot)
{
  stringstream ss(s);
  string word;
  int num = 0;   
  while (ss >> word) 
  {
     num = stoi(word);
     bstroot = bstroot->insertNode(bstroot, num);    
  
  }
  return bstroot;
}
