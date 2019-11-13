//
// Created by admin on 13.11.2019.
//

#ifndef TEST_PARSER_H
#define TEST_PARSER_H

#include "Object.h"

using namespace std;

class Parser {
private:
    string parsedText;
    int pos;
    Object *object;

    void parse();

    string getParsedName();

    string getParsedValue();

    int getParsedType();

public:
    Object *getObject();

    Parser(string parsedText, string objectName);

};


#endif //TEST_PARSER_H
