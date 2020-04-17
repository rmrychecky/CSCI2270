#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;


const int TABLESIZE = 50; // PICK A TABLE SIZE
const int KEYLENGTH = 2;

struct Record{
	string key;
	// other member data would go here:
};


class Hash{
private:
	// int KEYLENGTH;
	Record table[TABLESIZE];
	int collisions;

	int hashSum(string key){
		int sum = 0;
		for(int i = 0; i<KEYLENGTH; i++){
			sum = sum + key[i];
		}
		return sum%TABLESIZE;
	}

public:
	Hash(){
		collisions = 0;
	}

	int search(string sKey){
		int index = hashSum(sKey);
		
		if(table[index].key == sKey){
			return index;
		}
		else{
			int count  = 0;
			while(count < TABLESIZE){
				count++;
				if(index != TABLESIZE){
					index++;
				}
				else{
					index = 0;
				}
				
				if(table[index].key == sKey){
					return index;
				}
			}
			return -1; //if you can't find it
		}
	}
	//Record search(string key){}

	void insertRecordOpenAddress(Record r){
		int index = hashSum(r.key);
		if(table[index].key.empty()){
			table[index] = r;
		}
		else{
			collisions++;
			//debug
			cout << "collision at index " << index << " ";
			bool placed = false;
			index++;
			while(placed){
				if(index != TABLESIZE && table[index].key.empty()){
					table[index] = r;
					placed = true;
				}
				else if (index == TABLESIZE){ //at end, put back to 0 and start searching again
					index = 0;
				}
				else{
					index++;
				}
			}
			cout <<  r.key << " placed at index " << index << endl;
		}

	}

	void insertRecord(Record r){
		int index = hashSum(r.key);
		if(table[index].key.empty()){
			table[index] = r;
		}
		else{
			collisions++;
		}	
	}

	void dispHashTable(){
		for(int i = 0; i<TABLESIZE; i++)
			cout << "Entry " << i << " " << table[i].key << endl;
		cout << "number of collisions " << collisions << endl;
		cout << "\n\n";

	}
}; 
////// end of Hash class



string randStr(int l){
	// Gnerate random strings with values A-Z
	// ascii 65-90
	// 0-25+65
	// rand()%26 => 0-25
	// rand()%26+65 => 65

	// utilize the string class constructor:
	// string st(x, ' ') will generate an empty string
	// with x characters 
	string st(l,' ');
	for(int i = 0; i<l; i++)
		st[i] = rand()%26+65;
	
 	return st;
}

int main(){
	// seed the randomizer
	//srand(time(NULL));

	
	// Number of records
	int N = 35; 
	// generate N records
	Record arr[N];
	for(int i = 0; i<N; i++){
		arr[i].key = randStr(KEYLENGTH);
		cout << arr[i].key << endl;
	}
	
	//now test the hash class
	Hash h0;
	for(int i = 0; i<N; i++){
		h0.insertRecordOpenAddress(arr[i]);
	}
	
	h0.dispHashTable();
	
	//test the search function
	string s(" ");
	while(s != "exit"){
		cout << "enter search value ";
		cin >> s;
		cout << "found at " << h0.search(s) << endl;
	}	

	return 0;
}





