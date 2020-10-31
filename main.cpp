

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

int main(int argc, char* argv[]) {
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
        if (!output.is_open() || !input1.is_open() || !input2.is_open())
            cout << "unable to open file" << endl;
        output << "Hello World!" << endl;

        Manager m(input1, input2, output);
    }
    return 0;
}

