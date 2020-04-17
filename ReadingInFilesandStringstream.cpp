#include <iostream>
#include <string>
#include <fstream>
using namespace std;

 //USING A STRUCT AND READING IN A FILE!

struct Student
{
  int idNumber;
  string name;
  string dept;
};

void readInFile(Student strArr[], int arrL, string fileName);

int main (int argc, char *argv[]) //command line arguments useful to have the user pass something (file name)
{
  if (arc !=2) //if the number of arguments is not 2 (specific condition)
  {
    cout << "incorrect number of arguments" << endl;
    return -1;
  }
  else
  {
    int N = 10;
    Student strArr[N];
    cout << "Executable name " << argv[0] << endl;
    cout << "Reading in file: " << argv[1] << endl;
    readInFile(strArr, N, argv[1]);
    //readInFile(strArr, N, "students.txt");
    return 0;
  }
}

void readInFile(Student strArr[], int arrL, string fileName)
{
  ifstream inStream;
  inStream.open(fileName);
  string sidString, studentName,major;

  if(inStream.is_open())
  {
    for(int i = 0; i < arrL; i++)
    {
      getline(inStream, sidString, ',');
      strArr[i].idNumber = stoi(sidString);
      cout << strArr[i].idNumber << endl;
      getline(inStream, studentName, ',');
      strArr[i].name = studentName;
      cout << strArr[i].name << endl;
      getline(inStream, major, '\n');
      strArr[i].dept = major;
      cout << strArr[i].dept << endl;
    }

  }
  else
  {
    cout << "file open error" << endl;
    exit(0);
  }
  inStream.close();

}
