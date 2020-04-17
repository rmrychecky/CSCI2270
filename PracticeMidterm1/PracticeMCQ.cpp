#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

//POINTERS ******************************************************************************

//QUESTION 1
// int main(){
// int a =100, b=200;
// int *p=&a, *q=&b;
// p=q;
//   cout << b << endl;
//   cout << a << endl;
//   cout << p << endl;
//   cout << &b << endl;
//   cout << q << endl;
//   cout << &a << endl;
//   //p now points to b
//   return 0;
// }

//QUESTION 2
// struct Book {
//   string name;
// };

// int main(){
//   Book* b = new Book;
//   b->name = "book1";
//   cout << b->name << endl;
//   cout << (*b).name << endl;
// }
// //print out the same thing

//QUESTION 3
// int main(){
//   int c, *pc;
//   *pc = &c; 
//   //not correct way to point pc to c; pc = &c; is correct
// }

//QUESTION 4
// void Sum(int a, int b, int & c){
//   a = b + c;
//   b = a + c;
//   c = a + b;
// }
// int main(){
//   int x = 2, y =3;
//   Sum(x, y, y);
//   cout << x << " " << y;
//   return 0;
// }
// //outputs 2 15

//DYNAMIC MEMORY ******************************************************************************
//need to free memory or youll get memory leak and the system will run out of memory 

//QUESTION 1 *************************************** ask
// int main(){
//   int *a = new int;
//   *a = 7;
//   int *b = a;
//   delete a;
//   a=nullptr;
//   cout << &b << endl;
//   cout << &a << endl;
// }

//QUESTION 2 *************************************** ask
// int main() {
//   int * p = new int;
//   delete p;
//   int * q = new int;

//   //yes there is memory leak because q is not freed
// }

//QUESTION 3  *************************************** ask
//How to create a dynamic array of pointers (to integers) of size 10?
// int *arr = new int [10];

//LINKED LISTS ******************************************************************************

// struct Node{
//   int key;
//   Node *next;
// };

// class List{
//   private:
//     Node *head;
//   public:
//     List(){
//       head = NULL;
//     }
//     int function_1();
//     int function_2();
// };

// Node* Insert(Node *head, int data)
// {
//     // Creates a temp to hold the last node and set last's data and next
//     Node *last = new Node;
//     last->key = data;
//     last->next = NULL;
//     // If the linked list is empty then set head = last
//     if (head == NULL) {
//         head = last;
//     } else {
//         // Creates a temp node and sets it to head
//         Node *temp = new Node;
//         temp = head;
//         // Uses temp to find the last node
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         // Appends the last node with last
//         temp->next = last;
//     }
//     // Returns head of linked list
//     return head;
// }

// //QUESTION 1
// int function_1(){
//   Node* temp1 = head;
//   Node* temp2 = head;
//   while(temp2 != NULL && temp2->next != NULL){
//     temp1 = temp1->next;
//     temp2 = temp2->next->next; 
//   }
//   return temp1->key;
//   //should return 4
// }

// //QUESTION 2
// int function_2(){
//   Node * temp = head;
//   head = head->next; 
//   delete temp;
//   int total = 0;
//   int count = 0;
//   Node * temp2 = head; 
//   while(temp2 != NULL){
//     total += temp2->key; 
//     count++;
//     temp2 = temp2->next;
//   }
//   //should return 19
// return total;
// }

// int main(){
//   Node *head = new Node;
//   head = nullptr;

//   head = Insert(head, 1);
//   head = Insert(head, 3);
//   head = Insert(head, 4);
//   head = Insert(head, 5);
//   head = Insert(head, 7);
  
//   int output;
//   output = function_1();
  
// }




