#include "../includes/input_utils.h"

#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

const int COMMISSION_MIN = 10;
const int COMMISSION_MAX = 100;

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
    static const regex pat(R"(^[+-]?\d+$)");

    while (true) {
        string input = readLineTrimmed(prompt);

        if (!input.empty() && regex_match(input, pat)) {
            try {
                return stoi(input);
            } catch (const invalid_argument &) {
                cout << "Invalid number format.\n";
            } catch (const out_of_range &) {
                cout << "Number is out of range.\n";
            }
        } else {
            cout << "Please enter an integer.\n";
        }
    }
}

int safePositiveInputInt(const string &prompt) {
    while (true) {
        int val = safeInputInt(prompt);
        if (val > 0) {
            return val;
        }
        cout << "Must be positive.\n";
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

double safePositiveInputDouble(const string &prompt) {
    while (true) {
        double val = safeInputDouble(prompt);
        if (val > 0.0) return val;
        cout << "Must be positive.\n";
    }
}

double safeInputCommission(const string& prompt) {
    while (true) {
        double val = safeInputDouble(prompt);
        if (val >= COMMISSION_MIN && val <= COMMISSION_MAX) {
            return val / 100.0;
        }
        cout << "Commission must be between " << COMMISSION_MIN
             << " and " << COMMISSION_MAX << " percent.\n";
    }
}

string safeInputWord(const string &prompt) {
    regex pat(R"(^\S+$)");
    while (true) {
        string input = readLineTrimmed(prompt);
        if (!input.empty() && regex_match(input, pat)) {
            return input;
        }
        cout << "Please enter one word (no spaces).\n";
    }
}
