/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:25:35 by lkoh              #+#    #+#             */
/*   Updated: 2025/08/08 15:04:41 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "\n--- ClapTrap Tests ---" << std::endl;
    ClapTrap ct("Clap1");
    ct.attack("Bandit");
    ct.takeDamage(5);
    ct.beRepaired(3);
    
    for (int i = 0; i < 10; i++)
    {
        ct.attack("DUM");
    }
    ct.beRepaired(1);

    std::cout << "\n--- ScavTrap Tests ---" << std::endl;
    ScavTrap st("Scav1");
    st.attack("Skag");
    st.takeDamage(30);
    st.beRepaired(10);
    st.guardGate();

    for (int i = 0; i < 50; i++)
    {
        st.attack("DUM");
    }
    st.beRepaired(1);

    std::cout << "\n--- Destruction order ---" << std::endl;
    return 0;
}
