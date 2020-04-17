Dynamic memory:
Have to manually allocate and deallocate in order to use it
Int *p1 = new int[n];
//declare a pointer pointing to int type, "new" keyword to allocate on the heap, n-length array of ints

P1 = &x 
//don’t do this could cause a segmentation fault if you don’t DEALLOCATE before

To access array elements:

Same as automatic arrays, use pointer name
p1[i]=27;

When finished with dynamic array
Delete [] p1; //deallocates;does not delete p1; does not delete data in memory
Then you can reuse the pointer 
P1 = &x;

// classIntro.cpp
// example class: 12-hour time clock

#include <iostream>
#include <string>

using namespace std;

class Time12
{
private:
	int hour;
	int minute;
	string mer;

public:
	//constructors:
	Time12( int h, int m, string me );
	Time12( ){};

	//display function
	void printTime();

	// mutator functions:
	void setHour( int h ); 
	void setMinute( int m );
	// accessor functions
	int getHour();
	int getMinute();

};

int main()
{

	return 0;
}

Time12::Time12( int h, int m, string me ){ // constructor definition, is special kind of public method

	if ( h >= 0 && h <= 12 )
		hour = h;
	else
		cout << "bad choice " << endl;

	if( m >=0 && m <=60 )
		minute = m;
	else
		cout << "wrong choice for minute " << endl;

	mer = me;
}

void Time12::printTime(){
	cout << hour << ":" << minute << mer << endl;
}


void Time12::setHour( int h ){ // mutator
	if ( h >= 0 && h <= 12 )
		hour = h;
	else
		cout << "bad choice " << endl;
}

void Time12::setMinute( int m ){
	if( m >=0 && m <=60 )
		minute = m;
	else
		cout << "wrong choice for minute " << endl;

}

// accessor methods
int Time12::getHour() {
	return hour;
}

// accessor methods
int Time12::getMinute() {
	return minute;
}




//dynamic memory

int main()
{
  //dynamic memory allocation
  int *ptr1 = new int; //variable
  int *ptr2 = new int[10]; //array
  
  delete ptr1; //deallocate
  delete [] ptr2;
}