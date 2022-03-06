#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

struct Node
{
  char data;
  Node* next;
};

class queue
{
 public:
  queue();
  ~queue();
  void enqueue(char value);
  void dequeue();
  char getQueue();
  void printQueue();
  Node* getNext(Node* n);
  bool isEmpty();
 private:
  Node* head = NULL;
  Node* tail = NULL;
 
};

#endif