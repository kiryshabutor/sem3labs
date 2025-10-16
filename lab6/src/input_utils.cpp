#include "../includes/input_utils.h"

#include <algorithm>
#include <format>
#include <iostream>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

inline void trimInplace(string &s) {
    while (!s.empty() && isspace(static_cast<unsigned char>(s.front())))
        s.erase(s.begin());
    while (!s.empty() && isspace(static_cast<unsigned char>(s.back())))
        s.pop_back();
}

string readLineTrimmed(const string &prompt) {
    cout << prompt;
    string input;
    getline(cin, input);
    trimInplace(input);
    return input;
}

int safeInputInt(const string &prompt) {
    string input = readLineTrimmed(prompt);

    regex pat(R"(^[+-]?\d+$)");
    if (!regex_match(input, pat))
        throw InputValidationError(std::format("Invalid integer input: '{}'", input));

    try {
        return stoi(input);
    } catch (const invalid_argument &) {
        throw InputValidationError(std::format("Invalid integer format: '{}'", input));
    } catch (const out_of_range &) {
        throw InputValidationError(std::format("Integer out of range: '{}'", input));
    }
}

int safePositiveInputInt(const string &prompt) {
    int number = safeInputInt(prompt);
    if (number <= 0)
        throw InputValidationError(std::format("Number must be positive, got {}", number));
    return number;
}

float safeInputFloat(const string &prompt) {
    string input = readLineTrimmed(prompt);
    regex pat(R"(^[+-]?\d+([.,]\d+)?$)");

    if (!regex_match(input, pat))
        throw InputValidationError(std::format("Invalid float input: '{}'", input));

    ranges::replace(input, ',', '.');

    stringstream ss(input);
    ss.imbue(locale::classic());
    float value;
    ss >> value;

    if (!ss || !ss.eof())
        throw InputValidationError(std::format("Invalid float format: '{}'", input));

    return value;
}

float safePositiveInputFloat(const string &prompt) {
    float number = safeInputFloat(prompt);
    if (number <= 0.0f)
        throw InputValidationError(std::format("Number must be positive, got {:.2f}", number));
    return number;
}

string safeInputLine(const string &prompt) {
    string input = readLineTrimmed(prompt);
    if (input.empty())
        throw InputValidationError("Input cannot be empty.");
    return input;
}

string safeInputWord(const string &prompt) {
    string input = readLineTrimmed(prompt);
    regex pat(R"(^\S+$)");
    if (!regex_match(input, pat))
        throw InputValidationError(std::format("Invalid word input: '{}'", input));
    return input;
}
