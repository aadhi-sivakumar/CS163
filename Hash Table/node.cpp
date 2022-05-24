#include "node.h"

//constructor
Node::Node(Student* newStudent) 
  {
    student = newStudent;
    next = NULL;
  }
//getter
Student* Node::getStudent() 
  { 
    return student;
  }
//setter
 void Node::setStudent(Student* newStudent) 
  { 
    student = newStudent;
  }
//getter
Node* Node::getNext() 
  { 
      return next;
  }
//setter
  void Node::setNext(Node* Next) 
  { 
      next = Next;
  }

