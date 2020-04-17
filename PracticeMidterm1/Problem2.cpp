#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "LL2.h"
using namespace std;


int main(){
  //ask the user to input values to create the linked list
  string input;
  string input1;
  bool result;
  Node *top = new Node;
  LL2 linkedList;
  
  
  cout << "Please enter integers to insert into the linked list. Once you are done entering values, enter NULL to indicate the linked list is done." << endl;
  getline(cin, input1);
  if(input1 != "NULL"){
      linkedList.insert_last(stoi(input1));
  }
  while (input1 != "NULL" && input != "NULL"){
    cout << "Please enter integer or NULL"<< endl;
    getline(cin, input);
    if(input != "NULL"){
      linkedList.insert_last(stoi(input));
    }
  }
  linkedList.displayList();
  top = linkedList.deleteNegatives();
  linkedList.displayList();

  return 0;
}