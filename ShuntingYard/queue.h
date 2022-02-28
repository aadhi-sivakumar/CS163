#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;
struct queueNode
{
  char data;
  queueNode* next;
};

class queue
{
 public:
  queue();
  void enqueue(char n);
  char dequeue();
 private:
  queueNode* head;
};

#endif