// SetPractice.cpp
#include <iostream>
#include <unordered_set>
#include <string>
#include <cassert>


using namespace std;

class SetPractice {

private:
    unordered_set<string>* set1;


public:
    SetPractice() {
        set1 = new unordered_set<string>();
    }

    ~SetPractice() {
        delete set1;
    }


    void act() {

        cout << "Running SetPractice" << endl;

        set1->insert("first");
        set1->insert("second");
        set1->insert("third");

        for (auto element: *set1) {
            element += "it wont be added";
        }

        auto firstIt = set1->find("first");
        string firstVal = *firstIt;

        assert(firstVal == "first");


        // remember *set1 for passing in reference
        assert(firstVal == "first");

        // Add a new element
        set1->insert("four");
        // Remove an element
        set1->erase("third");

        //similar to map, you can use iterator to check if item exists
        // but CANT do something like set1["mykey"]

        auto nonExist = set1->find("nonExist");
        assert(nonExist == set1->end());
        assert(set1->size() == 3);
    }
};