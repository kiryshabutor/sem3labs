#include "../includes/entrepreneur.h"
#include "../includes/input_utils.h"
#include <iostream>
using namespace std;

Entrepreneur::Entrepreneur() : Person(), licenseNumber(0), registrationAddress(""), inn(0) {
}

Entrepreneur::Entrepreneur(const string &f, const string &l,
                           const string &m, int y,
                           int lic, const string &addr, int i)
    : Person(f, l, m, y), licenseNumber(lic), registrationAddress(addr), inn(i) {
}

void Entrepreneur::setLicenseNumber(int lic) { licenseNumber = lic; }
void Entrepreneur::setRegistrationAddress(std::string_view addr) { registrationAddress = addr; }
void Entrepreneur::setInn(int i) { inn = i; }

int Entrepreneur::getLicenseNumber() const { return licenseNumber; }
std::string_view Entrepreneur::getRegistrationAddress() const { return registrationAddress; }
int Entrepreneur::getInn() const { return inn; }

void Entrepreneur::addTaxPayment(const Date &d, float sum) {
    taxPayments.emplace_back(d, sum);
}

void Entrepreneur::printTaxPayments() const {
    cout << "Tax payments:\n";
    for (const auto &[date, sum]: taxPayments) {
        date.printDate();
        cout << " - " << sum << endl;
    }
}

void Entrepreneur::inputData() {
    Person::inputData();
    licenseNumber = safePositiveInputInt("Enter license number: ");
    registrationAddress = safeInputLine("Enter registration address: ");
    inn = safePositiveInputInt("Enter INN: ");
}

void Entrepreneur::printInfo() const {
    Person::printInfo();
    cout << "License: " << licenseNumber
            << ", INN: " << inn
            << ", Address: " << registrationAddress << endl;
}
