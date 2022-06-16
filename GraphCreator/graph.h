#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct edge;

//structure to build nodes into the ajacency table
struct vertex 
{
  int id;
  string name;
  edge* next;
};

//struct to connect the two nodes
struct edge 
{
  int weight;
  vertex* start;
  vertex* end;
};

class Graph 
{
 public:
//functions
  Graph();
  ~Graph();
  void print();
  void addVertex(string newLabel);
  void removeVertex(string label);
  void addEdge(string newStart, string newEnd);
  void removeEdge(string start, string end);
 private:
//variables
  int size = 0;
  vertex* nArray[20];
  bool adjTable[20][20] = {false};
//fund edge functions
  vertex* findVertex(string label);
  edge* findEdge(vertex* startNode, vertex* endNode);
};

#endif