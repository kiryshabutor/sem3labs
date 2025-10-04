#include "../includes/commission_employee.h"
#include "../includes/input_utils.h"
#include <iostream>
using namespace std;

CommissionEmployee::CommissionEmployee() = default;

CommissionEmployee::CommissionEmployee(string_view f, string_view l, double sales, double rate)
    : Worker(f, l), salesAmount(sales), commissionRate(rate) {}

void CommissionEmployee::setSalesAmount(double s) { salesAmount = s; }
void CommissionEmployee::setCommissionRate(double r) { commissionRate = r; }
double CommissionEmployee::getSalesAmount() const { return salesAmount; }
double CommissionEmployee::getCommissionRate() const { return commissionRate; }

double CommissionEmployee::calculateSalary() const { return salesAmount * commissionRate; }

void CommissionEmployee::inputData() {
    setFirstName(safeInputWord("Enter first name: "));
    setLastName(safeInputWord("Enter last name: "));
    salesAmount = safePositiveInputDouble("Enter sales amount: ");
    commissionRate = safeInputCommission("Enter commission rate: ");
}

void CommissionEmployee::printInfo() const {
    cout << "Commission Employee: " << getFirstName() << " " << getLastName()
         << ", Sales: " << salesAmount
         << ", Rate: " << commissionRate
         << ", Salary: " << calculateSalary() << endl;
}
