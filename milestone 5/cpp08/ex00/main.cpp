/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:57:09 by lkoh              #+#    #+#             */
/*   Updated: 2025/09/25 15:03:31 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
    try {
        // Test with vector
        std::vector<int> vec;
        for (int i = 0; i < 10; i++)
            vec.push_back(i);

        std::cout << "Vector test: " << std::endl;
        std::cout << "Found: " << *easyfind(vec, 5) << std::endl;
        std::cout << "Found: " << *easyfind(vec, 9) << std::endl;

        try {
            easyfind(vec, 42);  // Not in vector
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        // Test with list
        std::list<int> lst;
        for (int i = 10; i < 20; i++)
            lst.push_back(i);

        std::cout << "\nList test: " << std::endl;
        std::cout << "Found: " << *easyfind(lst, 15) << std::endl;

        try {
            easyfind(lst, 30);
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        // Test with deque
        std::deque<int> deq;
        for (int i = 100; i < 105; i++)
            deq.push_back(i);

        std::cout << "\nDeque test: " << std::endl;
        std::cout << "Found: " << *easyfind(deq, 102) << std::endl;

        try {
            easyfind(deq, 500);
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }
}

