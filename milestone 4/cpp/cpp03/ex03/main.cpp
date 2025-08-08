/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:34:41 by lkoh              #+#    #+#             */
/*   Updated: 2025/08/08 15:14:18 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n--- ClapTrap Test ---" << std::endl;
    ClapTrap ct("Clap1");
    ct.attack("target1");
    ct.takeDamage(5);
    ct.beRepaired(3);

    for (int i = 0; i < 10; i++)
    {
        ct.attack("DUM");
    }
    ct.beRepaired(1);

    std::cout << "\n--- ScavTrap Test ---" << std::endl;
    ScavTrap st("Scav1");
    st.attack("target2");
    st.takeDamage(20);
    st.beRepaired(10);
    st.guardGate();

    for (int i = 0; i < 50; i++)
    {
        st.attack("DUM");
    }
    st.beRepaired(1);

    std::cout << "\n--- FragTrap Test ---" << std::endl;
    FragTrap ft("Frag1");
    ft.attack("target3");
    ft.takeDamage(50);
    ft.beRepaired(25);
    ft.highFivesGuys();

    for (int i = 0; i < 100; i++)
    {
        ft.attack("DUM");
    }
    ft.beRepaired(1);

    std::cout << "\n--- DiamondTrap Test ---" << std::endl;
    DiamondTrap dt("Diamond1");
    dt.attack("target4");
    dt.takeDamage(75);
    dt.beRepaired(50);
    dt.whoAmI();

    for (int i = 0; i < 100; i++)
    {
        dt.attack("DUM");
    }
    dt.beRepaired(1);

    std::cout << "\n--- Destruction Order ---" << std::endl;
    return 0;
}
