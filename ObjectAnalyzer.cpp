//
// Created by admin on 05.11.2019.
//

#include "ObjectAnalyzer.h"
#include "Redactor.h"

//TODO ТРЕТИЙ АНАЛИЗАТОР
ObjectAnalyzer::ObjectAnalyzer(string text) {
    numbCount = 0;
    arrayCount = 0;
    boolCount = 0;
    objectCount = 0;
    stringCount = 0;
    nullCount = 0;

    analyzedText = text.substr(1, text.size()-1);
    elementAnalyzer = new ElementAnalyzer(analyzedText);
}

int ObjectAnalyzer::getBoolCount() {
    return elementAnalyzer -> getBoolCount();
}

int ObjectAnalyzer::getNullCount(){
    return elementAnalyzer -> getNullCount();
}

int ObjectAnalyzer::getObjectCount() {
    return elementAnalyzer -> getObjectCount();
}

int ObjectAnalyzer::getStringCount() {
    return elementAnalyzer -> getStringCount();
}

int ObjectAnalyzer::getNumbCount() {
    return elementAnalyzer -> getNumbCount();
}

int ObjectAnalyzer::getArrayCount() {
    return elementAnalyzer -> getArrayCount();
}
