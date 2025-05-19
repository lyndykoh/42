/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:41:38 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/18 23:45:47 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

    Weapon::Weapon(std::string type) {
        _type = type;
    }
    
    std::string Weapon::getType() {
        return _type;
    }
    
    void Weapon::setType(std::string type) {
        _type = type;
    }