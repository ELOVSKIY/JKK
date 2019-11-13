//
// Created by admin on 13.11.2019.
//
#include "Redactor.h"
#include "Parser.h"

Object *Parser::getObject() {
    return object;
}

Parser::Parser(string parsedText, string objectName) : parsedText(parsedText){
    Redactor * redactor = new Redactor(parsedText);
    parsedText = redactor->getCompressedText();
    delete(redactor);
    object = new Object(objectName);
    pos = 0;
    parse();
}

int Parser::getParsedType(string value) {
    if (value[0] == '{'){
        return TYPE_OBJECT;
    }
}

void Parser::parse() {
    pos++; // пропуск открывающей стрелочки
    while (pos < parsedText.length()){
            string name = getParsedName();
            pos++;
            string value = getParsedValue();
            int type = getParsedType(value);
    }
}

string Parser::getParsedName() {
    string name;
    pos++;
    while ((parsedText[pos] != '\"') || (parsedText[pos - 1] != '\\')){
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
    while (true){
        if ((objectDeep == 0) && (arrayDeep == 0) && (!isString) && (parsedText[pos] == ',')){
            break;
        }
        typeValue += parsedText[pos];
        if ((parsedText[pos] != '\"') || (parsedText[pos - 1] != '\\')){
            isString = !isString;
        }
        if (!isString){
            if (parsedText[pos] == '{'){
                objectDeep++;
            }else if (parsedText[pos] == '}'){
                objectDeep--;
            }else if (parsedText[pos] == '['){
                arrayDeep++;
            }else if (parsedText[pos] == ']'){
                arrayDeep--;
            }

        }
        pos++;
    }
    return typeValue;
}
