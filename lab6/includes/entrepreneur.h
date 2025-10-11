#pragma once
#include "person.h"
#include "date.h"
#include <string>
#include <utility>
#include <string_view>

class Entrepreneur : public virtual Person {
private:
    int licenseNumber{0};
    std::string registrationAddress{};
    int inn{0};

    std::pair<Date, float>* taxPayments{nullptr};
    int taxCount{0};
    int taxCapacity{0};

    void ensureCapacity();

public:
    Entrepreneur();
    Entrepreneur(const std::string& f, const std::string& l,
                 const std::string& m, int y,
                 int lic, const std::string& addr, int i);
    ~Entrepreneur() override;

    Entrepreneur(const Entrepreneur& other);
    Entrepreneur& operator=(const Entrepreneur& other);
    Entrepreneur(Entrepreneur&& other) noexcept;
    Entrepreneur& operator=(Entrepreneur&& other) noexcept;

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
