#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
#include "binaryST.h"

BinaryST::BinaryST()
{
	root = nullptr;
}

// Insert new node
void BinaryST::insert( int newValue )
{	
	//create a pointer to keep track of previous node
	Node *prev = nullptr;
	//create a pointer to traverse the tree. Say start with Root
	Node *temp = root;
	//create a new node
	Node *n = new Node;
	//set all pointers inside n to null. Write new value to the key.
	n->parent = nullptr;
	n->leftChild = nullptr;
	n->rightChild = nullptr;
	n->key = newValue;
	
	//loop until we find first empty spot in the tree
	//if the tree is empty then the root will be null and the loop will not get executed once
	while(temp != nullptr){
		//set prev to temp to keep track of the last node
		prev = temp;
		//check which way to go
		if(n->key < temp->key){
			temp = temp->leftChild;
		}
		else{ //if n->key is greater than or equal to
			temp = temp->rightChild;
		}
	}
	//at this point the parent has been found
	
	if(prev == nullptr){ //this is if the while loop never iterated aka tree was empty 
		root = n;
	}
	else if(n->key < prev->key){
		prev->leftChild = n;
		n->parent = prev;
	}
	else{
		prev->rightChild = n;
		n->parent = prev;
	}
}

void BinaryST::disp( string Order ) //public and can call dispPreOrd and dispInOrd with root!
{
	if(Order == "pre-order"){
		dispPreOrd(root);
	}
	else if(Order == "in-order"){
		dispInOrd(root);
	}
	else if(Order == "post-order"){
		postorder(root);
	}
}

void BinaryST :: postorder (Node *root){
	if (root != NULL ){
		postorder(root->leftChild);
		postorder(root->rightChild);
		cout << (root->key) << endl;
	}
}

void BinaryST::dispPreOrd( Node *n )
{

}

void BinaryST::dispInOrd( Node *n )
{
	if(n->leftChild != nullptr){
		dispInOrd(n->leftChild);
	}
	cout << n->key << endl;
	if(n->rightChild != nullptr){
		dispInOrd(n->rightChild);
	}
}

Node* BinaryST::search( int value )
{
	return searchRecur(root, value);
}

Node* BinaryST::searchRecur( Node *n , int searchKey )
{
	if(n != nullptr){
	cout << "node visited: " << n->key << endl; //cout debug statement; has to be in the if statement or else it tries to read the key of a nullptr which will give an error
		if(n->key == searchKey){
			return n;
		}
		else if(n->key > searchKey){
			return searchRecur(n->leftChild, searchKey);
		}
		else{
			return searchRecur(n->rightChild, searchKey);
		}
	}
	else{
		cout << searchKey << " not found" << endl;
		return nullptr;
	}
}

Node* BinaryST::findMin()
{
	return getMin(root);
}

Node* BinaryST::getMin( Node *n )
{
	while(n->leftChild != nullptr){
		n=n->leftChild;
	}
	return n;
}

void BinaryST::deleteNode( int value )
{
	Node *n = search(value); //find the node you ned to delete 
	
	//non-root case
	if(n != root){
		//1) the leaf case (n is a leaf node)
		 if(n->leftChild == nullptr && n->rightChild == nullptr){
		 	//go to parent node and update correct child pointer
		 	//check n's relationship to its parents
		 	//is n left child?
		 	if(n == n->parent->leftChild){
		 		n->parent->leftChild=nullptr; //no children so no rearranging 
		 	}
		 	//otherwise, n must be rightchild
		 	else{
		 		n->parent->rightChild = nullptr;
		 	}
		 }
		//2) the 2 children case
		else if(n->leftChild != nullptr && n->rightChild != nullptr){
		 	//find the min of the right subtree to replace the deleted node
		 	Node *min = getMin(n->rightChild);
		 	//if min is the right child of n (single node in right tree)
		 	if(min == n->rightChild){
		 		//make parent point to the min
		 		//check if node is left child
		 		if(n==n->parent->leftChild){
		 			n->parent->leftChild = min;
		 		}
		 		//otherwise it is a right child
		 		else{
		 			n->parent->rightChild =  min;
		 		}
				//make min point to the parent
				min->parent=n->parent;
				//make min point to n's old child
				min->leftChild=n->leftChild;
				//make old LC point to min
				min->leftChild->parent = min;
		 	}
		 	//otherwise, min is NOT the RC of n meaning it's somewhere in the right subtree
		 	else{
		 		//min's old RC takes min's spot
		 		min->parent->leftChild=min->rightChild;
		 		//new node needs to point back up to min's former parent
		 		if(min->rightChild != nullptr){
		 			min->rightChild->parent = min->parent;
		 		}
		 		
		 		//now, insert the min into n's old spot. 
		 		//check if node is LC
		 		if(n==n->parent->leftChild){
		 			n->parent->leftChild = min;
		 		}
		 		//otherwise it is the RC
		 		else{
		 			n->parent->rightChild = min;
		 		}
		 		
		 		min->parent=n->parent;
		 		min->leftChild=n->leftChild;
		 		min->leftChild->parent=min;
		 		min->rightChild=n->rightChild;
		 		min->rightChild->parent= min;
		 	}
		 }
		//3) the 1 child case
		else{
			// 1. The one child is a left child
			if(n->leftChild != nullptr){
				n->leftChild->parent = n->parent;
				//check if node is leftChild
				if(n == n->parent->leftChild){
					n->parent->leftChild = n->leftChild;
				}
				//otherwise it is the rightChild
				else{
					n->parent->rightChild = n->leftChild;
				}
			}
			//2. The one child is the right child
			else{
				n->rightChild->parent = n->parent;
				//check if node is leftChild
				if(n == n->parent->leftChild){
					n->parent->leftChild = n->rightChild;
				}
				//otherwise it is the rightChild
				else{
					n->parent->rightChild = n->rightChild;
				}
			}
		}
	}
	//root case
	else{
		
	}
	
	delete n;
	
}

int BinaryST :: findSum(Node * root, int depth)
{
    if(root != NULL)
    {
        int rightSum = findSum(root->rightChild, depth + 1);
        int leftSum = findSum(root->leftChild, depth + 1);
        cout << root->key;
        if (depth != 0)
        {
            cout << " ";
        }
        return rightSum + leftSum + root->key;
    }
    else
       return 0;
       
}