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
    //DSString d = "Dallas";
    //DSString h = "Chicago";
    //DSString t = "T";
    //connections.print();
    //makePlan(d, h, t);
    fileCheck = false;
    input2.getline(line, 80);
    numLines = atoi(line);
    for(int i = 0; i<numLines; i++){
        input2.getline(line, 80);
        splitLine();
    }
}
void Manager::splitLine(){
    int cost;
    int time;
    char * temp2;
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
        print(delim);
        plans.clear();
    }
}
void Manager::makePlan(DSString& city, DSString& dest, DSString& delim){
    cout<<city<<"->"<<dest<<endl;
    Stack s;
    RouteData r(city, 0, 0, "");
    s.push(r);
    while(!s.empty()){
        CityConnections temp(connections.getConnection(s.top().getDest()));
        if(s.top().getDest() == dest){
            storePath(s, delim);
            s.pop();
        }
        else{
            if(temp.getIter() == temp.getSize()){
                connections.getConnection(s.top().getDest()).setIter(0);
                s.pop();
            }
            else {
                bool check = false;
                for (int k = 0; k < s.getSize(); k++) {
                    if (temp.getRouteData(temp.getIter()).getDest() == s.getElement(k).getDest())
                        check = true;
                }
                if (!check) {
                    connections.getConnection(s.top().getDest()).moveIter();
                    s.push(temp.getRouteData(temp.getIter()));
                } else
                    connections.getConnection(s.top().getDest()).moveIter();
            }
        }
    }
}
void Manager::storePath(Stack& s, DSString& delim){
    int index = 0;
    int time = compTime(s);
    int cost = compPrice(s);
    if (delim == "T"){
        if(plans.empty())
            plans.insertAtEnd(s);
        else if(time>=compTime(plans.getElement(plans.getSize()-1)))
            plans.insertAtEnd(s);
        else if(time<=compTime(plans.getElement(0)))
            plans.insertAtFront(s);
        else {
            int i = 0;
            while (time >= compTime(plans.getElement(i)) && i < plans.getSize()){
                index = i;
                i++;
            }
            plans.insertAt(index, s);
        }
    }
    else{
        if(plans.empty())
            plans.insertAtEnd(s);
        else if(cost>=compPrice(plans.getElement(plans.getSize()-1)))
            plans.insertAtEnd(s);
        else if(cost<=compPrice(plans.getElement(0)))
            plans.insertAtFront(s);
        else {
            int i = 0;
            while (cost >= compPrice(plans.getElement(i)) && i < plans.getSize()){
                index = i;
                i++;
            }
            plans.insertAt(index, s);
        }
    }
}
int Manager::compTime(Stack& s){
    int time = 0;
    for (int i = 1; i < s.getSize(); i++){
        time+=s.getElement(i).getTime();
        if (i>=2 && s.getElement(i).getAirline() != s.getElement(i-1).getAirline())
            time+=22;
    }
    time += ((s.getSize()-2)*43);
    return time;
}
int Manager::compPrice(Stack& s){
    int cost = 0;
    for (int i = 1; i < s.getSize(); i++){
        cost+=s.getElement(i).getCost();
    }
    cost += ((s.getSize()-2)*19);
    return cost;
}
void Manager::print(DSString& delim){
    for(int i = 0; i <plans.getSize(); i++){
        //plans.getElement(i).print();
        if(delim == "T")
            cout<<"Time: "<<compTime(plans.getElement(i))<<endl;
        else
            cout<<"Cost: "<<compPrice(plans.getElement(i))<<endl;
    }
}