//Author: Aadhi Sivakumar
//Assignment: Hash Table
//Description: Student list but with a hash table
//Sourcs: Dad and Zayeed helped me

#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <cstring>
#include "node.h"
using namespace std;


//function prototypes
void displayMenu();
void add(Node*& head, Student* student);
void print(Node* head);
void del(Node* &head, Node* curr, Node* prev, int studID);
int hashF(Student* student, int size);
void randStud(Node**& hashtable, int num, int& studID, int size);
void manStud(Node**& hashtable, int num, int& studID, int size);
int collisionCount(Node** hashtable, int size);


int main() 
{
  char option[50];
  int size = 100;
  Node** hashtable = new Node*[size];
  int studID = 0;
  int num;
  
  //clears hash table
  for (int i = 0; i < size; i++) 
  {
      hashtable[i] = NULL;
  }
  
  //welcome message
  cout << "Welcome to Hash Table!" << endl;
  
  do
	{
    //shows the display menu
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
      cout << "Would you like to add students Manually or Randomly? Type MANUAL for manually or RANDOM for randomly." << endl;
      char input[50];
      cin >> input;

      cout << "How many students would you like to add?" << endl;
      cin >> num;
	//converts input to upper case so it can accept any input
      for (int i =0; i < strlen(input); i++)
      {
	      input[i] = toupper(input[i]);
	}
	//if user wants to enter students manually
      if (strcmp(input, "MANUAL") == 0)
	{

        	manStud(hashtable, num, studID, size);

	}
      	//if user wants to grab names from the file randomly
      	else if (strcmp(input, "RANDOM") == 0)
	{

     		 randStud(hashtable, num, studID, size);
	}
	// if user input is not MANUAL or RANDOM
	else 
	{
		cout << "Invalid Input. Please choose either 'MANUAL' or 'RANDOM'" << endl;

    	}
	//updates size of table if collision occurs
      if (collisionCount(hashtable, size) > 3) 
      { 
        size = size*2;
        
        Node** newTable = new Node*[size];
        for (int i = 0; i < size; i++) 
        {
          newTable[i] = NULL;
        }
	//rehashes function using linked list
        for (int i = 0; i < size/2; i++) 
        { 
            Node* node = hashtable[i];
            while (node != NULL) 
            {
              add(newTable[hashF(node->getStudent(), size)], node->getStudent());
              node = node->getNext();
            }
        }
        //replaces the hash table with the updated collision table
        hashtable = new Node*[size];
        hashtable = newTable;
            }
        }
	
    	//if user enters PRINT
        else if (strcmp(option, "PRINT") == 0) 
        { 

          cout << "Printed Students: " << endl;
          for (int i = 0; i < size; i++) 
          {
            print(hashtable[i]);
          }
        }

	//if user enters DELETE
        else if (strcmp(option, "DELETE") == 0) 
        { 
          cout << "Enter the ID number of the student you want to delete: ";
          cin >> studID;
          
          for (int i = 0; i < size; i++) 
          {
            del(hashtable[i], hashtable[i], hashtable[i], studID);
          }
        }
	//if user enters quit
        else if (strcmp(option, "QUIT") == 0) 
        { 
          break;
        }

        else
        {
          cout << "Invalid Input, please enter a valid option" << endl; 
        }
    }
    while(strcmp(option, "QUIT") != 0);
}
//user display menu with available options
void displayMenu()
{
  cout << endl;
	cout << "Select an option:" << endl << endl; 
	cout << "ADD--->Type 'ADD' to add a new student record: " << endl;
  cout << "PRINT--->Type 'PRINT' to print out all the students currently stored: " << endl;
	cout << "DELETE--->Type 'DELETE' to delete a student ID number from the record: " << endl;
	cout << "QUIT--->Type 'QUIT' to exit the program: " << endl << endl;
}

//function that adds student to end of current linked list
void add(Node*& head, Student* student) 
{
    Node* curr = head;
    //adds node to head if head is empty
    if(curr == NULL) 
    { 
      head = new Node(student);
    } 
    //adds node to the end of the linked list
    else 
    { 
      while (curr->getNext() != NULL) 
      {
        curr = curr->getNext();
      }
      curr->setNext(new Node(student));
    }
}

//function that prints all students stored from one head
void print(Node* head) 
{
  if (head != NULL) 
  {
    while (head!=NULL)
      {
        cout << "Name: " << (head->getStudent()->firstName) << " " << (head->getStudent()->lastName) << endl; 
        cout << "Student ID: " << (head->getStudent()->studID) << endl;
        cout << "GPA:" << fixed << setprecision(2) << (head->getStudent()->GPA) << endl;
        cout << endl;
        head = head->getNext(); 
      }
  }
}

//function that deletes a student by id number
void del(Node* &head, Node* curr, Node* prev, int studID) 
{
	//nothing if the head node is empty
  if (head == NULL) 
  { 
    return;
  } 
    //nothing if the current node is empty
  else if (curr == NULL) 
  { 
    return;
  } 
	//removes node if id matches
  else if (studID == curr->getStudent()->studID) 
  { 
    if (studID == head->getStudent()->studID) 
    {
      Node* temp = head;
      head = head->getNext();
    } 
    else 
    {
      prev->setNext(curr->getNext());
    }
  } 
    
  else 
  {
    del(head, curr->getNext(), curr, studID); 
  }
}

//hash function
int hashF(Student* student, int size) 
{
  return student->studID % size;
}

//function that generates random students and adds them to the hash table
void randStud(Node**& hashtable, int num, int& studID, int size) {
    srand(time(NULL));
    for (int i = 0; i < num; i++) 
    {
        int lineFirst = rand() % 25+1;
        int lineLast= rand() % 25+1;

        fstream fin; 
        fstream lin;
        fin.open("first.txt");
        lin.open("last.txt");
        char* firstName = new char[100];
        char* lastName = new char[100];

        for (int j = 0; j < lineFirst; j++) 
        {
          fin >> firstName;
        }
        for (int j = 0; j < lineLast; j++) 
        {
          lin >> lastName;
        }
	//generates id
        float GPA = float(rand()%501)/100; 
	//increments id by one so every id is unique
        studID++; 
	//creates the student
        Student* student = new Student(firstName, lastName, studID, GPA);
	//adds the student to the hashtable
        add(hashtable[hashF(student, size)], student); 
    }
}
//manual input from user
void manStud(Node**& hashtable, int num, int& studID, int size)
{
	
	for (int i = 0; i < num; i++)
	{
		char* firstName = new char[100];
		char* lastName = new char[100];
		float GPA;

      		cout << "Enter First Name: " << endl;
		cin >> firstName;
		cout << endl << "Enter Last Name: " << endl;
		cin >> lastName;
		cout << endl << "Enter Unique ID Number: " << endl;
		cin >> studID;
		cout << endl << "Enter GPA between 1-5" << endl << endl;
		cin >> GPA;
			
        	Student* student = new Student(firstName, lastName, studID, GPA); //makes the student
		add(hashtable[hashF(student, size)], student); //adds student to table
	}
}	
//function that returns the max number of collisions found in the table
//help from Zayeed
int collisionCount(Node** hashtable, int size) 
{
    int limit = 0;
    for (int i = 0; i < size; i++) 
    {
      Node* node = hashtable[i];
      int curr = 1;
      if (node != NULL) 
      {
        while (node->getNext() != NULL) 
        {
          node = node->getNext();
          curr++;
        }
        limit = max(limit,curr);
      }
    }
    return limit;
}
