#include <iostream>
using namespace std;
#include "SLL.h"

SLL ::SLL () {
  head = nullptr;
  tail = nullptr;
}

SLL :: ~SLL(){
  Node *tmp, *current = head; //you start at the head and then delete and then point to the next until the tail is nullpointer
  while (current != nullptr) { //don't want to start deleting things past tail!
    temp = current->next;
    delete current;
    current = tmp;
  }
  head = nullptr;
  tail = nullptr;
}

void SLL :: appendNode (string newItem){
  
  if (head == nullptr){ //if the head has the null pointer then nothig in there
    head = new Node;
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

void SLL :: insert(string afterMe, string newValue){
  
  if (afterMe==""){ //assume that if afterMe is an empty string, the node is made the head
    Node *temp = new Node; //create node
    temp -> key = newValue; //put correct value in
    temp -> next = head; //point it to head
    head = temp; //update the head so it points to temp
    temp = nullptr;
  }
  else{
    Node *last = search(afterMe); //check if search is in there
    if (last==nullptr){
      cout << "node not found, new node not inserted" << endl; //if you can't find, error message
    }
    else if(last -> next == nullptr){ //after me is the tail
      appendNode(newValue);
    }
    else{ //last case (4) you found node and have pointer; it is head or somewhere in the middle 
      Node *temp = new Node;
      temp -> key = newValue;
      temp -> next = last -> next;
      last -> next = temp;
      temp = nullptr;
    }
    
  }
  
}

void SLL :: displayList(){
  
  Node *current = head;
  int count = 0;
  cout << "Display entire linked list: " << endl;
  
  while (current!=nullptr){
    cout << "node " << count++ << current->key << endl;
    current = current->next;
  }
  
}

Node *SLL :: search(string sKey){
  
  Node *returnNode = nullptr;
  Node *tmp = head;
  
  bool found = false;
  
  while (!found && temp!= nullptr){
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

void SLL :: deleteNode(string sKey){
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