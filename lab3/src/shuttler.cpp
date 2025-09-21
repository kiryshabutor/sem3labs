#include "../includes/shuttler.h"
#include "../includes/input_utils.h"
#include <iostream>
using namespace std;

Shuttler::Shuttler() : Person(), Entrepreneur(), Tourist() {}

Shuttler::Shuttler(const string& f, const string& l,
                   const string& m, int y,
                   int lic, const string& addr, int inn,
                   const string& passport)
    : Person(f, l, m, y),
      Entrepreneur(f, l, m, y, lic, addr, inn),
      Tourist(f, l, m, y, passport) {}

void Shuttler::addShoppingAddress(const string& address) {
    shoppingAddresses.push_back(address);
}

void Shuttler::printShoppingAddresses() const {
    cout << "Shopping addresses:\n";
    for (const auto& a : shoppingAddresses) {
        cout << "- " << a << endl;
    }
}

void Shuttler::inputData() {
    Entrepreneur::inputData();
    passportData = safeInputWord("Enter passport data: ");
    int n = safePositiveInputInt("How many shopping addresses? ");
    for (int i = 0; i < n; i++) {
        string addr = safeInputLine("Address " + to_string(i + 1) + ": ");
        shoppingAddresses.push_back(addr);
    }
}

void Shuttler::printInfo() const {
    cout << "\n[Shuttler]\n";
    Person::printInfo();
    cout << "License: " << licenseNumber
         << ", INN: " << inn
         << ", Address: " << registrationAddress << endl;
    cout << "Passport: " << passportData << endl;
    printShoppingAddresses();
}
