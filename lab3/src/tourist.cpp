#include "../includes/tourist.h"
#include "../includes/input_utils.h"
#include <iostream>
using namespace std;

Tourist::Tourist() : Person(), passportData("") {}

Tourist::Tourist(const string& f, const string& l,
                 const string& m, int y,
                 const string& passport)
    : Person(f, l, m, y), passportData(passport) {}

void Tourist::setPassportData(std::string_view p) { passportData = p; }
std::string_view Tourist::getPassportData() const { return passportData; }

void Tourist::addBorderCrossing(const Date& d, std::string_view country) {
    borderCrossings.emplace_back(d, std::string(country));
}

void Tourist::printBorderCrossings() const {
    cout << "Border crossings:\n";
    for (const auto& [date, country] : borderCrossings) {
        date.printDate();
        cout << " - " << country << endl;
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
