//
// Created by admin on 07.11.2019.
//

#include "ArrayAnalyzer.h"
#include "ElementAnalyzer.h"
#include "ObjectAnalyzer.h"

ArrayAnalyzer::ArrayAnalyzer(string text) { // TODO ОСВОБОЖДЕНИЕ ПАМЯТИ
    analyzedText = text.substr(1, text.size() - 1); //TODO() ПОЧЕМУ 1

    numbCount = 0;
    arrayCount = 0;
    boolCount = 0;
    objectCount = 0;
    stringCount = 0;
    nullCount = 0;
    elementTextList = new list<string>();
    parseTextIntoElements();
    calculateValues();
    delete(elementTextList);

}

bool ArrayAnalyzer::isDigit(char c) {
    return ((c >= '0') && (c <= '9'));
}

void ArrayAnalyzer::calculateValues() { //TODO НЕТ ПРОВЕРКИ НА МАССИВ
    for (string text : *elementTextList){
        if (text[0] == '{') {
            AnalyzerInterface *analyzer = new ObjectAnalyzer(text);
            numbCount = max(numbCount, analyzer -> getNumbCount());
            stringCount = max(stringCount, analyzer -> getStringCount());
            boolCount = max(boolCount, analyzer -> getBoolCount());
            objectCount = max(objectCount, analyzer -> getObjectCount());
            arrayCount = max(arrayCount, analyzer -> getArrayCount());
            nullCount = max(numbCount, analyzer -> getNullCount());
            delete(analyzer);
        } else{
            if (text[0] == 't') boolCount = 1;
            if (text[0] == 'f') boolCount = 1;
            if (text[0] == 'n') nullCount = 1;
            if (text[0] == '\"') stringCount = 1;
            if (isDigit(text[0])) numbCount = 1;
        }

    }
}

void ArrayAnalyzer::parseTextIntoElements() {
    string elementText;
    bool isString = false;
    int arrayDeep = 0;
    int objectDeep = 0;
    for (int i = 0; i < analyzedText.length(); i++) {
        elementText = elementText + analyzedText[i];
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
                    elementText = elementText.substr(0, elementText.length() - 1);
                    elementTextList -> push_front(elementText);
                    elementText.clear();
                }
            }
        }
    }
    if (elementText.length() != 0){
        elementText = elementText.substr(0, elementText.length() - 1);
        elementTextList -> push_front(elementText);
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