#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

struct numberItem{
    int number;
};

struct counters{
    int capacity;
	  int currentSize;
	  int timesDoubled;
};


bool isFull(counters* tally){
  if(tally->capacity == tally->currentSize){
    return true;
  }
  else{
    return false;
  }
}

//PUSH WITH RESIZE BUT RETURNS A POINTER BECAUSE IS DUMB 
// numberItem* push(numberItem *arrPoint, int value, counters* tally){
//     if (isFull(tally)){
//     tally->currentSize = (tally->currentSize)*2;
    
//     // for(int i = 0; i < tally->capacity; i++){ 
//     //   cout<< arrPoint[i].number;
//     // }
//     // cout<<endl;
    
//     numberItem *copyArray = new numberItem[tally->currentSize]; //make a temp array double the size
//     for(int i = 0; i < tally->capacity; i++){ 
//       copyArray[i].number = arrPoint[i].number; //copy the values up to original array capacity 
//       cout << copyArray[i].number << endl;
//     }
  
//     delete []arrPoint; //deallocate the pointer wordItem array (original)
//     arrPoint = copyArray; //set that array to the copy 
//     //delete []copyArray;
  
//     //tally->currentSize = (tally->currentSize)*2; //now, set the current size to double
//     tally->timesDoubled = tally->timesDoubled + 1; //increment the number of times the array had to be doubled 
//   }
//   arrPoint[tally->capacity].number = value;
//     //capacity = capacity + 1 ;
//   tally->capacity = tally->capacity + 1;
//   return arrPoint;
// }

//VOID PUSH WITH RESIZE! WORKS
void push(numberItem **arrPoint, int value, counters* tally){
    if (isFull(tally)){
    tally->currentSize = (tally->currentSize)*2;
    
    numberItem *copyArray = new numberItem[tally->currentSize]; //make a temp array double the size
    for(int i = 0; i < tally->capacity; i++){ 
      copyArray[i] = (*arrPoint)[i]; //copy the values up to original array capacity 

    }
  
    delete[] *arrPoint; //deallocate the pointer wordItem array (original)
    *arrPoint = copyArray; //set that array to the copy 

    tally->timesDoubled = tally->timesDoubled + 1; //increment the number of times the array had to be doubled 
  }
  (*arrPoint)[tally->capacity].number = value;
    //capacity = capacity + 1 ;
  tally->capacity = tally->capacity + 1;
  //return arrPoint;
}

void pop (numberItem *arrPoint[], counters* tally){
  if (tally->capacity == 0){
    cout << "underflow error" << endl;
  }
  else{
    //capacity = capacity - 1;
    tally->capacity = tally->capacity - 1;
    if(tally->currentSize - tally->capacity == tally->capacity && tally->capacity >= 5){
      tally->currentSize = tally->capacity;
    }
  }
}

void print(numberItem arrPoint[], counters* tally){
  for (int i = 0; i < tally->capacity; i++){
    cout << arrPoint[i].number;
  }
  cout<<endl;
}

int main(){

  const int INITIAL_ARRAY_SIZE = 5; //the inital size of the array is 100 
  numberItem* arrPoint = new numberItem[INITIAL_ARRAY_SIZE]; //pointer array of type wordItem
  counters* tally = new counters;
 tally->currentSize = 5;
 tally->capacity = 0;
 tally->timesDoubled = 0;
 
  push(&arrPoint, 7, tally);
  push(&arrPoint, 7, tally);
  push(&arrPoint, 7, tally);
  push(&arrPoint, 7, tally);
  push(&arrPoint, 7, tally);
  push(&arrPoint, 7, tally);
  //arrPoint=push(arrPoint, 7, tally);

  print(arrPoint, tally);
  
  return 0;
}