//
// Created by Kylie Jordan on 10/25/20.
//

#ifndef INC_20F_FLT_PLN_CITYCONNECTIONS_H
#define INC_20F_FLT_PLN_CITYCONNECTIONS_H

#include <fstream>
#include <iostream>
#include "DSDLinkedList.h"
#include "DSString.h"
#include "RouteData.h"

using namespace std;

class CityConnections{
    private:
        DSDLinkedList<RouteData> connections;
        DSString firstLoc;
    public:
        CityConnections(DSString l, RouteData r): firstLoc(l){
            connections.insertAtEnd(r);
        };
        void addConnection(RouteData& g){
            connections.insertAtEnd(g);
        };
        DSString& getLoc(){ return firstLoc;};
        RouteData& getRouteData(int i){
            return connections.getElement(i);
        }
};

#endif //INC_20F_FLT_PLN_CITYCONNECTIONS_H
