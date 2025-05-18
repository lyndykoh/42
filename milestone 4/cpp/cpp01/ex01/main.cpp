/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:29:53 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/18 22:16:36 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main () {
    int hordeSize = 5;
    Zombie *Zombie1 = zombieHorde(hordeSize, "Foo");
    if (Zombie1){
        for (int i = 0; i < hordeSize; i++) {
            Zombie1[i].announce();
        }
        delete[] Zombie1;
    }
    return (0);
}