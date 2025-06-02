/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:41:06 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/03 00:18:08 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed area(const Point &a, const Point &b, const Point &c) {
    return Fixed((a.GetX() * (b.GetY() - c.GetY()) +
                  b.GetX() * (c.GetY() - a.GetY()) +
                  c.GetX() * (a.GetY() - b.GetY())).toFloat() / 2.0f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed Area = area(a, b, c);
    Fixed s1 = area(point, b, c);
    Fixed s2 = area(a, point, c);
    Fixed s3 = area(a, b, point);

    if (s1 == 0 || s2 == 0 || s3 == 0)
        return false;
    return (Area == (s1 + s2 + s3));
}