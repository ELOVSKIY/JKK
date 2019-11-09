#include <iostream>
#include "Redactor.h"
#include "ObjectAnalyzer.h"
#include "Validator.h"
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    string str = "{\n"
                 "    \"count\": 7,\n"
                 "    \"next\": null,\n"
                 "    \"previous\": null,\n"
                 "    \"results\": [\n"
                 "        {\n"
                 "            \"id\": 8,\n"
                 "            \"name\": \"Baranovichi\",\n"
                 "            \"description\": \"Baranovichi\"\n"
                 "        },\n"
                 "        {\n"
                 "            \"id\": 3,\n"
                 "            \"name\": \"Brest\",\n"
                 "            \"description\": \"Brest\"\n"
                 "        },\n"
                 "        {\n"
                 "            \"id\": 4,\n"
                 "            \"name\": \"Gomel\",\n"
                 "            \"description\": \"Gomel\"\n"
                 "        },\n"
                 "        {\n"
                 "            \"id\": 7,\n"
                 "            \"name\": \"Bobruisk\",\n"
                 "            \"description\": \"Bobruisk\"\n"
                 "        },\n"
                 "        {\n"
                 "            \"id\": 6,\n"
                 "            \"name\": \"Mogilev\",\n"
                 "            \"description\": \"Mogilev\"\n"
                 "        },\n"
                 "        {\n"
                 "            \"id\": 5,\n"
                 "            \"name\": \"VItebsk\",\n"
                 "            \"description\": \"VItebsk\"\n"
                 "        },\n"
                 "        {\n"
                 "            \"id\": 2,\n"
                 "            \"name\": \"Minsk\",\n"
                 "            \"description\": \"Minsk\"\n"
                 "        }\n"
                 "    ]\n"
                 "}";
    auto *val = new Validator(str);
    cout<<val->isCorrectJSON()<<endl<<endl;
    auto *anal = new ObjectAnalyzer(str);
    cout<<"String "<<anal->getStringCount()<<endl;
    cout<<"Bool "<<anal->getBoolCount()<<endl;
    cout<<"Numb "<<anal->getNumbCount()<<endl;
    cout<<"Array "<<anal->getArrayCount()<<endl;
    cout<<"Object "<<anal->getObjectCount()<<endl;
    return 0;
}