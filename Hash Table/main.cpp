#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>

using namespace std;

struct Student 
{ //student struct
  char firstName[100];
  char lastName[100];
  int studID;
  float GPA;

public:
  Student(char* newFirst, char* newLast, int newId, float newGPA) 
  {
    strcpy(firstName, newFirst);
    strcpy(lastName, newLast);
    studID = newId;
    GPA = newGPA;
  }
};

class Node 
{ //node class
  Student* student;
  Node* next;

public:
  Node(Student* newStudent) 
  { //constructor
    student = newStudent;
    next = NULL;
  }

  Student* getStudent() 
  { //getter for student
    return student;
  }

  void setStudent(Student* newStudent) 
  { //setter for student
    student = newStudent;
  }

  Node* getNext() 
  { //getter for next node
      return next;
  }

  void setNext(Node* inNext) 
  { //setter for next node
      next = inNext;
  }

};

//function prototypes
void displayMenu();
void add(Node*& head, Student* student);
void print(Node* head);
void del(Node* &head, Node* curr, Node* prev, int studID);
int hashF(Student* student, int size);
void randStud(Node**& hashtable, int num, int& studID, int size);
int collisionCount(Node** hashtable, int size);


int main() 
{
  char option[50];
  int size = 100;
  Node** hashtable = new Node*[size];
  int studID = 0;
  int num;
  
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
    cin >> option;
    cout << endl;

    for (int i=0; i < strlen(option); i++)
		{		
   		option[i] = toupper(option[i]);
		}	

    if (strcmp(option, "ADD") == 0) 
    { //add
      cout << "How many students would you like to add?" << endl;
      cin >> num;
      
      randStud(hashtable, num, studID, size);
    
      if (collisionCount(hashtable, size) > 3) 
      { 
        size = size*2;
        
        Node** temp = new Node*[size];
        for (int i = 0; i < size; i++) 
        {
          temp[i] = NULL;
        }

        for (int i = 0; i < size/2; i++) 
        { //rehash
            Node* node = hashtable[i];
            while (node != NULL) 
            {
              add(temp[hashF(node->getStudent(), size)], node->getStudent());
              node = node->getNext();
            }
        }
        //replace the hash table with the temporary table
        hashtable = new Node*[size];
        hashtable = temp;
            }
        }

        else if (strcmp(option, "PRINT") == 0) 
        { //print

          cout << "Printed Students: " << endl;
          for (int i = 0; i < size; i++) 
          {
            print(hashtable[i]);
          }
        }

        else if (strcmp(option, "DELETE") == 0) 
        { //delete 
          cout << "Enter the ID number of the student you want to delete: ";
          cin >> studID;
          
          for (int i = 0; i < size; i++) 
          {
            del(hashtable[i], hashtable[i], hashtable[i], studID);
          }
        }

        else if (strcmp(option, "QUIT") == 0) 
        { //quit
          break;
        }

        else
        {
          cout << "Invalid Input, please enter a valid option" << endl; 
        }
    }
    while(strcmp(option, "QUIT") != 0);
}

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
    Node* current = head;
    if(current == NULL) 
    { //sets new to head if head is null
      head = new Node(student);
    } 
    else 
    { //adds new node to end of the linked list
      while (current->getNext() != NULL) 
      {
        current = current->getNext();
      }
      current->setNext(new Node(student));
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
  if (head == NULL) 
  { //does nothing if head is null
    return;
  } 
    
  else if (curr == NULL) 
  { //does nothing if the current node is null
    return;
  } 

  else if (studID == curr->getStudent()->studID) 
  { //removes current node if target id is found
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
    del(head, curr->getNext(), curr, studID); //recursion
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
        //generates 2 random numbers from 0 to 19 for which line of the 'first.txt' and 'last.txt' to get the names from
        int firstline = rand() % 20+1;
        int lastline = rand() % 20+1;

        //file stuff
        fstream fin; 
        fstream lin;
        fin.open("first.txt");
        lin.open("last.txt");
        char* firstName = new char[100];
        char* lastName = new char[100];

        for (int j = 0; j < firstline; j++) 
        {
          fin >> firstName;
        }
        for (int j = 0; j < lastline; j++) 
        {
          lin >> lastName;
        }

        float GPA = float(rand()%501)/100; //generates random float from 0.00 to 5.00 to use as gpa

        Student* student = new Student(firstName, lastName, studID, GPA); //makes the student
        studID++; //increments id

        add(hashtable[hashF(student, size)], student); //adds student to table
    }
}

//function that returns the max number of collisions found in the table
int collisionCount(Node** hashtable, int size) 
{
    int maximum = 0;
    for (int i = 0; i < size; i++) 
    {
      Node* node = hashtable[i];
      int current = 1;
      if (node != NULL) 
      {
        while (node->getNext() != NULL) 
        {
          node = node->getNext();
          current++;
        }
        maximum = max(maximum, current);
      }
    }
    return maximum;
}
