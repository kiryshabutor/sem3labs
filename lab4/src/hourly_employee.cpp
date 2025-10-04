#include "../includes/hourly_employee.h"
#include "../includes/input_utils.h"
#include <iostream>
using namespace std;

HourlyEmployee::HourlyEmployee() = default;

HourlyEmployee::HourlyEmployee(string_view f, string_view l, double rate, int hours)
    : Worker(f, l), hourlyRate(rate), hoursWorked(hours) {}

void HourlyEmployee::setHourlyRate(double r) { hourlyRate = r; }
void HourlyEmployee::setHoursWorked(int h) { hoursWorked = h; }
double HourlyEmployee::getHourlyRate() const { return hourlyRate; }
int HourlyEmployee::getHoursWorked() const { return hoursWorked; }

double HourlyEmployee::calculateSalary() const { return hourlyRate * static_cast<double>(hoursWorked); }

void HourlyEmployee::inputData() {
    setFirstName(safeInputWord("Enter first name: "));
    setLastName(safeInputWord("Enter last name: "));
    hourlyRate = safePositiveInputFloat("Enter hourly rate: ");
    hoursWorked = safePositiveInputInt("Enter hours worked: ");
}


void HourlyEmployee::printInfo() const {
    cout << "Hourly Employee: " << getFirstName() << " " << getLastName()
         << ", Rate: " << hourlyRate
         << ", Hours: " << hoursWorked
         << ", Salary: " << calculateSalary() << endl;
}
