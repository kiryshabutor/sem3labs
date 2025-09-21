#pragma once
#include <string>
#include <string_view>

class Person {
private:
    std::string firstName;
    std::string lastName;
    std::string middleName;
    int birthYear;

public:
    Person();
    Person(const std::string& f, const std::string& l,
           const std::string& m, int y);
    virtual ~Person() = default;

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getMiddleName() const;
    int getBirthYear() const;

    void setFirstName(std::string_view f);
    void setLastName(std::string_view l);
    void setMiddleName(std::string_view m);
    void setBirthYear(int y);

    virtual void inputData();
    virtual void printInfo() const;
};
