#include <iostream>
#include "Redactor.h"
#include "ObjectAnalyzer.h"
#include <string.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    string str = "{\n"
                 "  \"active\": false,\n"
                 "      \"name\": \"Molecule Man\",\n"
                 "      \"age\": 29\n"
                 "  \"members\":"
                 "    {\n"
                 "      \"name\": \"Molecule Man\",\n"
                 "      \"name\": \"Molecule Man\",\n"
                 "  \"active\": false,\n"

                 "      \"age\": 29\n"
                 "      \"age\": 29\n"
                 "    }\n"
                 "      \"age\": 29\n"
                 "}";
    auto *anal = new ObjectAnalyzer(str);
    cout << anal->getBoolCount() << endl << endl;

    return 0;
}