#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// void reset(int *ip)
// {
//   ip = 0;
// }

// int main()
// {
//   int i =100;
//   int *p = &i;
//   reset (p);
//   cout << "i : " << *p << endl;
  
//   int a[] = {1, 3, 5, 7};
//   cout << *(a+2) << endl;
// }

// void swap(int &v1, int &v2)
// {
//   int tmp = v2;
//   v2=v1;
//   v1=tmp;
// }

// int main()
// {
//   int i =10;
//   int j=20
  
//   cout << "Before swap() " << i << ":" << j << endl;
//   swap(i, j);
//   cout << "After swap() " << i << ":" << j << endl;
//   return 0;
// }

// int main()
// {
//   int a=100, b=200, c=50, *pa=&a, *pb=&b, *pc=&c;
//   *pa = *pa + *pb + *pc;
//   *pb=100;
//   pb=pa;
//   pc=pb;
//   cout << *pa << "," << *pb << "," << *pc << endl;
// }

int main()
{
  int m=1, n=2, *p=&m, *q=&n, *r;
  r=p;p=q;q=r;
  cout <<m<<","<<n<<","<<*p<<","<<*q<<endl;
}