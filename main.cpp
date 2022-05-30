using namespace std;
#include <iostream>
#include "bst.h"

int main()
{
   bst* bstroot = new bst();
   bstroot = NULL;
   bstroot = bstroot->insertNode(bstroot,5);
   bstroot = bstroot->insertNode(bstroot,10);
   bstroot = bstroot->insertNode(bstroot,3);
  
   bool searchResult = false;
   searchResult = bstroot->searchBST(bstroot, 10);
   cout << searchResult << endl;
   searchResult = bstroot->searchBST(bstroot, 40);
   cout << searchResult << endl;
   searchResult = bstroot->searchBST(bstroot, 3);
   cout << searchResult << endl;
}
