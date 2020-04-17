#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
#include "LL2.h"

LL2 :: LL2 () {
  head = nullptr;
  tail = nullptr;
}

LL2 :: ~LL2(){
  Node *tmp, *current = head; //you start at the head and then delete and then point to the next until the tail is NULLpointer
  while (current != nullptr) { //don't want to start deleting things past tail!
    tmp = current->next;
    delete current;
    current = tmp;
  }
  head = nullptr;
  tail = nullptr;
}

void LL2 :: insert_last(int x) {
    Node *newer = new Node;
    newer->key = x;
    if (is_empty()) {
        newer->next = head;
        head = newer;
    }
    else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        newer->next = temp->next;
        temp->next = newer;
    }
}

Node* LL2 :: deleteNegatives(){
  Node *temp = head;
  while(temp!=NULL){
    if(temp->key < 0){
      deleteNode(temp->key);
    }
    temp = temp -> next;
  }
  temp = NULL;
  return head;
}

void LL2 :: displayList(){
  
  Node *current = head;
  int count = 0;
  cout << "Display entire linked list: " << endl;
  
  while (current!=nullptr){
    cout << "node " << count++ << current->key << endl;
    current = current->next;
  }
  
}

void LL2 :: deleteNode(int sKey){
  Node *tmp;
  if(head->key == sKey){ //if the sKey is in the head
    tmp = head;
    head = tmp->next;
    delete tmp;
    tmp = nullptr;
  }
  else{ 
    bool found = false;
    Node *last = head;
    tmp = head->next; //pointer advancing ahead
    while(!found && tmp!=nullptr){ //while you haven't found it and you haven't reached the tail
      if(tmp->key==sKey){
        found = true;
      }
      else{
        last = tmp; //move to the next one
        tmp = tmp->next;
      }
    }
    if(found){
      if (tmp->next == nullptr){ //if what you found is a tail pointer
        last->next = nullptr;
        tail = last; //update the tail
      }
      else{ //this is the middle case (dont need to update the tail pointer)
        last->next = tmp->next;
      }
      delete tmp; //deallocate the tmp
      tmp = nullptr;
      last = nullptr; //last is your new tail now 
    }
  }
}

bool LL2 :: is_empty() { 
    return head == NULL; 
}