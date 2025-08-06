/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 23:51:56 by lkoh              #+#    #+#             */
/*   Updated: 2025/08/04 17:56:46 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    _name = name;
    _weapon = NULL;
}

void HumanB::attack() const {
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else 
        std::cout << _name << " attacks with his bare hands" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
}