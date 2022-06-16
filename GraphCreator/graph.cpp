#include "graph.h"

using namespace std;

//constructor
Graph::Graph() 
{
  
}

//destructor
Graph::~Graph() 
{
  
}

//adds the vertex
void Graph::addVertex(string newlabel) 
{
  //if the adjacency table is full
  if(size >= 20) 
  {
    cout << "Graph is full" << endl;
    return;
  }
  //constructs new vertex
  vertex* newVertex = new vertex();
  newVertex->id = size;
  newVertex->name = newlabel;
  newVertex->next = NULL;
  nArray[size] = newVertex;
  size++;
}
//add edge
void Graph::addEdge(string newStart, string newEnd) 
{
  //finds the two vertexes
  vertex* sNode = findVertex(newStart);
  vertex* eNode = findVertex(newEnd);
  //returns that at least one of the vertices are not there
  if(!sNode || !eNode) 
  {
    cout << "Couldn't find one of the vertices." << endl;
    return;
  }
  int nWeight = 1;
  cout << "New edge weight: ";
  cin >> nWeight;
  //makes edge
  edge* nEdge = new edge();
  nEdge->weight = nWeight;
  nEdge->start = sNode;
  nEdge->end = eNode;
  vertex* a = sNode;
  while(a->next != NULL) 
  {
    a = a->next->end;
  }
  a->next = nEdge;
  //declares the adjacency table with values
  adjTable[sNode->id][eNode->id] = true;
  adjTable[eNode->id][sNode->id] = true;
}

//Prints the adjacency table
void Graph::print() 
{
  int space = 0;
  bool connection;
  //define buffer
  for(int i = 0; i < size; i++) 
  {
    if(nArray[i]->name.size() > space) 
    {
      space = nArray[i]->name.size();
    }
  }
   //apply buffer to top row
  for(int i = 0; i < space; i++) 
  {
    cout << " ";
  }
  //print names horizontally
  for(int i = 0; i < size; i++) 
  { 
    cout << nArray[i]->name << " ";
  }
  cout << endl;
  //print names vertically
  for(int i = 0; i < size; i++)
    { 
    cout << nArray[i]->name;
    for(int j = 0; j < space - nArray[i]->name.size(); j++) 
    {
      cout << " ";
    }
    for(int j = 0; j < size; j++)
      { 
      if(nArray[j]->name.size() % 2 != 0 && nArray[j]->name.size() > 1) 
      {
	      connection = true;
      }
      else 
      {
	      connection = false;
      }
      for(int x = 0; x < nArray[j]->name.size() / 2;  x++) 
      { 
	cout << " ";
      }
      if(adjTable[i][j] == false) 
      {
	      cout << "F ";
      }
      else 
      {
	      cout << "T ";
      }
      cout << (connection ? " " : "");
      for(int x = 0; x < nArray[j]->name.size() / 2;  x++) 
      {
	      cout << " ";
      }
    }
    cout << endl;
  }
}

//find node
vertex* Graph::findVertex(string label) 
{
  for(int i = 0; i < size; i++) 
  {
    if(nArray[i]->name == label) 
    {
      return nArray[i];
    }
  }
  return NULL;
}

//find edge
edge* Graph::findEdge(vertex* startNode, vertex* endNode) 
{
  if(!adjTable[startNode->id][endNode->id]) 
  {
    return NULL;
  }
  vertex* a = nArray[startNode->id];
  while(a->next && a->next->end->id != endNode->id) 
  {
    a = a->next->end;
  }
  return a->next;
}

//remove node
void Graph::removeVertex(string label) 
{
  //finds the node you want to delete
  vertex* target = findVertex(label);
  //if the node you want to delete is not there, states that the vertex is not found
  if(!target) 
  {
    cout << "Couldn't find one of the vertices" << endl;
    return;
  }
  vertex* startNode;
  edge* remove;
  for(int i = 0; i < size; i++) 
  { 
    //Remove all connecting edges
    if(adjTable[i][target->id]) 
    {
      startNode = nArray[i];
      remove = findEdge(startNode, target);
      startNode->next = startNode->next->end->next;
      adjTable[startNode->id][target->id] = false;
      adjTable[target->id][startNode->id] = false;
    }
  }
  //Shift nodeArray up
  for(int i = target->id; i < size - 1; i++) 
  { 
    nArray[i + 1]->id = nArray[i]->id;
    nArray[i] = nArray[i + 1];
  }
  nArray[size] = NULL;
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

//remove edge
void Graph::removeEdge(string start, string end)
{
  //finds the two vetexs to remove the edge from
  vertex* startVertex = findVertex(start);
  vertex* endVertex = findVertex(end);
  //returns that at least one of the vertexs are not there
  if(!startVertex || !endVertex) 
  {
    cout << "Couldn't find one of the vertices." << endl;
    return;
  }
  //finds the edge tp be deleted
  edge* target = findEdge(startVertex, endVertex);
  //if the edge you want to be deleted is not found
  if(!target) 
  {
    cout << "There is no edge between " << startVertex->name << " and " << endVertex->name << "." << endl;
    return;
  }
  startVertex->next = startVertex->next->end->next;
  adjTable[startVertex->id][endVertex->id] = false;
  adjTable[endVertex->id][startVertex->id] = false;
  cout << "Edge deleted." << endl;
}
