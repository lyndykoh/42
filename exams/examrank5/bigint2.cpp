#include "bigint2.hpp"

void bigint::stripzero() {
    if (value.empty())
    {         
        value = "0";
        return;
    }
    size_t start = value.find_first_not_of('0');
    if (start == std::string::npos)
        value = "0";
    else 
        value.erase(0, start);
}

std::string bigint::addstring(std::string s1, std::string s2) const {
    std::string res = "";
    int len1 = s1.length() - 1;
    int len2 = s2.length() - 1;
    int carry = 0;

    while (len1 >= 0 || len2 >= 0 || carry != 0)
    {
        int sum = carry;
        if (len1 >= 0)
        {
            sum += s1[len1] - '0';
            --len1;
        }
        if (len2 >= 0)
        {
            sum += s2[len2] - '0';
            --len2;
        }
        carry = sum / 10;
        res = char(sum % 10 + '0') + res;
    }
    return res;
}

std::string bigint::getval() const {
    return value;
}

bigint::bigint() : value("0") {}

bigint::bigint(std::string val) : value(val) {
    stripzero();
}

bigint::bigint(int val) : value(std::to_string(val)) {
    stripzero();
}

bigint::bigint(const bigint &other) : value(other.value) {}

bigint::~bigint() {}

bigint &bigint::operator=(const bigint &other) {
    if (this != &other)
        value = other.value;
    return *this;
}

bigint &bigint::operator+=(const bigint &other) {
    value = addstring(value, other.value);
    return *this;
}

bigint bigint::operator+(const bigint &other) const {
    bigint tmp;
    tmp.value = addstring(value, other.value);
    return tmp;
}

bigint &bigint::operator++() {
    value = addstring(value, "1");
    return *this;
}

bigint bigint::operator++(int) {
    bigint tmp;
    tmp.value = addstring(value, "1");
    return tmp;
}