#ifndef NODE_H
#define NODE_H


#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <cstring>


//student info in struct
struct Student 
{ 
  char firstName[100];
  char lastName[100];
  int studID;
  float GPA;

public:
  Student(char* newFirstName, char* newLastName, int newStudID, float newGPA) 
  {
    strcpy(firstName, newFirstName);
    strcpy(lastName, newLastName);
    studID = newStudID;
    GPA = newGPA;
  }
};
class Node 
{ 
public:	
  Student* student;
  Node* next;
  Node(Student* newStudent);
  //getter
  Student* getStudent(); 
  //setter
  void setStudent(Student* newStudent); 
  //getter
  Node* getNext();
  //setter
  void setNext(Node* Next); 
};
#endif
