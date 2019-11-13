//
// Created by admin on 13.11.2019.
//

#include "Parser.h"

Object *Parser::getObject() {
    return object;
}

Parser::Parser(string parsedText, string objectName) : parsedText(parsedText) {
    object = new Object(objectName);
    pos = 0;
}

int Parser::getParsedType() {
    return 0;
}

void Parser::parse() {

}

string Parser::getParsedName() {

}

string Parser::getParsedValue() {

}
