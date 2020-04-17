#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

struct Node{
	string key;
	Node *next;
};


class LL{
private:
	Node *head, *tail;

public:
	LL(); // constructor declaration

	~LL(); //gets called when object goes out of scope
  //Use to deallocate all the linked nodes

	Node* search(string sKey);
	// Precodndition: sKey parameter is a string type

	// Postcondition:  if found, returns a pointer to the node containing sKey value.
	// If not found, returns a null pointer.

	void appendNode(Node *head, string newItem);
	// Precondition: newItem is a valid string.

	// Postcondition: a new node is created. The new node is appended to the end
	// of the existing list. If the list is empty prior to call, new node becomes
	// the head.

	void insert_end(string newKey);
	
	void displayList();
	// Precondition: the head node is defined.

	// Post condition: display the key values of the entire list, starting with 
	// first node and ending with last node.

	void deleteNode(string sKey);
	// Precondition: head and tail pointers are set.

	// Post condition: node where with a matching key value is deleted. 
	
	bool lengthIsEven();

};

