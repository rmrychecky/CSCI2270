#include<iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include "HashTable.hpp"

using namespace std;

wordItem* searchItem(string key, wordItem** table, int hashTableSize)
{
    unsigned int hashValue = 5381;
    
    for(unsigned int i = 0; i < key.length(); i++){
        hashValue = hashValue*33 + key[i];
    }
    hashValue = hashValue % hashTableSize;
    
    wordItem* temp = table[hashValue]; //this pointer points at the head 
    while(temp != nullptr){
        if(temp->word == key){ //once you find the pointer with the correct word then it's good
            return temp;
        }
        temp = temp -> next; //keep traversing till you find it
    }
    return nullptr;
}

void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable) 
{
    ifstream file; //create variable to write file into
    file.open(ignoreWordFileName); //open file
    
    string line1;
    
    while(getline(file,line1)){ //while you can still grab lines keep going
        stopWordsTable.addWord(line1);
    }
    file.close(); //close file at the end
}

bool isStopWord(string word, HashTable &stopWordsTable){
    
    return stopWordsTable.isInTable(word); //check if it is a stop word using the isInTable member fxn
    
}

unsigned int HashTable:: getHash(string word){ //hash function given to us
    
    unsigned int hash = 5381;
    for(unsigned int i = 0; i < word.length(); i++){
        hash = hash*33 + word[i];
    }

    hash = hash % hashTableSize;
    
    return hash;
}

HashTable::HashTable(int tableSize)
{
    hashTableSize = tableSize; //in constructor set hashTableSize and make the new wordItem table
    hashTable = new wordItem*[hashTableSize];
    numItems = 0;
    numCollisions = 0; //number of collisions and items is set to 0 to start
    for(int i = 0; i < hashTableSize; i++ ){
        hashTable[i] = nullptr; //fill the table with nullptrs
    }
}

wordItem* HashTable::searchTable(string word){ //search using the searchItem helper fxn
    
    return searchItem(word, hashTable, hashTableSize);
}

void HashTable:: addWord(string word){
    unsigned int hashValue = getHash(word);
    if(!searchTable(word)){
        wordItem* newWordItem = new wordItem; //create the new node to add
        newWordItem->word = word;
        newWordItem->count = 1;
        newWordItem->next = nullptr;
        
        if(hashTable[hashValue] == nullptr){
            hashTable[hashValue] = newWordItem; //if the hashTable at the index from hash function is empty then insert there
        }
        else{
            newWordItem -> next = hashTable[hashValue]; //otherwise you will have to make it part of the link list
            hashTable[hashValue] = newWordItem;
            numCollisions++; //increment the number of collisions in this case 
        }
        numItems++; //increment number of items either way 
    }
}

int HashTable::getTotalNumWords()
{
    int total = 0;
    for(int i = 0; i < hashTableSize; i++){ //traverse the entire table size
        wordItem* temp = hashTable[i];
        while(temp != nullptr){
            total += temp -> count; //start with pointer to head at first index and go along till LL is done
            temp = temp -> next; //add to the total counter
        }
    }
    return total;
}

void arraySort(wordItem** list, int length) //helper function to sort the entire array
{
    int sorted = 0;
    int indexBig;
    int maxBig = 0;
    bool change = false;
    wordItem* holder;
    for(int i = 0; i < length; i++){
        maxBig = list[sorted] -> count;
        for(int z = sorted+1; z < length; z++){
            
            if(list[z] -> count > maxBig){
                maxBig = list[z] -> count;
                indexBig = z;
                change = true;
            }
        }
        if(change == true){
            holder = list[sorted];
            list[sorted] = list[indexBig];
            list[indexBig] = holder;
            change = false;
        }
        sorted ++;
    }
}

void HashTable:: printTopN(int n){
    
    wordItem** tempArr = new wordItem*[n];
    wordItem* itemHold;
    int inTempArr = 0;
    for(int i = 0; i < hashTableSize; i++){ //for each index in the table
        itemHold = hashTable[i];
        if(inTempArr < n && itemHold != nullptr){ //if the temp array isn't full yet then just add it at the next stop
            tempArr[inTempArr] = itemHold;
            inTempArr++;
        }
        else if(itemHold != nullptr){ //if the hashTable at the index isn't null then 
            arraySort(tempArr, n);
            int minCount = 10000000; //sort array until you find the min index
            int minIndex = 0;
            for(int x = 0; x < n; x++){
                if(tempArr[x] -> count < minCount){
                    minCount = tempArr[x] -> count;
                    minIndex = x;
                }
            }
            
            if(itemHold -> count > minCount){
                tempArr[minIndex] = itemHold;
            }
            
        }
        
        if(itemHold != nullptr){
         itemHold = itemHold -> next;
        }
        
        while(itemHold != nullptr){
            
        if(inTempArr < n && itemHold != nullptr){
            tempArr[inTempArr] = itemHold;
            inTempArr++;
        }
        else if(itemHold != nullptr){
                    arraySort(tempArr, n);
                int minCount = 10000000; //find the thing in temp array with the min index
                int minIndex = 0;
                for(int y = 0; y < n; y++){
                    if(tempArr[y] -> count < minCount){
                        minCount = tempArr[y] -> count;
                        minIndex = y;
                    }
                }
                
                if(itemHold -> count > minCount){
                    tempArr[minIndex] = itemHold;
                }
            }        
                
            itemHold = itemHold -> next;
        }
        
    }
    
      
    float probability;
    float holder;
    float total = getTotalNumWords();
    for(int i = 0; i < n; i++){
        holder = tempArr[i]->count;
        probability = holder/total;
        cout << setprecision(4) << fixed << probability << " - " << tempArr[i]->word << endl;
    }
    
    
   
}

void HashTable:: incrementCount(string word){
    
    wordItem* temp = searchTable(word); //find the word and set to a temp pointer
    
    if(temp != nullptr){
        temp -> count = temp -> count + 1; //add one to the total pointer count
    }
}

int HashTable:: getNumCollisions(){ //getter function
    return numCollisions;
}

int HashTable:: getNumItems(){
    return numItems;//getter function
}

HashTable:: ~HashTable(){
    
    for (int i = 0; i < hashTableSize; i++) {
        wordItem* entry = hashTable[i];
        while (entry != nullptr){
            wordItem* prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] hashTable;
}

bool HashTable:: isInTable(string word){
    
    wordItem* temp = searchTable(word); //search the table for the word
    
    if(temp != nullptr){ //if it's nullptr
        return true;
    }
    else{
        return false;
    }
}