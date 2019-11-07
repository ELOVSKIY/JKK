//
// Created by admin on 07.11.2019.
//

#ifndef TEST_ANALYZER_H
#define TEST_ANALYZER_H

class AnalyzerInterface {
public:
    virtual int getStringCount();

    virtual int getArrayCount();

    virtual int getObjectCount();

    virtual int getBoolCount();

    virtual int getNumbCount();

    virtual int getNullCount();
};

#endif //TEST_ANALYZER_H
