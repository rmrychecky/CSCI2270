#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "BST.hpp"
using namespace std;

int main (int argc, char* argv[]){
  cout<<"Creating tree"<<endl;
  // BST tree(5);


  // tree.addNode(2); //left child to 5
  // tree.addNode(1); //left child to 1
  // tree.addNode(4); //right child to 2
  // tree.addNode(7); //right child to 5
  // tree.addNode(10); //right child of 7
  // tree.addNode(8); // left child of 10
  // tree.addNode(6); // left child of 7
  
  
  BST tree(7);


  tree.addNode(5); //left child to 5
  tree.addNode(9); //left child to 1
  tree.addNode(4); //right child to 2
  tree.addNode(7); //right child to 5
  tree.addNode(10); //right child of 7
  tree.addNode(8); // left child of 10
  tree.addNode(6); // left child of 7
  
  
  
                  //        5
                    //  2        7
                    //1   4   6    10
                      //          8

  cout<<"----------------Intial tree is ---------------"<<endl<<endl;
  tree.print2DUtil(1);

  cout<<"----------------Inorder traversal of the tree is ---------------"<<endl<<endl;
  tree.printTree();


  cout<<"----------------Final tree after deletion is ---------------"<<endl<<endl;
  tree.print2DUtil(1);

  cout<<"----------------Inorder traversal of the tree after deletion ---------------"<<endl<<endl;
  tree.printTree();
  
  
  cout<<"----------------Post order traversal of the tree after deletion ---------------"<<endl<<endl;
  tree.printPostOrder();
  
  cout<<"----------------Pre order traversal of the tree after deletion ---------------"<<endl<<endl;
  tree.printPreOrder();
}
