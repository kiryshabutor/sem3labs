#include "../includes/date.h"
#include "../includes/input_utils.h"
#include <array>
#include <chrono>
#include <ctime>
#include <iostream>
using namespace std;

constexpr int TM_YEAR_BASE = 1900;
constexpr int TM_MONTH_BASE = 1;

Date::Date() : day(1), month(1), year(2000) { getCurrentDate(); }

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    getCurrentDate();
}

bool Date::isLeapYear(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

bool Date::isValidDate(const int d,const int m,const int y) const {
    if (y < 1 || y > currentYear) return false;
    if (m < 1 || m > 12) return false;

    array<int, 12> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeapYear(y)) daysInMonth[1] = 29;
    return (d >= 1 && d <= daysInMonth[m - 1]);
}

void Date::getCurrentDate() {
    using namespace std::chrono;
    const auto now = system_clock::now();
    time_t timeNow = system_clock::to_time_t(now);
    tm localTime{};
#ifdef _WIN32
    localtime_s(&localTime, &timeNow);
#else
    localtime_r(&timeNow, &localTime);
#endif
    currentDay = localTime.tm_mday;
    currentMonth = localTime.tm_mon + TM_MONTH_BASE;
    currentYear = localTime.tm_year + TM_YEAR_BASE;
}

static int inputPositiveIntSafely(const string& prompt) {
    while (true) {
        try {
            return safePositiveInputInt(prompt);
        } catch (const exception& ex) {
            cout << "Invalid input: " << ex.what() << ". Try again.\n";
        }
    }
}

void Date::inputDate() {
    while (true) {
        try {
            cout << "Enter date:\n";
            int d = inputPositiveIntSafely("Day: ");
            int m = inputPositiveIntSafely("Month: ");
            int y = inputPositiveIntSafely("Year: ");

            if (!isValidDate(d, m, y))
                throw invalid_argument("Invalid date values.");
            day = d;
            month = m;
            year = y;
            break;
        } catch (const invalid_argument& e) {
            cout << "Invalid input: " << e.what() << ". Try again.\n";
        } catch (const out_of_range& e) {
            cout << "Value out of range: " << e.what() << ". Try again.\n";
        }
    }
}

void Date::printDate() const {
    cout << day << "." << month << "." << year;
}
