#include "../includes/input_utils.h"

#include <algorithm>
#include <iostream>
#include <ranges>
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
    string input;
    cout << prompt;
    getline(cin, input);
    trimInplace(input);
    return input;
}

int safeInputInt(const string &prompt) {
    string input = readLineTrimmed(prompt);
    regex pat(R"(^[+-]?\d+$)");

    if (!regex_match(input, pat))
        throw invalid_argument("Invalid input: expected an integer, got \"" + input + "\"");

    try {
        return stoi(input);
    } catch (const out_of_range &) {
        throw out_of_range("Integer value out of range: \"" + input + "\"");
    }
}

int safePositiveInputInt(const string &prompt) {
    int number = safeInputInt(prompt);
    if (number <= 0)
        throw invalid_argument("Invalid input: number must be positive, got " + to_string(number));
    return number;
}

float safeInputFloat(const string &prompt) {
    string input = readLineTrimmed(prompt);
    regex pat(R"(^[+-]?\d+([.,]\d+)?$)");

    if (!regex_match(input, pat))
        throw invalid_argument("Invalid input: expected a floating-point number, got \"" + input + "\"");

    ranges::replace(input, ',', '.');

    try {
        return stof(input);
    } catch (const out_of_range &) {
        throw out_of_range("Floating-point value out of range: \"" + input + "\"");
    }
}

float safePositiveInputFloat(const string &prompt) {
    float number = safeInputFloat(prompt);
    if (number <= 0.0f)
        throw invalid_argument("Invalid input: number must be positive, got " + to_string(number));
    return number;
}

string safeInputLine(const string &prompt) {
    string input = readLineTrimmed(prompt);
    if (input.empty())
        throw invalid_argument("Invalid input: line cannot be empty");
    return input;
}

string safeInputWord(const string &prompt) {
    string input = readLineTrimmed(prompt);
    regex pat(R"(^\S+$)");

    if (input.empty() || !regex_match(input, pat))
        throw invalid_argument("Invalid input: expected a single word without spaces, got \"" + input + "\"");
    return input;
}