//
// Created by Kylie Jordan on 10/25/20.
//

#ifndef INC_20F_FLT_PLN_ADJLIST_H
#define INC_20F_FLT_PLN_ADJLIST_H

#include <fstream>
#include <iostream>
#include "DSDLinkedList.h"
#include "DSString.h"
#include "CityConnections.h"
#include "RouteData.h"

using namespace std;

class AdjList{
    private:
        DSDLinkedList<CityConnections> list = DSDLinkedList<CityConnections>();
    public:
        AdjList(){};
        int getSize();
        CityConnections& getConnection(DSString&);
        DSString& getFirstLoc(int);
        RouteData& getConnectData(DSString&, DSString&);
        void addLocDest(DSString&, RouteData&);
        void print();
};

#endif //INC_20F_FLT_PLN_ADJLIST_H
