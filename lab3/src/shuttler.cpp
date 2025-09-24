#include "../includes/shuttler.h"
#include "../includes/input_utils.h"
#include <iostream>
#include <format>
using namespace std;

Shuttler::Shuttler() : Person(), Entrepreneur(), Tourist() {}

Shuttler::~Shuttler() {
    delete[] shoppingAddresses;
}

Shuttler::Shuttler(const Shuttler& other)
    : Person(other),
      Entrepreneur(other),
      Tourist(other),
      shopCount(other.shopCount),
      shopCapacity(other.shopCapacity) {
    if (shopCapacity > 0) {
        shoppingAddresses = new string[shopCapacity];
        for (int i = 0; i < shopCount; i++) {
            shoppingAddresses[i] = other.shoppingAddresses[i];
        }
    }
}

Shuttler& Shuttler::operator=(const Shuttler& other) {
    if (this == &other) return *this;
    Entrepreneur::operator=(other);
    Tourist::operator=(other);
    delete[] shoppingAddresses;
    shopCount = other.shopCount;
    shopCapacity = other.shopCapacity;
    if (shopCapacity > 0) {
        shoppingAddresses = new string[shopCapacity];
        for (int i = 0; i < shopCount; i++) {
            shoppingAddresses[i] = other.shoppingAddresses[i];
        }
    } else {
        shoppingAddresses = nullptr;
    }
    return *this;
}

Shuttler::Shuttler(Shuttler&& other) noexcept
    : Person(std::move(other)),
      Entrepreneur(std::move(other)),
      Tourist(std::move(other)),
      shoppingAddresses(other.shoppingAddresses),
      shopCount(other.shopCount),
      shopCapacity(other.shopCapacity) {
    other.shoppingAddresses = nullptr;
    other.shopCount = 0;
    other.shopCapacity = 0;
}

Shuttler& Shuttler::operator=(Shuttler&& other) noexcept {
    if (this == &other) return *this;
    Entrepreneur::operator=(std::move(other));
    Tourist::operator=(std::move(other));
    delete[] shoppingAddresses;
    shoppingAddresses = other.shoppingAddresses;
    shopCount = other.shopCount;
    shopCapacity = other.shopCapacity;
    other.shoppingAddresses = nullptr;
    other.shopCount = 0;
    other.shopCapacity = 0;
    return *this;
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
    while (shopCount >= shopCapacity) {
        ensureCapacity();
    }
    ++shopCount;
    shoppingAddresses[shopCount-1] = string(address);
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
