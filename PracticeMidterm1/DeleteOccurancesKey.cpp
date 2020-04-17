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

void deleteKey(struct Node **head_ref, string key) 
{ 
    // Store head node 
    struct Node* temp = *head_ref, *prev; 
  
    // If head node itself holds the key or multiple occurrences of key 
    while (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        temp = *head_ref;         // Change Temp 
    } 
  
    // Delete occurrences other than head 
    while (temp != NULL) 
    { 
        // Search for the key to be deleted, keep track of the 
        // previous node as we need to change 'prev->next' 
        while (temp != NULL && temp->data != key) 
        { 
            prev = temp; 
            temp = temp->next; 
        } 
  
        // If key was not present in linked list 
        if (temp == NULL) return; 
  
        // Unlink the node from linked list 
        prev->next = temp->next; 
  
        free(temp);  // Free memory 
  
        //Update Temp for next iteration of outer loop 
        temp = prev->next; 
    } 
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
  deleteKey(&head, "hello");
  displayList(head);
  return 0;
}