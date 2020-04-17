// #include <iostream>
// using namespace std;
// class Test{
//   int x;
// };
// int main(){
//   Test t;
//   cout << t.x;
//   return 0;
// }

// #include <iostream>
// using namespace std;

// void printArray(int **array, int array_size)
// {
//   for (int i = 0; i < array_size;i++)
//   {
//     //cout <<  **array+i   << endl;
//     //cout <<  *(*array+i)   << endl;
//     cout <<  (*array)[i]   << endl;
//   }
// }

// int main (int argc, char* argv[])
// {
//   int *a = new int[5];
//   int array_length = 5;
//   for (int i = 0; i < array_length; i++)
//   {
//     a[i] = i;
//   }
//   printArray(&a, array_length);
// }

// #include <iostream>
// using namespace std;
// int main(){
//   int x = 5;
//   int &y = x;
//   x = 20;
//   y = 10;
//   cout << x << "," << y << endl;
// }

// int* foo(int x){
// 	int *y = new int[x*x];
// 	return y;
// }
// int main(){
// 	int * z = foo(10);
// 	delete *z;
// 	return 0;
// }

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  int i;
  int *pi = &i;
  int *j = new int (1024);
  double *pd = new double[20];
  
  //delete i;
  // delete pi;
  //delete j;
  //delete pd;
  return 0;
}