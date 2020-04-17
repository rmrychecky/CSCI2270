#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct wordItem
{
    string word;
    int count;
};

void getStopWords(const char *ignoreWordFileName, string ignoreWords[])
{

  ifstream file;
  file.open(ignoreWordFileName); 
  string line;
  int i = 0;

  if (file.is_open())
  {
     while (getline(file, line))
     {
        ignoreWords[i] = line;
        i++;
     }
  }
  else 
  {
     cout << "Failed to open " << ignoreWordFileName << endl;
  }
  file.close();
}

bool isStopWord(string word, string ignoreWords[])
{
    bool marker = false;
    for (int i = 0; i < 50; i++)
    {
        if (word == ignoreWords[i])
        {
            marker = true; 
        }
    }
    return marker;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        counter = counter + uniqueWords[i].count;
    }
    return counter;
}

void arraySort(wordItem uniqueWords[], int length)
{
    int temp;
    string temp1;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (uniqueWords[j].count < uniqueWords[i].count)
            {
                temp = uniqueWords[i].count;
                temp1 = uniqueWords[i].word;
                
                uniqueWords[i].count = uniqueWords[j].count;
                uniqueWords[i].word = uniqueWords[j].word;
                
                uniqueWords[j].count = temp;
                uniqueWords[j].word = temp1;
            }
        }
    }
}

void printTopN (wordItem uniqueWords[], int topN, int totalNumWords)
{
    float probability;
    float holder;
    for (int i = 0; i < topN; i++)
    {
        holder = uniqueWords[i].count;
        probability = holder/totalNumWords;
        cout << setprecision(4) << fixed << probability << " - " << uniqueWords[i].word << endl;
    }
}

bool addNonStop(wordItem arr1[], int capacity, string word1){
    
    int foundIndex;
    bool found = false;
    
    for(int i = 0; i < capacity; i++){
                    if(arr1[i].word == word1){
                        found = true; //if you find it, the word is at index i in the array
                        foundIndex = i;
                        break;
                    }
                }
                if(found == false){
                    arr1[capacity].word = word1; //if you don't find it, then you add it to the array and set the count to 1
                    arr1[capacity].count = 1;
                    return true; //return true if this word is new
                }else{
                    arr1[foundIndex].count += 1; //if the word is not new just increment the count 
                    found = false; //return false if the word is not new
                    return false;
                }
}

int main (int argc, char* argv[]) 
{
    //number of arguments is not tested, fake news
    string ignoreWord[50]; 
    getStopWords(argv[3], ignoreWord); //argument 3 is the ignore words file
    
    
    ifstream writeFile; //create ifstream variable
    writeFile.open(argv[2]); 
  
    const int INITIAL_ARRAY_SIZE = 100; //the inital size of the array is 100 

    wordItem* arrPoint = new wordItem[INITIAL_ARRAY_SIZE]; //pointer array of type wordItem
    
    int capacity = 0;
  
    string name;
    
    bool found1 = false; 
    
    int currentSize = 100;
    
    int timesDoubled = 0;
    
    int uniqueNonStopWords = 0;
    
    int totalNonStopWords = 0;
    
    int j = 0;
    
    while(writeFile >> name){ //while there are still words being read in, continue
            
                if(isStopWord(name,ignoreWord)){
                    //stop word 
                }else{
                    
                    if(capacity == currentSize){ //if the array has been filled to 100
                        wordItem *copyArray = new wordItem[currentSize*2]; //make a temp array double the size
                        for(int i = 0; i < capacity; i++){ 
                            copyArray[i] = arrPoint[i]; //copy the values up to original array capacity 
                        }
                        delete []arrPoint; //deallocate the pointer wordItem array (original)
                        arrPoint = copyArray; //set that array to the copy 
                        
                        currentSize = currentSize*2; //now, set the current size to double
                        timesDoubled ++; //increment the number of times the array had to be doubled 
                    }
                    
                    found1 = addNonStop(arrPoint, capacity, name);  //use the addNonStop word function
                    if(found1 == true){ //if it returns true then that means it is a new word
                        capacity++; //increment the number of entries in the array
                        uniqueNonStopWords++; //increment the uniqueNonStopWords and totalNonStopWords
                        totalNonStopWords++;
                    }else{ //if it returns false then it is an old word, only increment totalNonStopWords
                        totalNonStopWords++; //if it is an old word, only increment the totalNonStopWords (not unique)
                    }
            }
            j++;
    }

    arraySort(arrPoint,capacity); //sort the array after everything has been read in
    
   
    
    cout << "Array doubled: " << timesDoubled << endl;
    cout << "#" << endl;
    cout << "Unique non-common words: " << uniqueNonStopWords << endl;
    cout << "#" << endl;
    cout << "Total non-common words: " << totalNonStopWords << endl;
    cout << "#" << endl;
    cout << "Probabilities of top " << stoi(argv[1]) << " most frequent words" << endl;
    cout << "---------------------------------------" << endl;
    printTopN(arrPoint, stoi(argv[1]), totalNonStopWords); //only do the total number of non stop words
    
    return 0;
    
}




