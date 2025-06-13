/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:47:12 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/13 15:15:03 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "--- Polymorphic Array Test ---" << std::endl;
    const int size = 4;
    Animal* animals[size];

    // Fill first half with Dogs, second half with Cats
    for (int i = 0; i < size; ++i) {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Making Sounds ---" << std::endl;
    for (int i = 0; i < size; ++i)
        animals[i]->makeSound();

    std::cout << "\n--- Deleting Animals ---" << std::endl;
    for (int i = 0; i < size; ++i)
        delete animals[i];

    std::cout << "\n--- Deep Copy Test ---" << std::endl;
    Dog basicDog;
    {
        Dog copyDog = basicDog;  // Calls copy constructor
    } // copyDog goes out of scope, destructor should be called

    std::cout << "\n--- Assignment Operator Deep Copy Test ---" << std::endl;
    Cat cat1;
    Cat cat2;
    cat2 = cat1;  // Calls assignment operator

    return 0;
}