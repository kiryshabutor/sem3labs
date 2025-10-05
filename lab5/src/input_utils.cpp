#include "../includes/input_utils.h"
#include <iostream>
#include <regex>
#include <sstream>
using namespace std;

int safeInputInt(const string& prompt) {
    regex pat(R"(^[+-]?\d+$)");
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);

        if (regex_match(input, pat)) {
            try {
                return stoi(input);
            } catch (const exception&) {
                cout << "Invalid number.\n";
            }
        } else {
            cout << "Please enter an integer.\n";
        }
    }
}

double safeInputDouble(const string& prompt) {
    regex pat(R"(^[+-]?\d+([.,]\d+)?$)");
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);
        if (regex_match(input, pat)) {
            replace(input.begin(), input.end(), ',', '.');
            stringstream ss(input);
            double value;
            ss >> value;
            if (ss && ss.eof()) return value;
        }
        cout << "Please enter a valid floating-point number.\n";
    }
}

char safeInputChar(const string& prompt) {
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);
        if (input.size() == 1) return input[0];
        cout << "Please enter a single character.\n";
    }
}
