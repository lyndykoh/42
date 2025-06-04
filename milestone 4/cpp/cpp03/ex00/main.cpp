/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:25:35 by lkoh              #+#    #+#             */
/*   Updated: 2025/06/04 17:26:39 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("CL4P-TP");
    ClapTrap clap2("Unit-01");

    // Display initial states by calling methods that print messages.
    clap1.attack("Skag");
    clap1.takeDamage(3);
    clap1.beRepaired(2);

    clap2.attack("Rakk Hive");
    clap2.takeDamage(5);
    clap2.beRepaired(4);

    // Testing depletion of energy and hit points
    for (int i = 0; i < 10; ++i) {
        clap1.attack("Dummy Target");
    }
    clap1.beRepaired(3); // should fail because no energy left

    // Testing overkill damage
    clap2.takeDamage(20);
    clap2.attack("another target"); // should fail because no hit points left
    clap2.beRepaired(5); // should fail because no hit points left

    return 0;
}
