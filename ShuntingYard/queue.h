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
  void enqueue(int value);
  char dequeue();
 private:
  Node* head = NULL;
  Node* tail = NULL;
};

#endif