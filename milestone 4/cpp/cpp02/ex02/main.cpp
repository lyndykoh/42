/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:47:59 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/02 22:36:40 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return (0);
}

// int main() {
//     // Testing constructors
//     Fixed a;                         // Default constructor
//     Fixed b(10);                     // Int constructor
//     Fixed c(42.42f);                 // Float constructor
//     Fixed d(b);                      // Copy constructor
//     Fixed e;                         
//     e = c;                           // Copy assignment operator

//     std::cout << "\n--- Testing output ---" << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "b: " << b << std::endl;
//     std::cout << "c: " << c << std::endl;
//     std::cout << "d: " << d << std::endl;
//     std::cout << "e: " << e << std::endl;

//     std::cout << "\n--- Testing toInt() ---" << std::endl;
//     std::cout << "b as int: " << b.toInt() << std::endl;
//     std::cout << "c as int: " << c.toInt() << std::endl;

//     std::cout << "\n--- Testing arithmetic operators ---" << std::endl;
//     Fixed sum = b + c;
//     Fixed diff = c - b;
//     Fixed prod = b * c;
//     Fixed quot = c / b;
//     std::cout << "b + c: " << sum << std::endl;
//     std::cout << "c - b: " << diff << std::endl;
//     std::cout << "b * c: " << prod << std::endl;
//     std::cout << "c / b: " << quot << std::endl;

//     std::cout << "\n--- Testing division by zero ---" << std::endl;
//     try {
//         Fixed zero;
//         Fixed result = b / zero;
//         std::cout << "b / zero: " << result << std::endl;
//     } catch (const std::runtime_error& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }

//     std::cout << "\n--- Testing comparison operators ---" << std::endl;
//     std::cout << "b > c: " << (b > c) << std::endl;
//     std::cout << "b < c: " << (b < c) << std::endl;
//     std::cout << "b >= d: " << (b >= d) << std::endl;
//     std::cout << "b <= d: " << (b <= d) << std::endl;
//     std::cout << "b == d: " << (b == d) << std::endl;
//     std::cout << "b != c: " << (b != c) << std::endl;

//     std::cout << "\n--- Testing increment/decrement operators ---" << std::endl;
//     Fixed inc;
//     std::cout << "inc: " << inc << std::endl;
//     std::cout << "++inc: " << ++inc << std::endl;
//     std::cout << "inc++: " << inc++ << std::endl;
//     std::cout << "inc after inc++: " << inc << std::endl;
//     std::cout << "--inc: " << --inc << std::endl;
//     std::cout << "inc--: " << inc-- << std::endl;
//     std::cout << "inc after inc--: " << inc << std::endl;

//     std::cout << "\n--- Testing min/max functions ---" << std::endl;
//     Fixed f(5.5f);
//     Fixed g(10.1f);
//     std::cout << "min(f, g): " << Fixed::min(f, g) << std::endl;
//     std::cout << "max(f, g): " << Fixed::max(f, g) << std::endl;

//     const Fixed h(2.2f);
//     const Fixed i(2.8f);
//     std::cout << "min(h, i): " << Fixed::min(h, i) << std::endl;
//     std::cout << "max(h, i): " << Fixed::max(h, i) << std::endl;

//     std::cout << "\n--- Done! ---" << std::endl;
//     return 0;
// }
