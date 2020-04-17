
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int myFunc(int n){
    int result = 0;
    if(n<=0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    result = myFunc(n-1) + myFunc(n-3);
    return result;
}

int main(){
    cout << myFunc(4);
    return 0;
}