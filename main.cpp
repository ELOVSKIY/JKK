#include <iostream>
#include "Redactor.h"
#include "ObjectAnalyzer.h"
#include "Validator.h"
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    string str = "{\n"
                 "    \"success\": false,\n"
                 "    \"error\": {\n"
                 "        \"code\": 104,\n"
                 "        \"type\": \"usage_limit_reached\",\n"
                 "        \"info\": \"Your monthly API request volume has been reached. Please upgrade your plan.\"    \n"
                 "    }\n"
                 "}";
    auto *analyzer = new ObjectAnalyzer(str);
    cout<<analyzer->getArrayCount()<<endl;
    cout<<analyzer->getNumbCount()<<endl;
    cout<<analyzer->getStringCount()<<endl;
    cout<<analyzer->getObjectCount()<<endl;
    cout<<analyzer->getBoolCount()<<endl;
    return 0;
}