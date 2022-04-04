#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
using namespace std;

class Student
{
  public:
  //variables for student information
  char firstName[100];
  char lastName[100];
  int studID;
  float GPA;

  //constructor
  Student(char* firstname, char* lastname, int id, float gpa);
  //destructor
  ~Student();

  //functions
  char* getFirstName();
  char* getLastName();
  int getID();
  float getGPA();
};

#endif