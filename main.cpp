

#define CATCH_CONFIG_RUNNER
#include <fstream>
#include <iostream>
#include "catch.hpp"
#include "AdjList.h"
#include "CityConnections.h"
#include "RouteData.h"
#include "DSString.h"
#include "DSDLinkedList.h"

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

        AdjList a;
        RouteData b("Austin", 98, 47, "Spirit");
        RouteData c("Austin", 98, 59, "American");
        RouteData d("Houston", 95, 39, "United");
        RouteData e("Houston", 101, 51, "Spirit");
        RouteData f("Chicago", 144, 192, "American");
        DSString g = "Dallas";
        DSString h = "Austin";
        DSString i = "Houston";
        DSString j = "Chicago";
        a.addLocDest(g, b);
        a.addLocDest(g, c);
        a.addLocDest(h, d);
        a.addLocDest(g, e);
        a.addLocDest(h, f);

        RouteData k(a.getConnectData(g, h));
        k.print();
    }
    return 0;
}

