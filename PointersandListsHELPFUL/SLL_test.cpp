#include <iostream>
using namespace std;

#include "SLL.h"

int main(){
  
  SLL l; //create an instance of SLL
  
  string arr[]={"jeden", "dwa", "trzy"}; //define a test string array
  int arrLen = 3;
  
  for (int i = 0; i < arrLen; i++){
    l.appendNode(arr[i]);
  }
  
  l.displayList();
  
  Node *tmp = l.search("dwa");
  cout << "node found " << tmp->key << endl;
  
  //l.~SLL(); //automatically called when the object goes out of scope (scope of l is main)
  l.displayList(); //this should now show us an emplty list
  
  //testing insert
  l.insert("jeden", "jedenipol");
  l.insert("trzy", "cztery"); //adding at tail
  l.displayList();
  
  return 0;
  
}