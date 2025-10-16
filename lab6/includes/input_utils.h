#pragma once
#include <stdexcept>
#include <string>

class InputValidationError : public std::runtime_error {
public:
    explicit InputValidationError(const std::string &msg)
        : std::runtime_error(msg) {}
};

int safeInputInt(const std::string &prompt);
int safePositiveInputInt(const std::string &prompt);
float safeInputFloat(const std::string &prompt);
float safePositiveInputFloat(const std::string &prompt);

std::string safeInputLine(const std::string &prompt);
std::string safeInputWord(const std::string &prompt);
