#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << PINK "=== Bureaucrats ===" RESET << std::endl;
    Bureaucrat boss("Boss", 1);       // highest grade
    Bureaucrat mid("Middle", 75);     // medium grade
    Bureaucrat intern("Intern", 150); // lowest grade

    std::cout << boss << std::endl;
    std::cout << mid << std::endl;
    std::cout << intern << std::endl;

    std::cout << PINK "\n=== Creating Forms ===" RESET << std::endl;
    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << "\n";
    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    std::cout << PINK "\n=== Signing Forms ===" RESET << std::endl;
    intern.signForm(shrub);  // too low grade
    mid.signForm(robo);      // too low grade
    boss.signForm(robo);     // success
    boss.signForm(shrub);    // success
    boss.signForm(pardon);   // success

    std::cout << PINK "\n=== Executing Forms ===" RESET << std::endl;

    std::cout << PINK "\n-- Shrubbery Creation --" RESET << std::endl;
    intern.executeForm(shrub); // fail: low grade
    // boss.executeForm(shrub);   // success: creates file

    std::cout << PINK "\n-- Robotomy Request --" RESET << std::endl;
    mid.executeForm(robo);     // fail: low grade
    boss.executeForm(robo);    // success: random outcome
    boss.executeForm(robo);    // test multiple times for randomness
    boss.executeForm(robo);    // test multiple times for randomness
    boss.executeForm(robo);    // test multiple times for randomness

    std::cout << PINK "\n-- Presidential Pardon --" RESET << std::endl;
    mid.executeForm(pardon);   // fail: low grade
    boss.executeForm(pardon);  // success

    std::cout << PINK "\n=== Copy & Assignment Tests ===" RESET << std::endl;
    ShrubberyCreationForm copyShrub(shrub); // copy constructor
    ShrubberyCreationForm assignShrub;
    assignShrub = shrub;                  // assignment

    std::cout << copyShrub << std::endl;
    std::cout << assignShrub << std::endl;

    return 0;
}
