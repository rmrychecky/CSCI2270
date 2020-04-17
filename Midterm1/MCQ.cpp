#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
//#include "LL.h"
using namespace std;

//Question 4

struct Node{
    int data;
    Node *next;
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
int main(){
    
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
    Node *temp = head->next;
    cout << head->next->data << endl;
    head->next->next = head;
    cout << head->data << endl;

    for (int i=0; i<3; i++) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    
}
