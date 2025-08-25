/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 03:00:10 by lkoh              #+#    #+#             */
/*   Updated: 2025/08/25 14:50:16 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern constructed" << std::endl;
}

Intern::Intern(const Intern &other) {
    (void) other;
}

Intern &Intern::operator=(const Intern &other) {
    (void) other;
    return (*this);
}

Intern::~Intern() {
    std::cout << "Intern destroyed" << std::endl;
}

AForm* Intern::makeForm(const std::string formName, const std::string formTarget) {
    std::string forms[3] = {"ShrubberyCreationForm" ,"RobotomyRequestForm", "PresidentialPardonForm"};
    int i = 0; 
    while (i < 3 && formName != forms[i])
        i++;
    
    switch(i)
    {
        case 0: 
            std::cout << "Intern created " << formName << std::endl;
            return new ShrubberyCreationForm(formTarget);
        case 1: 
            std::cout << "Intern created " << formName << std::endl;
            return new RobotomyRequestForm(formTarget);
        case 2: 
            std::cout << "Intern created " << formName << std::endl;
            return new PresidentialPardonForm(formTarget);
        default: 
            std::cout << RED "File does not exist, cant create" RESET << std::endl;
            return NULL;
    }
        return NULL;
    
}
