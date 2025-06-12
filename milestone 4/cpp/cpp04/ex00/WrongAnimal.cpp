/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:30:40 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/12 22:41:45 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "WrongAnimal default constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
    std::cout << "WrongAnimal copy constructed" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << "WrongAnimal copy assigned" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Woem Foow huh?" << std::endl;
}

std::string WrongAnimal::getType() const {
    return (_type);
}