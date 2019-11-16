//
// Created by admin on 16.11.2019.
//

#include "KotlinClass.h"
#include "ArrayValue.h"

string KotlinClass::getFileContext(){
    string context;
    context.append("@Entity(tableName = \"");
    context.append(tableName + "\")\n\r");
    context.append("data class ");
    context.append(className + "(");
    for (auto v: *classFields){
        if (isDatabaseAnnotated){
            context.append("   @ColumnInfo(name = \"");
            context.append(v->getTableName() +"\")\n");
        }
        if (isResponseAnnotated){
            context.append("   @SerializedName(\"");
            context.append(v->getSerializeName() +"\")\n");
        }
        context.append("   val ");
        context.append(v->getName());
        context.append(" : ");
        context.append(v->getTypeName());
        context.append(",");
    }
    context[context.length() - 1] = '\n';
    context.append("}");
    if (hasPrimaryKey){
        context.append("{\n"
                       "    @PrimaryKey(autoGenerate = false)\n"
                       "    var id: Int = CURRENT_WEATHER_ID\n"
                       "}");
    }
}

KotlinClass::KotlinClass(Object *object) {
    this->className = object -> getClassName();
    this->tableName = object -> getName();
    classFields = new list<Value*>;
    for (auto v: object->getObjectFields()){
        classFields->push_front(v);
    }
}

void KotlinClass::setIsDatabaseAnnotated(bool isDatabaseAnnotated) {
    this->isDatabaseAnnotated = isDatabaseAnnotated;
}

void KotlinClass::setIsResponseAnnotated(bool isResponseAnnotated) {
    this->isResponseAnnotated = isResponseAnnotated;
}
