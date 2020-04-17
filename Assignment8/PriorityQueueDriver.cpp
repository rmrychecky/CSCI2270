#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#include "PriorityQueue.hpp"

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

void displayMenu()
{
  cout << "============Main Menu============" << endl;
  cout << "1. Get group information from file" << endl;
  cout << "2. Add a group to Priority Queue" << endl;
  cout << "3. Show next group in the queue" << endl;
  cout << "4. Serve Next group" << endl;
  cout << "5. Serve Entire Queue" << endl;
  cout << "6. Quit" << endl;
}

int main(int argc, char* argv[]){
  string line;
  string choice;
  string name;
  string filenameInput;
  string groupsize;
  string cookingtime;
  string array[3];
  PriorityQueue Queue1 = PriorityQueue(stoi(argv[1]));
  GroupNode temp;
  ifstream file;
  int totalCookTime = 0;

    while (choice != "6") {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) {
                case 1:
                    cout << "Enter filename:" << endl;
                    getline(cin, filenameInput);
                    
                    file.open(filenameInput); 
                    
                    if (file.is_open()){
      
                        while (getline(file, line)){
                            split(line, ' ', array, 3);
                            name = array[0];
                            groupsize = stoi(array[1]);
                            cookingtime = stoi(array[2]);
        
                            Queue1.enqueue(name, stoi(groupsize), stoi(cookingtime));
                        }
                    }
                    else{
                        cout << "Failed to open the file." << endl;
                    }
                    file.close();
                    
                    break;
                    
                case 2:
                    cout << "Enter Group Name:" << endl;
                    getline(cin, name);
                    cout << "Enter Group Size:" << endl;
                    getline(cin, groupsize);
                    cout << "Enter Estimated Cooking Time:" << endl;
                    getline(cin, cookingtime);
                    
                    Queue1.enqueue(name, stoi(groupsize), stoi(cookingtime));
                    
                    break;
                
                case 3:
                    if(Queue1.isEmpty()){
                    cout << "Heap empty, nothing to peek" << endl;
                }
                else{
                    temp = Queue1.peek();
                    cout << "Group Name: " << temp.groupName << endl;
                    cout << "Group Size: " << temp.groupSize << endl;
                    cout << "Group Time: " << temp.cookingTime << endl;
                    
                }
                    break;

                case 4:
                    temp = Queue1.peek();
                    cout << "Group Name: " << temp.groupName << " - Total Cook Time for the Group: " << temp.cookingTime << endl;
                    
                    Queue1.dequeue();
                    
                    break;
                    
                case 5:
                    
                  
                    while(!(Queue1.isEmpty())){
                        temp = Queue1.peek();
                        totalCookTime = totalCookTime + temp.cookingTime;
                        cout << "Group Name: " << temp.groupName << " - Total Cook Time for the Group: " << totalCookTime << endl;
                    
                        Queue1.dequeue();
                    }
                    
                    break;
                
                case 6:
                    cout << "Goodbye!" << endl;
                    break;

                default:
                    cout << "invalid input" << endl;
            }
    }
    
  return 0;
}




