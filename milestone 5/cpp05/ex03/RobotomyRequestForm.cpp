/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 02:13:39 by lkoh              #+#    #+#             */
/*   Updated: 2025/08/25 02:51:32 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : 
    AForm("RobotomyRequestForm", 72, 45), _target("Default") {
    std::cout << "RobotomyRequestForm " << _target << " default constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : 
    AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm " << _target << " constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
    AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm " << _target << " copy constructed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm " << _target << " is destroyed" << std::endl;
}

void RobotomyRequestForm::executeAction() const {
    if (rand() % 2)
        std::cout << "BZZZZZZZZ " << _target << " successfully robotomised" << std::endl;
    else 
        throw RobotomyFailException();
}

const char* RobotomyRequestForm::RobotomyFailException::what() const throw() {
    return (RED "Failed to robotomise" RESET);
}