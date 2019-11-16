#include <iostream>
#include "Redactor.h"
#include "ObjectAnalyzer.h"
#include "Validator.h"
#include <string>
#include "Object.h"
#include "Parser.h"
#include "ArrayValue.h"

using namespace std;

void printValue(Value *value) {
    if (value->getType() == TYPE_OBJECT) {
        auto object = (Object *) value;
        auto set = object->getObjectFields();
        for (auto v : set) {
            printValue(v);
        }
    } else if (value->getType() == TYPE_ARRAY) {
        auto array = (ArrayValue *) value;
        auto v = array->getArrayValue();
        printValue(v);
    }
        cout<<value->getName()<<endl;
}

int main() {
    setlocale(LC_ALL, "RUS");
    string str = "{\n"
                 "  \"title\":\"Совещание\",\n"
                 "  \"occupiedBy\":[{\"name\":\"Иванов\"},{\"name\":\"Петров\"}],\n"
                 "  \"place\":{\"number\":23}\n"
                 "}";
    Parser *parser = new Parser(str, "Pars");
    printValue(parser->getObject());
    return 0;
}