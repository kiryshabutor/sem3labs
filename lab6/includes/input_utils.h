#pragma once
#include <stdexcept>
#include <string>

class InputValidationError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};


int safeInputInt(const std::string &prompt);
int safePositiveInputInt(const std::string &prompt);
float safeInputFloat(const std::string &prompt);
float safePositiveInputFloat(const std::string &prompt);

std::string safeInputLine(const std::string &prompt);
std::string safeInputWord(const std::string &prompt);
