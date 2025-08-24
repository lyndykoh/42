/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:43:07 by lkoh              #+#    #+#             */
/*   Updated: 2025/08/25 01:49:52 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _signed;
        const int _sign_grade;
        const int _exec_grade;
        virtual void executeAction() const = 0;
        
    public:
        AForm();
        AForm(const std::string name, const int sign_grade, const int exec_grade);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        ~AForm();

        const std::string getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(const Bureaucrat &bureaucrat);
        void execute(Bureaucrat const & executor) const;
    
        class GradeTooHighException : public std::exception {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            const char* what() const throw();
        };
        class AlreadySignedException : public std::exception {
            const char* what() const throw();
        };
        class NotSignedException : public std::exception {
            const char* what() const throw();
        };
        
};

std::ostream &operator<<(std::ostream& os, AForm const &aform);

#endif
