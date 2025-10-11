#pragma once
#include <string>
#include <string_view>

class Person {
private:
    std::string firstName;
    std::string lastName;
    std::string middleName;
    int birthYear{0};

public:
    Person();
    Person(const std::string& f, const std::string& l,
           const std::string& m, int y);
    virtual ~Person() = default;

    Person(const Person& other) = default;
    Person& operator=(const Person& other) = default;
    Person(Person&& other) noexcept = default;
    Person& operator=(Person&& other) noexcept = default;

    void setFirstName(std::string_view f);
    void setLastName(std::string_view l);
    void setMiddleName(std::string_view m);
    void setBirthYear(int y);

    std::string_view getFirstName() const;
    std::string_view getLastName() const;
    std::string_view getMiddleName() const;
    int getBirthYear() const;

    virtual void inputData();
    virtual void printInfo() const;
};
