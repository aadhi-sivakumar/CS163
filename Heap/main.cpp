//Author: Aadhi Sivakumar
//Assignment: Heap
//Description:Program that creates a max heao and user can perform functions on it.
//Sources: Dad helped me with the deletion. 
//// reference https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/

#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std;


//function prototypes
void displayMenu();
void add(int* &heap,int input); 
void print(int* &heap,int i);
void deleteLargest(int* &heap);
void deleteTree(int* &heap);
// reference https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
void simple_tokenizer(string s, int* heap);

int main()
{
  //array of numbers
  int* heap = new int[100];
  char option[100];
  
  //Welcome Message
   cout << "Welcome to Heap!" << endl; 
  
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
      cout << "Would you like to add numbers to the heap manually(type 'MANUAL') or by file name (type 'FILE')?" << endl;
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
        cin.ignore();
        cout << "Enter sequence of numbers sperated by spaces: " << endl;
         string s;
         getline(cin, s);
         simple_tokenizer(s, heap);
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
        if(strcmp(fileName,"numbers.txt")==0)
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
            add(heap, input);
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
      print(heap, 1);
    }
      
    //if user enters delete
    else if (strcmp(option, "DELETE") == 0)
    {
      cout << "Do you want to delete the largest value or the entire tree? Enter 'LARGEST' to delete the largest value and 'ENTIRE' to clear the tree." << endl;
      char response[100];
      cin >> response;

      //convert response to uppercase
      for (int i=0; i < strlen(response); i++)
		  {		
   		  response[i] = toupper(response[i]);
		  }
      //if user wants to delete the largest value
      if (strcmp(response, "LARGEST") == 0)
      {
        deleteLargest(heap);
      }
      //if user wants to clear the entire tree
      else if (strcmp(response, "ENTIRE") == 0)
      {
        deleteTree(heap);
      }
      else
      {
        cout << "Invalid option. Choose one of the two." << endl;
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


//user display menu with available options
void displayMenu()
{
  cout << endl;
	cout << "Select an option:" << endl << endl; 
	cout << "ADD--->Type 'ADD' to add to the heap: " << endl;
  cout << "PRINT--->Type 'PRINT' to print the heap: " << endl;
	cout << "DELETE--->Type 'DELETE' to delete heap: " << endl;
	cout << "QUIT--->Type 'QUIT' to exit the program: " << endl << endl;
}

//add to heap
void add(int* &heap, int input)
{
  for(int i = 1; i < 100;i++)
  {
    //if user enters a value greater than the vaue in heap, replaces the greater value with the smaller
    if(input > heap[i])
    {
      int x = heap[i];
      heap[i]= input;
      add(heap,x);
      break;
    }
  }
}

//prints tree
void print (int* &heap, int i)
{
  //left child
  if(i*2 <= 100 && heap[i*2]!=0)
  {
    print(heap,(i*2));
  }
  int space=(int) floor(i / 2);
  //prints spaces
  for(int b = 0; b< space; b++)
  {
    cout << "\t";
  }
  cout<<heap[i]<<endl;
  //right child
  if(i*2+1 <= 100 && heap[i*2+1]!=0)
  {
    print(heap,(i*2+1));
  }
}

//delete function
////clears the tree and prints the array from greatest to least
void deleteLargest(int* &heap)
{
  //cout << "Output Largest: ";
   if(heap[1]!=0)
  {
    int i = 1;
    //outputs largest number
    cout << heap[1] << " ";
    while(heap[i]!=0)
    {
      heap[i]=heap[i+1];
      i++;
    }
  }

  
  
}
//deletes entire tree using recursion
void deleteTree(int* &heap)
{
  int i = 1;
  while (heap[i] != 0)
    {
      deleteLargest(heap);
    }
    cout << endl;
}

// reference https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
void simple_tokenizer(string s, int* heap)
{
    stringstream ss(s);
    string word;
    while (ss >> word) 
    {
        add(heap, stoi(word));
    }
}

