//
// Created by admin on 07.11.2019.
//

#ifndef TEST_ARRAYANALYZER_H
#define TEST_ARRAYANALYZER_H

#include <string>
#include "list"
using namespace std;

class ArrayAnalyzer {

private:
    string analyzedText;
    int nullCount;
    int stringCount;
    int numbCount;
    int arrayCount;
    int objectCount;
    int boolCount;

    list<string> *elementTextList;

    void parseTextIntoElements();
    void calculateValues();

public:

    int getStringCount();

    int getArrayCount();

    int getObjectCount();

    int getBoolCount();

    int getNumbCount();

    int getNullCount();

    ArrayAnalyzer(string
    text);
};

#endif //TEST_ARRAYANALYZER_H
