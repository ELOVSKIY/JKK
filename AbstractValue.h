//
// Created by admin on 09.11.2019.
//

#ifndef TEST_ABSTRACTVALUE_H
#define TEST_ABSTRACTVALUE_H

#include <string>

using namespace std;


class AbstractValue {
protected:
    string name;
    string serializeName;
    string tableName;
    int type;
    bool isNullable;
public:
    static const int TYPE_OBJECT = 0;
    static const int TYPE_NUMB = 1;
    static const int TYPE_STRING = 2;
    static const int TYPE_BOOL = 3;
    static const int TYPE_ARRAY = 4;
    static const int TYPE_ANY = 5;

    void setName(string name);

    void setSerializeName(string serializeName);

    void setIsNullable(bool isNullable);

    void setTableName(string tableName);

    AbstractValue(string name, int type);

};


#endif //TEST_ABSTRACTVALUE_H
