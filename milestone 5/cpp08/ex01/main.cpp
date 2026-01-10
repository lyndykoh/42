/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:06:58 by lkoh              #+#    #+#             */
/*   Updated: 2025/11/07 17:49:38 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }

#include "span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>   // rand()
#include <ctime>     // time()

int main()
{
    std::srand(std::time(0));

    std::cout << "=== TEST 1: Basic single adds and spans ===" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Overflow exception ===" << std::endl;
    try {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);  // Should throw
    }
    catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Range insertion (vector iterators) ===" << std::endl;
    try {
        std::vector<int> nums;
        for (int i = 0; i < 5; ++i)
            nums.push_back(i * 10);

        Span sp(10);
        sp.addNumber(nums.begin(), nums.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Range insertion overflow ===" << std::endl;
    try {
        Span sp(3);
        int arr[] = {1, 2, 3, 4, 5};
        std::vector<int> tooMany(arr, arr + 5);
        sp.addNumber(tooMany.begin(), tooMany.end());  // Should throw
    }
    catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Large dataset (10,000 numbers) ===" << std::endl;
    try {
        Span sp(10000);
        for (int i = 0; i < 10000; ++i)
            sp.addNumber(std::rand());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 6: Not enough numbers to compute span ===" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(42);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Should throw
    }
    catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 7: Copy constructor and assignment ===" << std::endl;
    try {
        Span original(5);
        original.addNumber(10);
        original.addNumber(20);
        original.addNumber(30);

        Span copy(original);  // Copy constructor
        Span assigned(10);
        assigned = original;  // Assignment operator

        std::cout << "Original shortest span: " << original.shortestSpan() << std::endl;
        std::cout << "Copy shortest span:     " << copy.shortestSpan() << std::endl;
        std::cout << "Assigned shortest span: " << assigned.shortestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
