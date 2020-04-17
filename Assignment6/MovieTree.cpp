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



LLMovieNode* deleteLL(LLMovieNode* in)
{
while(in != NULL){
    LLMovieNode* temp = in;
    in = in -> next;
    delete temp;
}
return in;

}

TreeNode* deleteTree(TreeNode *check)
{
if(check == NULL){
    return NULL;
} 
deleteTree(check -> leftChild);
deleteTree(check -> rightChild);
deleteLL(check -> head);
delete check;
return check;
}

MovieTree::~MovieTree()
{
    root = deleteTree(root);
}

void displayList(LLMovieNode *m){
  //display the entire linked list under the BST node

  while (m!=nullptr){
    cout << " >> " << m->title << " " << m->rating << endl;
    m = m->next;
  }
}

void dispInOrd( TreeNode *n )
{
    if (n == NULL) 
        return; 
        
	if(n->leftChild != nullptr){
		dispInOrd(n->leftChild);
	}
	cout << "Movies starting with letter: " << n->titleChar << endl;
	//n->head = head; //what do you do here since there is not 
	displayList(n->head);
	if(n->rightChild != nullptr){
		dispInOrd(n->rightChild);
	}
}

void MovieTree :: printMovieInventory(){
    TreeNode *n = root;
    dispInOrd(n);
}



 










TreeNode* Search(TreeNode *root, char titleI)
{
	int depth = 0;
	TreeNode *temp = root;
	// Run the loop untill temp points to a NULL pointer.
	while(temp != NULL)
	{
		depth++;
		if(temp->titleChar == titleI)
		{
			return temp;
		}
		// Shift pointer to left child.
		else if(temp->titleChar > titleI)
			temp = temp->leftChild;
		// Shift pointer to right child.
		else
			temp = temp->rightChild;
	}

	return nullptr;
}

TreeNode* Search1(TreeNode *root, char titleI)
{
	TreeNode *temp = root;
	// Run the loop untill temp points to a NULL pointer.
	while(temp != NULL)
	{
		if(temp->head == nullptr)
		{
			return temp;
		}
		// Shift pointer to left child.
		else if(temp->titleChar > titleI)
			temp = temp->leftChild;
		// Shift pointer to right child.
		else
			temp = temp->rightChild;
	}

	return nullptr;
}

TreeNode* createNode(char data)
{
    TreeNode* newNode = new TreeNode;
    newNode->titleChar = data;
    newNode->parent = NULL;
    newNode->head = NULL;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

TreeNode* addNodeHelper(TreeNode* currNode, char data)
{
    
    if(currNode == nullptr)
    {
        return createNode(data);
    }
    else if(currNode->titleChar > data)
    {
        currNode->leftChild = addNodeHelper(currNode->leftChild, data);
    }
    else if(currNode->titleChar < data)
    {
        currNode->rightChild = addNodeHelper(currNode->rightChild, data);
    }
    //return currNode;
}


void MovieTree :: addMovie(int ranking, string title, int year, float rating){

    TreeNode *n = Search(root, title[0]);
    
   if (root == nullptr ){
        //add a TreeNode

        root = addNodeHelper(root, title[0]);
      
        //insert into the linked list
      if (root->head==nullptr){ //assume that if afterMe is an empty string, the node is made the head
        LLMovieNode *temp = new LLMovieNode; //create node
        temp -> title = title; //put correct value in
        temp ->ranking = ranking;
        temp ->year = year;
        temp->rating = rating;
        
        root->head = temp;

      }

    }
    else if(Search(root, title[0]) == nullptr){
      
        
        root = addNodeHelper(root, title[0]);
        TreeNode *addedNode = Search1(root, title[0]);
      
        
        if (addedNode->head==nullptr){ //assume that if afterMe is an empty string, the node is made the head
        LLMovieNode *temp = new LLMovieNode; //create node
        temp -> title = title; //put correct value in
        temp ->ranking = ranking;
        temp ->year = year;
        temp->rating = rating;
    
        addedNode->head = temp;

        }
    }
    else if (root != nullptr && Search(root, title[0]) != nullptr){
        
        LLMovieNode * temp = new LLMovieNode;
        temp -> title = title; //put correct value in
        temp ->ranking = ranking;
        temp ->year = year;
        temp->rating = rating;
        
       
        LLMovieNode *traverse = n->head;
        LLMovieNode *previous = nullptr;
     
        if(traverse->title > temp->title){
            temp->next = n->head;
            n->head = temp;
        }
        else{
            while (traverse->next != nullptr && traverse->next->title < temp->title){
                previous = traverse;
                traverse = traverse->next;
            }
            temp->next=traverse->next;
            traverse->next = temp;
        }
    }

}
















TreeNode* getMaxValueHelper(TreeNode* curNode)
{
    if(curNode == NULL){
        return curNode;
    }
    if(curNode -> rightChild == NULL){
        return curNode;
    }    
    return getMaxValueHelper(curNode->rightChild);
}

TreeNode* deleteNodeHelper(TreeNode* curNode, char titleI)
{
    //search key in tree
    if(curNode == NULL){
        cout <<  "Key doesn't exist" << endl;
        return NULL;
    }
    else if(curNode -> titleChar > titleI){
        curNode -> leftChild = deleteNodeHelper(curNode->leftChild, titleI);
    }
    else if(curNode -> titleChar < titleI){
        curNode -> rightChild = deleteNodeHelper(curNode->rightChild, titleI);
    }
    else{
        //No children 
        if(curNode->leftChild == NULL && curNode->rightChild == NULL){
            delete curNode;
            curNode = NULL;
        }
        //check for only right subtree
        else if(curNode -> leftChild == NULL){
            TreeNode* temp = curNode -> rightChild;
            delete curNode;
            curNode = temp;
        }
        //check  for only left subtree
        else if(curNode -> rightChild == NULL){
            TreeNode* temp = curNode -> leftChild;
            delete curNode;
            curNode = temp;
        }
        else{
        //if both left and right subtree exist
        //replace deleted node with maximum value in left subtree
        TreeNode *maxtitleChar = getMaxValueHelper(curNode -> leftChild); //int minval = getMinValue(curNode-> right);
        curNode -> titleChar = maxtitleChar -> titleChar;
        curNode -> head = maxtitleChar -> head;
        curNode -> leftChild = deleteNodeHelper(curNode-> leftChild, maxtitleChar->titleChar); //curNode-> right = deleteNodeHelper(curNode-> right, minValue);
        }
    }
   
    return curNode;
}
//search LL for movie title
LLMovieNode* searchLL(LLMovieNode *top, string movie){
    LLMovieNode *returnMovie = nullptr;
    LLMovieNode *tmp = top;
    
    bool found = false;
    
    while (!found && tmp!= nullptr){
        if (tmp->title==movie){
            found = true;
            returnMovie = tmp; //just returning the address
             
        }
        else{
            tmp = tmp -> next; //otherwise continue to traverse
        }
    }
   
    return returnMovie; //if nothing is ever found then nullptr is returned
}
 
void MovieTree :: deleteMovie(string title){
    //cout << "1" << endl;
    TreeNode *n = Search(root, title[0]);
    LLMovieNode *movie1;
    if(n != nullptr){
        movie1 = searchLL(n->head, title);
    }
   //cout << "2" << endl;
    if(n == nullptr){ //if there is no tree node then the movie cannot be found 
        cout << "Movie: " << title << " not found, cannot delete." << endl;
        //cout << "3" << endl;
    }
    else if(n->head->next == nullptr && n->head->title == title){ //if there is a tree node with just one movie in the linked list
        //delete the LLMovieNode 
        delete n->head;
        n->head = nullptr;
        //cout << "hello" << endl;
        //delete the TreeNode
        //cout << title << endl;
        root = deleteNodeHelper(root, title[0]);
        
    }
    else{ //just delete the LLMovieNode from the linked list
        //delete the LLMovieNode
        //cout << "deleting from LL" << endl;
       
        LLMovieNode *tmp;
        if(n->head->title == title){
            tmp=n->head;
            n->head=tmp->next;
            delete tmp;
        }
        else{
            bool found = false;
            LLMovieNode *last = n->head;
            tmp=n->head->next;
            while(!found && tmp!=nullptr){
                if(tmp->title==title){
                    found = true;
                }
                else{
                    last = tmp;
                    tmp=tmp->next;
                }
            }
            if(found){
                if(tmp->next == nullptr){
                    last->next = nullptr;
                }
                else{
                    last->next = tmp->next;
                }
                delete tmp;
                //delete last;
            }
            else{
                 cout << "Movie: " << title << " not found, cannot delete." << endl;
            }
        }
        
    }
}








