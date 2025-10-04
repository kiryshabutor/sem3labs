#pragma once
#include <string>

int safeInputInt(const std::string& prompt);
int safePositiveInputInt(const std::string& prompt);

double safeInputDouble(const std::string& prompt);
double safePositiveInputDouble(const std::string& prompt);

double safeInputCommission(const std::string& prompt);

std::string safeInputWord(const std::string& prompt);
