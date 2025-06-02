/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:56:07 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/03 00:13:05 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        Fixed const _x;
        Fixed const _y;
    public:  
        Point();
        Point(const float x, const float y);
        Point(const Point &other);
        Point& operator=(const Point &other);
        ~Point();

        Fixed GetX() const;
        Fixed GetY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif