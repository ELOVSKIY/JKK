//
// Created by admin on 09.11.2019.
//

#include "AbstractValue.h"

void AbstractValue::setTableName(string tableName) {
    this -> tableName = tableName;
}

void AbstractValue::setName(string name) {
    this ->name = name;
}

void AbstractValue::setIsNullable(bool isNullable) {
    this ->isNullable = isNullable;
}

void AbstractValue::setSerializeName(string serializeName) {
    this -> serializeName = serializeName;
}

AbstractValue::AbstractValue(string name, int type) {
    this->name = name;
    this->type = type;
    this->tableName = name;
    this->serializeName = name;
    this->isNullable = false;
    (this->name)[0] = tolower(name[0]);
}