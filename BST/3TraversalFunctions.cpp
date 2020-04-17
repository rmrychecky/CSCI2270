#include <iostream>
using namespace std;


void inorder ( int *root){
	if (root != NULL ){
		inorder(root->left);
		print(root->data);
		inorder(root->right);
	}
}

void postorder ( int *root){
	if (root != NULL ){
		postorder(root->left);
		postorder(root->right);
		print(root->data);
	}
}

void preorder ( int *root){
	if (root != NULL ){
		print(root->data);
		preorder(root->left);
		preorder(root->right);
	}
}