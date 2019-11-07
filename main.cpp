#include <iostream>
#include "Redactor.h"
#include "ObjectAnalyzer.h"
#include <string.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    string str = "{\n"
                 "  \"name\": \"John\",\n"
                 "  \"age\": 30,\n"
                 "  \"isAdmin\": false,\n"
                 "  \"courses\": [\"html\", \"css\", \"js\"],\n"
                 "  \"wife\": null\n"
                 "}";
    auto *anal = new ObjectAnalyzer(str);
    cout << anal->getNumbCount() << endl << endl;
    cout << anal->getArrayCount() << endl << endl;
    cout << anal->getStringCount() << endl << endl;
    cout << anal->getNullCount() << endl << endl;
    return 0;
}