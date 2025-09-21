#include "../includes/tourist.h"
#include "../includes/input_utils.h"
#include <iostream>
using namespace std;

Tourist::Tourist() : Person(), passportData("") {}

Tourist::Tourist(const string& f, const string& l,
                 const string& m, int y,
                 const string& passport)
    : Person(f, l, m, y), passportData(passport) {}

void Tourist::setPassportData(const string& p) { passportData = p; }
string Tourist::getPassportData() const { return passportData; }

void Tourist::addBorderCrossing(const Date& d, const string& country) {
    borderCrossings.push_back({d, country});
}

void Tourist::printBorderCrossings() const {
    cout << "Border crossings:\n";
    for (const auto& b : borderCrossings) {
        b.first.printDate();
        cout << " - " << b.second << endl;
    }
}

void Tourist::inputData() {
    Person::inputData();
    passportData = safeInputWord("Enter passport data: ");
}

void Tourist::printInfo() const {
    Person::printInfo();
    cout << "Passport: " << passportData << endl;
}
