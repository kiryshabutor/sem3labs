#pragma once
#include "entrepreneur.h"
#include "tourist.h"
#include <string>
#include <string_view>

class Shuttler : public Entrepreneur, public Tourist {
private:
    std::string* shoppingAddresses{nullptr};
    int shopCount{0};
    int shopCapacity{0};

    void ensureCapacity();

public:
    Shuttler();
    ~Shuttler();

    Shuttler(const Shuttler& other);
    Shuttler& operator=(const Shuttler& other);
    Shuttler(Shuttler&& other) noexcept;
    Shuttler& operator=(Shuttler&& other) noexcept;

    void addShoppingAddress(std::string_view address);
    void printShoppingAddresses() const;

    void inputData() override;
    void printInfo() const override;
};
