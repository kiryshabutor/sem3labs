#pragma once
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

class String {
private:
    char *data;
    size_t length = 0;

public:
    String();

    explicit String(const char *str);

    String(const String &other);

    ~String();

    String &operator=(const String &other);

    String &operator+=(const String &other);

    friend std::ostream &operator<<(std::ostream &os, const String &str) {
        if (str.data)
            os << str.data;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, String &str) {
        std::string temp;
        std::getline(is >> std::ws, temp);

        delete[] str.data;
        str.length = temp.size();
        str.data = new char[str.length + 1];
        std::ranges::copy(temp, str.data);
        str.data[str.length] = '\0';

        return is;
    }

    const char *c_str() const;
};
