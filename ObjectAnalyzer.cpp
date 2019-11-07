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
    calculateBoolCount();
    calculateNumbCount();
    calculateStringCount();
    calculateObjectCount();
    calculateNullCount();
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

void ObjectAnalyzer::calculateArrayCount() { //TODO WTF
   arrayCount += elementAnalyzer -> getArrayCount();
}

void ObjectAnalyzer::calculateNullCount() { // TODO TESTED
   nullCount += elementAnalyzer ->getNullCount();
}

void ObjectAnalyzer::calculateStringCount() { //TODO ЕБАННЫЕ ПАЛОЧКИ ПРИДЕТСЯ ФИКСИТЬ МБ (протещено)
    stringCount += elementAnalyzer ->getStringCount();
}

void ObjectAnalyzer::calculateBoolCount() { // TODO TESTED
    boolCount += elementAnalyzer ->getBoolCount();
}


void ObjectAnalyzer::calculateObjectCount() { // TODO TESTED
    objectCount += elementAnalyzer -> getObjectCount();
}

void ObjectAnalyzer::calculateNumbCount() { //TODO TESTED
   numbCount += elementAnalyzer -> getNumbCount();
}