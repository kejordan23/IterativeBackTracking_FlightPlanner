// Project 4: Flight Planner
// Author: Kylie Jordan
//
// StackTests.cpp
//
// This source file uses TDD CATCH tests to evaluate the Stack class

#include "catch.hpp"
#include "DSDLinkedList.h"
#include "DSString.h"
#include "AdjList.h"
#include "CityConnections.h"
#include "RouteData.h"
#include "Stack.h"

TEST_CASE ("Stack class"){
    Stack<RouteData> s;
    Stack<RouteData> t;
    Stack<RouteData> o;
    RouteData b("Austin", 98, 47, "Spirit");
    RouteData c("Austin", 98, 59, "American");
    RouteData d("Houston", 95, 39, "United");
    RouteData e("Houston", 101, 51, "Spirit");
    RouteData f("Chicago", 144, 192, "American");
    s.push(b);
    s.push(c);
    s.push(d);
    s.push(e);
    s.push(f);
    t.push(c);
    t.push(f);
    o.push(b);
    o.push(d);
    o.push(e);

    SECTION("getSize()"){
        REQUIRE((s.getSize() == 5));
        REQUIRE((t.getSize() == 2));
        REQUIRE((o.getSize() == 3));
    }
    SECTION("top()"){
        REQUIRE((s.top().getDest() == "Chicago"));
        REQUIRE((t.top().getDest() == "Chicago"));
        REQUIRE((o.top().getDest() == "Houston"));
    }
    SECTION("getElement(index)"){
        REQUIRE((s.getElement(0).getDest() == "Austin"));
        REQUIRE((s.getElement(3).getDest() == "Houston"));
        REQUIRE((t.getElement(1).getDest() == "Chicago"));
        REQUIRE((o.getElement(0).getDest() == "Austin"));
        REQUIRE((o.getElement(2).getDest() == "Houston"));
    }
    SECTION("push(RouteData)"){
        Stack<RouteData> z;
        z.push(e);
        z.push(d);
        z.push(b);
        z.push(f);
        REQUIRE((z.getElement(0).getDest() == "Houston"));
        REQUIRE((z.getElement(1).getDest() == "Houston"));
        REQUIRE((z.getElement(2).getDest() == "Austin"));
        REQUIRE((z.getElement(3).getDest() == "Chicago"));
    }
    SECTION("pop()"){
        s.pop();
        t.pop();
        o.pop();
        REQUIRE((s.getSize() == 4));
        REQUIRE((t.getSize() == 1));
        REQUIRE((o.getSize() == 2));
        REQUIRE((s.getElement(3).getDest() == "Houston"));
        REQUIRE((t.getElement(0).getDest() == "Austin"));
        REQUIRE((o.getElement(1).getDest() == "Houston"));
    }
}

