//
// Created by admin on 07.11.2019.
//

#ifndef TEST_ARRAYANALYZER_H
#define TEST_ARRAYANALYZER_H

#include <string>
#include "list"
#include "Analyzer.h"

using namespace std;

class ArrayAnalyzer : AnalyzerInterface {

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

    bool isDigit(char c);

public:

    ArrayAnalyzer(string text);

    int getBoolCount();

    int getNullCount();

    int getObjectCount();

    int getStringCount();

    int getNumbCount();

    int getArrayCount();
};

#endif //TEST_ARRAYANALYZER_H
