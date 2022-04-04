#include "node.h"

//constructor
Node::Node(Student* newStudent)
{
  student = newStudent;
  next = NULL;
}

//destructor
Node::~Node()
{

}

Node* Node:: getNext()
{
  return next;
}

void Node::setNext(Node* newNext)
{
  next = newNext;
}

Student* Node:: getStudent()
{
  return student;
}

void Node::setStudent(Student* newStudent)
{
  student = newStudent;
}
