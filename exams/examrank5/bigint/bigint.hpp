#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
    private:
        std::string value;
        void stripzero();
        std::string addstring(std::string s1, std::string s2) const;

    public:
        std::string getval() const;

        bigint();
        bigint(std::string val);
        bigint(int val);
        bigint(const bigint &other);
        ~bigint();

        //assignment operators
        bigint &operator=(const bigint &other);
        bigint &operator+=(const bigint &other);

        //arithmetic operators
        bigint operator+(const bigint &other) const;
        bigint &operator++();
        bigint operator++(int);

        //shift operators
        bigint operator<<(int shift) const;
        bigint operator>>(int shift) const;
        bigint &operator<<=(int shift);
        bigint &operator>>=(int shift);

        bigint operator<<(const bigint &shift) const;
        bigint operator>>(const bigint &shift) const;
        bigint &operator<<=(const bigint &shift);
        bigint &operator>>=(const bigint &shift);

        //comparison operators
        bool operator<(const bigint &other) const;
        bool operator>(const bigint &other) const;
        bool operator<=(const bigint &other) const;
        bool operator>=(const bigint &other) const;
        bool operator==(const bigint &other) const;
        bool operator!=(const bigint &other) const;
};

std::ostream &operator<<(std::ostream os, const bigint &bi);

#endif