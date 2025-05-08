/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:04:41 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/08 20:06:44 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>


class PhoneBook {
    private: 

        int count;
        int index;
    public:
        Contact contacts[8];
        PhoneBook();
        void AddContact();
        void SearchContact() const;
        bool CheckNum(std::string number) const;
};

#endif
