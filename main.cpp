#include <iostream>
#include "Redactor.h"
#include "ObjectAnalyzer.h"
#include "Validator.h"
#include <string>
#include "Object.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    auto *ob = new Object("SUKA", AbstractValue::TYPE_ANY);
    return 0;
}