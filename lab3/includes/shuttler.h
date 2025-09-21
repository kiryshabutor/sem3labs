#pragma once
#include "entrepreneur.h"
#include "tourist.h"
#include <string>
#include <vector>

class Shuttler : public Entrepreneur, public Tourist {
private:
    std::vector<std::string> shoppingAddresses;

public:
    Shuttler();
    Shuttler(const std::string& f, const std::string& l,
             const std::string& m, int y,
             int lic, const std::string& addr, int inn,
             const std::string& passport);

    void addShoppingAddress(const std::string& address);
    void printShoppingAddresses() const;

    void inputData() override;
    void printInfo() const override;
};
