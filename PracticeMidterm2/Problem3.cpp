#include "MinHeap.hpp"
#include <limits.h>
using namespace std;

/*
Swaps two integer values
*/
void swap(float *a, float *b)
{
  float temp = *a;
  *a = *b;
  *b = temp;
}

/*
Constructor for our MinHeap implementation
*/
MinHeap::MinHeap(int cap)
{
  currentSize = 0;
  capacity = cap;
  heapArr = new float[capacity];
}

/*
Finds the parent of a node, given its index.
*/
int MinHeap::parent(int index)
{
  return (index-1)/2;
}

/*
Returns the left child of a node.
*/
int MinHeap::leftChild(int index)
{
  return ((2*index) + 1);
}

/*
Returns the right child of a node.
*/
int MinHeap::rightChild(int index)
{
  return ((2*index) + 2);
}

/*
Returns the smallest element from the heap.
*/
int MinHeap::getMin()
{
  return heapArr[0];
}

// SILVER TODO : Complete this function
/*
To heapify a subtree with the root at given index
*/
void MinHeap::heapify(int i)
{
  int l = leftChild(i);
  int r = rightChild(i);
  int smallest = i;

  //TODO
  if(l < currentSize && heapArr[l] < heapArr[i]){
    smallest = l;
  }
  if(r < currentSize && heapArr[r] < heapArr[smallest]){
    smallest = r;
  }
  
  if(smallest != i){
    swap(heapArr[i], heapArr[smallest]);
    heapify(smallest);
  }


}

/*
Inserts an element into the heap by maintaining the heap property.
*/
void MinHeap::insertElement(float value)
{
  if(currentSize == capacity)
  {
    cout<<"Maximum heap size reached. Cannot insert anymore"<<endl;
    return;
  }

  currentSize = currentSize + 1;
  int index = currentSize - 1;
  heapArr[index] = value;

  while (index != 0 && heapArr[parent(index)] > heapArr[index])
    {
       swap(&heapArr[index], &heapArr[parent(index)]);
       index = parent(index);
    }
}

/*
Prints the elements in the heap
*/
void MinHeap::print()
{
  int iter = 0;
  while(iter < currentSize)
  {
    cout<<heapArr[iter]<<" ";
    iter = iter + 1;
  }
  cout<<endl;
}

// SILVER TODO : Complete this function
// Method to remove minimum element (or root) from min heap
float MinHeap::extractMin()
{
  if (currentSize <= 0)
      return INT_MAX;

  if (currentSize == 1)
  {
      currentSize--;
      return heapArr[0];
  }

  float minimum = heapArr[0];
  //remove element and min heapify (TODO done)
  heapArr[0] = heapArr[currentSize - 1];
  currentSize--;
  heapify(0);
  

  return minimum;

}

// GOLD TODO : Complete this function
// This function deletes a key
void MinHeap::deleteKey(float key)
{
  // there are many ways of doing it, one of them can be :
  // replace the key to be deleted with INT_MIN (a very small number), traverse it up to the root and then remove it!
  
  //first I find the index where the key we want to delete is 
  int i = 0;
  int indexKey;
  while(heapArr[i] != key){
    i++;
    if(heapArr[i] == key){
      indexKey = i;
    }
  }
  
  heapArr[indexKey] = -10; 
  while (indexKey != 0 && heapArr[parent(indexKey)] > heapArr[indexKey]) 
  { 
    swap(&heapArr[indexKey], &heapArr[parent(indexKey)]); 
    indexKey = parent(indexKey); 
  }

  extractMin();
}

int MinHeap::getCurrentSize(){
  return currentSize;
}