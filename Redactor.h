//---------------------------------------------------------------------------

#ifndef RedactorH
#define RedactorH
//------------------------------------------------------------------------------------------------------------
#include <string>
using namespace std;

class Redactor {
private:
    string editedText;
    string plainText;
    string compressedText;
    int tabSize;

    static bool isWhiteSpaceChar(char plainChar);
    void calculateCompressedText();
    void calculateEditedText();

public:
    Redactor(string text);
    Redactor(string text, int tabSize);
    void setTabSize(int tabSize);
    string getCompressedText();
    string getEditedText();

};

//---------------------------------------------------------------------------

#endif
