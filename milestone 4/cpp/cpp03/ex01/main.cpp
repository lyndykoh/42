/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:25:35 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/05 17:18:04 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

    std::cout << "\n--- Destruction order ---" << std::endl;
    return 0;
}
