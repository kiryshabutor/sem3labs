#include "../includes/entrepreneur.h"
#include "../includes/input_utils.h"
#include <iostream>
using namespace std;

Entrepreneur::Entrepreneur() : Person() {}

Entrepreneur::Entrepreneur(const string &f, const string &l,
                           const string &m, int y,
                           int lic, const string &addr, int i)
    : Person(f, l, m, y),
      licenseNumber(lic),
      registrationAddress(addr),
      inn(i) {}

Entrepreneur::~Entrepreneur() {
    delete[] taxPayments;
}

Entrepreneur::Entrepreneur(const Entrepreneur& other)
    : Person(other),
      licenseNumber(other.licenseNumber),
      registrationAddress(other.registrationAddress),
      inn(other.inn),
      taxCount(other.taxCount),
      taxCapacity(other.taxCapacity) {
    if (taxCapacity > 0) {
        taxPayments = new pair<Date, float>[taxCapacity];
        for (int i = 0; i < taxCount; i++)
            taxPayments[i] = other.taxPayments[i];
    }
}

Entrepreneur& Entrepreneur::operator=(const Entrepreneur& other) {
    if (this == &other) return *this;
    Person::operator=(other);
    licenseNumber = other.licenseNumber;
    registrationAddress = other.registrationAddress;
    inn = other.inn;
    delete[] taxPayments;
    taxCount = other.taxCount;
    taxCapacity = other.taxCapacity;
    if (taxCapacity > 0) {
        taxPayments = new pair<Date, float>[taxCapacity];
        for (int i = 0; i < taxCount; i++)
            taxPayments[i] = other.taxPayments[i];
    } else {
        taxPayments = nullptr;
    }
    return *this;
}

Entrepreneur::Entrepreneur(Entrepreneur&& other) noexcept
    : Person(std::move(other)),
      licenseNumber(other.licenseNumber),
      registrationAddress(std::move(other.registrationAddress)),
      inn(other.inn),
      taxPayments(other.taxPayments),
      taxCount(other.taxCount),
      taxCapacity(other.taxCapacity) {
    other.taxPayments = nullptr;
    other.taxCount = 0;
    other.taxCapacity = 0;
}

Entrepreneur& Entrepreneur::operator=(Entrepreneur&& other) noexcept {
    if (this == &other) return *this;
    Person::operator=(std::move(other));
    licenseNumber = other.licenseNumber;
    registrationAddress = std::move(other.registrationAddress);
    inn = other.inn;
    delete[] taxPayments;
    taxPayments = other.taxPayments;
    taxCount = other.taxCount;
    taxCapacity = other.taxCapacity;
    other.taxPayments = nullptr;
    other.taxCount = 0;
    other.taxCapacity = 0;
    return *this;
}

void Entrepreneur::inputData() {
    bool valid = false;
    while (!valid) {
        try {
            Person::inputData();
            licenseNumber = safePositiveInputInt("Enter license number: ");
            registrationAddress = safeInputLine("Enter registration address: ");
            inn = safePositiveInputInt("Enter INN: ");
            valid = true;
        } catch (const invalid_argument& e) {
            cout << "Invalid input: " << e.what() << ". Please try again.\n";
        } catch (const out_of_range& e) {
            cout << "Value out of range: " << e.what() << ". Please try again.\n";
        }
    }
}
