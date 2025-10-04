#pragma once
#include "worker.h"

class HourlyEmployee : public Worker {
private:
    double hourlyRate{0.0};
    int hoursWorked{0};

public:
    HourlyEmployee();
    HourlyEmployee(std::string_view f, std::string_view l, double rate, int hours);
    ~HourlyEmployee() override = default;

    void setHourlyRate(double r);
    void setHoursWorked(int h);
    double getHourlyRate() const;
    int getHoursWorked() const;

    double calculateSalary() const override;
    void inputData() override;
    void printInfo() const override;
};
