#include "../includes/shuttler.h"
#include "../includes/input_utils.h"
#include <iostream>
#include <format>
using namespace std;

Shuttler::Shuttler() : Person(), Entrepreneur(), Tourist() {}

void Shuttler::addShoppingAddress(std::string_view address) {
    shoppingAddresses.emplace_back(address);
}

void Shuttler::printShoppingAddresses() const {
    cout << "Shopping addresses:\n";
    for (const auto& addr : shoppingAddresses) {
        cout << "- " << addr << endl;
    }
}

void Shuttler::inputData() {
    Entrepreneur::inputData();
    setPassportData(safeInputWord("Enter passport data: "));
    int n = safePositiveInputInt("How many shopping addresses? ");
    for (int i = 0; i < n; i++) {
        string addr = safeInputLine(std::format("Address {}: ", i + 1));
        shoppingAddresses.emplace_back(addr);
    }
}

void Shuttler::printInfo() const {
    cout << "\n[Shuttler]\n";
    Person::printInfo();
    cout << "License: " << getLicenseNumber()
         << ", INN: " << getInn()
         << ", Address: " << getRegistrationAddress() << endl;
    cout << "Passport: " << getPassportData() << endl;
    printShoppingAddresses();
}
