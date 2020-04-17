#include<iostream>
#include<time.h>
#include <queue>
#include <algorithm>

using namespace std;

const int ARRAY_SIZE = 40e3;



// A class for Min Heap
class MinHeap
{
    public:
        MinHeap(int capacity);
        ~MinHeap();
        void push(int k);
        int pop();
        int peek() { return heap[1]; }
        void printHeap();
    private:
        int *heap; // pointer to array of elements in heap
        int capacity; // maximum possible size of min heap
        int currentSize; // Current number of elements in min heap      
        void MinHeapify(int index);
        int parent(int i) { return (i-1)/2; }
        int left(int i) { return (2*i+1); }
        int right(int i) { return (2*i + 2); }
        void swap(int &x, int &y);
};
 
MinHeap::MinHeap(int cap)
{
    currentSize = 0;
    capacity = cap; 
    heap = new int[capacity];
}

MinHeap::~MinHeap()
{
    delete [] heap;
}
 
void MinHeap::push(int k)
{
    if(currentSize == capacity){
        cout << "at capacity, cannot insert key" << endl;
    }
    else{
        //writing inserted value to the end of the array
        currentSize++;
        int i = currentSize-1;
        heap[i] = k;
        
        //fix the min heap property if it is violated
        while(i!=0 && heap[parent(i)] > heap[i]){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
        
    }
}
 
// for now, just return -1 if there's nothing to pop
int MinHeap::pop() //LOOK HERE FOR HOMEWORKS
{
    if(currentSize <= 0){
        return -1;
    }
    if(currentSize == 1){
        currentSize--;
        return heap[0];
    }
    
    int poppedVal = heap[0];
    //minHeapify 
    heap[0] = heap[currentSize - 1];
    currentSize--;
    MinHeapify(0);

    return poppedVal;
}
 
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i) //ALSO CHECK FOR HOMEWORKS
{
    int leftChild = left(i);
    int rightChild = right(i);
    int smallest = i;
    
    if(leftChild < currentSize && heap[leftChild] < heap[i]){//make sure your not reading something out of bounds
        smallest = leftChild;
    } 
    if(rightChild < currentSize && heap[rightChild] < heap[smallest]){
        smallest = rightChild;
    }
    
    //check if the index was changed
    if(smallest != i){
        swap(heap[i], heap[smallest]);
        MinHeapify(smallest);
    }
}
 
void MinHeap::swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void MinHeap::printHeap() {
    cout << "The heap array is currently {";
    for (int i = 0; i < currentSize; i++) 
    {
        cout << heap[i];
        if (i < currentSize-1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}
 
 
 //this heapSort works too!!!!!
 
 
void heapSort(float arr[], int n) 
{ 
    MinHeap heap(n);
    
    //rearrange 
    for (int i = 0; i < n; i++) {
        heap.push(arr[i]);
    }
    
    for( int j = 0; j < n; j++){
        arr[j] = heap.pop();
    }
    
    for(int h = 0; h < n; h++){
        cout << arr[h] << " ";
    }
    
} 

int main()
{

    // ////////////////////////////////////////////////////////////////////////
    // // CREATE A TEST ARRAY OF RANDOM INTEGERS
    // int arr[ARRAY_SIZE];
    // for( int i = 0; i < ARRAY_SIZE; i++)
    //     arr[i] = rand()%1000;


    // // cout << "the array is: " << endl;

    // // for( int i = 0; i < ARRAY_SIZE; i ++ )
    // //     cout << arr[i] << " ";


    // int startTime, endTime;   
    // double execTime;

    // ////////////////////////////////////////////////////////////////////////
    // // TEST BUBBLE SORT

    // startTime = clock(); //write current system time to an int 

    // for ( int i = ARRAY_SIZE-1; i > 0; i-- )
    // {
    //     for ( int j = 0; j < i; j++ )
    //         if ( arr[j] > arr[j+1])
    //         {
    //             int temp = arr[j+1];
    //             arr[j+1] = arr[j];
    //             arr[j] = temp;
    //         }
    // }
    
    // endTime = clock();

    // execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;

    // cout << "bubble execution time: " << execTime << endl;

    // ////////////////////////////////////////////////////////////////////////
    // // TEST HEAP SORT

    // // Re-populate test array with random ints
    // for( int i = 0; i < ARRAY_SIZE; i++)
    //     arr[i] = rand()%1000;
        
    // MinHeap h0(ARRAY_SIZE);
    
    // startTime = clock();
    
    // //write array elements to the heap
    // for( int i = 0; i < ARRAY_SIZE; i++){
    //     h0.push(arr[i]);
    // }
    
    // //h0.printHeap();
    
    // //pop the elemtns off into the array
    // for( int i = 0; i < ARRAY_SIZE; i++){
    //     arr[i] = h0.pop();
    // }

    // endTime = clock();
    
    // execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
    
    // for( int i = 0; i < ARRAY_SIZE; i++){ //check if the sorting is working
    //     //cout << arr[i] << endl;
    // }

    // cout << "heap execution time: " << execTime << endl;
    
    // //TEST sort() from STL for sorting
    
    // //repopulate test array with random ints
    //  for( int i = 0; i < ARRAY_SIZE; i++)
    //     arr[i] = rand()%1000;
        
    // startTime=clock();
    // sort(arr, arr+ARRAY_SIZE);
    // endTime=clock();
    
    // execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
    // cout << "sort() execution time: " << execTime << endl;
    
    float arr[] = {1.2,10.5,5,15,20.7}; 
    int n = 5;
    
    heapSort(arr, n);
    
    return 0;
}