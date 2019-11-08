//
// Created by admin on 05.11.2019.
//

#ifndef TEST_OBJECTANALYZER_H
#define TEST_OBJECTANALYZER_H

#include <string>
#include "ElementAnalyzer.h"
#include "Analyzer.h"

using namespace std;

class ObjectAnalyzer : public AnalyzerInterface {
private:
    string analyzedText;
    ElementAnalyzer *elementAnalyzer;
    int nullCount;
    int stringCount;
    int numbCount;
    int arrayCount;
    int objectCount;
    int boolCount;
    void calculateNullCount();
    void calculateBoolCount();
    void calculateStringCount();
    void calculateArrayCount();
    void calculateNumbCount();
    void calculateObjectCount();


public:

    ObjectAnalyzer(string text);

    int getBoolCount();

    int getNullCount();

    int getObjectCount();

    int getStringCount();

    int getNumbCount();

    int getArrayCount();
};

#endif //TEST_OBJECTANALYZER_H
