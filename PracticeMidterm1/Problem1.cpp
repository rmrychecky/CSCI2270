#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "LL.h"
using namespace std;

int main(){
  //ask the user to input values to create the linked list
  string input;
  string input1;
  bool result;
  //Node *head = new Node;
  LL linkedList;
  
  cout << "Please enter items to insert into the linked list. Once you are done entering values, enter NULL to indicate the linked list is done." << endl;
  getline(cin, input1);
  if(input1 == "NULL"){
    result = true;
    cout << result << endl;
    return 0;
  }
  linkedList.insert_end(input1);
  while (input1 != "NULL" && input != "NULL"){
    cout << "Please enter items or NULL"<< endl;
    getline(cin, input);
    linkedList.insert_end(input1);
  }

  
  result = linkedList.lengthIsEven();
  cout << result << endl;
  
  return 0;
}