#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "heaps.hpp"
using namespace std;

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int parent(int index){
  return (index-1)/2;
}

int leftChild(int index){
  return ((2*index) + 1);
}

int rightChild(int index){
  return ((2*index) + 2);
}

Heap :: Heap(int heapSize1){
  heapSize = heapSize1;
  currentSize = 0;
  heap = new int[heapSize];
}

Heap :: ~Heap(){
  delete [] heap;
}

void Heap::printHeap(){
  int iter = 0;
  while(iter < currentSize)
  {
    cout<<heap[iter]<<" ";
    iter = iter + 1;
  }
  cout<<endl;
}

void Heap :: addToHeap(int value){

  if(currentSize == heapSize){
    cout<<"Maximum heap size reached. Cannot insert anymore"<<endl;
    return;
  }
  
  currentSize = currentSize + 1;
  int index = currentSize - 1;
  heap[index] = value;
  
  while (index != 0 && heap[parent(index)] > heap[index]){
       swap(&heap[index], &heap[parent(index)]);
       index = parent(index);
  }
}

int Heap :: removeFromHeap(){
  int returnValue;
  if(isEmpty()){
    cout << "Heap empty, cannot dequeue" << endl;
  }
  else if(currentSize == 1){
    currentSize--;
  }
  else{
    returnValue = heap[0];
    heap[0] = heap[currentSize - 1];
    currentSize--;
    repairDownward(0);
    return returnValue;
  }
}

int Heap :: peekValue(){
  if(isEmpty()){
    cout << "Heap empty, nothing to peek" << endl;
  }
  //else{
    return heap[0];
  //}
}

bool Heap :: isFull(){
  if (currentSize == heapSize){
    return true;
  }
  else{
    return false;
  }
}

bool Heap :: isEmpty(){
  if (currentSize == 0){
    return true;
  }
  else{
    return false;
  }
}

void Heap :: repairUpward(int nodeIndex){
  if(heap[(nodeIndex - 1)/2] > heap[nodeIndex]){
    int temp = heap[nodeIndex];
    heap[nodeIndex] = heap[(nodeIndex - 1)/2];
    heap[(nodeIndex - 1)/2] = temp;
    repairUpward((nodeIndex - 1)/2);
  }
}

void Heap :: repairDownward(int nodeIndex){ 
  int leftChild = 2*(nodeIndex) + 1;
  int rightChild = 2*(nodeIndex) + 2;
  int smallest = nodeIndex;
  
 
  //leftChild comparison
  if(leftChild < currentSize && heap[leftChild] < heap[nodeIndex]){
    smallest = leftChild;
  }

  //rightChild comparison
  if(rightChild < currentSize && heap[rightChild] < heap[smallest]){
    smallest = rightChild;
  }

  //swap with lesser value and call repairDownward recursively 
  if(smallest != nodeIndex){
    int temp = heap[nodeIndex];
    heap[nodeIndex] = heap[smallest];
    heap[smallest] = temp;
    
    repairDownward(smallest);
  }
}
