#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "student.h"

class Node
{
  public:
    //variables to create a student and node
    Student* student;
    Node* next;

    //constructor
    Node(Student* newStudent);
    //destructor
    ~Node();

    //functions 
    Node* getNext();
    void setNext(Node* newNext);
    Student* getStudent();
    void setStudent(Student* newStudent);
};

#endif