#include <bits/stdc++.h>
using namespace std;

char* convertToUpper(char* str);
void fileInput(int*& arr, int& size);
void userInput(int*& arr, int& size);
void print(int* arr);
void add(int*& arr, int num, int index);
void displayTree(int index, int* array, int depth, int size);
void displaySort(int*& array, int& size);


int main() 
{
  bool running = true;
  char input[1000];
  int* arr = new int[100];
  for (int i = 0; i < 100; i++) 
  { 
        arr[i] = 0;
  }
  int size = 0;
  
  cout << "Welcome to Heap!" << endl; 
  cout << "Would you like to enter the numbers by 'FILE' or by 'INPUT'" << endl; 
  cin >> input;
  
  if (strcmp(convertToUpper(input), "FILE") == 0)
  {
    fileInput(arr, size);
  }

  if (strcmp(convertToUpper(input), "INPUT") == 0)
  {
    userInput(arr, size);
  }

  displayTree(1, arr, 0, size);
  displaySort(arr, size);
}

char* convertToUpper(char* str)
{
  int i = 0;
  while(str[i])
  {
    str[i] = toupper(str[i]);
    i++;
  }
  return str;
}

void fileInput(int*& arr, int& size) 
{
    fstream first;
    first.open("numbers.txt"); 

    int input;
    int index = 1;
    while(first >> input) 
    { 
        add(arr, input, index); 
        index++;
    }
    size = index - 1;

    first.close();
}

void userInput(int*& arr, int& size)
{
  int amount;
  int input;
  cout << "How many numbers do you want to enter?" << endl;
  cin >> amount;
  for (int index = 1; index < amount + 1; index++)
  {
    cin >> input;
    add(arr, input, index);
  }
}

void print(int* arr)
{
    cout << "PRINT" << endl;
    for (int i = 0; i < 100; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void add(int*& arr, int num, int index) 
{ 
  int pIndex = index / 2;
  arr[index] = num; //add to heap array
  while (arr[index] > arr[pIndex] && index > 1 ) 
  {
      int temp = arr[index];
      arr[index] = arr[pIndex];
      arr[pIndex] = temp;
      index = pIndex;
      pIndex = pIndex / 2;
  }
}

void displayTree(int index, int* arr, int depth, int size) 
{
  if (size >= index * 2 + 1  && arr[index*2+1] != 0) 
  { 
    displayTree(index * 2 + 1, arr, depth + 1, size); 
  }
  for(int i = 0; i < depth; i++) 
  { 
    cout << "\t";
  }
  cout << arr[index] << endl;
  if (index * 2 <= size && arr[index * 2] != 0) 
  {
    displayTree(index * 2, arr, depth + 1, size);
  }
}

void displaySort(int*& arr, int& size) 
{ 
  cout << arr[1] << " "; 
  arr[1] = arr[size];
  arr[size] = 0;  
  size--;
  
  int index = 1;
  while(arr[index * 2] != 0) 
  {
    if (arr[index * 2] > arr[index] || arr[index * 2 + 1] > arr[index]) 
    {
      if (arr[index * 2] > arr[index * 2 + 1]) 
      {
        int temp = arr[index];
        arr[index] = arr[index * 2];
        arr[index * 2] = temp;
        index = index * 2;
      } 
      
      else 
      {
        int temp = arr[index];
        arr[index] = arr[index * 2 + 1];
        arr[index * 2 + 1] = temp;
        index = index * 2 + 1;
      } 
    } 
    else 
    {
      break;
    }
  }
    if (size != 0) 
    {
        displaySort(arr, size); //recursive call
    }
}