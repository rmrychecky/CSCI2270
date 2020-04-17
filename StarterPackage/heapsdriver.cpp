#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "heaps.hpp"
using namespace std;

int main()
{
  Heap heap(7);
  heap.addToHeap(25);
  heap.addToHeap(14);
  heap.addToHeap(16);
  heap.addToHeap(13);
  heap.addToHeap(10);
  heap.addToHeap(18);
  heap.addToHeap(12);

  cout<<"***********Elements in the heap are **********"<<endl;
  heap.printHeap();
  cout<<endl;

  cout << "Smallest element extracted is: "<<heap.removeFromHeap() <<endl<<endl;
  cout<<"***********Elements in the heap after extracting the smallest element**********"<<endl;
  heap.printHeap();
  cout<<endl;
  
  cout << "Smallest element extracted is: "<<heap.removeFromHeap() <<endl<<endl;
  cout<<"***********Elements in the heap after extracting the smallest element**********"<<endl;
  heap.printHeap();
  cout<<endl;
  
  cout<<endl;
  return 0;
}
