#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
//#include "LL2.h"
using namespace std;

struct Node{
     int data;
     struct Node *next;
     struct Node *head;
};

Node* Insert(Node *head, int data){
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

void displayList(Node *head){
  
  Node *current = head;
  int count = 0;
  cout << "Display entire linked list: " << endl;
  
  while (current!=nullptr){
    cout << "node " << count++ << current->data << endl;
    current = current->next;
  }
  
}

void deleteNode(struct Node *head, int n) 
{ 
    // When node to be deleted is head node 
    if(head->data == n) 
    { 
        if(head->next == NULL) 
        { 
            cout << "There is only one node. The list can't be made empty " << endl; 
            return; 
        } 
  
        /* Copy the data of next node to head */
        head->data = head->next->data; 
  
        
        // store address of next node 
        Node *temp = head->next;
        //n = head->next; 
  
        // Remove the link of next node 
        head->next = head->next->next; 
  
        // free memory 
        //free(n); 
        temp = NULL;
        
        return; 
    } 
  
  
    // When not first node, follow the normal deletion process 
  
    // find the previous node 
    struct Node *prev = head; 
    while(prev->next != NULL && prev->next->data != n) 
        prev = prev->next; 
  
    // Check if node really exists in Linked List 
    if(prev->next == NULL) 
    { 
        cout << "Given node is not present in Linked List" << endl;; 
        return; 
    } 
  
    // Remove node from Linked List 
    prev->next = prev->next->next; 
  
    // Free memory 
    //free(n); 
    
    return;  
} 

Node* deleteNegatives(Node *head){
  Node *temp = head;
  while(temp!=NULL){
    if(temp->data < 0){
      deleteNode(temp, temp->data);
    }
    temp = temp -> next;
  }
  temp = NULL;
  return head;
}

int main(){
  string input;
  string input1;
  bool result;
  Node *head = new Node;
  
  cout << "Please enter items to insert into the linked list. Once you are done entering values, enter NULL to indicate the linked list is done." << endl;
  getline(cin, input1);
  if(input1 != "NULL"){
    head = Insert(head, stoi(input1));
  }
  while (input1 != "NULL" && input != "NULL"){
    cout << "Please enter items or NULL"<< endl;
    getline(cin, input);
    if(input != "NULL"){
      head = Insert(head, stoi(input));
    }
  }
  
  displayList(head);
  head = deleteNegatives(head);
  displayList(head);

  

  return 0;
}
