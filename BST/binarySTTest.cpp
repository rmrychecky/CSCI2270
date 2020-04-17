#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

#include "binaryST.h"


int main(){
	BinaryST bst0;

	bst0.insert( 19 );
	bst0.insert( 17 );
	bst0.insert( 14 );
	bst0.insert( 21 );
	bst0.insert( 7 );
	bst0.insert( 15 );
	bst0.insert( 12 );


/*  
        9
       /  \ 
      2   10
     / \    \
    0   7   10
*/

	// cout << "display in-order: " << endl;
	// bst0.disp("in-order");
	// cout << "display post-order: " << endl;
	// bst0.disp("post-order");

	// Node *sNode = bst0.search(45);
	// if(sNode!=nullptr){
	// 	cout << "skey: " << sNode->key << endl; //make sure its not a nullptr before trying to print it out
	// }
	Node *root = root;
	
	
	int returnVAlue =	bst0.findSum(root, 0);
	
	int depth = maxDepth(root);
	cout << depth << endl;

	return 0;
}


