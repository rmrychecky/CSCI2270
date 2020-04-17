#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
#include "Stack3.h"

Stack3 :: Stack3(){
  capacity = 0;
  currentSize = 5;
  timesDoubled = 0;
}

bool Stack3 :: isFull(){
  if(capacity == currentSize){
    return true;
  }
  else{
    return false;
  }
}

void Stack3 :: push(int value){
  if (!isFull()){
    arrPoint[capacity].number = value;
    capacity = capacity + 1 ;
  }
  else if (isFull()){
    numberItem *copyArray = new numberItem[currentSize*2]; //make a temp array double the size
    for(int i = 0; i < capacity; i++){ 
      copyArray[i] = arrPoint[i]; //copy the values up to original array capacity 
    }
    delete []arrPoint; //deallocate the pointer wordItem array (original)
    arrPoint = copyArray; //set that array to the copy 
                        
    currentSize = currentSize*2; //now, set the current size to double
    timesDoubled ++; //increment the number of times the array had to be doubled 
    arrPoint[capacity].number = value;
    capacity = capacity + 1 ;
  }
}

void Stack3 :: pop (){
  if (capacity == 0){
    cout << "underflow error" << endl;
  }
  else{
    capacity = capacity - 1;
    if(currentSize - capacity == capacity && capacity >= 5){
      currentSize = capacity;
    }
  }
}

void Stack3 :: print(){
  for (int i = 0; i < capacity; i++){
    cout << arrPoint[i].number << endl;
  }
}