/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:10:13 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/12 22:13:18 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    std::cout << "Cat default constructed" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructed" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    Animal::operator=(other);
    std::cout << "Cat copy assigned" << std::endl;
    return (*this);
}

Cat::~Cat() {
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow meow meow meow" << std::endl;
}