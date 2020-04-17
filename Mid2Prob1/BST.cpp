#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
#include "BST.hpp"
#define COUNT 10

Node* BST:: createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* BST:: addNodeHelper(Node* currNode, int data)
{
    if(currNode == NULL){
        return createNode(data);
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
    }
    return currNode;

}

//helper function to get the minimum value from the tree 
Node* getMinValueNode(Node* currNode){

    if(currNode->left == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->left);
}

Node* BST::deleteNodeHelper(Node *currNode, int value)
{

  if(currNode == NULL)
  {
    return NULL;
  }
  else if(value < currNode->key)
  {
    currNode->left = deleteNodeHelper(currNode->left, value);
  }
  else if(value > currNode->key)
  {
    currNode->right = deleteNodeHelper(currNode->right, value);
  }
  // We found the node with the value
  else
  {
    //TODO Case : No child
    if(currNode->left == nullptr && currNode->right == nullptr)
    {
        delete currNode;
        return nullptr;
    }
    //TODO Case : Only right child
    else if(currNode->left == nullptr)
    {
        Node *record = currNode -> right;
        delete(currNode);
        return record;
    }
    //TODO Case : Only left child
    else if(currNode->right == nullptr)
    {
        Node *record = currNode -> left;
        delete currNode;
        return record;
    }
    //TODO Case: Both left and right child
    else
    {
        //Replace with Minimum from right subtree
        Node *temp = getMinValueNode(currNode->right);
        currNode -> key = temp->key;
        currNode -> right = deleteNodeHelper(currNode->right, temp->key);
        //delete temp;
        return currNode;
    }

  }
return currNode;
}

Node* BST::searchKeyHelper(Node* currNode, int data){
    if(currNode == NULL)
        return NULL;

    if(currNode->key == data)
        return currNode;

    if(currNode->key > data)
        return searchKeyHelper(currNode->left, data);

    return searchKeyHelper (currNode->right, data);
}

void BST:: printTreeHelper(Node* currNode){
     if(currNode)
     {
        printTreeHelper( currNode->left);
        cout << " "<< currNode->key;
        printTreeHelper( currNode->right);
     }
 }

void BST::print2DUtilHelper(Node *currNode, int space)
{
    // Base case
    if (currNode == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}

void BST:: addNode(int data)
{
    addNodeHelper(root, data);
    cout<<data<<" has been added"<<endl;
}

void BST:: deleteNode(int data)
{
    deleteNodeHelper(root, data);
    cout<<data<<" has been deleted"<<endl;
}

bool BST::searchKey(int key){
    Node* tree = searchKeyHelper(root, key);
    if(tree != NULL) {
        return true;
    }
    cout<<"Key not present in the tree"<<endl;
    return false;
}

void BST:: printTree(){
     printTreeHelper(root);
     cout<<endl;
}

BST::BST()
{

}

BST::BST(int data)
{
    root = createNode(data);
    cout<< "New tree created with "<<data<<endl;
}

//helper for destructor
void destroyNode(Node *currNode){
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = NULL;
     }
 }
 
BST::~BST(){
     destroyNode(root);
}

void BST::print2DUtil( int space)
{
  print2DUtilHelper(root, space);
}

void BST :: postorderHelper(Node *root){
   if (root != NULL ){
		postorderHelper(root->left);
		postorderHelper(root->right);
		cout << root->key << endl;
	}
}

void BST :: printPostOrder(){
    postorderHelper(root);
}

void BST :: preorderHelper(Node *root){
	if (root != NULL ){
		cout << root->key << endl;
		preorderHelper(root->left);
		preorderHelper(root->right);
	}
}

void BST :: printPreOrder(){
    preorderHelper(root);
}

//private class to access root
int BST :: sumRange(Node *root, int min, int max){
    if(root == NULL){
        return 0;
    }
    
    if (root->key <= max && root->key >= min){
        return (root->key) + sumRange(root->left, min, max) + sumRange(root->right, min, max); 
    }
    else if (root->key < min){
        return sumRange(root->right, min, max);
    }
    else{
        return sumRange(root->left, min, max);
    }
    
}

//call this one in the main!
int BST :: sumRangeHelper(int min, int max){
    int number;
    number = sumRange(root, min, max);
    return number;
}
