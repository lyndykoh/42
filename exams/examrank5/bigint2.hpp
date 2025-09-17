#ifndef BIGINT2_HPP
#define BIGINT2_HPP

#include <iostream>
#include <string>
#include <algorithm>

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

        bigint &operator=(const bigint &other);
        bigint &operator+=(const bigint &other);

        bigint operator+(const bigint &other) const;
        bigint &operator++();
        bigint operator++(int);

        bigint operator<<(int shift) const;
        bigint operator>>(int shift) const;
};

#endif 