//
// Created by admin on 09.11.2019.
//

#include "Value.h"
#include "Object.h"
#include "ArrayValue.h"

void Value::setTableName(string tableName) {
    this->tableName = tableName;
}

void Value::setName(string name) {
    this->name = name;
}

void Value::setIsNullable(bool isNullable) {
    this->isNullable = isNullable;
}

void Value::setSerializeName(string serializeName) {
    this->serializeName = serializeName;
}

Value::Value(string name, int type) {
    this->name = name;
    this->type = type;
    this->tableName = name;
    this->serializeName = name;
    this->isNullable = true;
    (this->name)[0] = tolower(name[0]);
}

int Value::getType() {
    return type;
}


string Value::getName() {
    return name;
}

string Value::getSerializeName() {
    return serializeName;
}

string Value::getTableName() {
    return tableName;
}

bool Value::isNullable1() {
    return isNullable;
}

string Value::getTypeName() {
    switch (type){
        case TYPE_ANY:
            return "Any?";
        case TYPE_BOOL:
            return "Boolean?";
        case TYPE_NUMB:
            return "Double?";
        case TYPE_STRING:
            return "String?";
        case TYPE_OBJECT:
            return ((Object*)this)->getClassName() = "?";
        case TYPE_ARRAY:
            return "Array<" + ((ArrayValue*)this)->getArrayValue()->getTypeName() + ">?";
    }
}

bool Value::isSpecialType() {
    return ((type == TYPE_ARRAY) || (type==TYPE_OBJECT));
}


