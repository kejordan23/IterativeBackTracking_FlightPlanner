//
// Created by Kylie Jordan on 10/25/20.
//

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
        AdjList plans;
        bool fileCheck;
    public:
        Manager(ifstream&, ifstream&, ofstream&);
        void splitLine();
        void makePlan(DSString&, DSString&, DSString&);
        void storePath(Stack&);
        void print();
};

#endif //INC_20F_FLT_PLN_MANAGER_H
