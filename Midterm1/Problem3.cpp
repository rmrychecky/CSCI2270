#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

struct Node{
     int data; //struct that will hold an int data value and have head/next pointers
    //  struct Node *head;
     struct Node *next;
     struct Node *tail;
};

Node* insertEnd(Node *tail, int data) //insert Nodes into my linked list through this function
{
    // Creates a temp to hold the last node and set last's data and next
    Node *last = new Node;

    last->data = data;
    last->next = NULL;

    // If the linked list is empty then set head = last
    if (tail == NULL) {
        tail->next = last;
    } 
    else {
        // Creates a temp node and sets it to head
        Node *temp = new Node;

        temp = tail;

        // Uses temp to find the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Appends the last node with last
        temp->next = last;
    }

    // Returns head of linked list
    return tail;
}


void print(Node *tail){ //I have a print list to check the Nodes are being inserted
  
  Node *current = tail;
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

int numNodes(Node* tail){
    int num = 0;
    Node *temp = tail;
    while(temp->next != nullptr){
        num++;
    }
    return num;
}

Node* shift(Node *tail, int n){
    int numberNodes;
    int nMod = n;
    numberNodes = numNodes(tail);
    if(numberNodes < n){
        nMod = numberNodes;
    }

        Node *prev = tail;
        Node *temp = tail->next;
        for (int i = 0; i < nMod; i++){
            tail->next = prev;
            temp = temp->next;
            tail = tail->next;
        }
    delete temp;
    return tail;
}


int main(){
  //ask the user to input values to create the linked list
  string input;
  string input1;
  bool result;
  int sum;
  Node *tail = new Node; //this is the head of the new linked list
  //tail->next = NULL;

 //i am using input user to do my test cases. In my output.txt file, you will see each of the test cases I performed!
  cout << "Please enter integers to insert into the linked list. Once you are done entering values, enter NULL to indicate the linked list is done." << endl;
  getline(cin, input1);
  while((!isNumber(input1) && input1 != "NULL") || (input1 == "" && input1 != "NULL")){
      cout << "Invalid input please enter an integer" << endl;
      getline(cin, input1);
  }
  if(input1 != "NULL" && isNumber(input1) ){ //make sure input isn't NULL or a number
    tail = insertEnd(tail, stoi(input1)); //insert the converted string value to the linked list
  }
  while (input1 != "NULL" && input != "NULL" && isNumber(input1) && isNumber(input)){ //make sure input isn't NULL or a number
    cout << "Please enter integers or NULL"<< endl;
    getline(cin, input); //use getline to take input from the user
   while((!isNumber(input) && input != "NULL") || (input == "" && input != "NULL")){
      cout << "Invalid input please enter an integer" << endl;
      getline(cin, input);
    }
    if(input != "NULL"){ //check if the user has typed NULL
    tail = insertEnd(tail, stoi(input)); //make sure to change the string value to an integer value before inserting it to the linked list
    }
  }
  
  cout << "Original List:" << endl;
  print(tail);
  tail = shift(tail, 1);
  cout << "Shifted List:" << endl;
  print(tail);

  return 0;
}

