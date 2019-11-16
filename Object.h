
//
// Created by admin on 09.11.2019.
//

#ifndef TEST_OBJECT_H
#define TEST_OBJECT_H

#include "Value.h"
#include <set>

class Object: public Value {
private:
    set<Value*> objectFields;
    string className;
public:
    string getClassName();

    void addValue(Value *value);

    set<Value*> getObjectFields();

    Object(string name);
};


#endif //TEST_OBJECT_H
