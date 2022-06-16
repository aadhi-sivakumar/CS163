#include "graph.h"

using namespace std;

Graph::Graph() 
{
  cout << "Graph Initialized" << endl;
}

Graph::~Graph() 
{
  cout << "Graph Destroyed" << endl;
}

void Graph::shortestPath(string newStart, string newEnd) 
{
  node* startNode = findNode(newStart);
  node* endNode = findNode(newEnd);
  if(!startNode || !endNode) 
  {
    cout << "Couldn't find specified vertices." << endl;
    return;
  }
  for(int i = 0; i < size; i++) 
  { //Copy over vertices to path
    step* newStep = new step();
    newStep->vertex = nodeArray[i];
    path[i] = newStep;
  }
  path[startNode->id]->shortest = 0;
}


void Graph::addNode(string newlabel) {
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
void Graph::addEdge(string newStart, string newEnd) 
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
//Prints the adjacency table
void Graph::print() {
  int leftbuffer = 0;
  bool odd;
  for(int i = 0; i < size; i++) { //define leftbuffer
    if(nodeArray[i]->name.size() > leftbuffer) {
      leftbuffer = nodeArray[i]->name.size();
    }
  }
  for(int i = 0; i < leftbuffer; i++) { //apply buffer to top row
    cout << " ";
  }
  for(int i = 0; i < size; i++) { //print names horizontally
    cout << nodeArray[i]->name << " ";
  }
  cout << endl;
  for(int i = 0; i < size; i++) { //print names vertically
    cout << nodeArray[i]->name;
    for(int j = 0; j < leftbuffer - nodeArray[i]->name.size(); j++) {
      cout << " ";
    }
    for(int j = 0; j < size; j++) { //print connections
      if(nodeArray[j]->name.size() % 2 != 0 && nodeArray[j]->name.size() > 1) {
	odd = true;
      }
      else {
	odd = false;
      }
      for(int x = 0; x < nodeArray[j]->name.size() / 2;  x++) { //apply left buffer
	cout << " ";
      }
      if(adjTable[i][j] == false) {
	cout << "\033[1;31m" << "F" << "\033[0m";
      }
      else {
	cout << "\033[1;32m" << "T" << "\033[0m";
      }
      cout << (odd ? " " : "");
      for(int x = 0; x < nodeArray[j]->name.size() / 2;  x++) { //apply right buffer
	cout << " ";
      }
    }
    cout << endl;
  }
}

node* Graph::findNode(string label) 
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

edge* Graph::findEdge(node* startNode, node* endNode) 
{
  if(!adjTable[startNode->id][endNode->id]) 
  {
    return NULL;
  }
  node* it = nodeArray[startNode->id];
  while(it->next && it->next->end->id != endNode->id) 
  {
    it = it->next->end;
  }
  return it->next;
}

void Graph::removeNode(string label) 
{
  node* target = findNode(label);
  if(!target) 
  {
    cout << "Couldn't find specified vertex." << endl;
    return;
  }
  node* startNode;
  edge* collateral;
  for(int i = 0; i < size; i++) 
  { //Remove all connecting edges
    if(adjTable[i][target->id]) 
    {
      startNode = nodeArray[i];
      collateral = findEdge(startNode, target);
      startNode->next = startNode->next->end->next;
      adjTable[startNode->id][target->id] = false;
      adjTable[target->id][startNode->id] = false;
    }
  }
  for(int i = target->id; i < size - 1; i++) 
  { //Shift nodeArray up
    nodeArray[i + 1]->id = nodeArray[i]->id;
    nodeArray[i] = nodeArray[i + 1];
  }
  nodeArray[size] = NULL;
  for(int i = target->id; i < size; i++) 
  {
    for(int j = target->id; j < size; j++) 
    {
      adjTable[i][j] = adjTable[i + 1][j + 1];
    }
  }
  delete target;
  size--;
}

void Graph::removeEdge(string start, string end)
{
  node* startNode = findNode(start);
  node* endNode = findNode(end);
  if(!startNode || !endNode) 
  {
    cout << "Couldn't find specified vertices." << endl;
    return;
  }
  edge* target = findEdge(startNode, endNode);
  if(!target) 
  {
    cout << "There is no edge between " << startNode->name << " and " << endNode->name << "." << endl;
    return;
  }
  startNode->next = startNode->next->end->next;
  adjTable[startNode->id][endNode->id] = false;
  adjTable[endNode->id][startNode->id] = false;
  cout << "Edge deleted." << endl;
}