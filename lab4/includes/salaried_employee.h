#pragma once
#include "worker.h"

class SalariedEmployee : public Worker {
private:
    double monthlySalary{0.0};

public:
    SalariedEmployee();
    SalariedEmployee(std::string_view f, std::string_view l, double salary);
    ~SalariedEmployee() override = default;

    void setMonthlySalary(double s);
    double getMonthlySalary() const;

    double calculateSalary() const override;
    void inputData() override;
    void printInfo() const override;
};
