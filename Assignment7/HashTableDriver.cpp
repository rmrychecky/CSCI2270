#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#include "HashTable.hpp"

int main (int argc, char* argv[]) 
{
    //number of arguments is not tested, fake news
   
    HashTable stopWords = HashTable(50);
    getStopWords(argv[3], stopWords ); //argument 3 is the ignore words file
    
    
    HashTable words = HashTable(stoi(argv[4]));
  
    ifstream writeFile; //create ifstream variable
    writeFile.open(argv[2]); 
  
   
    string word;
    
    while(writeFile >> word){ //while there are still words being read in, continue
                if(isStopWord(word, stopWords)){
                   
                }else if(words.isInTable(word)){
                     words.incrementCount(word);
                }
                else{
                    words.addWord(word);
                }

    }

  
    
    words.printTopN(stoi(argv[1])); //only do the total number of non stop words

    cout << "#" <<endl;
    cout << "Number of collisions: " << words.getNumCollisions() << endl;
    cout << "#" <<endl;
    cout << "Unique non-stop words: " << words.getNumItems() << endl;
    cout << "#" <<endl;
    cout << "Total non-stop words: " << words.getTotalNumWords() << endl;
    
    
    return 0;
    
}




