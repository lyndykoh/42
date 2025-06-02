/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:26:16 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/03 00:16:23 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return (*this);
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

Fixed::Fixed(const int num) {
    // std::cout << "Int constructor called" << std::endl;
    _value = num << _fraction;
}

Fixed::Fixed(const float num) {
    // std::cout << "Float constructor called" << std::endl;
    _value = roundf((num) * (1 << _fraction));
}

float Fixed::toFloat(void) const {
    return ((float)this->_value / (1 << _fraction));
}

int Fixed::toInt(void) const {
    return (this->_value >> _fraction);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed& other) const {
    return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const {
    return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) const {
    return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const {
    return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) const {
    return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const {
    return (this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.toFloat() == 0) {
        std::cerr << "Cannot divide by 0.. U fail math? Give u 0 for ur math" << std::endl;
        return (Fixed(0));
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    ++this->_value;
    return (*this);
}

Fixed Fixed::operator++(int){
    Fixed temp(*this);
    ++this->_value;
    return (temp);
}

Fixed& Fixed::operator--(){
    --this->_value;
    return (*this);
}

Fixed Fixed::operator--(int){
    Fixed temp(*this);
    --this->_value;
    return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a > b)
        return (b);
    else 
        return (a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a < b)
        return (b);
    else 
        return (a);
}

Fixed Fixed::min(const Fixed &a, const Fixed &b) {
    if (a > b)
        return (b);
    else 
        return (a);
}

Fixed Fixed::max(const Fixed &a, const Fixed &b) {
    if (a < b)
        return (b);
    else 
        return (a);
}