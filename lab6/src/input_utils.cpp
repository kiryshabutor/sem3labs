#include "../includes/input_utils.h"

#include <algorithm>
#include <format>
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
    regex pat(R"(^[+-]?\d+$)");

    while (true) {
        string input = readLineTrimmed(prompt);

        if (!input.empty() && regex_match(input, pat)) {
            try {
                return stoi(input);
            } catch (const invalid_argument &) {
                throw invalid_argument("Invalid input: not a number.");
            } catch (const out_of_range &) {
                throw out_of_range("Invalid input: number out of range.");
            }
        } else {
            cout << "Invalid input. Please enter an integer (with optional + or -).\n";
        }
    }
}

int safePositiveInputInt(const string &prompt) {
    int number = safeInputInt(prompt);

    if (number <= 0) {
        throw invalid_argument(std::format(
            "Invalid input: number must be positive, got {}", number));
    }

    return number;
}

float safeInputFloat(const string &prompt) {
    static const regex pat(R"(^[+-]?\d+([.,]\d{0,2})?$)");

    while (true) {
        string input = readLineTrimmed(prompt);

        if (!input.empty() && regex_match(input, pat)) {
            ranges::replace(input, ',', '.');

            stringstream ss(input);
            ss.imbue(locale::classic());
            float value;
            ss >> value;

            if (ss && ss.eof()) {
                return value;
            } else {
                throw invalid_argument("Invalid input: not a valid float value.");
            }
        } else {
            cout << "Invalid input. Please enter a floating-point number.\n";
        }
    }
}

float safePositiveInputFloat(const string &prompt) {
    float number = safeInputFloat(prompt);

    if (number <= 0.0f) {
        throw invalid_argument(std::format(
            "Invalid input: number must be positive, got {:.2f}", number));
    }

    return number;
}

string safeInputLine(const string &prompt) {
    while (true) {
        string input = readLineTrimmed(prompt);
        if (!input.empty()) {
            return input;
        }
        cout << "Input cannot be empty.\n";
    }
}

string safeInputWord(const string &prompt) {
    static const regex pat(R"(^\S+$)");
    while (true) {
        string input = readLineTrimmed(prompt);
        if (!input.empty() && regex_match(input, pat)) {
            return input;
        }
        cout << "Please enter only one word (no spaces).\n";
    }
}
