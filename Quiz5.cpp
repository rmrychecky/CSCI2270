
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// struct DateType
// {
//   int day;
//   int month;
//   int year;
// };

// struct PersonType
// {
//   int age;
//   float weight;
//   DateType birthday;
// };

 
// int main(){
//   PersonType person;
//   person.age = 12;
//   person.weight = 100.0;
//   person.birthday.year = 2000;
  
//   //cout << person.year;
//   //cout<< birthday.year;
//   //cout << year;
//   cout << person.birthday.year;
// }

// void CalculateCost(int count, float& subTotal, float& taxCost){

// 	if(count<10){

// 		subTotal = count * 0.50;

// 	}

// 	else{

// 		subTotal = count * 0.20;

// 	}

// 	taxCost = 0.1 * subTotal;

// }

// int main(){

// 	float tax = 0.0, subTotal = 0.0;

// 	CalculateCost(15,subTotal,tax);

// 	cout<<"The cost for 15 items is"<<subTotal<<", and the tax for"<<subTotal<<"is"<<tax<<endl;

// 	return 0;

// }

struct Node {
  int key;
  Node *next;
};

int main(){
  
  Node *walker = head;
int count = 0;
while(walker!= NULL && count < 3) {
        if(walker->key == 10) {
                 count = count + 1;
         }
         walker = walker->next;
}
cout <<  walker->key  << endl;

}