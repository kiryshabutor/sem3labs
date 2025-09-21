#pragma once
#include "person.h"
#include "date.h"
#include <string>
#include <vector>
#include <utility>
#include <string_view>

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
    void setRegistrationAddress(std::string_view addr);
    void setInn(int i);

    int getLicenseNumber() const;
    std::string_view getRegistrationAddress() const;
    int getInn() const;

    void addTaxPayment(const Date& d, float sum);
    void printTaxPayments() const;

    void inputData() override;
    void printInfo() const override;
};
