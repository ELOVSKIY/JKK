#include "AbstractObjectJSON.h"

//
// Created by admin on 06.11.2019.
//

bool AbstractObjectJSON::isNeedAdapter(){
    return needAdapter;
}

bool AbstractObjectJSON::isNullable(){
    return nullable;
}

bool AbstractObjectJSON::isPrimaryKey(){
    return primaryKey & (!nullable);
}

bool AbstractObjectJSON::isAutoGenerate(){
    return isPrimaryKey() & autoGenerate;
}

bool AbstractObjectJSON::isIgnored() {
    return ingored;
}


#include "AbstractObjectJSON.h"
