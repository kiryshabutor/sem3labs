#include "../includes/input_utils.h"
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <algorithm>

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

int safeInputInt(const string& prompt) {
    regex pat(R"(^[+-]?\d+$)");
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);

        if (regex_match(input, pat)) {
            try {
                return stoi(input);
            } catch (const invalid_argument&) {
                cout << "Invalid number.\n";
            } catch (const out_of_range&) {
                cout << "Number out of range.\n";
            }
        } else {
            cout << "Please enter an integer.\n";
        }
    }
}

double safeInputDouble(const string &prompt) {
    static const regex pat(R"(^[+-]?\d+([.,]\d+)?$)");

    while (true) {
        string input = readLineTrimmed(prompt);

        if (!input.empty() && regex_match(input, pat)) {
            ranges::replace(input, ',', '.');

            stringstream ss(input);
            ss.imbue(locale::classic());

            double value;
            ss >> value;

            if (ss && ss.eof()) {
                return value;
            }
        }

        cout << "Please enter a valid number.\n";
    }
}

char safeInputChar(const string& prompt) {
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);
        if (input.size() == 1)
            return input[0];
        cout << "Enter a single character.\n";
    }
}
