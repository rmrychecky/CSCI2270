#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

struct Node
{
	int key;
	Node *parent;
	Node *leftChild;
	Node *rightChild;
};

class BinaryST
{
private:
	Node *root;
	// create these as private functions so that root can be abstracted from the user
	void dispPreOrd( Node *n );
	void dispInOrd( Node *n );
	void postorder(Node *n);
	Node* searchRecur( Node *n , int searchKey );
	Node* getMin( Node *n );
	int findSum(Node *n, int depth);

public:
	BinaryST(); // constructor declaration
	//~BinaryST();
	void insert( int newValue );
	void disp( string Order );
	Node* search( int value );
	Node* findMin();

	void deleteNode( int value );


};

