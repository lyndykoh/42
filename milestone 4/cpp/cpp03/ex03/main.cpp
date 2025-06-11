/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:34:41 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/11 12:34:42 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n--- ClapTrap Test ---" << std::endl;
    ClapTrap clap("CL4P-TP");
    clap.attack("target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n--- ScavTrap Test ---" << std::endl;
    ScavTrap scav("SC4V-TP");
    scav.attack("target2");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n--- FragTrap Test ---" << std::endl;
    FragTrap frag("FR4G-TP");
    frag.attack("target3");
    frag.takeDamage(50);
    frag.beRepaired(25);
    frag.highFivesGuys();

    std::cout << "\n--- DiamondTrap Test ---" << std::endl;
    DiamondTrap diamond("DI4M-TP");
    diamond.attack("target4");
    diamond.takeDamage(75);
    diamond.beRepaired(50);
    diamond.whoAmI();

    std::cout << "\n--- Destruction Order ---" << std::endl;
    return 0;
}
