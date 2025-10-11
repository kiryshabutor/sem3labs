#include "../includes/input_utils.h"
#include <iostream>
#include <regex>
#include <format>
#include <stdexcept>
#include <cctype>

using namespace std;

inline void trimInplace(string& s) {
    while (!s.empty() && isspace(static_cast<unsigned char>(s.front())))
        s.erase(s.begin());
    while (!s.empty() && isspace(static_cast<unsigned char>(s.back())))
        s.pop_back();
}

string readLineTrimmed(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    trimInplace(input);
    return input;
}

int safeInputInt(const string& prompt) {
    const regex pattern(R"(^[+-]?\d+$)");
    while (true) {
        string input = readLineTrimmed(prompt);
        if (!input.empty() && regex_match(input, pattern)) {
            try {
                return stoi(input);
            } catch (const invalid_argument&) {
                cout << format("Invalid input '{}'. Please enter a number.\n", input);
            } catch (const out_of_range&) {
                cout << format("Number '{}' is out of int range.\n", input);
            }
        } else {
            cout << "Error: enter an integer (optionally with + or - sign).\n";
        }
    }
}
