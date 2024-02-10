// DictionaryPractice.cpp
#include "DictionaryPractice.h"  // Include the header file
#include <cassert>
#include <iostream> 

using namespace std;


// Constructor implementation
DictionaryPractice::DictionaryPractice() {
    mapHeap = new unordered_map<string, int>();
}

DictionaryPractice::~DictionaryPractice() {
    // alternatively, could use smart ptr
    delete mapHeap;
}

void DictionaryPractice::act() {

    cout << "Running DictionaryPractice" << endl;

    mapStack["rabbit"] = 5;
    unordered_map<string, int> newMap = actOnStack(mapStack);
    
    // pass by value is not affected
    assert(mapStack.size() == 1);

    // returned copied object by value
    assert(newMap.size() == 2);

    // will add total of 3 elements.
    actOnHeap(*mapHeap);
    assert(mapHeap->size() == 3);
    mapHeap->clear();

    iteratorPractice(*mapHeap);
    assert(mapHeap->size() == 4);
}

unordered_map<string, int> DictionaryPractice::actOnStack(unordered_map<string, int> map) {
    /**
     * map is not a pointer. Caller will pass in a copy of map.
     * 
     */
    map["input1"] = 4;

    // returns by value
    return map;
}

void DictionaryPractice::actOnHeap(unordered_map<string, int> &map) {

    assert(map.empty() == true);

    map["first"] = 1;
    map["second"] = 2;
    map.insert({"third", 3});

    int firstResult = map["first"];
    // exists
    assert(firstResult == 1);

    // find call will return an interator instead.
    auto secondResultIt = map.find("second");
    int secondResult = secondResultIt->second;
    // map.end() means item was not found.
    assert(secondResultIt != map.end() && secondResult == 2);

    // accessing non existing key will actually create {"meow": 0}
    int nonExisting1 = map["meow"];
    assert(map.find("meow")->second == 0);
    assert(map.size() == 4);

    auto nonExisting2 = map.find("woof");
    assert(nonExisting2 == map.end());

    // using iterator to find makes sure no side effect of adding.
    assert(map.size() == 4);

    int numItemsDeleted = map.erase("first");
    assert(numItemsDeleted == 1);
    int numNonExistingDeleted = map.erase("non-existig-key");
    assert(numNonExistingDeleted == 0);

    assert(map.size() == 3);

    // nothing happens
    for (auto entry : map) {
        string key = entry.first;
        entry.second = 10000;
    }

    assert(map["second"] == 2);

    // will modify map.
    for (auto& entry : map) {
        string key = entry.first;
        entry.second = 10000;
    }

    assert(map["second"] == 10000);
}

void DictionaryPractice::iteratorPractice(unordered_map<string, int>& map) {
    map = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}};

    auto it = map.begin();
    auto end = map.end();
    
    while (it != end) {
        string key = it->first;
        it -> second = it->second + 10;
        ++it;
    }

    assert(map.find("one")->second == 11);
}