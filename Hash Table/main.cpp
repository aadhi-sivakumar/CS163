//**********************************************
//Author: Aadhi Sivakumar
//Assignment: Hash Table
//Description: Student list with hash table. Help from Zayeed and my dad on the program.
//Date: 3/12/22
//***********************************************



#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <fstream>
#include "node.h"
#include "student.h"
using namespace std;

//Function Prototypes
void displayMenu();
Student* makeStudent();
void add(Node* &head, Student* newStudent);
void print(Node* head);
void del(Node*&head, Node* current, Node* previous, int studentID);
int collision(Node* head);
int hashFunction(Student* newStudent, int size);
void rehash(Node** &HashTable, Node* head, int size);

int main()
{
  char option[50];
  int size = 101;
  int randID = 0;
  char firstName[100];
  char lastName[100];
  int studID = 0;
  float GPA = 0;
  int ID;
  
  Node** hashtable = new Node*[size];
  
  for (int i = 0; i < size; i++) 
  {
    hashtable[i] = NULL;
  }
  
  do
	{
    //shows the display menu
		displayMenu();
    
    //gets user's input on action
		cin.getline(option, 50);
    
	  // convert the input to upper case	
		for (int i=0; i < strlen(option); i++)
		{		
   			option[i] = toupper(option[i]);
		}	
    
		// options based on users input for option
    // if user inputs add
		if (strcmp(option, "ADD") == 0)
		{
      //adds student to hashtable
      cout << "Enter the student's firstname." << endl;
      cin >> firstName;
      cout << "Enter the student's lastname." << endl;
      cin >> lastName;
      cout << "Enter the student's student ID." << endl;
      cin >> studID;
      cout << "Enter the student's GPA." << endl;
      cin >> GPA;

      //creates a new student with these parameters
      Student* student = new Student(firstName,lastName, studID, GPA);
      //adds the student to the hashtable
      add(hashtable[hashFunction(student, size)], student);

      //checks for collision
      for(int i = 0; i < size; i++)
      {
        if(hashtable[i] != NULL)
        {
          if(collision(hashtable[i])> 3)
          {
            //size of table doubles if there are more than three collisions
            size = size * 2;
            
            //Create a new empty table
            Node** newTable = new Node*[size];
            for(int i = 0; i < size; i++)
            {
             newTable[i] = NULL;
            }
            
            //Rehash the table
            for(int i = 0; i < size/2; i++)
            {
              rehash(newTable, hashtable[i], size);
            }   
            cout << "The table has been rehashed!" << endl;
            for (int i = 0; i < size/2; i++) 
            {
              hashtable[i]->~Node();
            }
            
            //Delete the old table
	          hashtable = new Node*[size];
	          hashtable = newTable;
	          delete[] newTable;
	          break;
          }
        }
      } 
    }
    else if(strcmp(option, "RANDOM") == 0)
    {
      int num = 0;
      cout << "How many students do you want to add?" << endl;
      cin >> num;
      for(int i = 0; i < num; i++)
      {
        Student* student= makeStudent();
        add(hashtable[hashFunction(student, size)], student);  
      }  
    }
    // if user inputs print
		else if (strcmp(option, "PRINT") == 0)
		{
      for (int i = 0; i < size; i++) 
      {
        print(hashtable[i]);
		  }
    }
      
    // if user inputs inputs delete
		else if (strcmp(option, "DELETE") == 0)
		{
      cout << "Enter the ID number of the student you want to delete: ";
      cin >> ID;
      for (int i = 0; i < size; i++) 
      {
        del(hashtable[i], hashtable[i], hashtable[i], ID);
      }
		}
    // if user inputs quit
		else if (strcmp(option, "QUIT") == 0)
		{
		   break;
		}
    // if user does not input one of the oprions
		else
		{
		   cout << "Invalid Input, please enter a valid option" << endl; 
		}
	}
	while(strcmp(option, "QUIT") != 0);
}

//display menu with user options
void displayMenu()
{
  cout << endl; 
	cout << "Select an option:" << endl << endl; 
	cout << "ADD--->Type 'ADD' to add a new student record: " << endl;
  cout << "PRINT--->Type 'PRINT' to print out all the students currently stored: " << endl;
	cout << "DELETE--->Type 'DELETE' to delete a student ID number from the record: " << endl;
  cout << "RANDOM--->Type 'RANDOM' to generate a random student: " << endl;
	cout << "QUIT--->Type 'QUIT' to exit the program: " << endl;
}


void add(Node* &head, Student* newStudent)
{
  Node* current = head;
  //If the current node is NULL
  if(current == NULL)
  {
    //Add student to the head node
    head = new Node(newStudent);
  }
  else
  {
      while(current->getNext() != NULL){
          current = current->getNext();
      }
      current->setNext(new Node(newStudent));
  }
}

void print(Node* head)
{
  if(head != NULL)
  {
    cout << "Name: " << (head->getStudent()->firstName) << " " 
    << (head->getStudent()->lastName) << endl; 
    cout << "Student ID: " << (head->getStudent()->studID) << endl;
    cout << "GPA:" << fixed << setprecision(2) << (head->getStudent()->GPA) << endl;
    cout << endl;
    print(head->getNext()); 
  }
}
//Delete a student
void del(Node*&head, Node* current, Node* previous, int studentID)
{
  if(head == NULL)
  {
    return;
  }
    else if(current == NULL)
    {
       return;
    }
    //If the entered id matches
    else if(studentID == current->getStudent()->getID())
    {
      //If the head node has the student who should be deleted
      if(studentID == head->getStudent()->getID())
      {
         Node* temp = head;
         head = head->getNext();
         //Deete t
         temp->~Node(); 
      }
      //If it's another node
      else
      {
        previous->setNext(current->getNext());
        current->~Node();    
      }
    }
    else
    {
      del(head, current->getNext(), current, studentID);
    }
}

//Generating a random student
Student* makeStudent()
{
  char* arr[100];
  char* arr2[100];
  //Filling two arrays with the names from text files
  fstream first;
  first.open("first.txt");
  for(int i = 0; i<100; i++)
  {
    char* firstName = new char[50];
    first >> firstName;
    arr[i] = firstName;
  }
    fstream last;
    last.open("last.txt");
    for(int j = 0; j<100; j++)
    {
      char* lastName = new char[50];
      last >> lastName;
      arr2[j] = lastName;
    }
    //Pulling random names from the text files
    char* studentFirst = arr[rand() %100 + 1];
    char* studentLast = arr2[rand() %100 + 1];
    int studentID = rand() %9000 + 1000;

    float studentGPA = float(rand()%501)/100; //generates random float from 0.00 to 5.00 to use as gpa

    //Rounding that number to 2 decimal places
    studentGPA = (studentGPA * 100) / 100;
    //Returning that student
    Student* s2 = new Student(studentFirst,studentLast, studentID, studentGPA);
    return s2;
}
//Rehashing the table
void rehash(Node** &HashTable, Node* head, int size)
{
    if(head != NULL)
    {
      add(HashTable[hashFunction(head->getStudent(), size)], head->getStudent());
      rehash(HashTable, head->getNext(), size);
    }
}


int hashFunction(Student* newStudent, int size)
{
  return newStudent->getID() % size;
}

int collision(Node* head)
{
  int collisionCount = 0;
  Node* current = head;
  while(current->getNext() != NULL)
  {
    collisionCount++;
    current = current->getNext();
  }
  return collisionCount;
}