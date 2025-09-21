#pragma once
#include <string>

class Person {
protected:
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

    void setFirstName(const std::string& f);
    void setLastName(const std::string& l);
    void setMiddleName(const std::string& m);
    void setBirthYear(int y);

    virtual void inputData();
    virtual void printInfo() const;
};
