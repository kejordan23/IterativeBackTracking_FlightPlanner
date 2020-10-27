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
        DSDLinkedList<RouteData> connections = DSDLinkedList<RouteData>();
        DSString firstLoc;
    public:
        CityConnections(DSString& l, RouteData& r): firstLoc(l){
            connections.insertAtEnd(r);
        };
        void addConnection(RouteData& g){
            connections.insertAtEnd(g);
        };
        DSString& getLoc(){ return firstLoc;};
        RouteData& getRouteData(int i){
            return connections.getElement(i);
        };
        void print(){
            for(int i = 0; i< connections.getSize(); i++){
                connections.getElement(i).print();
                cout<<endl;
            }
        };
};

#endif //INC_20F_FLT_PLN_CITYCONNECTIONS_H
