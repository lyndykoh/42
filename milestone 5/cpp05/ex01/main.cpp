/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:27:21 by lkoh              #+#    #+#             */
/*   Updated: 2025/08/24 21:28:46 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << PINK "===== Testing Valid Signing =====" RESET << std::endl;
    try {
        Bureaucrat alice("Alice", 10);
        Form contract("Contract", 20, 30);

        std::cout << alice << std::endl;
        std::cout << contract << std::endl;

        alice.signForm(contract);   // should succeed
        std::cout << contract << std::endl; // check signed status
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << PINK "\n===== Testing Invalid Signing (Too Low Grade) =====" RESET << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        Form topSecret("TopSecret", 10, 20);

        std::cout << bob << std::endl;
        std::cout << topSecret << std::endl;

        bob.signForm(topSecret);   // should fail
        std::cout << topSecret << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << PINK "\n===== Testing Double Signing =====" RESET << std::endl;
    try {
        Bureaucrat charlie("Charlie", 5);
        Form nda("NDA", 10, 15);

        std::cout << charlie << std::endl;
        std::cout << nda << std::endl;

        charlie.signForm(nda);   // first time succeeds
        charlie.signForm(nda);   // second time → should not throw, but should say "already signed"
        std::cout << nda << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << PINK "\n===== Testing Multiple Bureaucrats =====" RESET << std::endl;
    try {
        Bureaucrat dave("Dave", 20);
        Bureaucrat eve("Eve", 100);
        Form budget("Budget", 50, 100);

        std::cout << budget << std::endl;

        eve.signForm(budget);   // too low, should fail
        dave.signForm(budget);  // should succeed
        std::cout << budget << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << PINK "\n===== Testing Copy & Assignment =====" RESET << std::endl;
    try {
        Form original("OriginalForm", 40, 80);
        Bureaucrat frank("Frank", 30);

        frank.signForm(original);
        std::cout << original << std::endl;

        Form copy(original);  // copy constructor
        std::cout << "Copy constructed: " << copy << std::endl;

        Form assigned("Temp", 100, 120);
        assigned = original;  // copy assignment
        std::cout << "After assignment: " << assigned << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << PINK "\n===== The End =====" RESET << std::endl;
    return 0;
}
