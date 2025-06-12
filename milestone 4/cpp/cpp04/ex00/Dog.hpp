/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:53:57 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/12 22:09:39 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
    public: 
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        virtual ~Dog();

        void makeSound() const;
};

#endif
