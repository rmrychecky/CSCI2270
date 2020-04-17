#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

struct Node{
     int data; //struct that will hold an int data value and have head/next pointers
     struct Node *next;
     struct Node *head;
};

Node* Insert(Node *head, int data) //insert Nodes into my linked list through this function
{
    // Creates a temp to hold the last node and set last's data and next
    Node *last = new Node;

    last->data = data;
    last->next = NULL;

    // If the linked list is empty then set head = last
    if (head == NULL) {
        head = last;
    } 
    else {
        // Creates a temp node and sets it to head
        Node *temp = new Node;

        temp = head;

        // Uses temp to find the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Appends the last node with last
        temp->next = last;
    }

    // Returns head of linked list
    return head;
}

void print(Node *head){ //I have a print list to check the Nodes are being inserted
  
  Node *current = head;
  int count = 0;
  //cout << "Display entire linked list: " << endl;
  
  while (current!=nullptr){
    cout << "node " << count++ << current->data << endl;
    current = current->next;
  }

}

bool isNumber(string s) //make sure it is a number
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

void splitList(Node *head){
    Node *temp = head;
    Node *even = new Node;
    even->head = nullptr;
    Node *odd = new Node;
    odd->head = nullptr;
    
    if(temp == NULL){
        cout << "No integers in list." << endl;
        return;
    }
    else{
        while (temp != NULL){
        if (temp->data % 2 == 0){
            even = Insert(even, temp->data);
        }
        else if (temp->data % 2 != 0){
            odd = Insert(odd, temp->data);
        }
        temp = temp->next;
        }
        cout << "Even list:" << endl;
        print(even);
        cout << "Odd list:" << endl;
        print(odd);
    }

}


int main(){
  //ask the user to input values to create the linked list
  string input;
  string input1;
  bool result;
  int sum;
  Node *head = new Node; //this is the head of the new linked list
  head = NULL;
  
  //i am using input user to do my test cases. In my output.txt file, you will see each of the test cases I performed!
  cout << "Please enter integers to insert into the linked list. Once you are done entering values, enter NULL to indicate the linked list is done." << endl;
  getline(cin, input1);
  while((!isNumber(input1) && input1 != "NULL") || (input1 == "" && input1 != "NULL")){
      cout << "Invalid input please enter an integer" << endl;
      getline(cin, input1);
  }
  if(input1 != "NULL" && isNumber(input1) ){ //make sure input isn't NULL or a number
    head = Insert(head, stoi(input1)); //insert the converted string value to the linked list
  }
  while (input1 != "NULL" && input != "NULL" && isNumber(input1) && isNumber(input)){ //make sure input isn't NULL or a number
    cout << "Please enter integers or NULL"<< endl;
    getline(cin, input); //use getline to take input from the user
   while((!isNumber(input) && input != "NULL") || (input == "" && input != "NULL")){
      cout << "Invalid input please enter an integer" << endl;
      getline(cin, input);
    }
    if(input != "NULL"){ //check if the user has typed NULL
    head = Insert(head, stoi(input)); //make sure to change the string value to an integer value before inserting it to the linked list
    }
  }

  cout << "Original List:" << endl;
  print(head);
  splitList(head);

  return 0;
}

//TEST CASES
//test normal ist
//test empty list
//check just even list
//check just odd list
//check if the entered values are not integers