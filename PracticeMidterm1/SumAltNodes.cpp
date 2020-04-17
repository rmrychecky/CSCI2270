#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
//#include "LL.h"
using namespace std;

struct Node{
     int data;
     struct Node *next;
     struct Node *head;
};

Node* Insert(Node *head, int data)
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

/* Function to get the alternate  
   nodes of the linked list */
int sumAlternateNode(struct Node* head) 
{ 
    int count = 0; 
    int sum = 0; 
    Node* temp = head;
  
    while (temp != NULL) { 
  
        // when count is even sum the nodes 
        if (count % 2 == 0) 
            sum += temp->data; 
  
        // count the nodes 
        count++; 
  
        // move on the next node. 
        temp = temp->next; 
    } 
    delete temp;
    return sum; 
} 


int main(){
  //ask the user to input values to create the linked list
  string input;
  string input1;
  bool result;
  int sum;
  Node *head = new Node;
  head = NULL;
  //LL linkedList;
  
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
  sum = sumAlternateNode(head);
  cout << sum << endl;
  displayList(head);
  return 0;
}

  













  
// // Function to push node at head 
// void push(struct Node** head_ref, int new_data) 
// { 
//     struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
//     new_node->data = new_data; 
//     new_node->next = (*head_ref); 
//     (*head_ref) = new_node; 
// } 
  
