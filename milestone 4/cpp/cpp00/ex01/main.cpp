/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:47:55 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/08 20:21:19 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook book;
    std::string c;

    while (1) {
        std::cout << "What uw lah.. only ADD, SEARCH or EXIT" << std::endl;
        if (!getline(std::cin, c))
            return (1);
        if (c == "ADD")
            book.AddContact();
        else if (c == "SEARCH")
            book.SearchContact();
        else if (c == "EXIT") {
            std::cout << "bye bitch. dont wanna see u ever" << std::endl;
            break;
        }
        else 
            std::cout << "bodoh udk how to read is it? i say only ADD, SEARCH or EXIT right?????" << std::endl;
    }

    return 0;
}
