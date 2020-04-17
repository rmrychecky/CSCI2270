#include <iostream>
using namespace std;

// struct Node {
//   int value;
//   struct Node* next;
// };

// int main() {
//   Node n1;
//   n1.value = 1;
//   n1.next = 0;
  
//   Node* n2 = 0;
//   n2 = &n1;
//   Node* n3 = new Node;
//   n3->value = 3;
  
//   Node* n4 = new Node;
//   (*n4).value = 4;
//   (*n4).next = &n1;
  
//   Node* n5 = n4;
//   n5->next = n2;
  
//   return 0;
// }

// struct Node {
//   int key;
//   Node *next;
// };

// Node *walker = head;
// int count = 0;
// while(walker!= NULL && count < 3) {
//         if(walker->key == 10) {
//                 count = count + 1;
//         }
//         walker = walker->next;
// }
// cout <<  walker->key  << endl;

// struct Node{
//   int data;
//   Node* next;
// };

// int deleteNode(int val){
//   Node *pres = head;
//   Node *prev = NULL;
  
//   while(pres->data != val){
//     prev= pres;
//     pres= pres->next;
//   }
//   prev->next = pres->next;
//   return 1;
// }

// struct node{
//   int key;
//   node *next;
// };

// int LinkedListFindMinimum(node *head){
//   node *temp = head;
  
//   int minValue = temp->key;
  
//   while (head != NULL){
//     if (temp->key < minValue){
//       minValue = temp->key;
//     }
//     temp = temp->next;
//   }
  
//   return minValue;
// }

// void initNode(struct node *head, int n){
//     head->key = n;
//     head->next = NULL;
// }

// void addNode(struct node *head, int n){
//     struct node *NewNode = new node;
//     NewNode-> key = n;
//     NewNode -> next = head;
//     head = NewNode;
// }

// int main(){
  
//   struct node *head = new node;
  
//   initNode(head, 9876);
//   addNode(head, 3);
//   addNode(head, 1000);
//   addNode(head, 100);
//   addNode(head, 3);
//   addNode(head, 9);
  
  
//   int output;
//   output = LinkedListFindMinimum(head);
//   cout << output;
// }



struct node{
  int key;
  node *next;
};

node* reverse(node *head){
  node *current = head;
  node *previous = nullptr;
  node *next = nullptr;
  
  while (current != nullptr){
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  head = previous;
  return head;
}


void initNode(struct node *head, int n){
    head->key = n;
    head->next = NULL;
}

void addNode(struct node *head, int n){
    struct node *NewNode = new node;
    NewNode-> key = n;
    NewNode -> next = head;
    head = NewNode;
}

int main(){
  
  struct node *head = new node;
  
  addNode(head, 1);
  addNode((head->next), 2);
  addNode(((head->next)->next), 3);
  addNode((((head->next)->next)->next), 4);
  addNode(((((head->next)->next)->next)->next), 5);
  addNode((((((head->next)->next)->next)->next)->next), 6);
  
  reverse(head);
  
}

