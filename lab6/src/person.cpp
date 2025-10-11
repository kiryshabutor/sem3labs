#include "../includes/person.h"
#include "../includes/input_utils.h"
#include <iostream>
#include <chrono>
#include <stdexcept>

using namespace std;

constexpr int TM_YEAR_BASE = 1900;

Person::Person() : firstName(""), lastName(""), middleName(""), birthYear(2000) {}

Person::Person(const string& f, const string& l,
               const string& m, int y)
    : firstName(f), lastName(l), middleName(m), birthYear(y) {}

std::string_view Person::getFirstName() const { return firstName; }
std::string_view Person::getLastName() const { return lastName; }
std::string_view Person::getMiddleName() const { return middleName; }
int Person::getBirthYear() const { return birthYear; }

void Person::setFirstName(std::string_view f) { firstName = f; }
void Person::setLastName(std::string_view l) { lastName = l; }
void Person::setMiddleName(std::string_view m) { middleName = m; }
void Person::setBirthYear(int y) { birthYear = y; }

void Person::inputData() {
    bool valid = false;
    while (!valid) {
        try {
            firstName = safeInputWord("Enter first name: ");
            lastName = safeInputWord("Enter last name: ");
            middleName = safeInputWord("Enter middle name: ");

            int y;
            while (true) {
                y = safePositiveInputInt("Enter birth year: ");

                const auto now = chrono::system_clock::now();
                time_t tt = chrono::system_clock::to_time_t(now);
                tm tmv{};
#ifdef _WIN32
                localtime_s(&tmv, &tt);
#else
                localtime_r(&tt, &tmv);
#endif
                int currentYear = tmv.tm_year + TM_YEAR_BASE;
                if (y <= currentYear) break;

                cout << "Year cannot be in the future.\n";
            }

            birthYear = y;
            valid = true;

        } catch (const invalid_argument& e) {
            cout << "Invalid input: " << e.what() << ". Please try again.\n";
        } catch (const out_of_range& e) {
            cout << "Value out of range: " << e.what() << ". Please try again.\n";
        } catch (const exception& e) {
            cout << "Unexpected error: " << e.what() << ". Try again.\n";
        }
    }
}

void Person::printInfo() const {
    cout << lastName << " " << firstName << " " << middleName
         << ", born in " << birthYear << endl;
}
