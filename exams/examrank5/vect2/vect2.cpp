#include <iostream>
#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}
vect2::~vect2() {}
vect2::vect2(const vect2& other) : x(other.x), y(other.y) {}
vect2::vect2(int nx, int ny) : x(nx), y(ny) {}

int vect2::getx() const { return x; }
int vect2::gety() const { return y; }
void vect2::setx(int nx) { x = nx; }
void vect2::sety(int ny) { y = ny; }

vect2& vect2::operator=(const vect2& rhs) {
	if (this != &rhs) {
		x = rhs.x;
		y = rhs.y;
	}
	return *this;
}

vect2 vect2::operator+(const vect2& rhs) const {
	return vect2(x + rhs.x, y + rhs.y);
}

vect2 vect2::operator-(const vect2& rhs) const {
	return vect2(x - rhs.x, y - rhs.y);
}

vect2 vect2::operator*(int scale) const {
	return vect2(x * scale, y * scale);
}

vect2& vect2::operator+=(const vect2& rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}

vect2& vect2::operator-=(const vect2& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

vect2& vect2::operator*=(int scale) {
	x *= scale;
	y *= scale;
	return *this;
}

vect2& vect2::operator++() {
	++x;
	++y;
	return *this;
}

vect2& vect2::operator--() {
	--x;
	--y;
	return *this;
}

vect2 vect2::operator++(int) {
	vect2 temp(*this);
	++(*this);
	return temp;
}

vect2 vect2::operator--(int) {
	vect2 temp(*this);
	--(*this);
	return temp;
}

vect2 vect2::operator-() const {
	return vect2(-x, -y);
}

bool vect2::operator==(const vect2& rhs) const {
	return (x == rhs.x) && (y == rhs.y);
}

bool vect2::operator!=(const vect2& rhs) const {
	return !(*this == rhs);
}

int& vect2::operator[](int idx) {
	return (idx == 0) ? x : y;
}

const int& vect2::operator[](int idx) const {
	return (idx == 0) ? x : y;
}

std::ostream& operator<<(std::ostream& os, const vect2& v2) {
	return os << "{" << v2.getx() << ", " << v2.gety() << "}";
}

vect2 operator*(int scale, const vect2& rhs) {
	return rhs * scale;
}