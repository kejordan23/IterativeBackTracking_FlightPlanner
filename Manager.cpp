//
// Created by Kylie Jordan on 10/30/20.
//

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "DSDLinkedList.h"
#include "DSString.h"
#include "CityConnections.h"
#include "RouteData.h"
#include "AdjList.h"
#include "Manager.h"
#include "Stack.h"

using namespace std;

Manager::Manager(ifstream& input, ifstream& input2, ofstream& output){
    int numLines = 0;
    fileCheck = true;
    input.getline(line, 80);
    numLines = atoi(line);
    for(int i = 0; i<numLines; i++){
        input.getline(line, 80);
        splitLine();
    }
    cout<<connections.getSize()<<endl;
    DSString d = "Austin";
    connections.getConnection(d).print();
    /*fileCheck = false;
    input2.getline(line, 80);
    numLines = atoi(line);
    for(int i = 0; i<numLines; i++){
        input2.getline(line, 80);
        splitLine();
    }*/
}
void Manager::splitLine(){
    int cost;
    int time;
    char * temp2;           //function implementation adapted from www.cplusplus.com example for <cstring> class
    temp2 = strtok(line, "|");
    if(fileCheck) {
        DSString city(temp2);
        temp2 = strtok(nullptr, "|");
        DSString dest(temp2);
        temp2 = strtok(nullptr, "|");
        cost = atoi(temp2);
        temp2 = strtok(nullptr, "|");
        time = atoi(temp2);
        temp2 = strtok(nullptr, "|");
        DSString airline(temp2);

        RouteData r(dest, cost, time, airline);
        RouteData g(city, cost, time, airline);
        connections.addLocDest(city, r);
        connections.addLocDest(dest, g);
    }
    else{
        DSString city(temp2);
        temp2 = strtok(nullptr, "|");
        DSString dest(temp2);
        temp2 = strtok(nullptr, "|");
        DSString delim(temp2);

        makePlan(city, dest, delim);
    }
}
void Manager::makePlan(DSString& city, DSString& dest, DSString& delim){
    Stack s;
    RouteData r(city, 0, 0, "");
    s.push(r);
    while(!s.empty()){
        CityConnections temp = connections.getConnection(s.top().getDest());
        if(s.top().getDest() == dest){
            storePath(s);
            s.pop();
        }
        else{
            if(temp.getIter() == temp.getSize()){
                s.pop();
                temp.setIter(0);
            }
            bool check = false;
            for(int k = 0; k< s.getSize(); k++){
                if(temp.getRouteData(temp.getIter()).getDest() == s.getElement(k).getDest())
                    check = true;
            }
            if(!check)
                s.push(temp.getRouteData(temp.getIter()));
            temp.moveIter();
        }
    }
}
void Manager::storePath(Stack& s){

}
void Manager::print(){

}