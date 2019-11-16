//
// Created by admin on 16.11.2019.
//

#ifndef TEST_KOTLINCLASS_H
#define TEST_KOTLINCLASS_H

#include <string>
#include <list>
#include "Object.h"
#include "Value.h"

using namespace std;

class KotlinClass {
private:
    string className;
    string fileContext;
    string fileName;
    string tableName;
    bool isDatabaseAnnotated = false;
    bool isResponseAnnotated = false;
    bool hasPrimaryKey = false;
    list<Value*> *classFields;
public:
    void setIsDatabaseAnnotated(bool isDatabaseAnnotated);

    void setIsResponseAnnotated(bool isResponseAnnotated);

    string getFileContext();

    KotlinClass(Object *object);
};


#endif //TEST_KOTLINCLASS_H
