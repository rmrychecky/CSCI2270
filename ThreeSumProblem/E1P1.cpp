#include "hash.hpp"
#include <iostream>
using namespace std;

node* HashTable::createNode(int key)
{
  node* newNode = new node;
  newNode -> data = key;
  return newNode;
}

HashTable::HashTable(int bsize)
{
  this -> tableSize = bsize;
  hashTable = new node*[tableSize];
  for(int i = 0; i < bsize; ++i)
  {
    hashTable[i] = NULL;
  }
}

HashTable::~HashTable()
{
  for(int i = 0; i < tableSize; i++)
  {
    node* temp = hashTable[i];
    while(temp != NULL)
    {
      node* deleteNode = temp;
      temp = temp -> next;
      delete deleteNode;
    }
  }
  delete [] hashTable;
}

bool HashTable::insertItem(int key)
{
  int index = hashFunction(key);
  node* search = searchItem(key);
  node* newNode = createNode(key);
  if(hashTable[index] == NULL)
  {
    if(search == NULL)
    {
      hashTable[index] = newNode;
      newNode -> next = NULL;
      return true;
    }
    return false;
  }
  else
  {
    if(search == NULL)
    {
      node *temp = hashTable[index];
      while(temp -> next != NULL)
      {
        temp = temp -> next;
      }
      temp -> next = newNode;
      newNode -> next = NULL;
      return true;
    }
    return false;
  }
}

unsigned int HashTable::hashFunction(int key)
{
  if(key < 0)
  {
    key = key *(-1);
    return (key % tableSize);
  }
  return (key % tableSize);
}
/*
unsigned int HashTable::hashFunction(string word)
{
  unsigned int hashValue = 5381;
  int length = word.length();
  for(int i = 0; i < length; i++)
  {
    hashValue = ((hashValue<<5)+hashValue)+word[i];
  }
  hashValue %= tableSize;
  return hashValue;
}
*/
void HashTable::printTable()
{
  for(int i = 0; i < tableSize; i++)
  {
    node* temp = hashTable[i];
    while(temp != NULL)//Traverse the linklist
    {
      cout<<temp -> data<<endl;
      temp = temp -> next;
    }
  }
}

node* HashTable::searchItem(int key)
{
  int index = hashFunction(key);
  node* current = hashTable[index];
  while(current != NULL)
  {
    if(current -> data == key)
    {
      return current;
    }
    current = current -> next;
  }
  return NULL;
}
bool findThreeSum(int arr[], int size, HashTable &ht)
{
  //Want to sum to 0
  int sum = 0;
  for(int i = 0; i < size - 2; i++)
  {
    for(int j = i + 1; j < size; j++)
    {
      int toPair = sum - arr[i];
      node* found = ht.searchItem(toPair - arr[j]);
      if(found != NULL)
      {
        cout<<"Found it!"<<endl;
        cout<<arr[i]<<" "<<found -> data<<" "<<arr[j]<<endl;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  int a[] = {-1,1};
  bool check = false;
  int b[] = {-1,0,1};
  int sizea = sizeof(a)/sizeof(a[0]);
  int sizeb = sizeof(b)/sizeof(b[0]);
  HashTable br(7);
  for(int i = 0; i < sizea; i++)
  {
    br.insertItem(a[i]);
  }
  for(int i = 0; i < sizeb; i++)
  {
    br.insertItem(b[i]);
  }

  check = findThreeSum(a, sizea, br);
  if(check == false)
  {
    cout<<"false"<<endl;
  }
  else
  {
    cout<<"true"<<endl;
  }
  check = findThreeSum(b, sizeb, br);
  if(check == false)
  {
    cout<<"false"<<endl;
  }
  else
  {
    cout<<"true"<<endl;
  }

}
