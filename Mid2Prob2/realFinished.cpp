#include <iostream> 
  
using namespace std; 
  
//heapify with i being where to start, and n being the size of the array
void heapify(float arr[], int n, int i) //modified from hpp implementation files given in advance 
{ 
    int big = i; 
    int left = 2*i + 1; 
    int right = 2*i + 2; 
  

    if (left < n && arr[left] > arr[big]) 
        big = left; 
  
    if (right < n && arr[right] > arr[big]) 
        big = right; 

    if (big != i) 
    { 
        swap(arr[i], arr[big]); 
        heapify(arr, n, big); 
    } 
} 
  
// heap sorting function
//takes array and size
void heapSort(float arr[], int n) 
{ 
    //rearrange 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
  
//display array
void printArray(float arr[], int n) 
{ 
    for (int i=0; i<n; ++i){ 
        cout << arr[i] << " "; 
    }
    cout << endl;
} 
  
// Driver program 
int main() 
{ 
    float arr[] = {1.2,10.5,5,15,20.7}; 
    int n = 5;
  
    cout << "Array before any sort" << endl;
    printArray(arr, n); 
    
    heapSort(arr, n); 
  
    cout << "Sorted array is " << endl; 
    printArray(arr, n); 
    
    cout << endl << endl;
    
    float arr1[] = {5}; 
    int n1 = 1;
    
    cout << "Array 2 before any sort" << endl;
    printArray(arr1, n1); 
    
    heapSort(arr1, n1); 
  
    cout << "Sorted array 2 is " << endl; 
    printArray(arr1, n1); 
    
    cout << endl << endl;
    
    float arr2[] = {30,8.2,34}; 
    int n2 = 3;
    
    cout << "Array 3 before any sort" << endl;
    printArray(arr2, n2); 
    
    heapSort(arr2, n2); 
  
    cout << "Sorted array 3 is " << endl; 
    printArray(arr2, n2); 
    
    cout << endl << endl;
    
    
} 