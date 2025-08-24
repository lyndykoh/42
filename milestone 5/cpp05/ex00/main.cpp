#include "Bureaucrat.hpp"

int main() {
    std::cout << PINK "==== Testing valid construction ====" RESET << std::endl;
    try {
        Bureaucrat a("Alice", 1);   // highest grade
        Bureaucrat b("Bob", 150);   // lowest grade
        Bureaucrat c("Charlie", 42); // normal grade

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << PINK "\n==== Testing invalid construction ====" RESET << std::endl;
    try {
        Bureaucrat d("Dave", 0); // too high
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat e("Eve", 151); // too low
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << PINK "\n==== Testing increment/decrement edge cases ====" RESET<< std::endl;
    try {
        Bureaucrat top("TopDog", 1);
        std::cout << top << std::endl;
        top.increment(); // should throw
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat low("LowMan", 150);
        std::cout << "\n" << low << std::endl;
        low.decrement(); // should throw
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << PINK "\n==== Testing normal grade changes ====" RESET << std::endl;
    try {
        Bureaucrat mid("Middle", 75);
        std::cout << mid << std::endl;
        mid.increment();
        std::cout << "After increment: " << mid << std::endl;
        mid.decrement();
        std::cout << "After decrement: " << mid << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << PINK "\n==== Testing copy and assignment ====" RESET << std::endl;
    try {
        Bureaucrat original("Original", 100);
        Bureaucrat copy(original); // copy constructor
        Bureaucrat assigned("Temp", 50);
        assigned = original;       // copy assignment

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        std::cout << "Assigned: " << assigned << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << PINK "\n==== The End ====" RESET << std::endl;
    return 0;
}
