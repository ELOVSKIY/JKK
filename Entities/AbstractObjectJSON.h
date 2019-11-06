//
// Created by admin on 06.11.2019.
//

#ifndef TEST_ABSTRACTOBJECTJSON_H
#define TEST_ABSTRACTOBJECTJSON_H

#include <string>
using namespace std;

class AbstractObjectJSON {
private:

    string serializedName;
    string columnName;
    string className;
    string typeName;

    bool ingored;
    bool needAdapter;
    bool nullable;
    bool primaryKey;
    bool autoGenerate;

public:
    virtual string getEntityString();
    bool isIgnored();
    bool isPrimaryKey();
    bool isAutoGenerate();
    bool isNullable();
    bool isNeedAdapter();
};
#endif //TEST_ABSTRACTOBJECTJSON_H
