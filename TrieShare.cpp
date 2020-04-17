// code adapted from https://www.geeksforgeeks.org/trie-insert-and-search/

#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
	TrieNode *children[ALPHABET_SIZE];

	bool isEndOfWord;
};

TrieNode *makeNode(){
	//allocate space for a new node
	TrieNode *newNode = new TrieNode;
	newNode->isEndOfWord = false;
	//initialize all children to nullptr
	for(int i = 0; i < ALPHABET_SIZE; i++){
		newNode->children[i] = NULL;
	}
	return newNode;
}

void insert(TrieNode *root, string key){
	TrieNode *newCrawl = root;
	for (int i = 0; i < key.length(); i++){
		//shift the index so it starts at 0
		int index = key[i] - 'a'; //would put a in 0
		//check if null pointer has been reached 
		//if so, add a new node
		if(!newCrawl->children[index]){ //if that index is a null pointer
			newCrawl->children[index] = makeNode();
		}
		
		newCrawl = newCrawl->children[index];
	}
	
	newCrawl->isEndOfWord = true;
}

//search returns a bool true if key exists in structure
bool search(TrieNode *root, string key){
	TrieNode *newCrawl = root;
	for (int i = 0; i < key.length(); i++){
		int index = key[i] - 'a';
		if(!newCrawl->children[index]){
			return false;
		}
		newCrawl = newCrawl->children[index];
	}
	//newCrawl != NULL = the last character exists 
	//newCrawl->isEndOfWord = the last character is end of word
	return(newCrawl->isEndOfWord);
}


int main(){

	// Test keys. Using only ASCII characters a through z
	string keys[] = {"the","a","there","answer","any","by","bye","their"};
	int n = 8;

	// The first node gets created here
	TrieNode *root = makeNode();

	for(int i = 0; i<n; i++)
		insert(root,keys[i]);
	// 
	string searchString;

	while(searchString!="exit"){
		cout << "Input a search string to see if it's in the dictonary: ";
		cin >> searchString;
		cout << "\"" << searchString;
		bool inDictonary =  search(root,searchString);
		if(inDictonary)
			cout << "\" found in dictionary" << endl;
		else
			cout << " not found in dictionary" << endl;
	}

	return 0;
}

