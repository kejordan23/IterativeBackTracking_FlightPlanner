// Project 4: Flight Planner
// Author: Kylie Jordan
//
// Stack.h
//
// This header file declares and defines the Stack class constructors and functions.

#ifndef INC_20F_FLT_PLN_STACK_H
#define INC_20F_FLT_PLN_STACK_H

#include <fstream>
#include <iostream>
#include "DSDLinkedList.h"
#include "DSString.h"
#include "CityConnections.h"
#include "RouteData.h"

using namespace std;
template <typename T>
class Stack{
    private:
        DSDLinkedList<T> stack = DSDLinkedList<T>();
    public:
        Stack(){};
        bool empty(){
            if(stack.getSize() == 0)
                return true;
            else
                return false;
        };
        int getSize(){ return stack.getSize();};
        T& top(){ return stack.getElement(stack.getSize()-1);};
        T& getElement(int i){ return stack.getElement(i);};
        void push(T& r){ stack.insertAtEnd(r);};
        void pop(){ stack.remove(stack.getSize()-1);};
        void print(ofstream& output){
            for(int i = 0; i< stack.getSize(); i++){
                if(i==0)
                    output<<stack.getElement(i).getDest()<<" -> ";
                else if(i<stack.getSize()-1)
                    output<<stack.getElement(i).getDest()<<"("<<stack.getElement(i).getAirline()<<")"<<" -> ";
                else
                    output<<stack.getElement(i).getDest()<<"("<<stack.getElement(i).getAirline()<<")"<<".";
            }
        };
};

#endif //INC_20F_FLT_PLN_STACK_H
