#include <iostream>
#include <vector>
using namespace std;

int main(){
  //declare a vector of ints
  //no need to specify size but can
  vector<int> v0;
  
  cout << "v0 length" << v0.size() << endl;
  
  v0 = {2, 2, 7, 0};
  cout << "v0 length" << v0.size() << endl;
  
  //with vectors we can append at the end
  //the container will automatically accommodate the size
  
  v0.push_back(9);
  cout << "v0 length" << v0.size() << endl;
  
  //can reduce the size of vector
  //takes off the last element 
  v0.pop_back();
  
  //to initalize size, just pass size to constructor
  vector<int> v1(7);
  
  //can also resize
  v1.resize(20);
  
  //print out the current size 
  cout << v1.capacity() << endl;
  
  return 0;
}