/*
//Author: Aadhi Sivakumar
//Assignment: Shunting Yard Algorithmn
//Date: 3/2/2022
//Sources: Dad helped me with queue
*/

#include "stack.h"
#include "queue.h"
#include <iostream>
#include <cstring>
#include <cctype>

/*
//function prototypes
int precedence(char operation);
void printInfix(tree* tree);
void printPostfix(tree* tree);
void printPrefix(tree* tree);
*/
int main() 
{
/*
  //variables
  char input[100];
  char output[100];
  int number = 0;
  //welcome message
  cout << "Welcome to the Shunting Yard   Algorithm! Please enter an equation in infix notation(how it is normally written)." << endl;
  //asking for user input
  cin.getline(input,100);
  //removes spaces from input
  for (int i = 0; i <strlen(input); i++) 
  {
    if (input[i] != ' ') {
      output[number] = input[i];
      number++;
*/
  }
    

/*
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
