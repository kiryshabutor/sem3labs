#pragma once
#include <string>
#include <string_view>

class Worker {
private:
    std::string firstName;
    std::string lastName;

public:
    Worker();
    Worker(std::string_view f, std::string_view l);
    virtual ~Worker() = default;

    void setFirstName(std::string_view f);
    void setLastName(std::string_view l);

    std::string_view getFirstName() const;
    std::string_view getLastName() const;

    virtual double calculateSalary() const = 0;
    virtual void inputData() = 0;
    virtual void printInfo() const = 0;
};
