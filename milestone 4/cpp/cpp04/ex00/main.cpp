/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:47:12 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/12 23:08:21 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();
//     ...
//     return 0;
// }

int main() {
    std::cout << "\n--- Normal Tests ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\nAnimal type: " << meta->getType() << std::endl;
    std::cout << "Dog type: " << j->getType() << std::endl;
    std::cout << "Cat type: " << i->getType() << std::endl;

    std::cout << "\nAnimal sounds:" << std::endl;
    std::cout << "Animal: ";
    meta->makeSound();
    std::cout << "Dog: ";
    j->makeSound();
    std::cout << "Cat: ";
    i->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- WrongAnimal Tests ---" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "\nWrongAnimal type: " << wrongMeta->getType() << std::endl;
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;

    std::cout << "\nWrongAnimal sounds: ";
    wrongMeta->makeSound();
    std::cout << "WrongCat sound: ";
    wrongCat->makeSound();

    delete wrongMeta;
    delete wrongCat;

    return 0;
}
