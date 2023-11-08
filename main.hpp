#pragma once
#include <iostream>

void run(std::string source);
void error(int line, std::string message);
void report(int line, std::string where, std::string message);
