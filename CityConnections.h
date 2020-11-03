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
        int iter;
    public:
        CityConnections(): firstLoc(""), iter(0){};
        CityConnections(DSString& l, RouteData& r): firstLoc(l), iter(0){
            connections.insertAtEnd(r);
        };
        CityConnections(CityConnections& list2){
            connections = list2.connections;
            firstLoc = list2.firstLoc;
            iter = list2.iter;
        };
        void setIter(int i){ iter = i;};
        void moveIter(){ iter++;};
        int getIter(){ return iter;};
        void addConnection(RouteData& g){
            connections.insertAtEnd(g);
        };
        DSString& getLoc(){ return firstLoc;};
        int getSize(){ return connections.getSize();};
        RouteData& getRouteData(int i){
            return connections.getElement(i);
        };
        void print(){
            for(int i = 0; i< connections.getSize(); i++){
                connections.getElement(i).print();
                cout<<endl;
            }
            cout<<iter<<endl;
        };
};

#endif //INC_20F_FLT_PLN_CITYCONNECTIONS_H
