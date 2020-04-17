#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Graph.hpp"

using namespace std;

int split (string str, char c, string array[], int size) //given split function
{
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count;
}

int main (int argc, char* argv[]) 
{
    ifstream writeFile; //create ifstream variable
    writeFile.open(argv[1]); 

    Graph g0;
    string line;
    int numberWords = 1;
    
    getline(writeFile, line);
    for(int i = 0; i < line.length(); i++){
            if(line[i] == ','){
                numberWords++;
            }
    }
    string arrayVertex[numberWords];
    split(line, ',', arrayVertex, numberWords);
    for(int j = 1; j < numberWords; j++){
        g0.addVertex(arrayVertex[j]);
    }
    
    string arrayDistance[numberWords];
    int numberRead = 0;
    
    while (getline(writeFile, line)){
        
        split(line, ',', arrayDistance, numberWords);
        for(int h = 0; h < numberWords-1; h++){
            
          
            if(stoi(arrayDistance[h+1]) > 0){
                
                g0.addEdge(arrayDistance[0], arrayVertex[h+1], stoi(arrayDistance[h+1]));
             
                cout << " ... Reading in " << arrayDistance[0] << " -- " << arrayVertex[h+1] << " -- " << stoi(arrayDistance[h+1]) << endl;
            }
        }
 
        numberRead++;
        
    }

    cout << "------------------------------" << endl << "Breadth First Traversal" << endl << "------------------------------" << endl;
    g0.printBFT();
  
    cout << "------------------------------" << endl << "Depth First Traversal" << endl << "------------------------------" << endl;
    g0.printDFT();
    
    cout << "------------------------------" << endl << "Display Edges" << endl << "------------------------------" << endl;
    g0.displayEdges();
 
    return 0;
    
}




