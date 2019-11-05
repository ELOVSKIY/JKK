//---------------------------------------------------------------------------

#ifndef AnalyzerH
#define AnalyzerH
//---------------------------------------------------------------------------
#include <string>
using namespace std;

class Analyzer {
private:
	string analyzedText;
	int stringCount;
	int numbCount;
	int arrayCount;
	int objectCount;
	int boolCount;

	void calculateArrayCount();
	void calculateStringCount();
	void calculateNumbCount();
	void calculateObjectCount();
	void calculateBoolCount();
public:
    Analyzer(string text);
	int getStringCount();
	int getArrayCount();
	int getObjectCount();
    int getBoolCount();
    int getNumbCount();
    void analyze();
};
//---------------------------------------------------------------------------
#endif
