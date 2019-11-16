//
// Created by admin on 09.11.2019.
//

#ifndef TEST_VALUE_H
#define TEST_VALUE_H

#include <string>

using namespace std;
static const int TYPE_ANY = 0;
static const int TYPE_NUMB = 1;
static const int TYPE_STRING = 2;
static const int TYPE_BOOL = 3;
static const int TYPE_ARRAY = 4;
static const int TYPE_OBJECT = 5;


class Value {
protected:
    string name;
    string serializeName;
    string tableName;
    int type;
    bool isNullable;
public:
    int getType();

    void setName(string name);

    string getTypeName();

    string getName();

    string getSerializeName();

    string getTableName();

    bool isSpecialType();

    bool isNullable1();

    void setSerializeName(string serializeName);

    void setIsNullable(bool isNullable);

    void setTableName(string tableName);

    Value(string name, int type);

};


#endif //TEST_VALUE_H
