// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// struct Distance
// {
//   int feet;
//   int inch;
// };

// int main()
// {
//   Distance d;
//   Distance* ptr;
//   d.feet=8;
//   d.inch=6;
  
//   ptr = &d; //store address of d in p
//   cout << "Distance=" << ptr -> feet << "ft" << ptr->inch << "inches"; //This gives the values of 8 and 6
//   return 0;
// }

// #include <iostream>
// using namespace std ;
// void add2 ( int num)
// {
// num = num + 2 ;
// }
// int main ()
// {
// int a = 10 ;
// add2(a) ;
// cout << a;
// }

// //cout is 10


#include <iostream>
using namespace std;

void add2 (int* num)
{
  *num = *num + 2 ;
}
int main ()
{
  int a = 10 ;
  add2( &a );
  cout << a;
}

//cout is 12 through use of pointers


1. Consider an array int a[] = {1, 2, 3}. What is the output for the following?
a. cout << a+2; //address of 3
b. cout << *(a+2); //3
c. cout << *a; //1
d. cout << *a[0]; //address of 1