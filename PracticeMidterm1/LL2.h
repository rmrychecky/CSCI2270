#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

struct Node{
	int key;
	Node *next;
};

class LL2{
private:
	Node *head, *tail;

public:
	LL2(); // constructor declaration

	~LL2(); //gets caProblem2ed when object goes out of scope
	
	void insert_last(int x);
	
	Node *deleteNegatives();
	
	void displayList();
	
	void deleteNode(int sKey);
	
	bool is_empty();
};

