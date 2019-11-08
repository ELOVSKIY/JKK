//
// Created by admin on 08.11.2019.
//

#include <iostream>
#include "Validator.h"
#include "Redactor.h"


Validator::Validator(string text) {
    this->text = text;
    isCorrect = true;
    pos = 0;
    try {
        skipObject();
    } catch (int e) {
        isCorrect = false;
    }
}

void Validator::checkEnd() { //TODO расставить надо
    if (pos == text.length()) {
        throw 0;
    }
}

void Validator::skipString() {
    int slashCount = 0;
    while (true) {
        pos++;
        if ((text[pos] == '\"') && (slashCount % 2 == 0)) {
            pos++;
            break;
        } else if (text[pos] == '\\') {
            slashCount++;
        } else {
            slashCount = 0;
        }
    }
}

bool isDigit(char c) {
    return ((c >= '0') && (c <= '9'));
}

void Validator::skipExponent() {//TODO(не обязательная часть)
    pos++; //ручаюсь
    if ((text[pos] == '-') || (text[pos] == '+')) {
        pos++;
    }
    if (!isDigit(text[pos])) {
        throw 0;
    }
    while (isDigit(text[pos])) {
        pos++;
    }
}

void Validator::skipFraction() {//TODO
    pos++; //ручаюсь
    if (!isDigit(text[pos])) {
        throw 0;
    }
    while (isDigit(text[pos])) {
        pos++;
    }
}

void Validator::skipNumber() {//TODO
    if (text[pos] == '-') {
        pos++;
    }
    if (text[pos] == '0') {
        pos++;
        if (text[pos] == '.')
            skipFraction();
        if ((text[pos] == 'e') || (text[pos] == 'E')) {
            skipExponent();
        }
    } else {
        if ((isDigit(text[pos])) && (text[pos] != '0')) {
            pos++;
        } else {
            throw 0; // ошибка
        }
        while (isDigit(text[pos])) {
            pos++;
        }
        if (text[pos] == '.')
            skipFraction();
        if ((text[pos] == 'e') || (text[pos] == 'E')) {
            skipExponent();
        }
    }
}

bool Validator::isCorrectJSON() {
    return isCorrect;
}

void Validator::skipFalse() {
    if (text[pos] == 'f') {
        pos++;
    } else {
        throw 0;
    }
    if (text[pos] == 'a') {
        pos++;
    } else {
        throw 0;
    }
    if (text[pos] == 'l') {
        pos++;
    } else {
        throw 0;
    }
    if (text[pos] == 's') {
        pos++;
    } else {
        throw 0;
    }
    if (text[pos] == 'e') {
        pos++;
    } else {
        throw 0;
    }
}

void Validator::skipTrue() {
    if (text[pos] == 't') {
        pos++;
    } else {
        throw 0;
    }
    if (text[pos] == 'r') {
        pos++;
    } else {
        throw 0;
    }
    if (text[pos] == 'u') {
        pos++;
    } else {
        throw 0;
    }
    if (text[pos] == 'e') {
        pos++;
    } else {
        throw 0;
    }
}

void Validator::skipNull() {
    if (text[pos] == 'n') {
        pos++;
    } else {
        throw 0;
    }
    if (text[pos] == 'u') {
        pos++;
    } else {
        throw 0;
    }
    if (text[pos] == 'l') {
        pos++;
    } else {
        throw 0;
    }
    if (text[pos] == 'l') {
        pos++;
    } else {
        throw 0;
    }
}

bool Validator::isWhiteSpace(char c) {
    if (c == ' ') {
        return true;
    } else if (c == '\n') {
        return true;
    } else if (c == '\r') {
        return true;
    } else if (c == '\t') {
        return true;
    } else {
        return false;
    }
}

void Validator::skipWhiteSpace() {
    while (isWhiteSpace(text[pos])) {
        pos++;
    }
}

void Validator::skipValue() {//TODO
    skipWhiteSpace();
    switch (text[pos]) {
        case '\"':
            skipString();
            break;
        case '[':
            skipArray();
            break;
        case '{':
            skipObject();
            break;
        case 't':
            skipTrue();
            break;
        case 'f':
            skipFalse();
            break;
        case 'n':
            skipNull();
            break;
        default: {
            if ((isDigit(text[pos])) || (text[pos] == '-')) {
                skipNumber();
            } else {
                throw 0;
            }
        }
    }
    skipWhiteSpace();
}

void Validator::skipObject() { //TODO
    pos++;
    skipWhiteSpace();
    if (text[pos] == '}') {
        pos++;
    } else if (text[pos] == '\"') {
        skipString();
        skipWhiteSpace();
        if (text[pos] == ':') {
            pos++;
        } else {
            throw 0;
        }
        skipValue();
        while (text[pos] != '}') {
            char wtf = text[pos]; //TODO DEBUG
            if (text[pos] == ',') {
                pos++;
                skipWhiteSpace();
                if (text[pos] == '\"') {
                    skipString();
                    skipWhiteSpace();
                    if (text[pos] == ':') {
                        pos++;
                    } else {
                        throw 0;
                    }
                    skipValue();
                } else {
                    throw 0;
                }
            } else {
                throw 0;
            }
        }
        pos++;
    } else {
        throw 0;
    }
}

void Validator::skipArray() { //TODO()
    pos++; // ручаюсь
    if ((isWhiteSpace(text[pos])) || (text[pos] == ']')) {
        skipWhiteSpace();
        if (text[pos] == ']') {
            pos++;
        } else {
            throw 0;
        }
    } else {
        skipValue();
        while (text[pos] != ']') {
            char wtf = text[pos]; //TODO DEBUG
            if (text[pos] == ',') {
                pos++;
                skipValue();
            } else {
                throw 0;
            }
        }
        pos++;
    }
}