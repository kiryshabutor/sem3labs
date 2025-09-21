#pragma once
#include "person.h"
#include "date.h"
#include <string>
#include <vector>
#include <utility>

class Entrepreneur : public virtual Person {
private:
    int licenseNumber;
    std::string registrationAddress;
    int inn;
    std::vector<std::pair<Date, float>> taxPayments;

public:
    Entrepreneur();
    Entrepreneur(const std::string& f, const std::string& l,
                 const std::string& m, int y,
                 int lic, const std::string& addr, int i);

    void setLicenseNumber(int lic);
    void setRegistrationAddress(const std::string& addr);
    void setInn(int i);

    int getLicenseNumber() const;
    std::string getRegistrationAddress() const;
    int getInn() const;

    void addTaxPayment(const Date& d, float sum);
    void printTaxPayments() const;

    void inputData() override;
    void printInfo() const override;
};
