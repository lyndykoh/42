/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:07:56 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/12 22:09:49 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        virtual ~Cat();

        void makeSound() const;
};

#endif
