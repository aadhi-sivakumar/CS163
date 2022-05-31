using namespace std;
#include <iostream>
#include "bst.h"

int main()
{
   bst* bstroot = new bst();
   // insert bunch
   bstroot = NULL;
   bstroot = bstroot->insertNode(bstroot,5);
   bstroot = bstroot->insertNode(bstroot,10);
   bstroot = bstroot->insertNode(bstroot, 7);
   bstroot = bstroot->insertNode(bstroot, 1);
   bstroot = bstroot->insertNode(bstroot, 20);
   bstroot = bstroot->insertNode(bstroot, 4);
   bstroot = bstroot->insertNode(bstroot,3);

   //print
   bstroot->printBST(bstroot);

   //Search some
   cout << endl << endl;
   bool searchResult = false;
   searchResult = bstroot->searchBST(bstroot, 10);
   cout << "Searching value: 10 -> " << ( searchResult ? " Found the value " : " Not Found") << endl;
   searchResult = bstroot->searchBST(bstroot, 40);
   cout << "Searching value: 40 -> " << ( searchResult ? " Found the value " : " Not Found") << endl;
   searchResult = bstroot->searchBST(bstroot, 3);
   cout << "Searching value: 3 -> " << ( searchResult ? " Found the value " : " Not Found") << endl;

   //Remove
   cout << endl << "BST before removal " << endl;
   bstroot->printBST(bstroot);

   bst* temp = NULL;

   //remove two child}

   cout << endl << endl;
   cout << "Removing root - 10" << endl << endl;
   temp = bstroot->removeNode(bstroot, 10);
   bstroot->printBST(bstroot);

   //remove one child
 
   cout << endl << "Removing root - 3" << endl << endl;
   temp = bstroot->removeNode(bstroot, 3);
   bstroot->printBST(bstroot);
   //remove root
   cout << endl << "Removing root - 5" << endl << endl;
   temp = bstroot->removeNode(bstroot, 5);
   bstroot->printBST(bstroot);
   
   return 0;
}
