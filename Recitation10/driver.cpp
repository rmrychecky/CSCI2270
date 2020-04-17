#include "MinHeap.hpp"
using namespace std;

float * heapSort(float arr[], int size){
  MinHeap heap(size);
  for(int i = 0; i < size; i++){
    heap.insertElement(arr[i]);
  }
  
  //heap.printHeap();
  
  
  float val;
  for(int j = 0; j < size; j++){
    
    val = heap.extractMin();
    cout << val << endl;
    arr[j] = val;

  }
 
  return arr;

}

int main()
{
  // MinHeap heap(7);
  // heap.insertElement(25);
  // heap.insertElement(14);
  // heap.insertElement(16);
  // heap.insertElement(13);
  // heap.insertElement(10);
  // heap.insertElement(18);
  // heap.insertElement(12);

  // cout<<"***********Elements in the heap are **********"<<endl;
  // heap.print();
  // cout<<endl;

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
  float arr[5] = {1.2,10.5,5,15,20.7};
  int size = 5;
  
  // float *returnarr[size];

   heapSort(arr, size);

  // for(int i = 0; i < size; i++){
  //   cout << &(returnarr[i]) << " " << endl;
  // } 
  
  cout<<endl;
  return 0;
}
