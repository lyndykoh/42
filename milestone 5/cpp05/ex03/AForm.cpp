/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:03:05 by lkoh              #+#    #+#             */
/*   Updated: 2025/08/25 01:49:49 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// default constructor
AForm::AForm() : _name("Default"), _signed(false), _sign_grade(150), _exec_grade(150) {
    std::cout << "Bureaucrat " << _name << " constructed." << std::endl;
}

// custom constructor
AForm::AForm(const std::string name, const int sign_grade, const int exec_grade) : 
    _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
        if (sign_grade < 1 || exec_grade < 1)
            throw GradeTooHighException();
        else if (sign_grade > 150 || sign_grade > 150)
            throw GradeTooLowException();
}

// copy constructor
AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), 
    _sign_grade(other._sign_grade), _exec_grade(other._exec_grade) {
        std::cout << "Bureaucrat " << _name << " copy constructed" << std::endl;
}

// copy assignment
AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        this->_signed = other._signed;
    return (*this);
}

// destructor
AForm::~AForm() {
    std::cout << "Form " << _name << " destroyed" << std::endl;
}

// getters
const std::string AForm::getName() const {
    return (_name);
}

bool AForm::isSigned() const{
    return (_signed);
}

int AForm::getSignGrade() const {
    return (_sign_grade);
}

int AForm::getExecGrade() const {
    return (_exec_grade);
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (_signed)
        throw AlreadySignedException();
    if (bureaucrat.getGrade() < _sign_grade)
        _signed = true;
    else 
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const {
    if (_signed == false)
        throw NotSignedException();
    else if (_exec_grade < executor.getGrade())
        throw GradeTooLowException();
    else 
        executeAction();
}

// exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return (RED "Grade too high" RESET);
}

const char* AForm::GradeTooLowException::what() const throw() {
    return (RED "Grade too low" RESET);
}

const char* AForm::AlreadySignedException::what() const throw() {
    return (RED "Form already signed" RESET);
}

const char* AForm::NotSignedException::what() const throw() {
    return (RED "Form not signed" RESET);
}

std::ostream &operator<<(std::ostream &os, AForm const &aform) {
    os << "Form: " << aform.getName() << "\nSigned: " << aform.isSigned() << 
    "\nMin Sign Grade: " << aform.getSignGrade() << "\nMin Execute Grade: " << aform.getExecGrade() << std:: endl;
    return (os);
}