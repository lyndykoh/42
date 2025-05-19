/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:41:54 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/18 23:45:20 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    private: 
        std::string _name;
        Weapon &_weapon;
    public:
        HumanA(std::string name, Weapon &weapon);
        void attack() const;
};

#endif