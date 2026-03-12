#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
private:
	int x;
	int y;

public:
	vect2();
	~vect2();
	vect2(const vect2& other);
	vect2(int nx, int ny);

	int getx() const;
	int gety() const;
	void setx(int nx);
	void sety(int ny);

	vect2& operator=(const vect2& rhs);
	vect2 operator+(const vect2& rhs) const;
	vect2 operator-(const vect2& rhs) const;
	vect2 operator*(int scale) const;

	vect2& operator+=(const vect2& rhs);
	vect2& operator-=(const vect2& rhs);
	vect2& operator*=(int scale);

	vect2& operator++();
	vect2& operator--();
	vect2 operator++(int);
	vect2 operator--(int);
	vect2 operator-() const;

	bool operator==(const vect2& rhs) const;
	bool operator!=(const vect2& rhs) const;

	int& operator[](int idx);
	const int& operator[](int idx) const;
};

std::ostream& operator<<(std::ostream& os, const vect2& v2);
vect2 operator*(int scale, const vect2& rhs);

#endif