#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

class queue
{
 public:
  queue();
  ~queue();
  void enqueue(int value);
  void dequeue();
 private:
  Node* head = NULL;
  Node* tail = NULL;
};

#endif
