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
void makeStudent(int numofStudents, Node** ht, int htsize);
void add(Node* &head, Student* newStudent);
void print(Node* head);
void del(Node*&head, Node* current, Node* previous, int studentID);
int collision(Node* head);
int hashFunction(Student* newStudent, int size);
void rehash(Node** &HashTable, Node* head, int size);

int main()
{
  //declaring variables
  char option[50];
  int size = 201;
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
      makeStudent(num,hashtable,size);
     
    }
    // if user inputs print
		else if (strcmp(option, "PRINT") == 0)
		{
      cout << endl << "Printed Students:" << endl;
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
    // if user does not input one of the options
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
	cout << "QUIT--->Type 'QUIT' to exit the program: " << endl << endl;
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
      while(current->getNext() != NULL)
      {
        current = current->getNext();
      }
      current->setNext(new Node(newStudent));
  }
}

void print(Node* head)
{
  if(head != NULL)
  {
    cout << "Name: " << (head->getStudent()->firstName) << " " << (head->getStudent()->lastName) << endl; 
    cout << "Student ID: " << (head->getStudent()->studID) << endl;
    cout << "GPA:" << fixed << setprecision(2) << (head->getStudent()->GPA) << endl;
    cout << endl;
    print(head->getNext()); 
  }
}
//Delete a student
void del(Node*&head, Node* current, Node* previous, int studentID)
{
  //nothing to delete
  if(head == NULL)
  {
    return;
  }
    //nothing to delete
    else if(current == NULL)
    {
       return;
    }
    //If the entered ID is there
    else if(studentID == current->getStudent()->getID())
    {
      //If the head node has the student who user wants to delete
      if(studentID == head->getStudent()->getID())
      {
         Node* found = head;
        //points head to next node delting the first node
         head = head->getNext();
      }
      //If it is not the head node
      else
      {
        previous->setNext(current->getNext());
      }
    }
    else
    {
      del(head, current->getNext(), current, studentID);
    }
}

//Generating a random student
void makeStudent(int numofStudents,Node** ht, int htsize)
{
  string firstNames[100];
  string lastNames[100];
  int idxFirst = 0;
  int idxLast = 0;
  
  char studentFirstName[100];
  char studentLastName[100];
  string strFirst;
  string strLast;
  int studentID = 0;
  float studentGPA = 0.0;
  Student* student;
  
  
  //read FirstNames into an array
  fstream streamFirst;
  streamFirst.open("first.txt");
  //read each line and store in firstName array 
  while(streamFirst >> firstNames[idxFirst])
  {
    //cout  <<  firstNames[idxFirst] << endl;
    idxFirst++;
   
  }

   //read LastNames into an array
  fstream streamLast;
  streamLast.open("last.txt");
  //read each line and store in firstName array 
  while(streamLast >> lastNames[idxLast])
  {
    idxLast++;
  }

  // add number of random number of students
  for(int i = 0; i < numofStudents; i++)
  {
   // srand(time(NULL));
   // cout << "random = " << rand() % 100 + 1 << endl;
    strFirst = firstNames[rand()%100 + 1 ];
    strcpy(studentFirstName, strFirst.c_str());
    

    strcpy(studentLastName, lastNames[rand() %100 + 1].c_str());
    studentID = rand() %8999 + 1000;
    studentGPA = float(rand()%501)/100; //generates random float from 0.00 to 5.00 to use as gpa
    //Returning that student
    student = new               Student(studentFirstName,studentLastName, studentID, studentGPA);
    add(ht[hashFunction(student, htsize)], student);  
  }
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