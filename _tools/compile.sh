#!/bin/bash

# Compilation of C++ files
# g++ *.cpp Func/*.cpp GoYa/*.cpp Interpreter/*.cpp IO/*.cpp Lexer/*.cpp Operator/*.cpp Parser/*.cpp -o GoYaExe

g++ -c *.cpp Func/*.cpp GoYa/*.cpp Interpreter/*.cpp IO/*.cpp Lexer/*.cpp Operator/*.cpp Parser/*.cpp
g++ *.o -o GoYaExe
# g++ -o *.o Func/*.o GoYa/*.o Interpreter/*.o IO/*.o Lexer/*.o Operator/*.o Parser/*.o
