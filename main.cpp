#include <iostream>
#include "Redactor.h"
#include "ObjectAnalyzer.h"
#include <string.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    string str = "{\n"
                 "  \"active\": true,\n"
                 "      \"name\": \"Molecule Man\",\n"
                 "  \"members\":"
                 "    {\n"
                 "      \"name\": \"Molecule Man\",\n"
                 "      \"name\": \"Molecule Man\",\n"
                 "      \"age\": 29\n"
                 "    }\n"
                 "}";
    auto *anal = new ObjectAnalyzer(str);
    cout << anal->getNumbCount() << endl << endl;

    return 0;
}