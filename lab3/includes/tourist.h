#pragma once
#include "person.h"
#include "date.h"
#include <string>
#include <vector>
#include <utility>

class Tourist : public virtual Person {
private:
    std::string passportData;
    std::vector<std::pair<Date, std::string>> borderCrossings;

public:
    Tourist();
    Tourist(const std::string& f, const std::string& l,
            const std::string& m, int y,
            const std::string& passport);

    void setPassportData(const std::string& p);
    std::string getPassportData() const;

    void addBorderCrossing(const Date& d, const std::string& country);
    void printBorderCrossings() const;

    void inputData() override;
    void printInfo() const override;
};
