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
    calculateArrayCount();
    calculateObjectCount();
    calculateStringCount();
    calculateNumbCount();
    calculateNullCount();
    calculateBoolCount();
    delete(elementAnalyzer);
}

void ObjectAnalyzer::calculateBoolCount() {
    boolCount = elementAnalyzer->getBoolCount();
}

void ObjectAnalyzer::calculateNullCount() {
    nullCount = elementAnalyzer-> getNullCount();
}

void ObjectAnalyzer::calculateNumbCount() {
    numbCount = elementAnalyzer -> getNumbCount();
}

void ObjectAnalyzer::calculateStringCount() {
    stringCount = elementAnalyzer -> getStringCount();
}

void ObjectAnalyzer::calculateObjectCount() {
    objectCount = elementAnalyzer -> getObjectCount();
}

void ObjectAnalyzer::calculateArrayCount() {
    arrayCount = elementAnalyzer -> getArrayCount();
}

int ObjectAnalyzer::getBoolCount() {
    return boolCount;
}

int ObjectAnalyzer::getNullCount(){
    return nullCount;
}

int ObjectAnalyzer::getObjectCount() {
    return objectCount;
}

int ObjectAnalyzer::getStringCount() {
    return stringCount;
}

int ObjectAnalyzer::getNumbCount() {
    return numbCount;
}

int ObjectAnalyzer::getArrayCount() {
    return arrayCount;
}
