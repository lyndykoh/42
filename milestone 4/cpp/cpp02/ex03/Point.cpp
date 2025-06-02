/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:15:10 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/03 00:15:54 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
    // std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
    // std::cout << "Point constructor w/ parameters called" << std::endl;
}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {
    // std::cout << "Point copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &other) {
    (void) other;
    // std::cout << "Point copy assignment called" << std::endl;
    return (*this);
}

Point::~Point() {
    // std::cout << "Point destructor called" << std::endl;
}

Fixed Point::GetX() const {
    return (_x);
}

Fixed Point::GetY() const {
    return (_y);
}