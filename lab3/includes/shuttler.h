#pragma once
#include "entrepreneur.h"
#include "tourist.h"
#include <string>
#include <vector>
#include <string_view>

class Shuttler : public Entrepreneur, public Tourist {
private:
    std::vector<std::string> shoppingAddresses;

public:
    Shuttler();

    void addShoppingAddress(std::string_view address);
    void printShoppingAddresses() const;

    void inputData() override;
    void printInfo() const override;
};
