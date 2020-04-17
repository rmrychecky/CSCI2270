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

Node* Insert(Node *head, string data)
{
    // Creates a temp to hold the last node and set last's data and next
    Node *last = new Node;

    last->data = data;
    last->next = NULL;

    // If the linked list is empty then set head = last
    if (head == NULL) {
        head = last;
    } 
    else {
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

void displayList(Node *head){
  
  Node *current = head;
  int count = 0;
  cout << "Display entire linked list: " << endl;
  
  while (current!=nullptr){
    cout << "node " << count++ << current->data << endl;
    current = current->next;
  }
  
}

void swapNodes(struct Node **head_ref, string x, string y) 
{ 
   // Nothing to do if x and y are same 
   if (x == y) return; 
  
   // Search for x (keep track of prevX and CurrX 
   struct Node *prevX = NULL, *currX = *head_ref; 
   while (currX && currX->data != x) 
   { 
       prevX = currX; 
       currX = currX->next; 
   } 
  
   // Search for y (keep track of prevY and CurrY 
   struct Node *prevY = NULL, *currY = *head_ref; 
   while (currY && currY->data != y) 
   { 
       prevY = currY; 
       currY = currY->next; 
   } 
  
   // If either x or y is not present, nothing to do 
   if (currX == NULL || currY == NULL) 
       return; 
  
   // If x is not head of linked list 
   if (prevX != NULL) 
       prevX->next = currY; 
   else // Else make y as new head 
       *head_ref = currY;   
  
   // If y is not head of linked list 
   if (prevY != NULL) 
       prevY->next = currX; 
   else  // Else make x as new head 
       *head_ref = currX; 
  
   // Swap next pointers 
   struct Node *temp = currY->next; 
   currY->next = currX->next; 
   currX->next  = temp; 
} 


int main(){
  //ask the user to input values to create the linked list
  string input;
  string input1;
  bool result;
  Node *head = new Node;
  head = NULL;
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

  displayList(head);
  swapNodes(&head, "hello", "goodbye");
  displayList(head);
  return 0;
}