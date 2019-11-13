#include <iostream>
#include "Redactor.h"
#include "ObjectAnalyzer.h"
#include "Validator.h"
#include <string>
#include "Object.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    string str = "{\n"
                 "  \"name\": \"John\",\n"
                 "  \"age\": 30, \"isAdmin\": false,\n"
                 "  \"courses\": [\"html\", \"css\", \"js\"],\n"
                 "  \"wife\": null\n"
                 "}";
    Redactor red(str);
    cout<<red.getEditedText()<<endl;
    return 0;
}