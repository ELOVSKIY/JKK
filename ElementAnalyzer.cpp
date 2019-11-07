//
// Created by admin on 07.11.2019.
//

#include "ElementAnalyzer.h"
#include "ObjectAnalyzer.h"
#include "Redactor.h"


ElementAnalyzer::ElementAnalyzer(string text) {
    auto redactor = new Redactor(text);
    analyzedText = redactor->getCompressedText();
    numbCount = 0;
    arrayCount = 0;
    boolCount = 0;
    objectCount = 0;
    stringCount = 0;
    nullCount = 0;

    calculateArrayCount();
    calculateBoolCount();
    calculateNumbCount();
    calculateStringCount();
    calculateObjectCount();
    calculateNullCount();
}

int ElementAnalyzer::getBoolCount() {
    return boolCount;
}

int ElementAnalyzer::getNullCount() {
    return nullCount;
}
`
int ElementAnalyzer::getObjectCount() {
    return objectCount;
}

int ElementAnalyzer::getStringCount() {
    return stringCount;
}

int ElementAnalyzer::getNumbCount() {
    return numbCount;
}

int ElementAnalyzer::getArrayCount() {
    return arrayCount;
}

void ElementAnalyzer::calculateArrayCount() { //TODO WTF
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

void ElementAnalyzer::calculateNullCount() { // TODO TESTED
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
                if ((analyzedText[i - 3] == 'n') && (analyzedText[i - 2] == 'u') &&
                    (analyzedText[i - 1] == 'l') && (analyzedText[i] == 'l')) {
                    nullCount++;
                }
            }
        }
    }
}

void ElementAnalyzer::calculateStringCount() { //TODO ЕБАННЫЕ ПАЛОЧКИ ПРИДЕТСЯ ФИКСИТЬ МБ (протещено)
    int quotesCount = 0;
    int objectDeep = 0;
    int arrayDeep = 0;
    bool isString = false;
    for (int i = 0; i < analyzedText.length(); i++) {
        if ((analyzedText[i] == '"') && (analyzedText[i - 1] != '\\')) {
            isString = !isString;
            if ((objectDeep == 0) && (arrayDeep == 0)) {
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

void ElementAnalyzer::calculateBoolCount() { // TODO TESTED
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
                if (((analyzedText[i - 3] == 't') && (analyzedText[i - 2] == 'r') &&
                     (analyzedText[i - 1] == 'u') && (analyzedText[i] == 'e')) ||
                    ((analyzedText[i - 4] == 'f') && (analyzedText[i - 3] == 'a') &&
                     (analyzedText[i - 2] == 'l') && (analyzedText[i - 1] == 's') &&
                     (analyzedText[i] == 'e')))
                    boolCount++;
            }
        }
    }
}

string ElementAnalyzer::getNextObject(int *pos) { // TODO TESTED
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
    objectText = objectText.substr(1, objectText.length() - 2);
    return objectText;
}

void ElementAnalyzer::calculateInnerElement(ElementAnalyzer *element) {
    nullCount += element->getNullCount();
    objectCount += element->getObjectCount();
    stringCount += element->getStringCount();
    numbCount += element->getNumbCount();
    boolCount += element->getBoolCount();
}

void ElementAnalyzer::calculateObjectCount() { // TODO TESTED
    bool isString = false;
    int arrayDeep = 0;
    for (int i = 0; i < analyzedText.length(); i++) {
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
                string elementText = getNextObject(&i);
                auto *analyzer = new ElementAnalyzer(elementText);
                calculateInnerElement(analyzer);
            }
        }
    }
}

bool isDigit(char c) {
    return ((c >= '0') && (c <= '9'));
}

void ElementAnalyzer::calculateNumbCount() { //TODO TESTED
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
            if ((analyzedText[i] == ':') && isDigit(analyzedText[i + 1])) {
                if ((objectDeep == 0) && (arrayDeep == 0)) {
                    numbCount++;
                }
            }
        }
    }
}