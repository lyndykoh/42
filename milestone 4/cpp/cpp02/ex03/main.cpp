/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:47:59 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/03 00:08:55 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    Point inside(2, 2);
    Point edge(2.5, 0);
    Point vertex(0, 0);
    Point outside(5, 5);

    std::cout << std::boolalpha;
    std::cout << "Point inside: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Point on edge: " << bsp(a, b, c, edge) << std::endl;
    std::cout << "Point on vertex: " << bsp(a, b, c, vertex) << std::endl;
    std::cout << "Point outside: " << bsp(a, b, c, outside) << std::endl;

    return 0;
}
