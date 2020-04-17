#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

struct numberItem{
    int number;
};

class Stack3{
private:
	int capacity;
	int currentSize;
	int timesDoubled;

public:
	Stack3(); // constructor declaration
	
	bool isFull();
	
	void push(int value);
	
	void pop();
	
	void print();

};

