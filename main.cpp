#include <iostream>
#include "Redactor.h"
#include "ObjectAnalyzer.h"
#include "Validator.h"
#include <string>
#include "Object.h"
#include "Parser.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    string str = "{\n"
                 "  \"title\":\"Conference\",\n"
                 "  \"room\":"
                 "     {"
                 "      \"number\":23,"
                 "      \"participants\":["
                 "                       \"john\","
                 "                        \"ann\""
                 "                       ]"
                 "     }\n"
                 "}";
    Parser *parser = new Parser(str, "Response");
    Object *obj = parser->getObject();
    return 0;
}