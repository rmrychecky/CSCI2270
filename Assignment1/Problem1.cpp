#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
    int i;
    
      
    myArray[numEntries] = newValue;
    
    int holder;
    
    
    for (i = numEntries - 1; i >= 0; i--)
    {
        if(myArray[i] > myArray[i+1]){
        holder = myArray[i];
        myArray[i] = newValue;
        myArray[i+1] = holder;
        }
        
    }
    
  
    
    numEntries++;
    
    for (int k = 0; k < numEntries; k++)
    {
        if (numEntries == 1 || k == numEntries - 1)
        {
            cout << myArray[k] << endl;
        }
        else
        {
            cout << myArray[k] << ",";
        }
    }
    

    return numEntries;
    
}

int main (int argc, char* argv[]) 
{
    
    
    
  ifstream file;
  file.open(argv[1]); 
  int numEntries;
  int newValue;
  string line;
  int myArray[100]; 

  numEntries = 0;
  if (file.is_open())
  {
      
     
     while (getline(file, line))
     {


        newValue = stoi(line);
        
        // if (numEntries == 100)
        // {
        //     file.close();
        //     return 0;
        // }
        numEntries = insertIntoSortedArray(myArray, numEntries, newValue);
        
        // for (int i = 0; i < numEntries - 1; i++)
        // {
        //     cout << myArray[i] << ",";
        // }
        // cout << endl;
       
       
     }
  }
  else 
  {
     cout << "Failed to open the file." << endl;
  }
  file.close();
  return 0;
}



