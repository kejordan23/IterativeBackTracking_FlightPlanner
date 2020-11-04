// Project 4: Flight Planner
// Author: Kylie Jordan
//
// RouteData.h
//
// This header file declares and defines the RouteData class constructors and functions.

#ifndef INC_20F_FLT_PLN_ROUTEDATA_H
#define INC_20F_FLT_PLN_ROUTEDATA_H

#include <fstream>
#include <iostream>
#include "DSDLinkedList.h"
#include "DSString.h"

using namespace std;

class RouteData{
    private:
        DSString dest;
        int cost;
        int time;
        DSString airline;
    public:
        RouteData(): dest(""), cost(0), time(0), airline(""){};
        RouteData(DSString d, int c, int t, DSString a): dest(d), cost(c), time(t), airline(a){};
        RouteData(RouteData& b){
            dest = b.dest;
            cost = b.cost;
            time = b.time;
            airline = b.airline;
        };
        DSString& getDest(){ return dest;};
        int getCost(){ return cost;};
        int getTime(){ return time;};
        DSString& getAirline(){ return airline;};
        void print(){
            cout<<dest<<endl;
            cout<<"$"<<cost<<endl;
            cout<<time<<" min"<<endl;
            cout<<airline<<endl;
        };
};

#endif //INC_20F_FLT_PLN_ROUTEDATA_H
