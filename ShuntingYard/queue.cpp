#include "queue.h"

queue::queue() 
{
  
}

queue::~queue() 
{
  
}

void queue::enqueue(char value)
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

void queue::dequeue()
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

bool queue::isEmpty()
{
  if (head == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

char queue::getQueue()
{
  if (head != NULL)
  {
     return head->data;
  }
  else
  {
    //returns a negative if the queue is empty
     return NULL; 
  }
}
void queue::printQueue()
{
  Node * node = head;
  while (node != NULL)
  { 
    cout << node->data << " " ;
    node = node->next;
  }
}
Node* queue::getNext(Node* n)
{
  if (n == NULL)
  {
     return head;
  }
  else if (n->next != NULL)
  {
    return n->next;
  }
  else
  {
    return NULL;
  }
  
}