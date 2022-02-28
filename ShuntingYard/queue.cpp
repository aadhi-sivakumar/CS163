#include "queue.h"

queue::queue() 
{
  head = NULL;
}

void queue::enqueue(char n)
{
  queueNode* number = new queueNode();
  number->data = n;
  if (head == NULL) 
  {
    head = number;
  }
  else 
  {
    queueNode* number2 = head;
    while (number2->next != NULL) {
      number2 = number2->next;
    }
    number2->next = number;
  }
}

char queue::dequeue() {
  if (head == NULL) {
    return NULL;
  }
  else 
  {
    queueNode* number = head;
    char next = number->data;
    head = number->next;
    delete number;
    return next;
  }
}