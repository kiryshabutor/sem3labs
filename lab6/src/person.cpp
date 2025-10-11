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

void Person::inputData() {
    while (true) {
        try {
            firstName = safeInputWord("Enter first name: ");
            lastName = safeInputWord("Enter last name: ");
            middleName = safeInputWord("Enter middle name: ");

            int y = safePositiveInputInt("Enter birth year: ");
            const auto now = chrono::system_clock::now();
            time_t tt = chrono::system_clock::to_time_t(now);
            tm tmv{};
#ifdef _WIN32
            localtime_s(&tmv, &tt);
#else
            localtime_r(&tt, &tt);
#endif
            int currentYear = tmv.tm_year + TM_YEAR_BASE;
            if (y > currentYear) throw invalid_argument("Year cannot be in the future.");

            birthYear = y;
            break;

        } catch (const invalid_argument& e) {
            cout << "Invalid input: " << e.what() << ". Please try again.\n";
        } catch (const out_of_range& e) {
            cout << "Value out of range: " << e.what() << ". Please try again.\n";
        }
    }
}

void Person::printInfo() const {
    cout << lastName << " " << firstName << " " << middleName
         << ", born in " << birthYear << endl;
}
