/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>

// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
    cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
	string choice;
    string numItems;
    string item;
    ProducerConsumer queue1;
    string outputPeek;
    int sizeOfQueue;
    
    while (choice != "3") {
        menu();
        getline(cin, choice);
        switch (stoi(choice)) {
            case 1:
                   cout << "Enter the number of items to be produced:" << endl;
                   getline(cin, numItems);
                   for (int i = 0; i < stoi(numItems); i++){
                   		cout << "Item" << i + 1 << ":" << endl;
                   		getline(cin, item);
                   		queue1.enqueue(item);
                   }
                  
                    break;
            case 2:
            	   cout << "Enter the number of items to be consumed:" << endl;
            	   getline(cin, numItems);
            	   sizeOfQueue = queue1.queueSize();
            	   if (stoi(numItems) > sizeOfQueue){
            	   	for (int i = 0; i < sizeOfQueue; i++){
            	   		outputPeek = queue1.peek();
            	   		queue1.dequeue();
            	   		cout << "Consumed: " << outputPeek << endl;
            		}
            		cout << "No more items to consume from queue" << endl;
            	   }
            	   else{
            	   	 for (int i = 0; i < stoi(numItems); i++){
            	   		outputPeek = queue1.peek();
            	   		queue1.dequeue();
            	   		cout << "Consumed: " << outputPeek << endl;
            		 }
            	   }
                   break;
            case 3:
            	   sizeOfQueue = queue1.queueSize();
            	   cout << "Number of items in the queue:" << sizeOfQueue << endl;
                   break;
            default:
                    cout << "invalid input" << endl;
                	cout << endl;
        }
    }
    return 0;
}
