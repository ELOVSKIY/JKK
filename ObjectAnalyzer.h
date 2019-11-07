//
// Created by admin on 05.11.2019.
//

#ifndef TEST_OBJECTANALYZER_H
#define TEST_OBJECTANALYZER_H

#include <string>
#include "ElementAnalyzer.h"
using namespace std;

class ObjectAnalyzer {
private:
    string analyzedText;
    ElementAnalyzer *elementAnalyzer;
    int nullCount;
    int stringCount;
    int numbCount;
    int arrayCount;
    int objectCount;
    int boolCount;

    void calculateArrayCount();

    void calculateStringCount();

    void calculateNumbCount();

    void calculateObjectCount();

    void calculateBoolCount();


    void calculateNullCount();

public:
    int getStringCount();

    int getArrayCount();

    int getObjectCount();

    int getBoolCount();

    int getNumbCount();

    int getNullCount();

    ObjectAnalyzer(string text);
};
#endif //TEST_OBJECTANALYZER_H
