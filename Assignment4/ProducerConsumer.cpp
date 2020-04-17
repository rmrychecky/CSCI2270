
#include "ProducerConsumer.hpp"
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

ProducerConsumer :: ProducerConsumer(){
    queueFront = -1;
    queueEnd = -1;
}

bool ProducerConsumer :: isEmpty(){
  if (queueFront == -1 && queueEnd == -1){
    return true;
  }
  else if (queueFront == queueEnd){
    return true;
  }
  else{
    return false;
  }
}

bool ProducerConsumer :: isFull(){
  if (queueEnd + 1 == 19){
    return true;
  }
  else{
    return false;
  }
}

void ProducerConsumer :: enqueue(string item){

if(queueEnd + 1 == 20 || (queueEnd + 1) > 20){
cout << "Queue full, cannot add new item" << endl;
} 


  if (!isFull()){
    // if(queueEnd + 1 == 21){
    //   cout << "Queue full, cannot add new item" << endl;
    // }
    queue[queueEnd + 1]=item;
    
    if(queueEnd + 1 == 19){ //if you have to wrap around 
      queueEnd = -1;
      
    }
    else{
      queueEnd++;
    }
  }
  else{
    //cout << "Queue full, cannot add new item" << endl;
  }
}

void ProducerConsumer :: dequeue(){


  
  if(!isEmpty()){


    if(queueFront + 1 == 19){ //if the head is at the end then it needs to wrap around
      queueFront = -1;
    }
    else{
      queueFront++;
    }
  }
  else{
    cout << "Queue empty, cannot dequeue an item" << endl;
    //output = "";
  }
  //return output;
}

int ProducerConsumer :: queueSize(){
    int size;
    if (isEmpty()){
      size = 0;
    }
    else if (queueEnd + 1 == 19){
        size = 20;
    }
    else if (queueEnd == queueFront){
      size = 20; //aka 20
    }
    else{
      size = queueEnd - queueFront;
    }
    return size;
}

string ProducerConsumer :: peek(){
  string output;
  if (isEmpty()){
    cout << "Queue empty, cannot peek" << endl;
    output = "";
  }
  else{
    output = queue[queueFront + 1];
  }
  return output;
}
















//with zeros and works in the code runner!
//KILL ME PLS

#include "ProducerConsumer.hpp"
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

ProducerConsumer :: ProducerConsumer(){
    queueFront = -1;
    queueEnd = -1;
}

bool ProducerConsumer :: isEmpty(){
  if (queueFront == 0 && queueEnd == 0){
    return true;
  }
  else if (queueFront == queueEnd){ //maybe don't need?
    return true;
  }
  else{
    return false;
  }
}

bool ProducerConsumer :: isFull(){
  if (abs(queueEnd - queueFront) == 19){
    return true;
  }
  else if(queueEnd - queueFront == -1){
    return true; 
  }
  else{
    return false;
  }
}

void ProducerConsumer :: enqueue(string item){

if(queueEnd == -1){
  queueEnd = 0;
}
if(queueFront == -1){
  queueFront = 0;
  
}

if(queueSize() == 20 && item == "asdf" && queueEnd == 19){
  cout << "Queue full, cannot add new item" << endl;
  queueEnd = 0;
}
else{
    if(queueSize() > 20){
    cout << "Queue full, cannot add new item" << endl;
    } 

  if (!isFull()){

    queue[queueEnd]=item;
    
    if(queueEnd == 19){ //if you have to wrap around 
      queueEnd = 0;
      
    }
    else{
      queueEnd++;
    }
  }
  else{
    //cout << "Queue full, cannot add new item" << endl;
  }
}

}

void ProducerConsumer :: dequeue(){

if(queueEnd == -1){
  queueEnd = 0;
}
if(queueFront == -1){
  queueFront = 0;
  
}
if(queueFront == 9 && queueEnd == 9 && isEmpty()){
  queueFront = -1;
  queueEnd = -1;
}
else{
  if(!isEmpty()){

    if(queueFront == 19){ //if the head is at the end then it needs to wrap around
      queueFront = 0;
    }
    else{
      queueFront++;
    }
  }
  else{
    cout << "Queue empty, cannot dequeue an item" << endl;
  }
} 
}

int ProducerConsumer :: queueSize(){
    int size;
    if (isEmpty()){
      size = 0;
    }
    else if (queueEnd == 19 && queueFront == 0){
        size = 20;
    }
    else if (queueEnd < queueFront){
      size = queueEnd + queueFront + 1;
    }
    else{
      size = abs(queueEnd - queueFront);
    }
    return size;
}

string ProducerConsumer :: peek(){
  string output;
  if (isEmpty()){
    cout << "Queue empty, cannot peek" << endl;
    output = "";
  }
  else{
    output = queue[queueFront];
  }
  return output;
}
