//
// Created by Kylie Jordan on 10/25/20.
//
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "DSDLinkedList.h"
#include "DSString.h"
#include "CityConnections.h"
#include "RouteData.h"
#include "AdjList.h"

using namespace std;

int AdjList::getSize(){
    return list.getSize();
}
CityConnections& AdjList::getConnection(DSString& city){
    int index1 = -1;
    for (int i = 0; i < list.getSize(); i++){
        if(list.getElement(i).getLoc() == city)
            index1 = i;
    }
    return list.getElement(index1);
}
DSString& AdjList::getFirstLoc(int i){
    return list.getElement(i).getLoc();
}
RouteData& AdjList::getConnectData(DSString& city, DSString& dest){
    int index1 = -1;
    for (int i = 0; i < list.getSize(); i++){
        if(list.getElement(i).getLoc() == city)
            index1 = i;
    }
    if(index1 != -1) {
        int index2 = -1;
        for (int j = 0; j < list.getElement(index1).getSize(); j++) {
            if (list.getElement(index1).getRouteData(j).getDest() == dest)
                index2 = j;
        }
        if (index2 != -1)
            return list.getElement(index1).getRouteData(index2);
    }
}
void AdjList::addLocDest(DSString& city, RouteData& dest){
    if(list.empty()){
        CityConnections c(city, dest);
        list.insertAtEnd(c);
    }
    else{
        int index = -1;
        for(int i = 0; i< list.getSize(); i++){
            if(list.getElement(i).getLoc() == city)
                index = i;
        }
        if(index != -1)
            list.getElement(index).addConnection(dest);
        else if (index == -1){
            CityConnections c(city, dest);
            list.insertAtEnd(c);
        }
    }
}
void AdjList::print(){
    for(int i = 0; i< list.getSize(); i++){
        cout<<getFirstLoc(i)<<endl;
        list.getElement(i).print();
        cout<<endl;
    }
}
