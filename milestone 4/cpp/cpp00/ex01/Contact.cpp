/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:49:55 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/09 14:49:03 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string first, std::string last, std::string nick, std::string number, std::string secret){
    FirstName = first;
    LastName = last;
    NickName = nick;
    PhoneNumber = number; 
    DarkestSecret = secret;
};

void Contact::DisplayFull() const {
    std::cout << "First Name: " << FirstName << std::endl;
    std::cout << "Last Name: " << LastName << std::endl;
    std::cout << "Nickname: " << NickName << std::endl;
    std::cout << "Phone Number: " << PhoneNumber << std::endl;
    std::cout << "Darkest Secret: " << DarkestSecret << std::endl;
};

void Contact::DisplaySummary(int index) const {
    std::cout << "............................................" << std::endl;
    std::cout << std::setw(10) << index << "|";

    if (FirstName.length() > 10) {
        std::cout << FirstName.substr(0, 9) << ".|";
    } else {
        std::cout << std::setw(10) << FirstName << "|";
    }

    if (LastName.length() > 10) {
        std::cout << LastName.substr(0, 9) << ".|";
    } else {
        std::cout << std::setw(10) << LastName << "|";
    }

    if (NickName.length() > 10) {
        std::cout << NickName.substr(0, 9) << ".|";
    } else {
        std::cout << std::setw(10) << NickName << "|";
    }
    std::cout << std::endl;
}
