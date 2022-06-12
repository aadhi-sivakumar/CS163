#include "graph.h"
using namespace std;

graph::graph() 
{
  cout << "Graph Initialized" << endl;
}

graph::~graph() 
{
  cout << "Graph Destroyed" << endl;
}

void graph::addNode(string newlabel) 
{
  if(size >= 20) 
  {
    cout << "Graph is full" << endl;
    return;
  }
  node* newNode = new node();
  newNode->id = size;
  newNode->name = newlabel;
  newNode->flagged = false;
  newNode->next = NULL;
  nodeArray[size] = newNode;
  size++;
}

void graph::addEdge(string newStart, string newEnd) 
{
  node* startNode = findNode(newStart);
  node* endNode = findNode(newEnd);
  if(!startNode || !endNode) 
  {
    cout << "Couldn't find specified vertices." << endl;
    return;
  }
  int newWeight = 1;
  cout << "New edge weight: ";
  cin >> newWeight;
  edge* newEdge = new edge();
  newEdge->weight = newWeight;
  newEdge->start = startNode;
  newEdge->end = endNode;
  node* it = startNode;
  while(it->next != NULL) 
  {
    it = it->next->end;
  }
  it->next = newEdge;
  adjTable[startNode->id][endNode->id] = true;
  adjTable[endNode->id][startNode->id] = true;
}

node* graph::findNode(string label) 
{
  for(int i = 0; i < size; i++) 
  {
    if(nodeArray[i]->name == label) 
    {
      return nodeArray[i];
    }
  }
  return NULL;
}

edge* graph::findEdge(node* startNode, node* endNode) 
{
  if(!adjTable[startNode->id][endNode->id])
  {
    return NULL;
  }
  node* it = nodeArray[startNode->id];
  while(it->next && it->next->end->id != endNode->id) {
    it = it->next->end;
  }
  return it->next;
}

void graph::removeNode(string label) 
{
  node* target = findNode(label);
  if(!target) 
  {
    cout << "Couldn't find specified vertex." << endl;
    return;
  }
  node* startNode;
  edge* collateral;

  
}
