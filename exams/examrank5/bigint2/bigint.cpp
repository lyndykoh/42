#include "bigint.hpp"

void bigint::stripzero()
{
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

std::string bigint::addstring(std::string s1, std::string s2) const
{
    std::string result = "";
    int l1 = s1.length() - 1;
    int l2 = s2.length() - 1;
    int carry = 0;

    
}