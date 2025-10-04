#include "../includes/salaried_employee.h"
#include "../includes/input_utils.h"
#include <iostream>
using namespace std;

SalariedEmployee::SalariedEmployee() = default;

SalariedEmployee::SalariedEmployee(string_view f, string_view l, double salary)
    : Worker(f, l), monthlySalary(salary) {}

void SalariedEmployee::setMonthlySalary(double s) { monthlySalary = s; }
double SalariedEmployee::getMonthlySalary() const { return monthlySalary; }

double SalariedEmployee::calculateSalary() const { return monthlySalary; }

void SalariedEmployee::inputData() {
    setFirstName(safeInputWord("Enter first name: "));
    setLastName(safeInputWord("Enter last name: "));
    monthlySalary = safePositiveInputFloat("Enter monthly salary: ");
}

void SalariedEmployee::printInfo() const {
    cout << "Salaried Employee: " << getFirstName() << " " << getLastName()
         << ", Salary: " << calculateSalary() << endl;
}
