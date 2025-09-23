#pragma once
#include "person.h"
#include "date.h"
#include <string>
#include <utility>
#include <string_view>

class Tourist : public virtual Person {
private:
    std::string passportData{};

    std::pair<Date, std::string>* borderCrossings{nullptr};
    int borderCount{0};
    int borderCapacity{0};

    void ensureCapacity();

public:
    Tourist();
    Tourist(const std::string& f, const std::string& l,
            const std::string& m, int y,
            const std::string& passport);
    ~Tourist();

    void setPassportData(std::string_view p);
    std::string_view getPassportData() const;

    void addBorderCrossing(const Date& d, std::string_view country);
    void printBorderCrossings() const;

    void inputData() override;
    void printInfo() const override;
};
