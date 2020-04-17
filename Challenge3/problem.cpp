#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
    node *next;  
      
    //new node construct sets all to null
    node(int data) 
    { 
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
        this->next = NULL; 
    } 
};  
  
//left child at a level p
node *getnext(node *p)  
{  
    node *temp = p->next;  
  
    //find the first child this will be the root of the list
    while (temp != NULL)  
    {  
        if (temp->left != NULL)  
            return temp->left;  
        if (temp->right != NULL)  
            return temp->right;  
        temp = temp->next;  
    }  
  
    //return nullptr if everything is a leaf node 
    return NULL;  
}  
  
//setting the next of all of the nodes with a given root p 
void connectRecur(node* rae)  
{  
    node *temp;  
  
    if (!rae)  
    return;  
  
    // Set next for root this is always nullptr
    rae->next = NULL;  
  
    //now go to next level
    while (rae != NULL)  
    {  
        node *q = rae;  
  
        //set the nodes at the same level
        while (q != NULL)  
        {  
            //start at the left child as demonstrated in problem
            if (q->left)  
            {  
                //if it has the right child then set the left->next to right 
                if (q->right)  
                    q->left->next = q->right;  
                else //else move on 
                    q->left->next = getnext(q);  
            }  
  
            if (q->right) 
                q->right->next = getnext(q);  
  
            //do this until you find there are no more nodes to the right on this level
            q = q->next;  
        }  
  
        //now go to leftmost node of next level
        if (rae->left)  
            rae = rae->left;  
        else if (rae->right)  
            rae = rae->right;  
        else
            rae = getnext(rae);  
    }  
}  
  
int main()  
{  
 
     /* Binary Tree Example 
             1  
            / \  
           2   3  
          / \    \  
         4   5    7  
    */
    node *root = new node(1);  
    root->left = new node(2);  
    root->right = new node(3);  
    root->left->left = new node(4);  
    root->left->right = new node(5);
    root->right->right = new node(7);  
    
  
    // this function connects all the nodes at the same level
    connectRecur(root);  
  
    cout << "Next pointers are as follows" << endl;
    
    cout << "next for " << root->data << " -> ";
    if( root->next == nullptr)
		cout << -1 << endl;
    else
     	cout << root->next->data << endl;
    
    cout << "next for " << root->left->data << " -> ";
    if( root->left->next == nullptr)
		cout << -1 << endl;
    else
     	cout << root->left->next->data << endl;
        
    cout << "next for " << root->right->data << " -> ";
    if(root->right->next == nullptr)
		cout << -1 << endl;
    else
     	cout << root->right->next->data << endl;
    
    cout << "next for " << root->left->left->data<< " -> ";
    if(root->left->left->next == nullptr)
		cout << -1 << endl;
    else
     	cout << root->left->left->next->data << endl;
    
    cout << "next for " << root->left->right->data<< " -> ";
    if(root->left->right->next == nullptr)
		cout << -1 << endl;
    else
     	cout << root->left->right->next->data << endl;
        
    cout << "next for " << root->right->right->data << " -> ";
    if(root->right->right->next == nullptr)
		cout << -1 << endl;
    else
     	cout << root->right->right->next->data << endl;
   
    return 0;  
}  
  