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

public:

    ObjectAnalyzer(string text);
};

#endif //TEST_OBJECTANALYZER_H
