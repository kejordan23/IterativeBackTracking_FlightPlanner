// Project 4: Flight Planner
// Author: Kylie Jordan
//
// Manager.h
//
// This header file declares Manager class constructors and functions.

#ifndef INC_20F_FLT_PLN_MANAGER_H
#define INC_20F_FLT_PLN_MANAGER_H

#include <fstream>
#include <iostream>
#include "DSDLinkedList.h"
#include "DSString.h"
#include "CityConnections.h"
#include "RouteData.h"
#include "AdjList.h"
#include "Stack.h"

using namespace std;

class Manager{
    private:
        char line[80];
        AdjList connections;
        DSDLinkedList<Stack<RouteData>> plans = DSDLinkedList<Stack<RouteData>>();
        bool fileCheck;
    public:
        Manager(ifstream&, ifstream&, ofstream&);
        void splitLine(ofstream&);
        void makePlan(DSString&, DSString&, DSString&, ofstream&);
        void storePath(Stack<RouteData>&, DSString&);
        int compTime(Stack<RouteData>&);
        double compPrice(Stack<RouteData>&);
        void print(ofstream&);
};

#endif //INC_20F_FLT_PLN_MANAGER_H
