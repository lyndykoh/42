/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:57:59 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/12 22:07:41 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << "Dog default constructed" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copy constructed" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    Animal::operator=(other);
    std::cout << "Dog copy assigned" << std::endl;
    return (*this);
}

Dog::~Dog() {
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof bitches" << std::endl;
}