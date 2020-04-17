#include "MovieTree.hpp"
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

MovieTree :: MovieTree(){
    root = NULL;
}

MovieTree :: ~MovieTree(){
    delete root;
}

struct MovieNode* searchRecursive(struct MovieNode* root, string title) //recursive search
{ 
    int i = 0;
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->title == title){ 
       return root; 
    }
    
   
    if(root->title[i] == title[i]){
        while(root->title[i] == title[i]){
            i++;
            if(root->title[i] < title[i]){
                return searchRecursive(root->rightChild, title); 
            }
            else if(root->title[i] > title[i]){
                return searchRecursive(root->leftChild, title); 
            }
        }
    }
    else if (root->title[i] < title[i]){ 
       // Key is greater than root's key 
       return searchRecursive(root->rightChild, title); 
    }
    else{
        // Key is smaller than root's key 
        return searchRecursive(root->leftChild, title); 
    }
    
} 

MovieNode* MovieTree :: search(string title){
    return searchRecursive(root, title);
}

void dispInOrd( MovieNode *n )
{
    if (n == NULL) 
        return; 
        
	if(n->leftChild != nullptr){
		dispInOrd(n->leftChild);
	}
	cout << "Movie: " << n->title << " " << n->rating << endl;
	if(n->rightChild != nullptr){
		dispInOrd(n->rightChild);
	}
}

void MovieTree :: printMovieInventory(){
    MovieNode *n = root;
    dispInOrd(n);
}

void MovieTree :: addMovieNode(int ranking, string title, int year, float rating)
{	
	//create a pointer to keep track of previous node
	MovieNode *prev = nullptr;
	//create a pointer to traverse the tree. Say start with Root
	MovieNode *temp = root;
	//create a new node
	MovieNode *n = new MovieNode;
	//set all pointers inside n to null. Write new value to the key.
	n->parent = nullptr;
	n->leftChild = nullptr;
	n->rightChild = nullptr;
	n->ranking = ranking;
	n->title = title;
	n->year = year;
	n->rating = rating;
	
	//loop until we find first empty spot in the tree
	//if the tree is empty then the root will be null and the loop will not get executed once
	while(temp != nullptr){
		//set prev to temp to keep track of the last node
		prev = temp;
		//check which way to go
		if(n->title < temp->title){
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
	else if(n->title < prev->title){
		prev->leftChild = n;
		n->parent = prev;
	}
	else{
		prev->rightChild = n;
		n->parent = prev;
	}
}

void MovieTree :: findMovie(string title){
    MovieNode *found = new MovieNode;
    found = search(title);
    if(found != NULL){
        cout << "Movie Info:" << endl;
        cout << "==================" << endl;
        cout << "Ranking:" << found->ranking << endl;
        cout << "Title  :" << found->title << endl;
        cout << "Year   :" << found->year << endl;
        cout << "rating :" << found->rating << endl;
    }
    else{
        cout << "Movie not found." << endl;
    }
}

void printPreorder(MovieNode* node, float rating, int year) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    if(node->rating >= rating && node->year > year){
        cout << node->title << "(" << node->year << ") " << node->rating << endl;
    }
    
    /* then recur on left sutree */
    printPreorder(node->leftChild, rating, year);  
  
    /* now recur on right subtree */
    printPreorder(node->rightChild, rating, year); 
} 

void MovieTree :: queryMovies(float rating, int year){ //****** LAST THING TO DO
    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
    
    MovieNode *traverse = root;
    printPreorder(traverse, rating, year);

}

float sumRatings(MovieNode *n){
    if (n == NULL) 
        return 0; 
    return (n->rating + sumRatings(n->leftChild) + sumRatings(n->rightChild)); 
}

int size(MovieNode *n){
    if(n == NULL)
        return 0;
        
    int num = 0;
    num++; //add one for the root
    num += (size(n->leftChild) + size(n->rightChild));
    return num;
}

void MovieTree :: averageRating(){ 
    
    MovieNode *n = root;
    float average = 0.0;
    int numEntries = 0;
    float sum = 0;
    
    if (n == NULL){
        cout << "Average rating:0" << endl;
        return;
    }
    
    sum = sumRatings(n);
    numEntries = size(n);
    average = sum/numEntries;

	cout << "Average rating:" << average << endl;
}
