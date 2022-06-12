#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct edge;

struct node 
{
  int id;
  string name;
  bool flagged = false;
  edge* next;
};

struct edge 
{
  int weight;
  node* start;
  node* end;
};

struct step 
{
  node* vertex;
  int shortest = numeric_limits<int>::max();
  node* prevertex;
};

class graph 
{
 public:
  graph();
  ~graph();
  void addNode(string newLabel);
  void addEdge(string newStart,string newEnd);
  void print();
  void removeNode(string label);
  void removeEdge(string start, string end);
  void shortestPath(string newStart, string newEnd);
 private:
  int size = 0;
  step* path[20];
  node* nodeArray[20];
  bool adjTable[20][20] = {false};
  node* findNode(string);
  edge* findEdge(node*, node*);
};
