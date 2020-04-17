#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "BST.hpp"
using namespace std;

int main (int argc, char* argv[]){
  
  // BST tree(5);


  // tree.addNode(2); //left child to 5
  // tree.addNode(1); //left child to 1
  // tree.addNode(4); //right child to 2
  // tree.addNode(7); //right child to 5
  // tree.addNode(10); //right child of 7
  // tree.addNode(8); // left child of 10
  // tree.addNode(6); // left child of 7
  
  
  // BST tree(7);


  // tree.addNode(5); //left child to 5
  // tree.addNode(9); //left child to 1
  // tree.addNode(4); //right child to 2
  // tree.addNode(7); //right child to 5
  // tree.addNode(10); //right child of 7
  // tree.addNode(8); // left child of 10
  // tree.addNode(6); // left child of 7
  
  
  //TEST CASE 1
  BST tree(9);

  tree.addNode(7); //left child to 5
  tree.addNode(16); //left child to 1
  tree.addNode(4); //right child to 2
  tree.addNode(8); //right child to 5
  tree.addNode(11); //right child of 7

  
  
  
                  //        5
                    //  2        7
                    //1   4   6    10
                      //          8

  // cout<<"----------------Intial tree is ---------------"<<endl<<endl;
  // tree.print2DUtil(1);

  cout << "testing sum range helper on tree" << endl;
  cout  << tree.sumRangeHelper(8,12) << endl;
  cout << "testing sum range helper on tree" << endl;
  cout << tree.sumRangeHelper(100, 200) << endl;
  
  //TEST CASE 2
  BST tree1(0);

  cout << "testing sum range helper on tree1" << endl;
  cout  << tree1.sumRangeHelper(8,12) << endl;
  
  //TEST CASE 3
  
  BST tree2(4);
  
  tree2.addNode(2); 
  tree2.addNode(7); 
  
  cout << "testing sum range helper on tree2" << endl;
  cout << tree2.sumRangeHelper(8,10) << endl;
  
}
