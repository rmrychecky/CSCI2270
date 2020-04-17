// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"
using namespace std;


node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->data = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    hashTable = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        hashTable[i] = nullptr;
}

bool HashTable::insertItem(int key)
{
     int index = hashFunction(key);
    if(!searchItem(key))
    {
        // TODO :
        // Use the hash function on the key to get the index/slot,
       
       node *temp = hashTable[index];
       hashTable[index] = createNode(key, hashTable[index]);
    
        return true;
        // create a new node with the key and insert it in this slot's list
    
    }
    else{
        cout<<"duplicate entry: "<<key<<endl;

        return false;
    }

}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

void HashTable::printTable()
{
   for (int i = 0; i < tableSize; i++){
       cout << i << " || ";
       node *temp = hashTable[i];
       while(temp != nullptr){
           cout << temp->data << "->";
           temp = temp->next;
       }
       cout << endl;
   }

 }

node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);
    
    node *temp = hashTable[index];
    while(temp != nullptr){
		if(temp->data == key){
		    return temp;
	    }
			 
		temp = temp->next;
			    
	}
			
    return nullptr;

}
