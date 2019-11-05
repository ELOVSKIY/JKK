#include <iostream>
#include "Redactor.h"
#include <string.h>

using namespace std;

int main() {
    string str = "{\n"
                 "   \"firstName\": \"Иван\",\n"
                 "   \"lastName\": \"Иванов\",\n"
                 "   \"address\": {\n"
                 "       \"streetAddress\": \"Московское ш., 101, кв.101\",\n"
                 "       \"city\": \"Ленинград\",\n"
                 "       \"postalCode\": \"101101\"\n"
                 "   },\n"
                 "   \"phoneNumbers\": [\n"
                 "       \"812 123-1234\",\n"
                 "       \"916 123-4567\"\n"
                 "   ]\n"
                 "}";
    Redactor *red = new Redactor(str);
    cout<<red->getEditedText()<<endl<<endl;
    red->setTabSize(2);
    cout<<red->getEditedText()<<endl<<endl;
    return 0;
}