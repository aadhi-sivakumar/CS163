//**********************************************
//Author: Aadhi Sivakumar
//Assignment: Hash Table
//Description: Student list with hash table
//Date: 3/12/22
//***********************************************

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

struct student
{	
	char firstName[50];
	char lastName[50];
	int studID;
	float GPA;
};

struct Node 
{
  student* Student;
  Node* next;
};

//function prototypes
void displayMenu();
void addstudent(Node* hashtable[], int size, student* s);
void printstudent(student* s);
void print(Node* hashtable[], int size);
bool check(Node* hashtable[], int size);
Node* remove(Node* hashtable[], int size, int id, bool confirmation);

int main()
{
  //initializing variables
  srand (time(NULL));
  int size = 100;
  int randomid = 1;
  char line[100];
	char option[20];
  int delId;

  //loop until user inputs quit
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

		}
    //if user inputs random
    else if (strcmp(option, "RANDOM") == 0)
    {
      
    }
    // if user inputs print
		else if (strcmp(option, "PRINT") == 0)
		{
      
		}
    // if user inputs inputs delete
		else if (strcmp(option, "DELETE") == 0)
		{

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
	return 0;				
}
// displays options user can do
void displayMenu()
{
  cout << endl; 
	cout << "Select an option:" << endl << endl; 
	cout << "ADD--->Type 'ADD' to add a new student record: " << endl;
        cout << "PRINT--->Type 'PRINT' to print out all the students currently stored: " << endl;
	cout << "DELETE--->Type 'DELETE' to delete a student ID number from the record: " << endl;
	cout << "QUIT--->Type 'QUIT' to exit the program: " << endl;
  cout << "RANDOM--->Type 'RANDOM' to add random names(random student generator): "
}
// option if user wants to add student record
void add(Node* hashtable[], int size, student* s)
{
	Node* node = new Node();
  node->Student = s;
  node->next = NULL;
  int hash = (node->studID)%size;
  Node* temp = new Node();
  temp = hashtable[hash];
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = node;
	student st; 

}

void addstudent(Node* hashtable[], int size, student* s) {
  Node* node = new Node();
  node->Student = s;
  node->next = NULL;
  int hash = (s->studID)%size;
  Node* temp = new Node();
  temp = hashtable[hash];
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = node;
}

void printstudent(student* s) {
  // print a student name, id, gpa
  cout << s->firstName << " " << s->lastName << endl;
  cout << s->studID << endl;
  cout << "GPA: " << fixed << setprecision(2) << s->GPA << endl;
  cout << endl;
}

void print(Node* hashtable[], int size) 
{
  // print all students using printstudent function
  Node* node = new Node();
  for (int i=0; i<size; i++) 
  {
    node = hashtable[i];
    node = node->next;
    while (n != NULL) 
    {
      printstudent(node->Student);
      node = node->next;
    }
  }
}

bool check(Node* hashtable[], int size) 
{
  // check if table should be rehashed
  bool rehash = false;
  int numfull = 0;
  int count = 0;
  Node* n = new Node();
  for (int i=0; i<size; i++) 
  {
    numfull = 0;
    node = hashtable[i];
    if (node->next == NULL) 
    {
      continue;
    }
    node = node->next;
    while (node != NULL) {
      numfull = numfull+1;
      n = n->next;
    }
    if (numfull > 3) {
      rehash = true;
    }
  }
  if (count > size/2) {
    rehash = true;
  }
  return rehash;
}

Node* remove(Node* hashtable[], int size, int id, bool needconfirm) 
{
  // remove a student
  int i = id % size;
  Node* previous = hashtable[i];
  Node* current = hashtable[i]->next;
  bool found = false;
  char confirm = 'y';
  while (current != NULL) 
  {
    if (current->Student->studID == id) 
    {
      if (needconfirm) 
      {
        cout << "I'm about to delete " << current->Student->firstName << " " << current->Student->lastName << ". Are you sure you want to remove this student? (y/n)" << endl;}
        cin >> confirm;
      }
      if (confirm == 'y' || confirm == 'Y') 
      {
        cout << "Deleting student." << endl;}
	      previous->next = current->next;
	      return current;
      }
      else 
      {
	      cout << " No student deleted." << endl;
	      return NULL;
      }
      found = true;
      break;
    }
    else 
    {
      previous = current;
      current = current->next;
    }
  }
  if (found == false) {
    cout << "Invalid ID number. Nothing has been deleted." << endl;
  }
  return NULL;
}

