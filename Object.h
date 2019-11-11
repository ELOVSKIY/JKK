
//
// Created by admin on 09.11.2019.
//

#ifndef TEST_OBJECT_H
#define TEST_OBJECT_H

#include "AbstractValue.h"
#include <set>

class Object: public AbstractValue {
private:
    set<AbstractValue> objectFields;
    string className;
public:
    Object(string name, int type);
};


#endif //TEST_OBJECT_H
