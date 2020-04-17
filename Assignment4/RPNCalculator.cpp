#include "RPNCalculator.hpp"



//#pragma once
#include <string>
#include <iostream>
using namespace std;

RPNCalculator :: RPNCalculator(){
    stackHead = NULL;
}

RPNCalculator :: ~RPNCalculator(){
    while(stackHead != NULL){
        pop();
    }
    stackHead = NULL;
}

bool RPNCalculator :: isEmpty(){
  if (stackHead == NULL){
    return true;
  }
  else{
    return false;
  }
}

void RPNCalculator :: push(float num){
    Operand *temp = new Operand;
    temp->number = num;
    
    temp->next = stackHead;
    
    stackHead = temp;
}

void RPNCalculator :: pop(){
    if (isEmpty()){
        cout << "Stack empty, cannot pop an item." << endl;
    }
    else if (!isEmpty()){
        Operand *temp = new Operand;
        temp = stackHead;
        stackHead = stackHead -> next;
        delete temp;
    }
}

Operand* RPNCalculator :: peek(){
    Operand *output;
    if(isEmpty()){
        cout << "Stack empty, cannot peek." << endl;
        output = NULL;
    }
    else{
        output = stackHead;
    }
    
    return output;
}

bool RPNCalculator :: compute(string symbol){

    float arithmetic;
    float variable1;
    float variable2;
    Operand *temp = stackHead;
    if (symbol != "+" && symbol != "*"){
        cout << "err: invalid operation" << endl;
        return false;
    }
    else if(isEmpty()){
        cout << "err: not enough operands" << endl;
        return false;
    }
    else{
        variable1 = temp->number;
        pop();
        if(isEmpty()){
            cout << "err: not enough operands" << endl;
            push(variable1);
            return false;
        }
        else{
            //do i need to do temp = temp next? or does it update in pop
            variable2 = temp->next->number;
            pop();
            if(symbol == "+"){
                arithmetic = variable1 + variable2;
            }
            else if(symbol == "*"){
                arithmetic = variable1*variable2;
            }
            push(arithmetic);
            return true;
        }
    }
}