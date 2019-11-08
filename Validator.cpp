//
// Created by admin on 08.11.2019.
//

#include <iostream>
#include "Validator.h"
#include "Redactor.h"


Validator::Validator(string text) {
    auto *redactor = new Redactor(text);
    this->text = text;
    isCorrect = true;
    pos = 0;
    try {
        skipNumber();
    } catch (int e) {
        isCorrect = false;
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