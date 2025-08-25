/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:31:28 by lkoh              #+#    #+#             */
/*   Updated: 2025/08/25 02:08:03 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : 
    AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
    std::cout << "ShrubberyCreationForm " << _target << " default constructed." << std::endl;
}

// custom constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : 
    AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm " << _target << " constructed" << std::endl;
}

// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : 
    AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm " << _target << " copy constructed" << std::endl;
}

// copy assignment
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

// destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm " << _target << " is destroyed" << std::endl;
}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream outfile(_target + "_shrubbery");
    if (outfile)
    {
        outfile << "          #\n";
        outfile << "         ###\n";
        outfile << "        #o###\n";
        outfile << "       ##*o###\n";
        outfile << "      #o#\\#|#*#\n";
        outfile << "     ##*##\\|/#o#\n";
        outfile << "    #o###\\|/#*###\n";
        outfile << "   ##*#o#\\|/#o##*#\n";
        outfile << "  #o###*##\\|/#o##*#\n";
        outfile << " ##*##o#*#\\|/##*##o#\n";
        outfile << "        }||{\n";
        outfile << "        }||{\n";
        outfile << "        }||{\n";
        outfile << "        }||{\n";
        outfile.close();
    }
    else 
        throw OpenWriteFileException();
}

const char* ShrubberyCreationForm::OpenWriteFileException::what() const throw() {
    return (RED "Cannot open or write file" RESET);
}