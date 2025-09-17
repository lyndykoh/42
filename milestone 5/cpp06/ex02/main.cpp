/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:12:40 by lkoh              #+#    #+#             */
/*   Updated: 2025/09/17 12:12:43 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Declare functions
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    srand(static_cast<unsigned>(time(NULL))); // seed RNG

    for (int i = 0; i < 10; i++) {
        std::cout << "--- Test " << i + 1 << " ---" << std::endl;
        Base* obj = generate();   // Random A/B/C
        identify(obj);            // Identify via pointer
        identify(*obj);           // Identify via reference
        delete obj;               // Clean up
        std::cout << std::endl;
    }

    return 0;
}
