/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:47:12 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/13 10:43:30 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "\n--- Creating Individual Animals ---\n" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\n--- Deleting Individual Animals ---\n" << std::endl;

    delete j; // Should delete Dog and its Brain
    delete i; // Should delete Cat and its Brain

    std::cout << "\n--- Creating Animal Array ---\n" << std::endl;

    const int arraySize = 4;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize / 2; ++i)
        animals[i] = new Dog();
    for (int i = arraySize / 2; i < arraySize; ++i)
        animals[i] = new Cat();

    std::cout << "\n--- Making Sounds ---\n" << std::endl;

    for (int i = 0; i < arraySize; ++i)
        animals[i]->makeSound();

    std::cout << "\n--- Deleting Animal Array ---\n" << std::endl;

    for (int i = 0; i < arraySize; ++i)
        delete animals[i];

    std::cout << "\n--- Deep Copy Test ---\n" << std::endl;

    Dog* original = new Dog();

    Dog* copy = new Dog(*original);  // Invokes copy constructor

    delete original;
    delete copy;

    return 0;
}
