#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct User {
    string username;
    float gpa;
    int age;
};

void addUser(User users[], string _username, float _gpa, int _age, int length)
{
    User user1;
    user1.username = _username;
    user1.gpa = _gpa;
    user1.age = _age;

    users[length] = user1;
    
}

void printList(const User users[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << users[i].username << " [" << users[i].gpa << "] age: " << users[i].age << endl;
    }
}

int main (int argc, char* argv[]) //command line arguments useful to have the user pass something (file name) //number of arguments, which one
{
    
  ifstream file;
  file.open(argv[1]); 
  string line;
  int k = 0;
  User users[15];
  string username;
  string s_gpa;
  string s_age;
  string s_username;
  float gpa;
  int age;
 
  if (file.is_open())
  {
     while (getline(file, line))
     {
         stringstream sin(line);
         
         getline(sin, s_username, ',');
         username = s_username;
         
         getline(sin, s_gpa, ',');
         gpa = stof(s_gpa);
         
         getline(sin, s_age, ' ');
         age = stoi(s_age);
         
         
         addUser(users, username, gpa, age, k);
         k++;
         
     }
     printList(users, k);

    ofstream myfile;
    myfile.open(argv[2]);
    if (myfile.is_open())
    {
        for (int i = 0; i < k; i++)
        {
            if (users[i].gpa > stof(argv[3]))
            {
                myfile << users[i].username << "," << users[i].gpa << "," << users[i].age << endl;
                
            }
        }
    }
    else 
    {
      cout << "Failed to open the file." << endl;
    }
    myfile.close();
    
  }  
  else 
  {
     cout << "Failed to open the file." << endl;
  }
  file.close();
  return 0;
}

