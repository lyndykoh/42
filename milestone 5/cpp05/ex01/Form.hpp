/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:43:07 by lkoh              #+#    #+#             */
/*   Updated: 2025/08/24 21:39:34 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _sign_grade;
        const int _exec_grade;
    public:
        Form();
        Form(const std::string name, const int sign_grade, const int exec_grade);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        const std::string getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(const Bureaucrat &bureaucrat);
    
        class GradeTooHighException : public std::exception {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            const char* what() const throw();
        };
        class AlreadySignedException : public std::exception {
            const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream& os, Form const &form);

#endif