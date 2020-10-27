//
// Created by Kylie Jordan on 10/25/20.
//

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
        RouteData& operator=(const RouteData& obj){
            if(this == &obj)
                return *this;
            dest = obj.dest;
            cost = obj.cost;
            time = obj.time;
            airline = obj.airline;
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
