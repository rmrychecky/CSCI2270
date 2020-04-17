#include "MovieTree.hpp"
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
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
      
      //HMWK7 1300
void displayMenu()
{
  cout << "======Main Menu======" << endl;
  cout << "1. Find a movie" << endl;
  cout << "2. Query movies" << endl;
  cout << "3. Print the inventory" << endl;
  cout << "4. Average Rating of movies" << endl;
  cout << "5. Quit" << endl;
}
      
      
int main(int argc, char* argv[]){
  ifstream file;
  file.open(argv[1]); 
  string line;
  int ranking;
  int year;
  float rating;
  string title;
  string array[4];
  MovieTree tree1;
  MovieNode *check = new MovieNode;

  if (file.is_open()){
      
     while (getline(file, line)){
        split(line, ',', array, 4);
        ranking = stoi(array[0]);
        title = array[1];
        year = stoi(array[2]);
        rating = stof(array[3]);
        
        tree1.addMovieNode(ranking, title, year, rating);
     }
  }
  else{
     cout << "Failed to open the file." << endl;
  }
  
      //initalization of all of my used variables
    string choice;
    string titleInput;
    string ratingInput;
    string yearInput;

    while (choice != "5") {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) {
                case 1:
                    cout << "Enter title:" << endl;
                    getline(cin, titleInput);
                    tree1.findMovie(titleInput);
                    
                    break;

                case 2:
                    cout << "Enter minimum rating:" << endl;
                    getline(cin, ratingInput);
                    cout << "Enter minimum year:" << endl;
                    getline(cin, yearInput);
                    
                    tree1.queryMovies(stof(ratingInput), stoi(yearInput));
                    break;

                case 3:
                    tree1.printMovieInventory();
                    
                    break;
                    
                case 4:
                    tree1.averageRating();
                    break;
                
                case 5:
                    cout << "Goodbye!" << endl;
                    break;

                default:
                    cout << "invalid input" << endl;
            }
    }
    
  file.close();
  return 0;
}