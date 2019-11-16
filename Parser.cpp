//
// Created by admin on 13.11.2019.
//
#include "Redactor.h"
#include "Parser.h"
#include "ArrayParser.h"

Object *Parser::getObject() {
    return object;
}

Parser::Parser(string parsedText, string objectName) : parsedText(parsedText) {
    Redactor *redactor = new Redactor(parsedText);
    this->parsedText = redactor->getCompressedText();
    delete (redactor);
    object = new Object(objectName);
    pos = 0;
    parse();
}

int Parser::getParsedType(string value) {
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

void Parser::parse() {
    pos++; // пропуск открывающей фигурной скобки
    while (pos < parsedText.length()) {
        string name = getParsedName();
        pos++; // пропуск двоеточия между именем и значением
        string value = getParsedValue();
        pos++; //пропуск запятой между value
        int type = getParsedType(value); //TODO ХУЕТА
        if (type == TYPE_ARRAY) {
            ArrayParser *arrayParser = new ArrayParser(value, name);
            object->addValue(arrayParser->getParserValue());
        } else if (type == TYPE_OBJECT) {
            Parser *innerParser = new Parser(value, name);
            object->addValue(innerParser->getObject());
        } else {
            object->addValue(new Value(name, type));
        }
    }
}

string Parser::getParsedName() {
    string name;
    pos++;
    while (true) {
        if ((parsedText[pos] == '\"') && (parsedText[pos - 1] != '\\')) {
            break;
        }
        name += parsedText[pos];
        pos++;
    }
    pos++;
    return name;
}

string Parser::getParsedValue() {
    string typeValue;
    bool isString = false;
    int objectDeep = 0;
    int arrayDeep = 0;
    while (true) {
        if ((objectDeep == 0) && (arrayDeep == 0) && (!isString) &&
            ((parsedText[pos] == ',') || (parsedText[pos]) == '}')) {
            break;
        }
        typeValue += parsedText[pos];
        if ((parsedText[pos] == '\"') && (parsedText[pos - 1] != '\\')) {
            isString = !isString;
        }
        if (!isString) {
            if (parsedText[pos] == '{') {
                objectDeep++;
            } else if (parsedText[pos] == '}') {
                objectDeep--;
            } else if (parsedText[pos] == '[') {
                arrayDeep++;
            } else if (parsedText[pos] == ']') {
                arrayDeep--;
            }

        }
        pos++;
    }
    return typeValue;
}
