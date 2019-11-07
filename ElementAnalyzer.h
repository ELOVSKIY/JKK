//
// Created by admin on 07.11.2019.
//

#ifndef TEST_ELEMENTANALYZER_H
#define TEST_ELEMENTANALYZER_H
#include <string>
#include "Analyzer.h"
using namespace std;

class ElementAnalyzer: public AnalyzerInterface {
private:
    string analyzedText;
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

    string getNextObject(int *pos);

    string getNextArray(int *pos);

public:

    ElementAnalyzer(string text);

    int getArrayCount();

    int getNumbCount();

    int getStringCount();

    int getObjectCount();

    int getNullCount();

    int getBoolCount();

};
#endif //TEST_ELEMENTANALYZER_H
