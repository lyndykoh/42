/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:03:05 by lkoh              #+#    #+#             */
/*   Updated: 2025/08/24 21:41:03 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// default constructor
Form::Form() : _name("Default"), _signed(false), _sign_grade(150), _exec_grade(150) {
    std::cout << "Bureaucrat " << _name << " constructed." << std::endl;
}

// custom constructor
Form::Form(const std::string name, const int sign_grade, const int exec_grade) : 
    _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
        if (sign_grade < 1 || exec_grade < 1)
            throw GradeTooHighException();
        else if (sign_grade > 150 || sign_grade > 150)
            throw GradeTooLowException();
}

// copy constructor
Form::Form(const Form &other) : _name(other._name), _signed(other._signed), 
    _sign_grade(other._sign_grade), _exec_grade(other._exec_grade) {
        std::cout << "Bureaucrat " << _name << " copy constructed" << std::endl;
}

// copy assignment
Form &Form::operator=(const Form &other) {
    if (this != &other)
        this->_signed = other._signed;
    return (*this);
}

// destructor
Form::~Form() {
    std::cout << "Form " << _name << " destroyed" << std::endl;
}

// getters
const std::string Form::getName() const {
    return (_name);
}

bool Form::isSigned() const{
    return (_signed);
}

int Form::getSignGrade() const {
    return (_sign_grade);
}

int Form::getExecGrade() const {
    return (_exec_grade);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (_signed)
        throw AlreadySignedException();
    if (bureaucrat.getGrade() < _sign_grade)
        _signed = true;
    else 
        throw GradeTooLowException();
}

// exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return (RED "Grade too high" RESET);
}

const char* Form::GradeTooLowException::what() const throw() {
    return (RED "Grade too low" RESET);
}

const char* Form::AlreadySignedException::what() const throw() {
    return (RED "Form already signed" RESET);
}

std::ostream &operator<<(std::ostream &os, Form const &form) {
    os << "Form: " << form.getName() << "\nSigned: " << form.isSigned() << 
    "\nMin Sign Grade: " << form.getSignGrade() << "\nMin Execute Grade: " << form.getExecGrade() << std:: endl;
    return (os);
}