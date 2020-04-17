#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
//#include "LL.h"
using namespace std;

struct Node{
     string data;
     struct Node *next;
     struct Node *head;
};
  
bool lengthIsEven(Node *head){
  int countNodes;
  bool result;
  //Node *temp = head;
  if(head == NULL){
    result = true;
  }
  else{
    while (head->next != NULL){
      //cout << head->key << endl;
      head = head->next;
      countNodes++;
    }
    if(countNodes % 2 == 0){
      result = true;
    }
    else{
      result = false;
    }
  }
  return result;
}

Node* Insert(Node *head, string data)
{
    // Creates a temp to hold the last node and set last's data and next
    Node *last = new Node;

    last->data = data;
    last->next = NULL;

    // If the linked list is empty then set head = last
    if (head == NULL) {
        head = last;
    } else {
        // Creates a temp node and sets it to head
        Node *temp = new Node;

        temp = head;

        // Uses temp to find the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Appends the last node with last
        temp->next = last;
    }

    // Returns head of linked list
    return head;
}

int main(){
  //ask the user to input values to create the linked list
  string input;
  string input1;
  bool result;
  Node *head = new Node;
  //Node *head = head;
  //LL linkedList;
  
  cout << "Please enter items to insert into the linked list. Once you are done entering values, enter NULL to indicate the linked list is done." << endl;
  getline(cin, input1);
  if(input1 == "NULL"){
    result = true;
    cout << result << endl;
    return 0;
  }
  head = Insert(head, input1);
  while (input1 != "NULL" && input != "NULL"){
    cout << "Please enter items or NULL"<< endl;
    getline(cin, input);
    head = Insert(head, input);
  }


  result = lengthIsEven(head);
  cout << result << endl;
  
  return 0;
}