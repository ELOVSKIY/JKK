// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Analyzer.h"

Analyzer::Analyzer(string text) {
    analyzedText = text;
}

int Analyzer::getBoolCount() {
    return boolCount;
}

int Analyzer::getObjectCount() {
    return objectCount;
}

int Analyzer::getStringCount() {
    return stringCount;
}

int Analyzer::getNumbCount() {
    return numbCount;
}

void Analyzer::analyze() {
    getNumbCount();
    getStringCount();
    getObjectCount();
    getBoolCount();
    getArrayCount();
    // TODO
}

void Analyzer::calculateArrayCount() {
    arrayCount = 0;

    bool isString = false;

    for (int i = 0; i < analyzedText.length(); i++) {
        if ((analyzedText[i] == '"') && (analyzedText[i - 1] != '\\')) {
            isString = !isString;
            if (!isString) {
                if (analyzedText[i] == '[') {
                    arrayCount++;
                }
            }
        }
    }
}

void Analyzer::calculateStringCount() { // todo test
    stringCount = 0;

    bool isString = false;
    bool isValue = true;
    for (int i = 0; i < analyzedText.length(); i++) {
        if ((analyzedText[i] == '"') && (analyzedText[i - 1] != '\\')) {
            isString = !isString;
            if (isString) {
                isValue = !isValue;
                if (isValue) {
                    stringCount++;
                }
            }
        }
    }
}

void Analyzer::calculateBoolCount() { // todo test
    boolCount = 0;

    bool isString = false;
    for (int i = 0; i < analyzedText.length(); i++) {
        if ((analyzedText[i] == '"') && (analyzedText[i - 1] != '\\')) {
            isString = !isString;
            if (!isString) {
                if (((analyzedText[i - 3] == 't') && (analyzedText[i - 2] == 'r') &&
                     (analyzedText[i - 1] == 'u') && (analyzedText[i] == 'e')) ||
                    ((analyzedText[i - 4] == 'f') && (analyzedText[i - 3] == 'a') &&
                     (analyzedText[i - 2] == 'l') && (analyzedText[i - 1] == 's') &&
                     (analyzedText[i] == 'e')))
                    boolCount++;

            }
        }
    }
} // todo test

void Analyzer::calculateObjectCount() { // todo test
    objectCount = 0;

    bool isString = false;

    for (int i = 0; i < analyzedText.length(); i++) {
        if ((analyzedText[i] == '"') && (analyzedText[i - 1] != '\\')) {
            isString = !isString;
            if (!isString) {
                if (analyzedText[i] == '{') {
                    objectCount++;
                }
            }
        }
    }
}

void Analyzer::calculateNumbCount() {
    // TODO
}

// ---------------------------------------------------------------------------
#pragma package(smart_init)
