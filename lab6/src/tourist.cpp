#include "../includes/tourist.h"
#include "../includes/input_utils.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Tourist::Tourist() : Person() {}

Tourist::Tourist(const string& f, const string& l,
                 const string& m, int y,
                 const string& passport)
    : Person(f, l, m, y), passportData(passport) {}

Tourist::~Tourist() {
    delete[] borderCrossings;
}

Tourist::Tourist(const Tourist& other)
    : Person(other),
      passportData(other.passportData),
      borderCount(other.borderCount),
      borderCapacity(other.borderCapacity) {
    if (borderCapacity > 0) {
        borderCrossings = new pair<Date, string>[borderCapacity];
        for (int i = 0; i < borderCount; i++) {
            borderCrossings[i] = other.borderCrossings[i];
        }
    }
}

Tourist& Tourist::operator=(const Tourist& other) {
    if (this == &other) return *this;
    Person::operator=(other);
    passportData = other.passportData;
    delete[] borderCrossings;
    borderCount = other.borderCount;
    borderCapacity = other.borderCapacity;
    if (borderCapacity > 0) {
        borderCrossings = new pair<Date, string>[borderCapacity];
        for (int i = 0; i < borderCount; i++) {
            borderCrossings[i] = other.borderCrossings[i];
        }
    } else {
        borderCrossings = nullptr;
    }
    return *this;
}

Tourist::Tourist(Tourist&& other) noexcept
    : Person(std::move(other)),
      passportData(std::move(other.passportData)),
      borderCrossings(other.borderCrossings),
      borderCount(other.borderCount),
      borderCapacity(other.borderCapacity) {
    other.borderCrossings = nullptr;
    other.borderCount = 0;
    other.borderCapacity = 0;
}

Tourist& Tourist::operator=(Tourist&& other) noexcept {
    if (this == &other) return *this;
    Person::operator=(std::move(other));
    passportData = std::move(other.passportData);
    delete[] borderCrossings;
    borderCrossings = other.borderCrossings;
    borderCount = other.borderCount;
    borderCapacity = other.borderCapacity;
    other.borderCrossings = nullptr;
    other.borderCount = 0;
    other.borderCapacity = 0;
    return *this;
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
    borderCount++;
    borderCrossings[borderCount - 1] = {d, string(country)};
}

void Tourist::printBorderCrossings() const {
    cout << "Border crossings:\n";
    for (int i = 0; i < borderCount; i++) {
        borderCrossings[i].first.printDate();
        cout << " - " << borderCrossings[i].second << endl;
    }
}

static string inputWordSafely(const string& prompt) {
    while (true) {
        try {
            return safeInputWord(prompt);
        } catch (const InputValidationError& ex) {
            cout << "Invalid argument: " << ex.what() << ". Please try again.\n";
        } catch (const out_of_range& ex) {
            cout << "Value out of range: " << ex.what() << ". Please try again.\n";
        } catch (const system_error& ex) {
            cout << "System error: " << ex.what() << ". Please try again.\n";
        }
    }
}

void Tourist::inputData() {
    while (true) {
        try {
            Person::inputData();
            passportData = inputWordSafely("Enter passport data: ");
            break;
        } catch (const InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        } catch (const out_of_range& e) {
            cout << "Value out of range: " << e.what() << ". Try again.\n";
        } catch (const system_error& e) {
            cout << "System error: " << e.what() << ". Try again.\n";
        }
    }
}

void Tourist::printInfo() const {
    Person::printInfo();
    cout << "Passport: " << passportData << endl;
}
