#pragma once
#include <string>

std::string readLineTrimmed(const std::string &prompt);

int safeInputInt(const std::string &prompt);
double safeInputDouble(const std::string &prompt);
char safeInputChar(const std::string &prompt);

void trimInplace(std::string &s);