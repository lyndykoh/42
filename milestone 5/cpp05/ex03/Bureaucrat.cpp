/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:09:11 by lkoh              #+#    #+#             */
/*   Updated: 2025/08/25 02:33:28 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// default constructor
Bureaucrat::Bureaucrat() : _name("No Name"), _grade(150) {
    std::cout << "Bureaucrat " << _name << " is constructed." << std::endl;
}

// custom constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else 
        _grade = grade;
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat " << _name << " copy constructed." << std::endl;
}

// copy assignment
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->_grade = other._grade;
    }
    return (*this);
}

// destructor
Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

// exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return (RED "Grade too high" RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return (RED "Grade too low" RESET);
}

// getters
const std::string Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const {
    return (_grade);
}

// increment decrement
void Bureaucrat::increment() {
    if (_grade == 1)
        throw GradeTooHighException();
    else 
        _grade -= 1;
}

void Bureaucrat::decrement() {
    if (_grade == 150)
        throw GradeTooLowException();
    else 
        _grade += 1;
}

void Bureaucrat::signForm(AForm &aform) {
    try {
        aform.beSigned(*this);
        std::cout << GREEN "Bureaucrat " << _name << " signed " << aform.getName() << RESET << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << RED <<  _name << " couldn't sign " << aform.getName() << " because " << e.what() << RESET << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &aform) {
    try {
        aform.execute(*this);
        std::cout << GREEN << _name << " executed " << aform.getName() << RESET << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << RED << _name << " couldn't execute " << aform.getName() << " because " << e.what() << RESET << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other) {
    os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (os);
}