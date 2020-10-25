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

using namespace std;

class Manager{
    private:
        AdjList connections;
        AdjList plans;
    public:
        Manager(ifstream&, ofstream&);
        void makePlan(DSString&, DSString&, DSString&);
        void print();
};

#endif //INC_20F_FLT_PLN_MANAGER_H
