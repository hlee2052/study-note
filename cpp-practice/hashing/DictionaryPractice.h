// DictionaryPractice.h

#ifndef DICTIONARY_PRACTICE_H
#define DICTIONARY_PRACTICE_H

#include <unordered_map>
#include <string>

using namespace std;

class DictionaryPractice {
private:
    unordered_map<string, int>* mapHeap;
    unordered_map<string, int> mapStack;

    unordered_map<string, int> actOnStack(unordered_map<string, int> map);
    void actOnHeap(unordered_map<string, int> &map);
    void iteratorPractice(unordered_map<string, int> &map);

public:
    // Constructor and Destructor
    DictionaryPractice();
    ~DictionaryPractice();

    void act();
};

#endif // DICTIONARY_PRACTICE_H