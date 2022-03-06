/*
//Author: Aadhi Sivakumar
//Assignment: Shunting Yard Algorithmn
//Date: 3/2/2022
//Sources: Dad helped me with queue
// 
*/

#include "stack.h"
#include "queue.h"
#include "tree.h"
#include <iostream>
#include <cstring>
#include <cctype>


//function prototypes
int precedence(char operation);
void test();
void toPostfix(char* infix);

int main() 
{
  stack* Stack = new stack();
  queue* Queue = new queue();
  
  //variables
  char input[100];
  char output[100];
  int number = 0;
  //welcome message
  cout << "Welcome to the Shunting Yard Algorithm! Please enter an equation in infix notation(how it is normally written)." << endl;
  //asking for user input
  cin.getline(input,100);
  //removes spaces from input
  for (int i = 0; i < strlen(input); i++) 
  {
    if (input[i] != ' ') 
    {
      output[number] = input[i];
      number++;
    }
  }
  toPostfix(output);

  return 0;
}

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

void toPostfix(char* infix)
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
  
  //display the postfix by printing out the queue 
  Queue->printQueue();
 /* while (!Queue->isEmpty())
  {
    cout << Queue->getQueue();
    Queue->dequeue();
  }
  */
}//end of function

//binary tree functions
void buildTree(queue* Queue)
{
  stack* Stack = new stack();
  tree* Btree = NULL;
  Node* queueNode = Queue->getNext(NULL);
  
  
  while (queueNode != NULL)
  {
    char item = queueNode->data;
    if (isdigit(item))
    {
      Stack->push(item);      
    }
    else
    {
      tree* Tree = new tree(item);
      if (Btree == NULL)
      {
        char data1 = Stack->peek();
        char data2 = Stack->getNext(NULL)->data;
        tree* right = new tree(data1);
        tree* left = new tree(data2);
        Tree->setRight(right);
        Tree->setLeft(left);
        Stack->pop();
        Stack->pop();
        Btree = Tree;
      }
      else
      {
      //  char data1 = Btree->getData();
        char data2 = Stack->peek();
        tree* right = new tree(data2);
        Tree->setRight(right);
        Tree->setLeft(Btree);
        Stack->pop();
        Btree = Tree;
        
      }
      
/*
    if (thead == NULL) {
        char a = peek(shead2);
        char b = peek(shead2->next);
        BNode* right = new BNode(a);
        BNode* left = new BNode(b);
        node->setRight(right);
        node->setLeft(left);
        pop(shead2);
        pop(shead2);
        thead = node;
    }

    else {
        char a = thead->getChar();
        char b = peek(shead2);
        BNode* right = new BNode(b);
        node->setRight(right);
        node->setLeft(thead);
        pop(shead2);
        thead = node;
    }
    */
            
    }
    queueNode = Queue->getNext(queueNode);
    
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