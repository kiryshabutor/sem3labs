#include "../includes/shuttler.h"
#include "../includes/input_utils.h"
#include <iostream>
#include <format>
using namespace std;

Shuttler::Shuttler() : Person(), Entrepreneur(), Tourist() {}

Shuttler::~Shuttler() {
    delete[] shoppingAddresses;
}

void Shuttler::ensureCapacity() {
    int newCapacity = (shopCapacity == 0 ? 2 : shopCapacity * 2);
    auto* newArr = new string[newCapacity];
    for (int i = 0; i < shopCount; i++) {
        newArr[i] = shoppingAddresses[i];
    }
    delete[] shoppingAddresses;
    shoppingAddresses = newArr;
    shopCapacity = newCapacity;
}

void Shuttler::addShoppingAddress(std::string_view address) {
    if (shopCount >= shopCapacity) {
        ensureCapacity();
    }
    shoppingAddresses[shopCount++] = string(address);
}

void Shuttler::printShoppingAddresses() const {
    cout << "Shopping addresses:\n";
    for (int i = 0; i < shopCount; i++) {
        cout << "- " << shoppingAddresses[i] << endl;
    }
}

void Shuttler::inputData() {
    Entrepreneur::inputData();
    setPassportData(safeInputWord("Enter passport data: "));
    int n = safePositiveInputInt("How many shopping addresses? ");
    for (int i = 0; i < n; i++) {
        string addr = safeInputLine(std::format("Address {}: ", i + 1));
        addShoppingAddress(addr);
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
