/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:25:35 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/06 15:28:54 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "\n--- ClapTrap Tests ---" << std::endl;
    ClapTrap ct("CT-Alpha");
    ct.attack("Bandit");
    ct.takeDamage(5);
    ct.beRepaired(3);

    std::cout << "\n--- ScavTrap Tests ---" << std::endl;
    ScavTrap st("ST-Beta");
    st.attack("Skag");
    st.takeDamage(30);
    st.beRepaired(10);
    st.guardGate();

    std::cout << "\n--- FragTrap Tests ---" << std::endl;
    FragTrap ft("FT-Gamma");
    ft.attack("Psycho");
    ft.takeDamage(50);
    ft.beRepaired(25);
    ft.highFivesGuys();

    std::cout << "\n--- Destruction order ---" << std::endl;
    return 0;
}

