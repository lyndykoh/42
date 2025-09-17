#include <string>
#include <iostream>
#include <algorithm>
#include "bigint.hpp"

std::string bigint::getval() const
{
	return value;
}

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

std::string bigint::addstring(std::string st1, std::string st2) const
{
	std::string result = "";
	int s1l = st1.length() - 1;
	int s2l = st2.length() - 1;
	int carry = 0;

	while (s1l >= 0 || s2l >= 0 || carry != 0)
	{
		int sum = carry;
		if (s1l >= 0)
		{
			sum += st1[s1l] - '0';
			--s1l;
		}
		if (s2l >= 0)
		{
			sum += st2[s2l] - '0';
			--s2l;
		}
		carry = sum / 10;
		result = char(sum % 10 + '0') + result;
	}
	return result;
}

bigint::bigint() : value("0") {}

bigint::bigint(std::string val) : value(val)
{
	stripzero();
}

bigint::bigint(const bigint& other) : value(other.value) {}

bigint::bigint(int val) : value(std::to_string(val))
{
	stripzero();
}

bigint::~bigint() {}

bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		value = other.value;
	return *this;
}

bigint& bigint::operator+=(const bigint &other)
{
	value = addstring(value, other.value);
	return *this;
}

bigint bigint::operator+(const bigint &other) const
{
	bigint tmp;
	tmp.value = addstring(value, other.value);
	return tmp;
}

bigint& bigint::operator++()
{
	value = addstring(value, "1");
	return *this;
}

bigint bigint::operator++(int)
{
	bigint temp(*this);
	value = addstring(value, "1");
	return temp;
}

bigint bigint::operator<<(int shift) const
{
	if (shift == 0)
		return *this;
	return bigint(value + std::string(shift, '0'));
}

bigint bigint::operator>>(int shift) const
{
	if (shift == 0)
		return *this;
	if (shift >= value.length())
		return bigint();
	return bigint(value.substr(0, value.length() - shift));
}

bigint& bigint::operator<<=(int shift)
{
	if (shift != 0)
		value += std::string(shift, '0');
	return *this;
}

bigint& bigint::operator>>=(int shift)
{
	if (shift == 0) return *this;
	if (shift >= value.length()) {
		value = "0";
	} else {
		value = value.substr(0, value.length() - shift);
	}
	return *this;
}

bigint bigint::operator<<(const bigint& shift) const
{
	int total_shift = 0;
	for (char digit : shift.value)
	{
		total_shift = total_shift * 10 + (digit - '0');
	}
	return (*this) << total_shift;
}

bigint bigint::operator>>(const bigint& shift) const
{
	int total_shift = 0;
	for (char digit : shift.value)
	{
		total_shift = total_shift * 10 + (digit - '0');
	}
	return (*this) >> total_shift;
}

bigint& bigint::operator<<=(const bigint& shift)
{
	int total_shift = 0;
	for (char digit : shift.value)
	{
		total_shift = total_shift * 10 + (digit - '0');
	}
	return (*this) <<= total_shift;
}

bigint& bigint::operator>>=(const bigint& shift)
{
	int total_shift = 0;
	for (char digit : shift.value)
	{
		total_shift = total_shift * 10 + (digit - '0');
	}
	return (*this) >>= total_shift;
}


bool bigint::operator<(const bigint &other) const
{
	if (value.length() != other.value.length())
		return value.length() < other.value.length();
	return value < other.value;
}

bool bigint::operator>(const bigint &other) const
{
	return other < *this;
}

bool bigint::operator<=(const bigint &other) const
{
	return !(*this > other);
}

bool bigint::operator>=(const bigint &other) const
{
	return !(*this < other);
}

bool bigint::operator==(const bigint &other) const
{
	return value == other.value;
}

bool bigint::operator!=(const bigint &other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const bigint& bi)
{
	os << bi.getval();
	return os;
}