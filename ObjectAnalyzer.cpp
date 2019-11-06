//
// Created by admin on 05.11.2019.
//

#include "ObjectAnalyzer.h"
#include "Redactor.h"


ObjectAnalyzer::ObjectAnalyzer(string text) {
    //TODO НАДО ЛИ РЕДАКТОР?
    auto redactor = new Redactor(text);
    analyzedText = redactor->getCompressedText();
    numbCount = 0;
    arrayCount = 0;
    boolCount = 0;
    objectCount = 0;
    stringCount = 0;
    calculateArrayCount();
    calculateBoolCount();
    calculateNumbCount();
    calculateStringCount();
    calculateObjectCount();
}

int ObjectAnalyzer::getBoolCount() {
    return boolCount;
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

void ObjectAnalyzer::calculateArrayCount() {
    bool isString = false;
    for (int i = 0; i < analyzedText.length(); i++) {
        if ((analyzedText[i] == '"') && (analyzedText[i - 1] != '\\')) {
            isString = !isString;
        }
        if (!isString) {
            if (analyzedText[i] == '[') {
                arrayCount++;
            }
        }
    }
}

void ObjectAnalyzer::calculateStringCount() { //TODO ЕБАННЫЕ ПАЛОЧКИ ПРИДЕТСЯ ФИКСИТЬ МБ (протещено)
    int quotesCount = 0;
    int objectDeep = 0;
    int arrayDeep = 0;
    bool isString = false;
    for (int i = 0; i < analyzedText.length(); i++) {
        if ((analyzedText[i] == '"') && (analyzedText[i - 1] != '\\')) {
            isString = !isString;
            if ((objectDeep == 1) && (arrayDeep == 0)) {
                quotesCount++;
                if (quotesCount == 4) {
                    stringCount++;
                    quotesCount = 0;
                }
            }

        } else if ((!isString) && (analyzedText[i] == '[')) {
            arrayDeep++;
        } else if ((!isString) && (analyzedText[i] == ']')) {
            arrayDeep--;
        } else if ((!isString) && (analyzedText[i] == '{')) {
            objectDeep++;
        } else if ((!isString) && (analyzedText[i] == '}')) {
            objectDeep--;
        } else if ((quotesCount == 2) &&
                   ((analyzedText[i] == ',') || (analyzedText[i] == '[') || (analyzedText[i] == '{'))) {
            quotesCount = 0;
        }
    }
}

void ObjectAnalyzer::calculateBoolCount() { // todo test
    bool isString = false;
    for (int i = 0; i < analyzedText.length(); i++) {
        if ((analyzedText[i] == '"') && (analyzedText[i - 1] != '\\')) {
            isString = !isString;
        }
        if (!isString) {
            if (((analyzedText[i - 3] == 't') && (analyzedText[i - 2] == 'r') &&
                 (analyzedText[i - 1] == 'u') && (analyzedText[i] == 'e')) ||
                ((analyzedText[i - 4] == 'f') && (analyzedText[i - 3] == 'a') &&
                 (analyzedText[i - 2] == 'l') && (analyzedText[i] - 1 == 's') &&
                 (analyzedText[i] == 'e')))
                boolCount++;

        }
    }
}

void ObjectAnalyzer::calculateInnerObject(ObjectAnalyzer *object) {
    stringCount += object->getStringCount();
    numbCount += object->getNumbCount();
    boolCount += object->getBoolCount();
    objectCount += object->getObjectCount();
    arrayCount += object->getArrayCount();
}

string ObjectAnalyzer::getNextObject(int *pos) {
    string objectText = "";
    int deepLevel = 0;
    bool isString = false;
    for (int i = *pos; i < analyzedText.length(); i++) {
        objectText = objectText + analyzedText[i];
        if ((analyzedText[i] == '"') && (analyzedText[i - 1] != '\\')) {
            isString = !isString;
        }
        if ((!isString) && (analyzedText[i] == '{')) {
            deepLevel++;
        }
        if ((!isString) && (analyzedText[i] == '}')) {
            deepLevel--;
            if (deepLevel == 0) {
                *pos = i;
                break;
            }
        }
    }
    return objectText;
}

void ObjectAnalyzer::calculateObjectCount() { // todo test
    bool isString = false;
    int arrayDeep = 0;
    for (int i = 1; i < analyzedText.length(); i++) {
        if ((analyzedText[i] == '"') && (analyzedText[i - 1] != '\\')) {
            isString = !isString;
        }
        if ((!isString) && (analyzedText[i] == '[')) {
            arrayDeep++;
        }
        if ((!isString) && (analyzedText[i] == ']')) {
            arrayDeep--;
        }
        if ((!isString) && (arrayDeep == 0)) {
            if (analyzedText[i] == '{') {
                objectCount++; // TODO МОЖНО ПО ДЕФОЛТУ ПОСТАВИТЬ ОДИН И УБРАТЬ ЭТО
                string objectText = getNextObject(&i);
                auto *analyzer = new ObjectAnalyzer(objectText);
                calculateInnerObject(analyzer);
            }
        }
    }
}

bool isDigit(char c) {
    bool correct = ((c >= '0') && (c <= '9'));
    return correct;
}

void ObjectAnalyzer::calculateNumbCount() {
    bool isString = false;
    int arrayDeep = 0;
    int objectDeep = 0;
    for (int i = 0; i < analyzedText.length(); i++) {
        char what = analyzedText[i];
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
            if ((analyzedText[i] == ':') && isDigit(analyzedText[i + 1])) {
                if ((objectDeep == 1) && (arrayDeep == 0)) {
                    numbCount++;
                }
            }
        }
    }
}