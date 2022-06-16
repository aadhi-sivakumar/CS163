////Author: Aadhi Sivakumar
//Assignment: Graph Creator
//Description: Creating a graph where you can add and remove vertices.
//Sources: Dad helped with making the table look nice

#include "graph.h"
#include <cstring>
#include <iomanip>
using namespace std;

//function prototypes
void displayMenu();

int main() 
{
  Graph* graph = new Graph();
  char option[10];
  
  //welcome message
  cout << "Welcome to Graph Creator!" << endl;
  
  do
  {
    //show the display menu
    displayMenu();

    //input from user
    cin >> option;
    cout << endl;

    //converts user input to uppercase so it can accept any input upper or lower case or mix.
    for (int i = 0; i < strlen(option); i++)
		{		
   		option[i] = toupper(option[i]);
		}

    //if user enters add vertex
    if (strcmp(option, "AV") == 0)
    {
      cout << "Add vertex: ";
      cin >> option;
      graph->addVertex(option);
      graph->print();
    }

    //if user wants to input an edge
    else if(strcmp(option, "AE") == 0)
    {
      string newEnd;
      cout << "First node: ";
      cin >> option;
      cout << "Second node: ";
      cin >> newEnd;
      graph->addEdge(option, newEnd);
      cin.ignore();
      cin.clear();
    }

    //remove vertex
    else if(strcmp(option, "RV") == 0)
    {
      cout << "Remove vertex: ";
      cin >> option;
      graph->removeVertex(option);
      graph->print();
    }

    //remove edge
    else if(strcmp(option, "RE") == 0)
    {
      string newEnd;
      cout << "First node: ";
      cin >> option;
      cout << "Second node: ";
      cin >> newEnd;
      graph->removeEdge(option, newEnd);
    }

    //prints the adjacency table
    else if(strcmp(option, "P") == 0)
    {
      graph->print();
    }
    
    //quit
    else if (strcmp(option, "Q") == 0)
    {
      break;
    }

    //invalid input
     else
    {
      cout << "Invalid Input, please enter a valid option." << endl;
    }  
  }
  while (strcmp(option,"Q") != 0);
}

//user display menu with available options
void displayMenu()
{
  cout << endl;
	cout << "Select an option:" << endl << endl; 
	cout << "ADD VERTEX--->Type 'AV' to add a vertex to the Graph: " << endl;
  cout << "ADD Edge--->Type 'AE' to add an edge between two Nodes: " << endl;
	cout << "REMOVE VERTEX--->Type 'RV' to remove a vertex from the graph and remove all edges to that Vertex: " << endl;
  cout << "REMOVE EDGE--->Type 'RE' to remove an edge between two vertex labels: " << endl;
  cout << "PRINT--->Type 'P' to print the adj table: " << endl;
	//cout << "FIND SHORTEST PATH--->Type 'FSP' to find the shortest path between two vertex: " << endl << endl;
  cout << "QUIT--->Type 'Q' to leave the program: " << endl;
}
