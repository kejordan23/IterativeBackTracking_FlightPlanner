//
// Created by Kylie Jordan on 10/31/20.
//

#ifndef INC_20F_FLT_PLN_STACK_H
#define INC_20F_FLT_PLN_STACK_H

#include <fstream>
#include <iostream>
#include "DSDLinkedList.h"
#include "DSString.h"
#include "CityConnections.h"
#include "RouteData.h"

using namespace std;

class Stack{
    private:
        DSDLinkedList<RouteData> stack = DSDLinkedList<RouteData>();
    public:
        Stack(){};
        bool empty(){
            if(stack.getSize() == 0)
                return true;
            else
                return false;
        };
        int getSize(){ return stack.getSize();};
        RouteData& top(){ return stack.getElement(stack.getSize()-1);};
        RouteData& getElement(int i){ return stack.getElement(i);};
        void push(RouteData& r){ stack.insertAtEnd(r);};
        void pop(){ stack.remove(stack.getSize()-1);};
};

#endif //INC_20F_FLT_PLN_STACK_H
