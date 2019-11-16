//
// Created by admin on 16.11.2019.
//

#ifndef TEST_ARRAYPARSER_H
#define TEST_ARRAYPARSER_H

#include "Value.h"
#include "list"

class ArrayParser {
    string arrayName;
    string parsedText;
    int arrayType;
    int pos;
    Value *value;

    list<string> *arrayElements;

    void parseArrayIntoElements();

    void parse();

    int getParsedType(string value);

    void getArrayType();

    Value *getParserValue();

public:
    ArrayParser(string parsedText, string arrayName);
};


#endif //TEST_ARRAYPARSER_H
