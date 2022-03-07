#include "queue.h"

//constructor
queue::queue() 
{
  
}

//destructor
queue::~queue() 
{
  
}

//pushing into queue
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

//removing from queue
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
//checking if queue is empty
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

//gets queue values
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

//prints queue
void queue::printQueue()
{
  Node * node = head;
  while (node != NULL)
  { 
    cout << node->data << " " ;
    node = node->next;
  }
}

//trasverses through queue node to get the contents in the queue to return as a string
char* queue::getQueueContent()
{
  char content[500];
  int idx = 0;
  
  Node * node = head;
  while (node != NULL)
  {
    content[idx++] =  node->data ;
    node = node->next;
  }
  content[idx] = '\0';
 
  return content;
}