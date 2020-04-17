#include <iostream>
using namespace std;

#include "QueArrCir.h"

QueArrCir :: QueArrCir(){
  head = 0;
  tail = 0;
  queSize = 0;
}

bool QueArrCir :: isEmpty(){
  if (queSize == 0){
    return true;
  }
  else{
    return false;
  }
}

bool QueArrCir :: isFull(){
  if (queSize==MAXSIZE){
    return true;
  }
  else{
    return false;
  }
}

void QueArrCir :: enque(string newItem){
  if (!isFull()){
    a[tail]=newItem;
    queSize++;
    if(tail == MAXSIZE - 1){ //if you have to wrap around 
      tail = 0;
    }
    else{
      tail++;
    }
   
  }
  else{
    cout << "queue is full" << endl;
  }
}

string QueArrCir :: deque(){
  string output;
  
  if(!isEmpty()){
    output = a[head];
    queSize--;
    if(head==MAXSIZE - 1){ //if the head is at the end then it needs to wrap around
      head = 0;
    }
    else{
      head++;
    }
  }
  else{
    cout << "queue empty. returning empty string" << endl;
    output = "";
  }
}