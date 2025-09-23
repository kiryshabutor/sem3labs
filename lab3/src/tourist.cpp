#include "../includes/tourist.h"
#include "../includes/input_utils.h"
#include <iostream>
using namespace std;

Tourist::Tourist() : Person() {}

Tourist::Tourist(const string& f, const string& l,
                 const string& m, int y,
                 const string& passport)
    : Person(f, l, m, y), passportData(passport) {}

Tourist::~Tourist() {
    delete[] borderCrossings;
}

void Tourist::setPassportData(std::string_view p) { passportData = p; }
std::string_view Tourist::getPassportData() const { return passportData; }

void Tourist::ensureCapacity() {
    int newCapacity = (borderCapacity == 0 ? 2 : borderCapacity * 2);
    auto* newArr = new pair<Date, string>[newCapacity];
    for (int i = 0; i < borderCount; i++) {
        newArr[i] = borderCrossings[i];
    }
    delete[] borderCrossings;
    borderCrossings = newArr;
    borderCapacity = newCapacity;
}

void Tourist::addBorderCrossing(const Date& d, std::string_view country) {
    while (borderCount >= borderCapacity) {
        ensureCapacity();
    }
    ++borderCount;
    borderCrossings[borderCount-1] = {d, string(country)};
}

void Tourist::printBorderCrossings() const {
    cout << "Border crossings:\n";
    for (int i = 0; i < borderCount; i++) {
        borderCrossings[i].first.printDate();
        cout << " - " << borderCrossings[i].second << endl;
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
