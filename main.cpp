#include <iostream>
#include "Redactor.h"
#include "ObjectAnalyzer.h"
#include "Validator.h"
#include <string>
#include "Object.h"
#include "Parser.h"
#include "ArrayValue.h"

using namespace std;

void printValue(Value *value){
    if (value)
}

int main() {
    setlocale(LC_ALL, "RUS");
    string str = "{\n"
                 "  \"title\":\"Совещание\",\n"
                 "  \"occupiedBy\":[{\"name\":\"Иванов\"},{\"name\":\"Петров\"}],\n"
                 "  \"place\":{\"number\":23}\n"
                 "}";
    Parser *parser = new Parser(str, "Pars");
    return 0;
}