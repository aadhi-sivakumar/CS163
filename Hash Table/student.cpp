#include "student.h"

//constructor
Student::Student(char* firstname, char* lastname, int id, float gpa)
{
  strcpy(firstName, firstname);
  strcpy(lastName, lastname);
  studID = id;
  GPA = gpa;
}

//destructor
Student::~Student()
{

}

float Student::getGPA()
{
  return GPA;
}

int Student::getID()
{
  return studID;
}

char* Student::getFirstName()
{
  return firstName;
}

char* Student::getLastName()
{
  return lastName;
}