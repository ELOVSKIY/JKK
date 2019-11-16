cmake_minimum_required(VERSION 3.15)
project(Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test main.cpp Redactor.cpp Redactor.h ObjectAnalyzer.cpp ObjectAnalyzer.h Entities/ObjectJSON.cpp Entities/ObjectJSON.h Entities/AbstractObjectJSON.cpp Entities/AbstractObjectJSON.h ArrayAnalyzer.cpp ArrayAnalyzer.h ElementAnalyzer.cpp ElementAnalyzer.h Analyzer.cpp Analyzer.h Validator.cpp Validator.h Value.cpp Value.h Object.cpp Object.h Parser.cpp Parser.h ArrayParser.cpp ArrayParser.h ArrayValue.cpp ArrayValue.h KotlinClass.cpp KotlinClass.h)