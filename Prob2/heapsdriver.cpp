#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "heaps.hpp"
using namespace std;

float * heapSort(float arr[], int size){
  Heap heap(size);
  for(int i = 0; i < size; i++){
    heap.addToHeap(arr[i]);
  }
  
  heap.printHeap();
  heap.repairUpward(0);
  
  float val;
  for(int j = 0; j < size; j++){
    val = heap.removeFromHeap();
    arr[j] = val;
    
  }
 
  return arr;

}

int main()
{
  // Heap heap(7);
  // heap.addToHeap(25);
  // heap.addToHeap(14);
  // heap.addToHeap(16);
  // heap.addToHeap(13);
  // heap.addToHeap(10);
  // heap.addToHeap(18);
  // heap.addToHeap(12);

  // cout<<"***********Elements in the heap are **********"<<endl;
  // heap.printHeap();
  // cout<<endl;

  // cout << "Smallest element extracted is: "<<heap.removeFromHeap() <<endl<<endl;
  // cout<<"***********Elements in the heap after extracting the smallest element**********"<<endl;
  // heap.printHeap();
  // cout<<endl;
  
  // cout << "Smallest element extracted is: "<<heap.removeFromHeap() <<endl<<endl;
  // cout<<"***********Elements in the heap after extracting the smallest element**********"<<endl;
  // heap.printHeap();
  // cout<<endl;
  
  // cout<<endl;
  
  float arr[5] = {1.2,10.5,5,15,20.7};
  int size = 5;
  
  float *returnarr[size];

 *returnarr = heapSort(arr, size);

  cout << *(returnarr[0]) << endl;
  cout << *(returnarr[1]) << endl;
  
  // for(int i = 0; i < size; i++){
  //   cout << arr[i] << " " << endl;
  // }
  
  return 0;
}
