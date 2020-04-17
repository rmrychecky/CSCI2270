#include "PriorityQueue.hpp"
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

PriorityQueue :: PriorityQueue(int queueSize){
    maxQueueSize = queueSize;
    currentQueueSize = 0;
    priorityQueue = new GroupNode[queueSize];
}

PriorityQueue :: ~PriorityQueue(){
  delete [] priorityQueue;
}

void PriorityQueue :: enqueue (std::string _groupName, int _groupSize, int _cookingTime){
  if(isFull()){
    cout << "Heap full, cannot enqueue" << endl;
  }
  else{
      GroupNode *newNode = new GroupNode;
      newNode->groupName = _groupName;
      newNode->groupSize = _groupSize;
      newNode->cookingTime = _cookingTime;
      
      priorityQueue[currentQueueSize] = *newNode;
      delete newNode;
      
      repairUpward(currentQueueSize);
      currentQueueSize++;
  }
}

void PriorityQueue :: dequeue(){
  if(isEmpty()){
    cout << "Heap empty, cannot dequeue" << endl;
  }
  else if(currentQueueSize == 1){
    currentQueueSize--;
  }
  else{
    priorityQueue[0] = priorityQueue[currentQueueSize - 1];
    currentQueueSize--;
    repairDownward(0);
  }
}

GroupNode PriorityQueue :: peek(){
  if(isEmpty()){
    cout << "Heap empty, nothing to peek" << endl;
  }
  //else{
    return priorityQueue[0];
  //}
}

bool PriorityQueue :: isFull(){
  if (currentQueueSize == maxQueueSize){
    return true;
  }
  else{
    return false;
  }
}

bool PriorityQueue :: isEmpty(){
  if (currentQueueSize == 0){
    return true;
  }
  else{
    return false;
  }
}

void PriorityQueue :: repairUpward(int nodeIndex){
  if(priorityQueue[(nodeIndex - 1)/2].groupSize > priorityQueue[nodeIndex].groupSize){
    GroupNode temp = priorityQueue[nodeIndex];
    priorityQueue[nodeIndex] = priorityQueue[(nodeIndex - 1)/2];
    priorityQueue[(nodeIndex - 1)/2] = temp;
    repairUpward((nodeIndex - 1)/2);
  }
  else if(priorityQueue[(nodeIndex - 1)/2].groupSize == priorityQueue[nodeIndex].groupSize){
    if(priorityQueue[(nodeIndex - 1)/2].cookingTime > priorityQueue[nodeIndex].cookingTime){
      GroupNode temp = priorityQueue[nodeIndex];
      priorityQueue[nodeIndex] = priorityQueue[(nodeIndex - 1)/2];
      priorityQueue[(nodeIndex - 1)/2] = temp;
      repairUpward((nodeIndex - 1)/2);
    }
    
  }
        

}

void PriorityQueue :: repairDownward(int nodeIndex){ 
  int leftChild = 2*(nodeIndex) + 1;
  int rightChild = 2*(nodeIndex) + 2;
  int smallest = nodeIndex;
  
 
  //leftChild comparison
  if(leftChild < currentQueueSize && priorityQueue[leftChild].groupSize < priorityQueue[nodeIndex].groupSize){
    smallest = leftChild;
  }
  else if(leftChild < currentQueueSize && priorityQueue[leftChild].groupSize == priorityQueue[nodeIndex].groupSize){
    if(priorityQueue[leftChild].cookingTime < priorityQueue[nodeIndex].cookingTime){
      smallest = leftChild;
    }
  }
  
  //rightChild comparison
  if(rightChild < currentQueueSize && priorityQueue[rightChild].groupSize < priorityQueue[smallest].groupSize){
    smallest = rightChild;
  }
  else if(rightChild < currentQueueSize && priorityQueue[rightChild].groupSize == priorityQueue[smallest].groupSize){
    if(priorityQueue[rightChild].cookingTime < priorityQueue[smallest].cookingTime){
      smallest = rightChild;
    }
  }

  //swap with lesser value and call repairDownward recursively 
  if(smallest != nodeIndex){
    GroupNode temp = priorityQueue[nodeIndex];
    priorityQueue[nodeIndex] = priorityQueue[smallest];
    priorityQueue[smallest] = temp;
    
    repairDownward(smallest);
  }
}
