/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:28:58 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/18 21:47:44 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void ) {
    std::cout << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) {
    Name = name;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << Name << " pewpew died.." << std::endl;
}