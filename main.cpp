// Project 4: Flight Planner
// Author: Kylie Jordan
// Class: CS 2341 section 801
// Lab section: N14
//
// This program takes input information from two files: the first about connecting flights (including their
// destination, time, cost, and airline) and the second about requested flight plans. The information from
// the first file is used to create an adjacency list of CityConnections. The second file also includes how the
// plans should be ordered in output ( T for least-greatest time, C for least-greatest cost). After creating the
// list and making possible plans, the top 3 plans for the designated delimiter (T or C) is printed to output.txt.
//
// main.cpp
//

#define CATCH_CONFIG_RUNNER
#include <fstream>
#include <iostream>
#include "catch.hpp"
#include "AdjList.h"
#include "CityConnections.h"
#include "RouteData.h"
#include "DSString.h"
#include "DSDLinkedList.h"
#include "Manager.h"

using namespace std;

//main() takes command line arguments argv 1: input01.txt, argv 2: input02.txt, and argv 3: output.txt
int main(int argc, char* argv[]) {
    //conditional to run CATCH tests if there are no command line arguments
    if (argc == 1) {
        return Catch::Session().run();
    }
    else {
        ofstream output;
        ifstream input1;
        ifstream input2;
        input1.open(argv[1]);
        input2.open(argv[2]);
        output.open(argv[3]);
        //opening files with a conditional to check if they open correctly
        if (!output.is_open() || !input1.is_open() || !input2.is_open())
            cout << "unable to open file" << endl;

        //creates a Manager object that creates the Adjacency List and outputs the plans to the output file
        Manager m(input1, input2, output);
    }
    return 0;
}

