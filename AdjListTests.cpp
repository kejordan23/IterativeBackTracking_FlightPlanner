// Project 4: Flight Planner
// Author: Kylie Jordan
//
// AdjListTests.cpp
//
// This source file uses TDD CATCH tests to evaluate the AdjList class

#include "catch.hpp"
#include "DSDLinkedList.h"
#include "DSString.h"
#include "AdjList.h"
#include "CityConnections.h"
#include "RouteData.h"

TEST_CASE ("AdjList class"){
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

    SECTION("getConnection(city)"){
        REQUIRE((a.getConnection(g).getLoc() == "Dallas"));
        REQUIRE((a.getConnection(h).getLoc() == "Austin"));
    }
    SECTION("getFirstLoc(index)"){
        REQUIRE((a.getFirstLoc(0) == "Dallas"));
        REQUIRE((a.getFirstLoc(1) == "Austin"));
    }
    SECTION("getConnectData(city, dest)"){
        RouteData k(a.getConnectData(g, h));
        REQUIRE((k.getDest() == "Austin"));
        REQUIRE((k.getCost() == 98));
        REQUIRE((k.getTime() == 59));
        REQUIRE((k.getAirline() == "American"));
    }
    SECTION("addLocDest(city, dest)"){
        AdjList z;
        z.addLocDest(g, b);
        z.addLocDest(g, e);
        z.addLocDest(h, d);
        REQUIRE((z.getFirstLoc(0) == "Dallas"));
        REQUIRE((z.getConnection(g).getRouteData(0).getDest() == "Austin"));
        REQUIRE((z.getConnection(g).getRouteData(1).getDest() == "Houston"));
        REQUIRE((z.getFirstLoc(1) == "Austin"));
        REQUIRE((z.getConnection(h).getRouteData(0).getDest() == "Houston"));
    }
}
