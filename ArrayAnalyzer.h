//
// Created by admin on 07.11.2019.
//

#ifndef TEST_ARRAYANALYZER_H
#define TEST_ARRAYANALYZER_H

#include <string>
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

    void calculateArrayCount();

    void calculateStringCount();

    void calculateNumbCount();

    void calculateObjectCount();

    void calculateBoolCount();

    void calculateInnerObject(ObjectAnalyzer *object);

    void calculateNullCount();

    string getNextObject(int *pos);

public:

    int getStringCount();

    int getArrayCount();

    int getObjectCount();

    int getBoolCount();

    int getNumbCount();

    int getNullCount();

    ObjectAnalyzer(string
    text);
};

#endif //TEST_ARRAYANALYZER_H
