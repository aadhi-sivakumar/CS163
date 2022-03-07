//header guard
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

//queue node structure
struct Node
{
  char data;
  Node* next;
};

class queue
{
 public:
  //constructor
  queue();
  //destructor
  ~queue();
  //queue functions
  void enqueue(char value);
  void dequeue();
  char getQueue();
  void printQueue();
  char* getQueueContent();
  bool isEmpty();
 private:
  // queue variables
  Node* head = NULL;
  Node* tail = NULL;
 
};

#endif