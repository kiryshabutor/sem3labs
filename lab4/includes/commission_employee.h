#pragma once
#include "worker.h"

class CommissionEmployee : public Worker {
private:
    double salesAmount{0.0};
    double commissionRate{0.0};

public:
    CommissionEmployee();
    CommissionEmployee(std::string_view f, std::string_view l, double sales, double rate);
    ~CommissionEmployee() override = default;

    void setSalesAmount(double s);
    void setCommissionRate(double r);
    double getSalesAmount() const;
    double getCommissionRate() const;

    double calculateSalary() const override;
    void inputData() override;
    void printInfo() const override;
};
