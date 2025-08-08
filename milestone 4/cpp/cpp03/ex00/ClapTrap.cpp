/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:03:48 by lkoh              #+#    #+#             */
/*   Updated: 2025/08/08 14:38:26 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("noname"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " default constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name("noname"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    _name = name;
    std::cout << "ClapTrap " << _name <<  " w/ params constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap " << _name << " copy constructed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap " << _name << " copy assigned" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " can't attack because there's no hit points" << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " can't attack because there's not enough energy points" << std::endl;
        return;
    }
    --_energyPoints;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    // std::cout << "ClapTrap " << _name << " energy at " << _energyPoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " has taken " << amount << " damage" << std::endl;
    if (_hitPoints <= 0) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " die alr lo" << std::endl;
        return;
    }
        std::cout << "ClapTrap " << _name << " health at " << _hitPoints << std::endl;
        // std::cout << "ClapTrap " << _name << " energy at " << _energyPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " does not have enough energy points to be repaired" << std::endl;
        return;
    }
    --_energyPoints;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " has been repaired " << amount << " points" << std::endl;
    std::cout << "ClapTrap " << _name << " health at " << _hitPoints << std::endl;
    // std::cout << "ClapTrap " << _name << " energy at " << _energyPoints << std::endl;
}