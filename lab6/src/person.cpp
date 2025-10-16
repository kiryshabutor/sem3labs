#include "../includes/person.h"
#include "../includes/input_utils.h"
#include <iostream>
#include <chrono>
using namespace std;

constexpr int TM_YEAR_BASE = 1900;

Person::Person() : firstName(""), lastName(""), middleName(""), birthYear(2000) {}

Person::Person(const string& f, const string& l,
               const string& m, int y)
    : firstName(f), lastName(l), middleName(m), birthYear(y) {}

string_view Person::getFirstName() const { return firstName; }
string_view Person::getLastName() const { return lastName; }
string_view Person::getMiddleName() const { return middleName; }
int Person::getBirthYear() const { return birthYear; }

void Person::setFirstName(string_view f) { firstName = f; }
void Person::setLastName(string_view l) { lastName = l; }
void Person::setMiddleName(string_view m) { middleName = m; }
void Person::setBirthYear(int y) { birthYear = y; }

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

static int inputPositiveIntSafely(const string& prompt) {
    while (true) {
        try {
            return safePositiveInputInt(prompt);
        } catch (const InputValidationError& ex) {
            cout << "Invalid argument: " << ex.what() << ". Please try again.\n";
        } catch (const out_of_range& ex) {
            cout << "Value out of range: " << ex.what() << ". Please try again.\n";
        } catch (const system_error& ex) {
            cout << "System error: " << ex.what() << ". Please try again.\n";
        }
    }
}

void Person::inputData() {
    while (true) {
        try {
            firstName = inputWordSafely("Enter first name: ");
            lastName = inputWordSafely("Enter last name: ");
            middleName = inputWordSafely("Enter middle name: ");

            int y = inputPositiveIntSafely("Enter birth year: ");
            const auto now = chrono::system_clock::now();
            time_t tt = chrono::system_clock::to_time_t(now);
            tm tmv{};
#ifdef _WIN32
            localtime_s(&tmv, &tt);
#else
            localtime_r(&tt, &tmv);
#endif
            int currentYear = tmv.tm_year + TM_YEAR_BASE;
            if (y > currentYear) throw InputValidationError("Year cannot be in the future.");

            birthYear = y;
            break;

        } catch (const InputValidationError& e) {
            cout << "Invalid argument: " << e.what() << ". Please try again.\n";
        } catch (const out_of_range& e) {
            cout << "Value out of range: " << e.what() << ". Please try again.\n";
        } catch (const system_error& e) {
            cout << "System error: " << e.what() << ". Please try again.\n";
        }
    }
}

void Person::printInfo() const {
    cout << lastName << " " << firstName << " " << middleName
         << ", born in " << birthYear << endl;
}
