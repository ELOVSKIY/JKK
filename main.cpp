#include <iostream>
#include "Redactor.h"
#include "ObjectAnalyzer.h"
#include "Validator.h"
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    string str = "-132.5e%23";
    auto *valid = new Validator(str);
    cout<<valid->isCorrectJSON();
    return 0;
}