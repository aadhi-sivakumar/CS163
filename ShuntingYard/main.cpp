/*
//Author: Aadhi Sivakumar
//Assignment: Shunting Yard Algorithmn
//Date: 3/2/2022

#include "stack.h"
#include "queue.h"
#include "tree.h"
#include <iostream>
#include <cstring>
#include <cctype>


//function prototypes
int precedence(char operation);
void test();
std::string ConvertToPostfix(char* infix);
tree* buildTree(string Exp);
void PrintInfix(tree* T);
void PrintPrefix(tree* T);
void PrintPostfix(tree* T);

int main() 
{
  stack* Stack = new stack();
  queue* Queue = new queue();
  tree* ExpBTree = NULL;
  
  //variables
  char inputExp[500];
  char noSpaceInputExp[500];
  string strPostFix;
  int idx = 0;
  //welcome message
  cout << "Welcome to the Shunting Yard Algorithm! Please enter an equation in infix notation(how it is normally written)." << endl;
  //asking for user input
  cin.getline(inputExp,100);
  //removes spaces from input
  for (int i = 0; i < strlen(inputExp); i++) 
  {
    if (inputExp[i] != ' ') 
    {
      noSpaceInputExp[idx++] = inputExp[i];
    }
  }
  noSpaceInputExp[idx] = '\0';
  
  //converts the postfix expression so it has no spaces
  strPostFix = ConvertToPostfix(noSpaceInputExp);
 
  //Build ExpressionTree 
  ExpBTree = buildTree(strPostFix);
  
  
  //Display Btree in Infix format
  cout << endl << "Infix:" << endl;
  PrintInfix(ExpBTree);
  //Display Btree in PreFix format
  cout << endl << "Prefix:" << endl;
  PrintPrefix(ExpBTree);
  //Display Btree in Postfix format
  cout << endl << "Postfix:" << endl;
  PrintPostfix(ExpBTree);
  cout << endl;
  return 0;
  
}

//precedence of operations
int precedence(char operation)
{
  if(operation == '^')
  {
    return 3;
  }
  if(operation == '*' || operation == '/')
  {
    return 2;
  }
  if(operation == '+' || operation == '-')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

//shunting yard algortithmn
//used the wikipedia link on canvas to help me write the shunting yard algorithmn
std::string ConvertToPostfix(char* infix)
{
  stack* Stack = new stack();
  queue* Queue = new queue();

  for (int i = 0; i < strlen(infix); i++)
  {
    char t = infix[i];
//for digit
    if (isdigit(t))
    {
      Queue->enqueue(t);
    }//end of digit if
    //for operator
    else if ((t == '^')||(t == '*')||(t == '/')||(t == '+')||(t == '-'))
    {
      char o1 = t;
      if (!Stack->isEmpty())
      {
        char o2 = Stack->peek();
        if (o2 != '(')
        {
          if (precedence(o2) > precedence(o1))
          {
            
            Queue->enqueue(o2);
            Stack->pop();
          }   
          if ((o1 != o2) && (precedence(o2) == precedence(o1)))
          {
            Queue->enqueue(o2);
            Stack->pop();
          }   
        }
      }
      Stack->push(o1);   
    }//end of operator if

    else if(t == '(')
    {
      Stack->push(t);
    }//end of '(' if

    else if(t == ')')
    {
      if (!Stack->isEmpty()) 
      {
        char o2 = Stack->peek();
        if (o2 == '(')
        {
           Stack->pop();
        }
        else
        {
          Queue->enqueue(o2);
          Stack->pop();
        }
      }
      
    }//end of ')' if
    
  }//end of for
  while (!Stack->isEmpty())
  {
    char o2 = Stack->peek();
    if (o2 != '(')
    {
      Queue->enqueue(o2);
    }
    Stack->pop();
  }//end of while
  
  //Get the queue content to return the converted postfix string to main
  return Queue->getQueueContent();

  
}//end of function

//building the binary tree
tree* buildTree(string postfix)
{
  stack* Stack = new stack();
  tree* Btree = NULL;
  tree* LeftTree = NULL;
  tree* RightTree = NULL;
  //Node* queueNode = Queue->getNext(NULL);
  int i = 0;
	while (postfix[i] != '\0')
	{
		if (!(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^'))
		{
			Btree = new tree(postfix[i]);
      //Stack->push(postfix[i]);
			Stack->pushNode(Btree);
		}
		else
		{
			Btree = new tree(postfix[i]);
   //  LeftTree = new tree(Stack->peekNode()->getData()); 
     LeftTree = Stack->peekNode();
     Stack->popNode();
     
      RightTree = Stack->peekNode();
     // RightTree = new tree(Stack->peek());
     // Stack->pop();
      Stack->popNode();
			Btree->setRight(RightTree); 
		  Btree->setLeft(LeftTree); 
		  Stack->pushNode(Btree);
		}
		i++;
	}
 
  tree* resultTree = Stack->peekNode();
  return resultTree; 
}

//print infix 
void PrintInfix(tree* T)
{
	if (T != NULL)
	{
		PrintInfix(T->getRight());
		T->printNode();
		PrintInfix(T->getLeft());
	}
}      
//print prefix
void PrintPrefix(tree* T)
{
	if (T != NULL)
	{
		T->printNode();
		PrintPrefix(T->getRight());
    PrintPrefix(T->getLeft());
	}
} 
//print postfix
void PrintPostfix(tree* T)
{
	if (T != NULL)
	{
    PrintPostfix(T->getRight());
		PrintPostfix(T->getLeft());
		T->printNode();
	}
} 

void test()
{
  stack* Stack = new stack();
  queue* Queue = new queue();
  
  Stack->push(30);
  Stack->push(40);
  Stack->push(50);
  while (!Stack->isEmpty())
  {
    cout << Stack->peek() << endl;
    Stack->pop();
  }
  cout << "Queue:" << endl;
  Queue->enqueue(30);
  Queue->enqueue(40);
  Queue->enqueue(50);
  cout << "removing queue inputs:" << endl;
  while (!Queue->isEmpty())
  {
    
    cout << Queue->getQueue() << endl;
    Queue->dequeue();
  }
}
