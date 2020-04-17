#include "MinHeap.hpp"
#include <array>
#include <iostream>
#include <cmath>
using namespace std;

float findKthNumber(float arr[], MinHeap &h){
    // for(int i = 0; i < h.getCurrentSize() - 1; i++){
    //   h.extractMin();
    // }
    // float returnValue = h.extractMin();
    return abs(h.extractMin());
}

int main()
{
  float array [4] = {5.4, 6.0, -17.3, 25.0};
  
  
  MinHeap heap(4);
  for (int i = 0; i < 4; i++){
    heap.insertElement(array[i]);
  }
  // heap.insertElement(25);
  // heap.insertElement(14);
  // heap.insertElement(16);
  // heap.insertElement(13);
  // heap.insertElement(10);
  // heap.insertElement(18);
  // heap.insertElement(12);

  cout<<"***********Elements in the heap are **********"<<endl;
  heap.print();
  cout<<endl;

  // cout << "Smallest element extracted is: "<<heap.extractMin() <<endl<<endl;
  // cout<<"***********Elements in the heap after extracting the smallest element**********"<<endl;
  // heap.print();
  // cout<<endl;
  
  // cout << "Smallest element extracted is: "<<heap.extractMin() <<endl<<endl;
  // cout<<"***********Elements in the heap after extracting the smallest element**********"<<endl;
  // heap.print();
  // cout<<endl;
  

  // int key = 15;
  // cout << "Deleting a key from the heap: "<<endl<<endl;
  // heap.deleteKey(key);
  // cout<<"***********Elements in the heap after deleting the key**********"<<endl;
  // heap.print();
  
  float number;
  number = findKthNumber(array, heap);
  cout << number << endl;
  
  cout<<endl;
  return 0;
}
