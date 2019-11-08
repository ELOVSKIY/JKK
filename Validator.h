//
// Created by admin on 08.11.2019.
//

#ifndef TEST_VALIDATOR_H
#define TEST_VALIDATOR_H

#include "string"

using namespace std;

class Validator {
private:
    string text;
    bool isCorrect;
    int pos;

    void skipObject();

    void skipString();

    void skipValue();

    void skipArray();

    void skipExponent();

    void skipFraction();

    void skipNumber();

    bool isWhiteSpace(char c);

    void skipWhiteSpace();

    void skipTrue();

    void skipFalse();

    void skipNull();

    void checkEnd();

public:
    Validator(string text);

    bool isCorrectJSON();

};


#endif //TEST_VALIDATOR_H
