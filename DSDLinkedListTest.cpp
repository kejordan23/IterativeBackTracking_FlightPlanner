// Project 2: Auto Indexer
// Author: Kylie Jordan
//
// DSDLinkedListTest.cpp
//
// This source file uses TDD CATCH tests to evaluate the DSDLinkedList class


#include "catch.hpp"
#include "DSDLinkedList.h"
#include "DSString.h"

//tests the functions with integer values
TEST_CASE ("DSDLinkedList class", "[int]"){
    DSDLinkedList<int> list = DSDLinkedList<int>();
    DSDLinkedList<int> list2 = DSDLinkedList<int>();
    DSDLinkedList<int> list3 = DSDLinkedList<int>();
    for(int i=1; i<=5; i++){
        list.insertAtEnd(i);
    }
    for(int i=2; i<=20; i+=2){
        list2.insertAtEnd(i);
    }
    for(int i=1; i<=20; i+=2){
        list3.insertAtEnd(i);
    }
    SECTION("Equality operators"){
        DSDLinkedList<int> list4 = DSDLinkedList<int>();
        list4 = list;
        REQUIRE((list4.getElement(0) == list.getElement(0)));
        REQUIRE((list4.getElement(1) == list.getElement(1)));
        REQUIRE((list4.getElement(2) == list.getElement(2)));
        REQUIRE((list4.getElement(3) == list.getElement(3)));
        REQUIRE((list4.getElement(4) == list.getElement(4)));
    }
    SECTION("empty()"){
        DSDLinkedList<int> list5 = DSDLinkedList<int>();
        REQUIRE((list.empty() == false));
        REQUIRE((list2.empty() == false));
        REQUIRE((list5.empty() == true));
    }
    SECTION("getElement()"){
        REQUIRE((list2.getElement(0) == 2));
        REQUIRE((list2.getElement(1) == 4));
        REQUIRE((list2.getElement(2) == 6));
        REQUIRE((list2.getElement(3) == 8));
        REQUIRE((list2.getElement(4) == 10));
        REQUIRE((list2.getElement(9) != 8));
    }
    SECTION("getSize()"){
        REQUIRE((list.getSize() == 5));
        REQUIRE((list2.getSize() == 10));
        REQUIRE((list3.getSize() == 10));
    }
    SECTION("insertAtFront()"){
        int i = 10;
        int j = 200;
        int k = 3;
        list.insertAtFront(i);
        list2.insertAtFront(j);
        list3.insertAtFront(k);
        REQUIRE((list.getElement(0) == 10));
        REQUIRE((list2.getElement(0) == 200));
        REQUIRE((list3.getElement(0) == 3));
    }
    SECTION("insertAtEnd()"){
        int i = 10;
        int j = 200;
        int k = 3;
        list.insertAtEnd(i);
        list2.insertAtEnd(j);
        list3.insertAtEnd(k);
        REQUIRE((list.getElement(list.getSize()-1) == 10));
        REQUIRE((list2.getElement(list2.getSize()-1) == 200));
        REQUIRE((list3.getElement(list3.getSize()-1) == 3));
    }
    SECTION("insertAt()"){
        int i = 10;
        int j = 200;
        int k = 3;
        list.insertAt(3, i);
        list2.insertAt(4, j);
        list3.insertAt(5, k);
        REQUIRE((list.getElement(3) == 10));
        REQUIRE((list2.getElement(4) == 200));
        REQUIRE((list3.getElement(5) == 3));
    }
    SECTION("remove()"){
        list.remove(0);
        list2.remove(list2.getSize()-1);
        list3.remove(3);
        REQUIRE((list.getElement(0) == 2));
        REQUIRE((list.getSize() == 4));
        REQUIRE((list2.getElement(list2.getSize()-1) == 18));
        REQUIRE((list2.getSize() == 9));
        REQUIRE((list3.getElement(3) == 9));
        REQUIRE((list3.getSize() == 9));
    }
    SECTION("clear()"){
        list.clear();
        list2.clear();
        list3.clear();
        REQUIRE((list.getSize() == 0));
        REQUIRE((list2.getSize() == 0));
        REQUIRE((list3.getSize() == 0));
    }
}


//tests the functions with DSString values
TEST_CASE("[DSStrings]"){
    DSString a1 = "Kylie";
    DSString a2 = "John";
    DSString a3 = "Byron";
    DSString a4 = "Amy";
    DSString b1 = "cat";
    DSString b2 = "dog";
    DSString b3 = "wolf";
    DSString b4 = "tiger";
    DSString b5 = "possum";
    DSString b6 = "marmot";
    DSString c1 = "house";
    DSString c2 = "car";
    DSString c3 = "trailer";
    DSDLinkedList<DSString> list = DSDLinkedList<DSString>();
    DSDLinkedList<DSString> list2 = DSDLinkedList<DSString>();
    DSDLinkedList<DSString> list3 = DSDLinkedList<DSString>();
    list.insertAtEnd(a1);
    list.insertAtEnd(a2);
    list.insertAtEnd(a3);
    list.insertAtEnd(a4);
    list2.insertAtEnd(b1);
    list2.insertAtEnd(b2);
    list2.insertAtEnd(b3);
    list2.insertAtEnd(b4);
    list2.insertAtEnd(b5);
    list2.insertAtEnd(b6);
    list3.insertAtEnd(c1);
    list3.insertAtEnd(c2);
    list3.insertAtEnd(c3);
    SECTION("Equality operators"){
        DSDLinkedList<DSString> list4 = DSDLinkedList<DSString>();
        list4 = list;
        REQUIRE((list4.getElement(0) == list.getElement(0)));
        REQUIRE((list4.getElement(1) == list.getElement(1)));
        REQUIRE((list4.getElement(2) == list.getElement(2)));
        REQUIRE((list4.getElement(3) == list.getElement(3)));
        REQUIRE((list4.getElement(4) == list.getElement(4)));
    }
    SECTION("empty()"){
        DSDLinkedList<DSString> list5 = DSDLinkedList<DSString>();
        REQUIRE((list.empty() == false));
        REQUIRE((list2.empty() == false));
        REQUIRE((list5.empty() == true));
    }
    SECTION("getElement()"){
        REQUIRE((list2.getElement(0) == "cat"));
        REQUIRE((list2.getElement(1) == "dog"));
        REQUIRE((list2.getElement(2) == "wolf"));
        REQUIRE((list2.getElement(3) == "tiger"));
        REQUIRE((list2.getElement(4) == "possum"));
        REQUIRE((list2.getElement(5) != "0"));
    }
    SECTION("getSize()"){
        REQUIRE((list.getSize() == 4));
        REQUIRE((list2.getSize() == 6));
        REQUIRE((list3.getSize() == 3));
    }
    SECTION("insertAtFront()"){
        DSString i = "Hally";
        DSString j = "giraffe";
        DSString k = "sink";
        list.insertAtFront(i);
        list2.insertAtFront(j);
        list3.insertAtFront(k);
        REQUIRE((list.getElement(0) == "Hally"));
        REQUIRE((list2.getElement(0) == "giraffe"));
        REQUIRE((list3.getElement(0) == "sink"));
    }
    SECTION("insertAtEnd()"){
        DSString i = "Hally";
        DSString j = "giraffe";
        DSString k = "sink";
        list.insertAtEnd(i);
        list2.insertAtEnd(j);
        list3.insertAtEnd(k);
        REQUIRE((list.getElement(list.getSize()-1) == "Hally"));
        REQUIRE((list2.getElement(list2.getSize()-1) == "giraffe"));
        REQUIRE((list3.getElement(list3.getSize()-1) == "sink"));
    }
    SECTION("insertAt()"){
        DSString i = "Hally";
        DSString j = "giraffe";
        DSString k = "sink";
        list.insertAt(3, i);
        list2.insertAt(4, j);
        list3.insertAt(1, k);
        REQUIRE((list.getElement(3) == "Hally"));
        REQUIRE((list2.getElement(4) == "giraffe"));
        REQUIRE((list3.getElement(1) == "sink"));
    }
    SECTION("remove()"){
        list.remove(0);
        list2.remove(list2.getSize()-1);
        list3.remove(1);
        REQUIRE((list.getElement(0) == "John"));
        REQUIRE((list.getSize() == 3));
        REQUIRE((list2.getElement(list2.getSize()-1) == "possum"));
        REQUIRE((list2.getSize() == 5));
        REQUIRE((list3.getElement(1) == "trailer"));
        REQUIRE((list3.getSize() == 2));
    }
    SECTION("clear()"){
        list.clear();
        list2.clear();
        list3.clear();
        REQUIRE((list.getSize() == 0));
        REQUIRE((list2.getSize() == 0));
        REQUIRE((list3.getSize() == 0));
    }
}
