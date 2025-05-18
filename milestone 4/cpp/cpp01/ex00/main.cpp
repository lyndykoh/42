/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:29:53 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/18 21:46:34 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main () {
    Zombie *Zombie1 = newZombie("Foo");
    Zombie1->announce();
    delete Zombie1;

    randomChump("Hoo");
    return (0);
}