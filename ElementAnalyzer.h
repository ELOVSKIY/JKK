//
// Created by admin on 07.11.2019.
//

#ifndef TEST_ELEMENTANALYZER_H
#define TEST_ELEMENTANALYZER_H
#include <string>
using namespace std;

class ElementAnalyzer {
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

public:
    int getStringCount();

    int getArrayCount();

    int getObjectCount();

    int getBoolCount();

    int getNumbCount();

    int getNullCount();

    ElementAnalyzer(string text);
};
#endif //TEST_ELEMENTANALYZER_H
