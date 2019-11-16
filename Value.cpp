//
// Created by admin on 09.11.2019.
//

#include "Value.h"

void Value::setTableName(string tableName) {
    this -> tableName = tableName;
}

void Value::setName(string name) {
    this ->name = name;
}

void Value::setIsNullable(bool isNullable) {
    this ->isNullable = isNullable;
}

void Value::setSerializeName(string serializeName) {
    this -> serializeName = serializeName;
}

Value::Value(string name, int type)  {
    this->name = name;
    this->type = type;
    this->tableName = name;
    this->serializeName = name;
    this->isNullable = true;
    (this->name)[0] = tolower(name[0]);
}

int Value::getType()  {
    return type;
}


