#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>
#include "node.h"

//function prototypes
void displayMenu();
void add(Node* newNode,Node* &head, Node* arr[], int &sizeCount);
void print(Node* head, int space);
void deleteTree(Node* arr[], int size);

int main() 
{
  //variables
  int size = 1; 
  Node* heap[100];
  int arr[100];
  Node* head = NULL;
  char option[100];

  //Welcome Message
   cout << "Welcome to Heap!" << endl; 

  do
  {
    //show the display menu
    displayMenu();

    //input from user
    cin >> option;
    cout << endl;

    //converts user input to uppercase so it can accept any input upper or lower case or mix.
    for (int i=0; i < strlen(option); i++)
		{		
   		option[i] = toupper(option[i]);
		}	

    if (strcmp(option, "ADD") == 0)
    {
      //Asks if they are entering manually or by file name
      cout << "Would you like to add numbers to the heap manually(type 'MANUALLY') or by file name (type 'FILE')?" << endl;
      char input[100];
      cin >> input;

      //convert input to uppercase
      for (int i=0; i < strlen(input); i++)
		  {		
   		  option[i] = toupper(input[i]);
		  }	
      
      //Adding through direct input
      if(strcmp(input, "MANUALLY") == 0)
      {
        cout << "Insert a number to the heap. If you want to add more than one number, repeat the command once again after you enter the number." << endl;
        int number = 0;
        cin >> number;
        Node* newNode = new Node(number);
        add(newNode, head, heap, size);
      }

      else if(strcmp(input, "FILE") == 0)
      {
        int temp = 0;
        cout << "Enter a file name: (e.g. filename.txt)" << endl;
        char filename[100];
        cin >> filename;

        //Opens the file and adds the numbers into an array
	      fstream numbers;
        numbers.open(filename);

        for(int i = 0; i < 100; i++)
        {
          numbers >> temp;
          //Adds the node to the heap
          Node* newNode = new Node(temp);
          add(newNode, head, heap, size);
	      }
      }    
  }
  //prints the heap
  else if (strcmp(option, "PRINT") == 0)
  {
    cout << "PRINTING HEAP" << endl;
    print(head, 0);
  }

  else if (strcmp(option, "DELETE") == 0)
  {
    deleteTree(heap, size-2);
    size = 1;
    head = NULL;
  }

  else if(strcmp(option, "QUIT") == 0)
  {
    break;
  }

  else
  {
    cout << "Invalid Input, please enter a valid option." << endl;
  }
}
while (strcmp(option,"QUIT") != 0);
}
//user display menu with available options
void displayMenu()
{
  cout << endl;
	cout << "Select an option:" << endl << endl; 
	cout << "ADD--->Type 'ADD' to add to the heap: " << endl;
  cout << "PRINT--->Type 'PRINT' to print the heap: " << endl;
	cout << "DELETE--->Type 'DELETE' to delete: " << endl;
	cout << "QUIT--->Type 'QUIT' to exit the program: " << endl << endl;
}

//add function
void add(Node* newNode, Node*& head, Node* arr[], int& sizeCount) 
{ 
  //if heap is empty
  if (head == NULL)
  {
    head = newNode;
    arr[sizeCount - 1] = head;
    sizeCount++;
  }
  //divide size by 2 since each child has two parents
  else
  {
    int pIndex = sizeCount/2;
    Node* parent = arr[pIndex - 1];
    Node* curr = newNode;

    //if left is empty, place node there
    if(parent->getLeft() == NULL)
    {
      parent->setLeft(newNode);
      arr[sizeCount-1] = newNode;
      sizeCount++;
    }

    //If left is occupied, add the node to the right
    if(parent->getLeft() == NULL)
    {
      parent->setLeft(newNode);
      arr[sizeCount-1] = newNode;
      sizeCount++;
    }

    //Sets up the heap as amax heap from least to greatest
    while(arr[pIndex-1]->getData() < curr->getData())
    {
        int newData = curr->getData();
        curr->setData(arr[pIndex-1]->getData());
        arr[pIndex-1]->setData(newData);
        curr = arr[pIndex-1];
        if(pIndex == 1)
        {
          break;
        }
        else
        {
          pIndex = pIndex/2;
        }
    } 
  }
} 

void print(Node* head, int space) 
{
  if(head == NULL)
  {
    return;
  }
  //This creates space between levels of the tree
  space = space + 10;

  //Start from the right
  print(head->getRight(), space);

  //Print the current node after a new line
  cout << endl;
  for(int i = 0; i < space; i++)
  {
    cout << " ";
  }
  cout << head->getData() << '\n';
  
  //Onto the left
  if(head->getLeft() != NULL)
  {
  print(head->getLeft(), space);
  }
}

//Deletes the tree
void deleteTree(Node* arr[], int size)
{
    //If the tree is empty
    if(arr[0] == NULL)
    {
      cout<< "Nothing to delete!" << endl;
        return;
    }
    //If the size is 0, print the one
    else if(size == 0)
    {
        cout << arr[0]->getData() << endl;
        delete arr[0];
        arr[0] = NULL;
    }
    //Swaps the first and last node if the last node is bigger
    else 
    {
        if(arr[0]->getData() > arr[size]->getData())
        {
          int temp = arr[size]->getData();
          arr[size]->setData(arr[0]->getData());
          arr[0]->setData(temp);
        }
    int temp2 = size + 1;
    int parentIndex = floor(temp2/2);
    if(arr[parentIndex-1]->getLeft() == arr[size])
    {
        arr[parentIndex-1]->setLeft(NULL);
        cout << arr[size]->getData() << endl;
        delete arr[size];
    }
    else if(arr[parentIndex-1]->getRight() == arr[size])
    {
        arr[parentIndex-1]->setRight(NULL);
        cout << arr[size]->getData() << endl;
        delete arr[size];
    }
    //After the last node is deleted, the heap is put back into order
    Node* curr = arr[0];
    while(curr->getLeft() != NULL || curr->getRight() != NULL)
    {
        //Compares the value of data in child nodes
        //If the left node is larger
        if(curr->getNewLeft() > curr->getNewRight())
        {
          int num = curr->getData();
          curr->setData(curr->getLeft()->getData());
          curr->getLeft()->setData(num);
          curr = curr->getLeft();
        }
        //If the right node is larger
        else if(curr->getNewLeft() < curr->getNewRight())
        {
            int num = curr->getData();
            curr->setData(curr->getRight()->getData());
            curr->getRight()->setData(num);
            curr = curr->getRight();
        }
        else
        {
          //If two child nodes have the same value
          if(curr->getNewLeft() != -1)
          {
            int num = curr->getData();
            curr->setData(curr->getNewLeft());
            curr->getLeft()->setData(num);
            curr = curr->getLeft();
          }
          else
          {
            return;
          }
        }
    }
    //Calls itself again on a one-size smaller array
    deleteTree(arr, size-1);
  }
}