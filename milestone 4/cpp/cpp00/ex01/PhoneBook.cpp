/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:09:58 by lkoh              #+#    #+#             */
/*   Updated: 2025/07/28 16:07:07 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    index = 0;
    count = 0;
};

bool PhoneBook::CheckNum(std::string number) const {
    for (size_t i = 0; i < number.length(); i++) {
        if (!isdigit(number[i]))
            return false;
    }
    return true;
};

void PhoneBook::AddContact(){
    std::string first, last, nick, number, secret;
    
    std::cout << "Enter First Name: ";
    if (!getline(std::cin, first))
        exit(1);
    else if (first.empty()){
        std::cout << "Brother udk ur friend's name? again lah ";
        if (!getline(std::cin, first))
            exit(1);
    }

    std::cout << "Enter Last Name: ";
    if (!getline(std::cin, last))
        exit(1);
    else if (last.empty()){
        std::cout << "Brother udk ur friend's last name? again lah ";
        if (!getline(std::cin, last))
            exit(1);
    }


    std::cout << "Enter Nickname: ";
    if (!getline(std::cin, nick))
        exit(1);
    else if (nick.empty()){
        std::cout << "udh a nickname for ur friend? thats not ur friend.. again.. ";
        if (!getline(std::cin, nick))
            exit(1);
    }

    
    std::cout << "Enter Phone Number: ";
    if (!getline(std::cin, number))
        exit(1);
    while (number.empty() || !CheckNum(number)){
        std::cout << "why u trying to save a contact without number? again lah ";
        if (!getline(std::cin, number))
            exit(1);
    }

    
    std::cout << "Enter Darkest Secret: ";
    if (!getline(std::cin, secret))
        exit(1);
    else if (secret.empty()){
        std::cout << "ik uk ur friends darkest secret.. ";
        if (!getline(std::cin, secret))
            exit(1);
    }

    std::cout << "\n";

    contacts[index] = Contact(first, last, nick, number, secret);
    index = (index + 1) % 8;
    if (count < 8) {
        count++;
    }

    std::cout << "Contact added successfully!\n";
};

void PhoneBook::SearchContact() const {
    std::string input;
    
    if (count == 0) {
        std::cout << "U nvr even add any contacts who u searching for???\n";
        return;
    }
    
    for (int i = 0; i < count; i++) {
        contacts[i].DisplaySummary(i + 1);
    }
    
    while (true) {
        std::cout << "who uw to see? give a number ";
        if (!getline(std::cin, input))
            exit(1);
        
        bool isValid = !input.empty();
        for (size_t i = 0; i < input.length(); i++) {
            if (!std::isdigit(input[i])) {
                isValid = false;
                break;
            }
        }
        if (!isValid) {
            std::cout << "bruh that's not even a number try again \n";
            continue;
        }
        int index = std::atoi(input.c_str());

        if (index >= 1 && index <= count) {
            contacts[index - 1].DisplayFull();
            break;
        } else {
            std::cout << "brother u cant read? theres only " << count << " numbers..\n";
        }
    }
}