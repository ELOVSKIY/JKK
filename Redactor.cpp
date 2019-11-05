//---------------------------------------------------------------------------

#pragma hdrstop

#include "Redactor.h"

#include <utility>

Redactor::Redactor(string text)
        : Redactor(text, 4) {
    this->plainText = text;
}

Redactor::Redactor(string text, int tabSize) {
    this->plainText = std::move(text);
    this->tabSize = tabSize;
    calculateCompressedText();
}

void Redactor::setTabSize(int tabSize) {
    this->tabSize = tabSize;
}

string Redactor::getCompressedText() {
    return compressedText;
}

string Redactor::getEditedText() {
    calculateEditedText();
    return editedText;
}


void Redactor::calculateEditedText() {
    editedText = "";
    int objectLevel = 0;
    bool isString = false;
    int arrayLevel = 0;
    for (unsigned i = 0; i < compressedText.length(); i++) {
        editedText = editedText + compressedText[i];

        if (compressedText[i] == '\"') {
            isString = !isString;
        }

        if ((compressedText[i] == '{') && (!isString)) {
            objectLevel++;
            editedText = editedText + '\n';
            for (int j = 0; j < objectLevel * tabSize; j++) {
                editedText.append(" ");
            }
            for (int j = 0; j < arrayLevel * tabSize; j++) {
                editedText.append(" ");
            }
        }
        if ((compressedText[i + 1] == '}') && (!isString)) {
            objectLevel--;
            editedText.append("\n");
            for (int j = 0; j < objectLevel * tabSize; j++) {
                editedText.append(" ");
            }
            for (int j = 0; j < arrayLevel * tabSize; j++) {
                editedText.append(" ");
            }
        }

        if ((!isString) && (compressedText[i] == '[')) {
            arrayLevel++;
            editedText.append("\n");
            for (int j = 0; j < objectLevel * tabSize; j++) {
                editedText.append(" ");
            }
            for (int j = 0; j < arrayLevel * tabSize; j++) {
                editedText.append(" ");
            }
        }
        if ((!isString) && (compressedText[i + 1] == ']')) {
            arrayLevel--;
            editedText.append("\n");
            for (int j = 0; j < objectLevel * tabSize; j++) {
                editedText.append(" ");
            }
            for (int j = 0; j < arrayLevel * tabSize; j++) {
                editedText.append(" ");
            }
        }

        if ((compressedText[i] == ':') && (!isString)) {
            editedText.append(" ");

        }

        if ((compressedText[i] == ',') && (!isString)) {
            editedText.append("\n");
            for (int j = 0; j < objectLevel * tabSize; j++) {
                editedText.append(" ");
            }
            for (int j = 0; j < arrayLevel * tabSize; j++) {
                editedText.append(" ");
            }
        }
    }
}

bool Redactor::isWhiteSpaceChar(char plainChar) {
    if (plainChar == ' ')
        return true;
    if (plainChar == '\n')
        return true;
    if (plainChar == '\t')
        return true;
    if (plainChar == '\r')
        return true;
    return false;
}

void Redactor::calculateCompressedText() {
    compressedText = "";
    bool isString = false;
    for (unsigned i = 0; i < plainText.length(); i++) {
        if ((plainText[i] == '\"') && (plainText[i - 1] != '\\')) {
            isString = !isString;
        }
        if ((isString) || (!isWhiteSpaceChar(plainText[i]))) {
            compressedText = compressedText + plainText[i];
        }
    }
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
