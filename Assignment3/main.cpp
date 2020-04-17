/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <iomanip>
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
    string choice;
    string nameOfCountry;
    string message;
    string newCountry;
    string previousCountry;
    Country *previous = new Country;
    bool checker;
    CountryNetwork F;
    
    while (choice != "8") {
        displayMenu();
        getline(cin, choice);
        switch (stoi(choice)) {
            case 1:
                    F.loadDefaultSetup();
                    cout << "== CURRENT PATH ==" << endl;
                    F.printPath();
                    cout << "===" << endl;
                    cout << endl;
                    break;
            case 2:
                    cout << "== CURRENT PATH ==" << endl;
                    F.printPath();
                    cout << "===" << endl;
                    cout << endl;
                    break;
            case 3:
                    cout << "Enter name of the country to receive the message:" << endl;
                    getline(cin, nameOfCountry);
                    //cout << endl;
                    cout << "Enter the message to send:" << endl;
                    getline(cin, message);
                    cout << endl;
                    F.transmitMsg(nameOfCountry, message);
                    cout << endl;
                    break;
            case 4:
                    cout << "Enter a new country name:" << endl;
                    getline(cin, newCountry);
                    //cout << endl;
                    cout << "Enter the previous country name (or First):" << endl;
                    getline(cin, previousCountry);
                    //cout << endl;
                    
                    if (previousCountry == "First"){
                        previous = NULL;
                    }
                    else {
                        
                        previous = F.searchNetwork(previousCountry);
                        while (previous == NULL){
                            //previous = nullptr;
                            cout << "INVALID country...Please enter a VALID previous country name:" << endl;
                            getline(cin, previousCountry);
                            if (previousCountry == "First"){
                                previous = NULL;
                                break;
                            }
                            previous = F.searchNetwork(previousCountry);
                            //cout << "hello bitch" << endl;
                        }
                        cout << endl;
                    }
                    
                    F.insertCountry(previous, newCountry);
                    cout << "== CURRENT PATH ==" << endl;
                    F.printPath();
                    cout << "===" << endl;
                    cout << endl;
                    break;
            case 5:
                    cout << "Enter a country name:" << endl;
                    getline(cin, nameOfCountry);
                    //cout << endl;
                    F.deleteCountry(nameOfCountry);
                    
                    cout << "== CURRENT PATH ==" << endl;
                    F.printPath();
                    cout << "===" << endl;
                    cout << endl;
                    break;
            case 6:
                    F.reverseEntireNetwork();
                    
                    cout << "== CURRENT PATH ==" << endl;
                    F.printPath();
                    cout << "===" << endl;
                    cout << endl;
                    break;
            case 7: 
                    F.deleteEntireNetwork();
                    cout << endl;
                    break;
            case 8:
                    cout << "Quitting... cleaning up path: " << endl;
                    
                    cout << "== CURRENT PATH ==" << endl;
                    F.printPath();
                    cout << "===" << endl;
                    
                    checker = F.isEmpty();
                    if (checker != true){
                        F.deleteEntireNetwork();
                        cout << "Deleted network" << endl;
                    }
                    
                     
                    
                    
                    
                    checker = F.isEmpty();
                    
                    if (checker == true){
                        //cout << "Deleted network" << endl;
                        cout << "Path cleaned" << endl;
                    }
                    else if (checker == false){
                        cout << "Error: Path NOT cleaned" << endl;
                    }
                    
                    cout << "Goodbye!" << endl;
                    break;
            default:
                    cout << "invalid input" << endl;
                    cout << endl;
        }             
    }
    return 0;

}

/*
 * Purpose: displays a menu with options
 */
void displayMenu()
{
    //cout << endl;
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Delete Country " << endl;
    cout << " 6. Reverse Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}