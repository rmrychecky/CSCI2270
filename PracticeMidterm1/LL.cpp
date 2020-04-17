#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
#include "LL.h"

LL ::LL () {
  head = nullptr;
  tail = nullptr;
}

LL :: ~LL(){
  Node *tmp, *current = head; //you start at the head and then delete and then point to the next until the tail is nullpointer
  while (current != nullptr) { //don't want to start deleting things past tail!
    tmp = current->next;
    delete current;
    current = tmp;
  }
  head = nullptr;
  tail = nullptr;
}

void LL:: appendNode (Node *head, string newItem){
  
  if (head == nullptr){ //if the head has the null pointer then nothig in there
    head->key = newItem;
    head->next = nullptr;
    tail = head;
  }
  else{ //more than 1 Node
    Node *temp = new Node;
    temp->key = newItem;
    tail->next = temp; //old tail linking to new list
    tail = temp; //new tail
    tail->next = nullptr;
  }
  
}

void LL::insert_end(string newKey){
  //1. ALLOCATE NODE
  Node* newNode = new Node;

  //2. PUT IN THE DATA
  newNode->key = newKey;

  //3. Make next of newNode as NULL
  newNode->next = NULL;

  //4. Check if head is not Null
  if(head == NULL){
    head = newNode;
    return;
  }

  //4. Traverse the LinkedList till end
  Node* temp = head;

  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
  return;
}

void LL :: displayList(){
  
  Node *current = head;
  int count = 0;
  cout << "Display entire linked list: " << endl;
  
  while (current!=nullptr){
    cout << "node " << count++ << current->key << endl;
    current = current->next;
  }
  
}

Node *LL :: search(string sKey){
  
  Node *returnNode = nullptr;
  Node *tmp = head;
  
  bool found = false;
  
  while (!found && tmp!= nullptr){
    if (tmp->key==sKey){
      found = true;
      returnNode = tmp; //just returning its address
    }
    else{
      tmp = tmp->next; //otherwise we continue to traverse
    }
  }
  
  return returnNode; //if we don't ever find the matching Node, its going to return the nullptr
}

void LL :: deleteNode(string sKey){
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

bool LL :: lengthIsEven(){
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