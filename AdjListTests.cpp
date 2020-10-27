//
// Created by Kylie Jordan on 10/25/20.
//

#include "catch.hpp"
#include "DSDLinkedList.h"
#include "DSString.h"
#include "AdjList.h"
#include "CityConnections.h"
#include "RouteData.h"

TEST_CASE("AdjList class"){
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
    SECTION("getFirstLoc(index)"){
        REQUIRE((a.getFirstLoc(0) == "Dallas"));
        REQUIRE((a.getFirstLoc(1) == "Dallas"));
        REQUIRE((a.getFirstLoc(2) == "Austin"));
        REQUIRE((a.getFirstLoc(3) == "Dallas"));
        REQUIRE((a.getFirstLoc(4) == "Austin"));
    }
    SECTION("getConnectData(city, dest)"){
        RouteData b = a.getConnectData(g, h);
        RouteData c = a.getConnectData(h, i);
        RouteData d = a.getConnectData(g, i);
        REQUIRE((b.getDest() == "Austin"));
        REQUIRE((b.getCost() == 98));
        REQUIRE((b.getTime() == 47));
        REQUIRE((b.getAirline() == "Spirit"));
    }
}
