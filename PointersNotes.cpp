#include <iostream>
int main(int argc, char* argv[])
{
    char ch = 'a';
    char *cp; //cp is a pointer variable
    cp = &ch; //cp oints to the address of the ch
    cout << "Size of a pointer to char: " << endl;
    cout sizeof(char *) << endl;
    cout << "Address of ch is = " << (void *) cp;
    return 0;
}

int x = 3;
cout << &x;//just printing the address of x
cout << x << endl; //just print value in x
int *p = &x;
cout << *p << endl; //dereference operator
cout << p << endl; //will display address
//reopening the space in the heap to use

//if a pointer equals 0 it doesn't refer to an object
//uses heap instead of stack

//passing by reference
void myPassByRef(int &x);
int main()
{
    int a;
    myPassByRef(a);
    //whatever operation you perform on x persists 
}

//passing by pointer
void myPassByPointer(int *p);
int main()
{
    int *myPtr;
    myPassByPointer(myPtr);
    //or
    int x;
    myPassByPointer(&x);
}

//function can return a pointer type
int *foo(int x; float &y; int arr[], int *x) ;
// int x (pass by value/calls with non pointer type)
// float &y (by reference/caller gives access to original variable calls with non pointer type)
// int arr[] (caller gives address of first array element/alls with array type)
// int *x (by pointer caller gives address/calls with pointer type)
{
    int x = 3;
    int *p = &x;
    return p;
}

int main()
{
    int arr[5];
    int *p = arr; //points to first address of the array 

    int a = 4;
    float b = 31;
    int arr[6];

    int x;
    int *ptr = &x;

    foo(a, b, arr, ptr);
}


//we learned a pointer is descripbed by what type it points to
// ex. data_type *p;
//pointers can point to user defined types
//can define a struct and have a pointer that points to that type







 // program9.cpp Trevidi
#include<iostream>
int main(int argc, char* argv[]) 
{
    int* pa = 0; // pa is a pointer to integers
    int n;
    cout << "Enter dynamically allocated array size:"; 
    cin >> n;
    pa = new int[n];
    for (int i = 0; i < n; i++) 
    {
        pa[i] = i; 
    }
    // Use a as a normal array
    delete[] pa; // When done, free memory pointed to by a.
    pa = 0; //// Clear a to prevent using invalid memory reference. 
    return 0;
}


