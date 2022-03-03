#include "queue.h"

queue::queue() 
{
  
}

queue::~queue() 
{
  
}

void queue::enqueue(int value)
{
  Node* temp = new Node();
  temp->data = value;
  if (head == NULL) 
  {
    head = temp;
    tail = temp;
  }
  else 
  {
    tail->next = temp;
    tail = temp;
  }
}

char queue::dequeue() 
{
  if (head == NULL) 
  {
    cout << "Queue is empty" << endl;
  }
  else if (head == tail)
  {
    free(head);
    head = NULL;
    tail = NULL;
  }
  else
  {
    Node* temp = head;
    head = head->next;
    free(temp);
  }
}