//
// Created by admin on 07.11.2019.
//

#include "ArrayAnalyzer.h"
#include "ElementAnalyzer.h"
#include "ObjectAnalyzer.h"

ArrayAnalyzer::ArrayAnalyzer(string text) {
    analyzedText = text.substr(1, text.size() - 1);

    numbCount = 0;
    arrayCount = 0;
    boolCount = 0;
    objectCount = 0;
    stringCount = 0;
    nullCount = 0;
    elementTextList = new list<string>();
    calculateValues();
    delete(elementTextList);

}

void ArrayAnalyzer::calculateValues() {
    for (string text : *elementTextList){
        if (text[0] != '{') {
            auto *elAnalyzer = new ElementAnalyzer(text);
        } else{
            auto *elAnalyzer = new ObjectAnalyzer(text);
        }
        numbCount = max(numbCount, elAnalyzer -> getNumbCount());
        stringCount = max(stringCount, elAnalyzer -> getStringCount());
        boolCount = max(boolCount, elAnalyzer -> getBoolCount());
        objectCount = max(objectCount, elAnalyzer -> getObjectCount());
        arrayCount = max(arrayCount, elAnalyzer -> getArrayCount());
        nullCount = max(numbCount, elAnalyzer -> getNullCount());
    }
}

void ArrayAnalyzer::parseTextIntoElements() {
    string elementText;
    bool isString = false;
    int arrayDeep = 0;
    int objectDeep = 0;
    for (int i = 0; i < analyzedText.length(); i++) {
        if ((analyzedText[i] == '"') && (analyzedText[i - 1] != '\\')) {
            isString = !isString;
        } else if ((!isString) && (analyzedText[i] == '[')) {
            arrayDeep++;
        } else if ((!isString) && (analyzedText[i] == ']')) {
            arrayDeep--;
        } else if ((!isString) && (analyzedText[i] == '{')) {
            objectDeep++;
        } else if ((!isString) && (analyzedText[i] == '}')) {
            objectDeep--;
        } else if (!isString) {
            if ((objectDeep == 0) && (arrayDeep == 0)) {
                if (analyzedText[i] == ','){
                    elementText.substr(0, elementText.length() - 1);
                    elementTextList -> push_front(elementText);
                    elementText.clear();
                }
            }
        }
    }
}

int ArrayAnalyzer::getBoolCount() {
    return boolCount;
}

int ArrayAnalyzer::getNullCount() {
    return nullCount;
}

int ArrayAnalyzer::getObjectCount() {
    return objectCount;
}

int ArrayAnalyzer::getStringCount() {
    return stringCount;
}

int ArrayAnalyzer::getNumbCount() {
    return numbCount;
}

int ArrayAnalyzer::getArrayCount() {
    return arrayCount;
}