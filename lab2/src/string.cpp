#include "../includes/string.h"
#include <cstring>
#include <iostream>

using namespace std;

String::String() : data(new char[1]) { data[0] = '\0'; }

String::String(const char *str) {
    if (!str) {
        data = new char[1];
        data[0] = '\0';
        length = 0;
        return;
    }
    length = ::strnlen_s(str, SIZE_MAX);

    data = new char[length + 1];
    std::copy(str, str + length, data);
    data[length] = '\0';
}

String::String(const String &other)
    : data(new char[other.length + 1]), length(other.length) {
    copy(other.data, other.data + length + 1, data);
}

String::~String() { delete[] data; }

String &String::operator=(const String &other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        copy(other.data, other.data + length + 1, data);
    }
    return *this;
}

String &String::operator+=(const String &other) {
    const size_t newLength = length + other.length;
    const auto newData = new char[newLength + 1];

    copy(data, data + length, newData);
    copy(other.data, other.data + other.length + 1, newData + length);

    delete[] data;
    data = newData;
    length = newLength;

    return *this;
}
