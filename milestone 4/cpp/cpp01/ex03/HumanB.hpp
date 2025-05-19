/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:42:54 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/18 23:45:07 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
    private: 
        std::string _name;
        Weapon *_weapon;
    public:
        HumanB(std::string name);
        void attack() const;
        void setWeapon(Weapon &weapon);
};

#endif