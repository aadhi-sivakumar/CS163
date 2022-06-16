// Author: Aadhi Sivakumar
// Assignment: Red-Black Tree Part 1 - Insertion
// Description: Insertion of Red-Black Tree. Insert Node into a Red-Black Tree
// and print it out. Sources: Dad helped me with the maintain function for add and deletion, looked
// at tutorials in canvas and youtube to figure out the cases.
// https://www.youtube.com/watch?v=5IBxA-bZZH8 - Insertion

#include "node.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

// Function Prototypes
// display function
void displayMenu();



int main()
{
  // declaring variables
  char option[100];
  rbtNode objRBT;
  
  // welcome message
  cout << endl << "Welcome to Red-Black Tree!" << endl;

  do
  {
    // show the display menu
    displayMenu();

    // input from user
    cin >> option;
    cout << endl;

    // converts user input to uppercase so it can accept any input upper or
    // lower case or mix.
    for (int i = 0; i < strlen(option); i++)
    {
      option[i] = toupper(option[i]);
    }

    // if user enters add, add direct input
    if (strcmp(option, "ADD") == 0) 
    {
        cout << "Enter a number between 1-999: " << endl;
        int num;
        cin >> num;

        if (num > 999 || num < 1)
        {
          cout << "Invalid input. Enter a number between 1-999." << endl;
        }
        else
        {
           objRBT.addkey(num); 
        }
    }
    // if user wants to input by file
    else if (strcmp(option, "READ") == 0)
    {
        cout << "File choice available: " << endl;
        cout << "numbers.txt" << endl;
        cout << "Enter a file name: ";
        char fileName[100];
        cin >> fileName;

        ifstream numbers;
        numbers.open(fileName);
        string numbersInFile;
        int input;
        // read in numbers from file
        numbers >> numbersInFile;
        while (!numbers.eof())
        {
          input = stoi(numbersInFile);
          objRBT.addkey(input);
           // read in numbers from file
          numbers >> numbersInFile;
        }
        numbers.close();
    }
    // if user enters print
    else if (strcmp(option, "PRINT") == 0)
    {
      objRBT.printRBT();
    }
    else if (strcmp(option, "REMOVE") == 0)
    {
      cout << "Enter the number you want to delete" << endl;
      int number = 0;
      cin >> number;

      objRBT.removekey(number);

      
    }
      
    //if user enters search
    else if (strcmp(option, "SEARCH") == 0)
    {
      cout << "Enter the number you want to search for: " << endl;
      int number;
      cin >> number;
      bool searchResult = false;
      searchResult = objRBT.searchRBT(number);
      if (searchResult)
      {
        cout << "Number: " << number << " exists in the Binary Tree." << endl;
      }
      else
      {
        cout << "Number: " << number << " does not exist in the Binary Tree." <<
    endl;
      }
    }
    // if user enters quit
    else if (strcmp(option, "QUIT") == 0)
    {
      break;
    }
    else 
    {
      cout << "Invalid Input, please enter a valid option." << endl;
    }
  } while (strcmp(option, "QUIT") != 0);

  return 0;
}
// display menu
void displayMenu() 
{
  cout << endl;
  cout << "Select an option:" << endl << endl;
  cout << "ADD--->Type 'ADD' to add to the Red-Black Tree manually: " << endl;
  cout << "READ--->Type 'READ' to add to the Red-Black Tree by file: " << endl;
  cout << "PRINT--->Type 'PRINT' to print the Red-Black Tree: " << endl;
  cout << "SEARCH--->Type 'SEARCH' to see if a number is in the Red-Black Tree: " << endl;
  cout << "REMOVE--->Type 'REMOVE' to remove a number from the Red-Black Tree: "
  << endl;
  cout << "QUIT--->Type 'QUIT' to exit the program:  " << endl;
}




