#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "\n=== Creating Bureaucrats ===\n" << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat junior("Junior", 150);
    Bureaucrat mid("Middle", 75);

    std::cout << boss << junior << mid << std::endl;

    std::cout << "\n=== Testing Intern ===\n" << std::endl;
    Intern someIntern;

    // Array of valid form names
    std::string formNames[] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm",
        "NonExistentForm" // invalid
    };

    // Try creating each form
    for (int i = 0; i < 4; i++) {
        std::cout << "\n--- Trying to create form: " << formNames[i] << " ---\n" << std::endl;
        AForm *form = someIntern.makeForm(formNames[i], "Target_" + std::to_string(i+1));

        if (!form) {
            std::cout << "Intern failed to create " << formNames[i] << std::endl;
            continue;
        }

        // Try signing forms with different bureaucrats
        try {
            boss.signForm(*form);   // always high enough grade
            mid.signForm(*form);    // may fail if sign grade too high
            junior.signForm(*form); // usually fails
        } catch (std::exception &e) {
            std::cerr << "Exception while signing: " << e.what() << std::endl;
        }

        // Try executing forms
        try {
            boss.executeForm(*form);    // should work
            mid.executeForm(*form);     // may fail if exec grade too high
            junior.executeForm(*form);  // usually fails
        } catch (std::exception &e) {
            std::cerr << "Exception while executing: " << e.what() << std::endl;
        }

        // delete form;
    }

    std::cout << "\n=== Testing copy and assignment ===\n" << std::endl;
    ShrubberyCreationForm original("Home");
    ShrubberyCreationForm copy(original); // copy constructor
    ShrubberyCreationForm assigned("Temp");
    assigned = original;                   // copy assignment

    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy: " << copy << std::endl;
    std::cout << "Assigned: " << assigned << std::endl;

    std::cout << "\n=== Testing increment/decrement edge cases ===\n" << std::endl;
    try {
        Bureaucrat top("TopDog", 1);
        top.increment();  // should throw
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat low("LowMan", 150);
        low.decrement();  // should throw
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== All tests done ===\n" << std::endl;
    return 0;
}
