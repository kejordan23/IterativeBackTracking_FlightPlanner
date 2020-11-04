// Project 4: Flight Planner
// Author: Kylie Jordan
//
// Manager.cpp
//
// This source file defines all the constructors and functions for the Manager class

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
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
    // creates adjacency list from input1
    fileCheck = true;
    input.getline(line, 80);
    numLines = atoi(line);
    for(int i = 0; i<numLines; i++){
        input.getline(line, 80);
        splitLine(output);
    }
    //makes plans according to info from input2
    fileCheck = false;
    input2.getline(line, 80);
    numLines = atoi(line);
    for(int i = 0; i<numLines; i++){
        input2.getline(line, 80);
        output<<"Flight "<<(i+1)<<": ";
        splitLine(output);
        output<<endl;
    }
}
void Manager::splitLine(ofstream& output){
    int cost;
    int time;
    char * temp2;
    //stores data from input file 1
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
    else{           //stores data from input file 2 and makes plans
        DSString city(temp2);
        temp2 = strtok(nullptr, "|");
        DSString dest(temp2);
        temp2 = strtok(nullptr, "|");
        DSString delim(temp2);

        makePlan(city, dest, delim, output);
        print(output);              //outputs plans to output.txt
        plans.clear();
    }
}
void Manager::makePlan(DSString& city, DSString& dest, DSString& delim, ofstream& output){
    DSString t;
    if(delim == "T")
        t = "Time";
    else
        t = "Cost";
    output<<city<<", "<<dest<<" ("<<t<<")"<<endl;
    Stack<RouteData> s = Stack<RouteData>();                                        //iterative backtracking algorithm
    RouteData r(city, 0, 0, "");//first departure location
    s.push(r);
    while(!s.empty()){
        CityConnections temp(connections.getConnection(s.top().getDest()));
        if(s.top().getDest() == dest){
            storePath(s, delim);        //stores path in ascending order
            s.pop();
        }
        else{
            if(temp.getIter() == temp.getSize()){       //checks if at the end of the connection list
                connections.getConnection(s.top().getDest()).setIter(0);
                s.pop();
            }
            else {
                bool check = false;
                for (int k = 0; k < s.getSize(); k++) {     //checks to see if the connection is on the stack
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
void Manager::storePath(Stack<RouteData>& s, DSString& delim){
    int index = 0;
    int time = compTime(s);
    int cost = compPrice(s);
    if (delim == "T"){          //inserts stack into plans in ascending order by time
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
    else{                       //inserts stack into plans in ascending order by cost
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
int Manager::compTime(Stack<RouteData>& s){
    int time = 0;
    for (int i = 1; i < s.getSize(); i++){
        time+=s.getElement(i).getTime();
        if (i>=2 && s.getElement(i).getAirline() != s.getElement(i-1).getAirline())
            time+=22;
    }
    time += ((s.getSize()-2)*43);
    return time;
}
double Manager::compPrice(Stack<RouteData>& s){
    double cost = 0;
    for (int i = 1; i < s.getSize(); i++){
        cost+=s.getElement(i).getCost();
    }
    cost += ((s.getSize()-2)*19);
    return cost;
}
void Manager::print(ofstream& output){
    if(plans.getSize() == 0)
        output<<"Error. No flightpaths found"<<endl;
    else if (plans.getSize() <3){
        for(int i = 0; i <plans.getSize(); i++){
            output<<"Path "<<(i+1)<<": ";
            plans.getElement(i).print(output);
            output<<" Time: "<<compTime(plans.getElement(i));
            output<<" Cost: "<<fixed<<setprecision(2)<<compPrice(plans.getElement(i))<<endl;
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            output << "Path " << (i + 1) << ": ";
            plans.getElement(i).print(output);
            output << " Time: " << compTime(plans.getElement(i));
            output << " Cost: " << fixed << setprecision(2) << compPrice(plans.getElement(i)) << endl;
        }
    }
}