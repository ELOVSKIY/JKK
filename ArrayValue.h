//
// Created by admin on 16.11.2019.
//

#ifndef TEST_ARRAYVALUE_H
#define TEST_ARRAYVALUE_H

#include "Value.h"

class ArrayValue: public Value {
private:
    Value *arrayValue;
public:
    ArrayValue(string name, Value *value);

    Value * getArrayValue();
};


#endif //TEST_ARRAYVALUE_H
