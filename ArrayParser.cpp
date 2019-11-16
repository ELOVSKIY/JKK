//
// Created by admin on 16.11.2019.
//

#include "ArrayParser.h"
#include "Object.h"

ArrayParser::ArrayParser(string parsedText, string arrayName) {
    this -> parsedText = parsedText.substr(1, parsedText.size() - 1);
    this->arrayName = arrayName;
    arrayElements = new list<string>();
    arrayType = TYPE_ANY;
    pos= 0;
    parse();
}

int ArrayParser::getParsedType(string value) {
    if (value[0] == '{') {
        return TYPE_OBJECT;
    }
    if (value[0] == 'n') {
        return TYPE_ANY;
    }
    if (value[0] == '[') {
        return TYPE_ARRAY;
    }
    if (value[0] == '\"') {
        return TYPE_STRING;
    }
    if (value[0] == '{') {
        return TYPE_OBJECT;
    }
    if ((value[0] == 't') || (value[0] == 'f')) {
        return TYPE_BOOL;
    }
    return TYPE_NUMB;
}

void ArrayParser::parse() {
    parseArrayIntoElements();
    getArrayType();
    if (arrayType == TYPE_OBJECT){
        value = new Object(arrayName);

    }else{
        value = new Value(arrayName, arrayType);
    }
}

void ArrayParser::getArrayType() {
    for (const string& element : *arrayElements) {
        int type = getParsedType(element);
        arrayType = type | arrayType;
        if ((type != arrayType) && (type != TYPE_ANY)){
            throw 0;
        }
    }
}

void ArrayParser::parseArrayIntoElements() {
    string elementText;
    bool isString = false;
    int arrayDeep = 0;
    int objectDeep = 0;
    for (int i = 0; i < parsedText.length(); i++) {
        elementText += parsedText[i];
        if ((parsedText[i] == '"') && (parsedText[i - 1] != '\\')) {
            isString = !isString;
        } else if (!isString) {
            if (parsedText[i] == '[') {
                arrayDeep++;
            } else if (parsedText[i] == ']') {
                arrayDeep--;
            } else if (parsedText[i] == '{') {
                objectDeep++;
            } else if (parsedText[i] == '}') {
                objectDeep--;
            } else if (parsedText[i] == ',') {
                if ((objectDeep == 0) && (arrayDeep == 0)) {
                    elementText = elementText.substr(0, elementText.length() - 1);
                    arrayElements->push_front(elementText);
                    elementText.clear();
                }
            }
        }
    }
    if (elementText.length() != 0) {
        elementText = elementText.substr(0, elementText.length() - 1);
        arrayElements->push_front(elementText);
    }
}

Value *ArrayParser::getParserValue() {
    return value;
}
